%{
#include <stdio.h>
#include <stdbool.h>
#include "tree.h"
#include "list.h"
#include "main.h"

int yylex();
void yyerror(const char *s);

extern int colu_number;
extern int line_number;
extern int syntaxErrors;

extern struct list *symbolTab;
extern struct node_s *cst_root;

#ifdef DEBUG_BISON
	#define DEBUG_B(...) printf(__VA_ARGS__)
#else
	#define DEBUG_B(...)
#endif
%}

%define lr.type canonical-lr
%define parse.error verbose

%token TYPE
%token CSEMICOLON

%token KY_IF
%token KY_THEN
%token KY_ELSE
%token KY_FOR
%token KY_RETURN

// ky do set
%token KY_EMPTY
%token KY_FORALL
%token KY_READ
%token KY_WRITE
%token KY_WRITELN
%token KY_EXISTS
%token KY_IN
%token KY_IS_SET
%token KY_ADD
%token KY_REMOVE

%token COPARENT
%token CCPARENT
%token COBRACE
%token CCBRACE
%token CCOMA

%token OP_ARITH_ADD
%token OP_ARITH_SUB
%token OP_ARITH_MUL
%token OP_ARITH_DIV
%token OP_LOG_OR
%token OP_LOG_AND
%token OP_LOG_NEG
%token OP_COMP
%token OP_ASSIGN

%token ID
%token STRING
%token CHAR
%token INTEGER
%token DECIMAL
// ------------------------------------------------------------

%right OP_ASSIGN
%left OP_COMP
%left OP_ARITH_MUL OP_ARITH_DIV
%left OP_ARITH_ADD OP_ARITH_SUB

%nonassoc KY_THEN
%nonassoc KY_ELSE

%type <node> source_program decl_definitions_list decl_or_func_def function_definition variable_declaration
%type <node> parameters parameter_list parameter statement_group_braces
%type <node> statement statement_list
%type <node> expression_statement return_statement set_statement loop_statement if_statement else_statement
%type <node> expression set_arith_expression simple_arith_expression call_function
%type <node> term factor set_in_expression call_set_expression set_func_expression
%type <node> arguments arguments_list argument op_log_and_operation
%type <node> op_log_or_operation op_neg_operation op_comp_operation expression_or_arith
%type <node> set_func_argument

%type <node> ID STRING CHAR TYPE OP_COMP
%type <node> INTEGER
%type <node> DECIMAL
// --- Tipos ---

%union{
	struct node_s *node;
}
%%

// Gramática:
source_program:
	decl_definitions_list
	{
		struct node_s *newNode = createNode(NODE_SOURCE, "source_program");
		attachNode(newNode, 1, $1);
		cst_root = newNode;

		DEBUG_B("[#%d] (source_program) -> decl_definitions_list\n", __LINE__);
	}
;

decl_definitions_list:
	decl_definitions_list decl_or_func_def
	{
		struct node_s *newNode = createNode(NODE_DECL_LIST, "decl_definitions_list");
		attachNode(newNode, 2, $1, $2);

		$$ = newNode;
		DEBUG_B("[#%d] (decl_definitions_list) -> decl_definitions_list decl_or_func_def\n", __LINE__);
	}
	| decl_or_func_def
	{
		$$ = $1;
		DEBUG_B("[#%d] (decl_definitions_list) -> decl_or_func_def\n", __LINE__);
	}
;

decl_or_func_def:
	function_definition
	{
		$$ = $1;
		DEBUG_B("[#%d] (decl_or_func_def) -> function_definition\n", __LINE__);
	}
	| variable_declaration
	{
		$$ = $1;
		DEBUG_B("[#%d] (decl_or_func_def) -> variable_declaration\n", __LINE__);
	}
;

variable_declaration:
	TYPE ID CSEMICOLON
	{
		struct node_s *newNode = createNode(NODE_VAR_DECL, "variable_declaration");
		attachNode(newNode, 2, $1, $2);
		newNode->pTable = insertSymbol(symbolTab, newNode);

		$$ = newNode;
		DEBUG_B("[#%d] (variable_declaration) -> TYPE ID CSEMICOLON\n", __LINE__);
	}
;

function_definition:
	TYPE ID COPARENT parameters CCPARENT statement_group_braces
	{
		struct node_s *newNode = createNode(NODE_FUNC_DEF, "function_definition");
		attachNode(newNode, 4, $1, $2, $4, $6);
		newNode->pTable = findSymbolOrInsert(newNode);

		applyParentAllChindren($6, $4);
		applyParentAllChindren(newNode, $6);

		$$ = newNode;
		DEBUG_B("[#%d] (function_definition) -> TYPE ID COPARENT parameters CCPARENT statement_group_braces\n", __LINE__);
	}
;

parameters:
	parameter_list
	{
		$$ = $1;
		DEBUG_B("[#%d] (parameters) -> (parameter_list)\n", __LINE__);
	}
	|
	{
		$$ = createNode(NODE_PARAMS, "parameter_list");
		DEBUG_B("[#%d] (parameters) -> EMPTY\n", __LINE__);
	}
;

parameter_list:
	parameter_list CCOMA parameter
	{
		struct node_s *newNode = createNode(NODE_PARAMS, "parameter_list");
		attachNode(newNode, 2, $1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (parameter_list) -> parameter_list CCOMA parameter\n", __LINE__);
	}
	| parameter
	{
		$$ = $1;
		DEBUG_B("[#%d] (parameter_list) -> parameter\n", __LINE__);
	}
;

parameter:
	TYPE ID
	{
		struct node_s *newNode = createNode(NODE_PARAMETER, "parameter");
		attachNode(newNode, 2, $1, $2);

		newNode->pTable = insertSymbol(symbolTab, newNode);

		$$ = newNode;
		DEBUG_B("[#%d] (parameter) -> TYPE ID\n", __LINE__);
	}
;

statement_group_braces:
	COBRACE statement_list CCBRACE
	{
		struct node_s *newNode = createNode(NODE_SCOPE, "scope");
		attachNode(newNode, 1, $2);
		applyParentAllChindren(newNode, $2);

		$$ = newNode;
		DEBUG_B("[#%d] (statement_group_braces) -> {statement_list}\n", __LINE__);
	}
	| COBRACE CCBRACE
	{
		$$ = createNode(NODE_SCOPE, "scope");
		DEBUG_B("[#%d] (statement_group_braces) -> {}\n", __LINE__);
	}
;

statement_list:
	statement_list statement
	{
		struct node_s *newNode = createNode(NODE_STMT_LIST, "statement_list");
		attachNode(newNode, 2, $1, $2);

		$$ = newNode;
		DEBUG_B("[#%d] (statement_list) -> statement_list statement\n", __LINE__);
	}
	| statement
	{
		$$ = $1;
		DEBUG_B("[#%d] (statement_list) -> statement\n", __LINE__);
	}
;

statement:
	variable_declaration
	{
		$$ = $1;
		DEBUG_B("[#%d] (statement) -> variable_declaration\n", __LINE__);
	}
	| expression_statement
	{
		$$ = $1;
		DEBUG_B("[#%d] (statement) -> expression_statement;\n", __LINE__);
	}
	| return_statement
	{
		$$ = $1;
		DEBUG_B("[#%d] (statement) -> return_statement;\n", __LINE__);
	}
	| set_statement
	{
		$$ = $1;
		DEBUG_B("[#%d] (statement) -> set_statement;\n", __LINE__);
	}
	| loop_statement
	{
		$$ = $1;
		DEBUG_B("[#%d] (statement) -> loop_statement\n", __LINE__);
	}
	| if_statement
	{
		$$ = $1;
		DEBUG_B("[#%d] (statement) -> if_statement\n", __LINE__);
	}
	| statement_group_braces
	{
		$$ = $1;
		DEBUG_B("[#%d] (statement) -> statement_group_braces\n", __LINE__);
	}
	| function_definition
	{
		$$ = $1;
		DEBUG_B("[#%d] (statement) -> function_definition\n", __LINE__);
	}
	| error { yyerrok; }
;

expression_statement:
	expression CSEMICOLON
	{
		$$ = $1;
		DEBUG_B("[#%d] (expression_statement) -> expression\n", __LINE__);
	}
	| CSEMICOLON
	{
		$$ = createNode(NODE_UNKNOWN, "expression");
		DEBUG_B("[#%d] (expression_statement) -> empty\n", __LINE__);
	}
;

return_statement:
	KY_RETURN expression CSEMICOLON
	{
		struct node_s *newNode = createNode(NODE_RETURN, "return");
		attachNode(newNode, 1, $2);

		$$ = newNode;
		DEBUG_B("[#%d] (return_statement) -> KY_RETURN expression CSEMICOLON", __LINE__);
	}
	| KY_RETURN CSEMICOLON
	{
		$$ = createNode(NODE_RETURN, "return");
		DEBUG_B("[#%d] (return_statement) -> KY_RETURN CSEMICOLON", __LINE__);
	}
;

expression:
	ID OP_ASSIGN expression
	{
		struct node_s *newNode = createNode(NODE_ASSIGN, "exp_assign");
		attachNode(newNode, 2, $1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (expression) -> ID OP_ASSIGN expression\n", __LINE__);
	}
	| op_log_and_operation
	{
		$$ = $1;
		DEBUG_B("[#%d] (expression) -> op_log_and_operation\n", __LINE__);
	}
;

simple_arith_expression:
	simple_arith_expression OP_ARITH_ADD term
	{
		struct node_s *newNode = createNode(NODE_ARITH_ADD, "op_add");
		attachNode(newNode, 2, $1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (simple_arith_expression) -> simple_arith_expression OP_ARITH_ADD term\n", __LINE__);
	}
	| simple_arith_expression OP_ARITH_SUB term
	{
		struct node_s *newNode = createNode(NODE_ARITH_SUB, "op_sub");
		attachNode(newNode, 2, $1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (simple_arith_expression) -> simple_arith_expression OP_ARITH_SUB term\n", __LINE__);
	}
	| term
	{
		$$ = $1;
		DEBUG_B("[#%d] (simple_arith_expression) -> term\n", __LINE__);
	}
;

term:
	term OP_ARITH_MUL factor
	{
		struct node_s *newNode = createNode(NODE_ARITH_MUL, "op_mul");
		attachNode(newNode, 2, $1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (term) -> (term OP_ARITH_MUL factor)\n", __LINE__);
	}
	| term OP_ARITH_DIV factor
	{
		struct node_s *newNode = createNode(NODE_ARITH_DIV, "op_div");
		attachNode(newNode, 2, $1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (term) -> (term OP_ARITH_DIV factor)\n", __LINE__);
	}
	| factor
	{
		$$ = $1;
		DEBUG_B("[#%d] (term) -> (factor)\n", __LINE__);
	}
;

factor:
	COPARENT expression CCPARENT
	{
		struct node_s *newNode = createNode(NODE_FACTOR, "factor");
		attachNode(newNode, 1, $2);
		
		$$ = newNode;
		DEBUG_B("[#%d] (factor) -> (expression)\n", __LINE__);
	}
	| KY_EMPTY
	{
		$$ = createNode(NODE_EMPTY, "EMPTY");
		DEBUG_B("[#%d] (factor) -> KY_EMPTY\n", __LINE__);
	}
	| ID
	{
		$$ = $1;
		DEBUG_B("[#%d] (factor) -> ID\n", __LINE__);
	}
	| INTEGER
	{
		$$ = $1;
		DEBUG_B("[#%d] (factor) -> INTEGER\n", __LINE__);
	}
	| DECIMAL
	{
		$$ = $1;
		DEBUG_B("[#%d] (factor) -> DECIMAL\n", __LINE__);
	}
	| STRING
	{
		// procurar string na tabela. Se não achar, insere!
		$$ = $1;
		DEBUG_B("[#%d] (factor) -> STRING\n", __LINE__);
	}
	| CHAR
	{
		$$ = $1;
		DEBUG_B("[#%d] (factor) -> CHAR\n", __LINE__);
	}
	| call_function
	{
		$$ = $1;
		DEBUG_B("[#%d] (factor) -> call_function\n", __LINE__);
	}
	/* Para casos especiais como: -5.0+2-3 */
	| OP_ARITH_ADD INTEGER
	{
		$$ = $2;
		DEBUG_B("[#%d] (factor) -> OP_ARITH_ADD INTEGER\n", __LINE__);
	}
	| OP_ARITH_SUB INTEGER
	{
		$2->integer = -$2->integer;
		$$ = $2;
		DEBUG_B("[#%d] (factor) -> OP_ARITH_SUB INTEGER\n", __LINE__);
	}
	| OP_ARITH_ADD DECIMAL
	{
		$$ = $2;
		DEBUG_B("[#%d] (factor) -> OP_ARITH_ADD DECIMAL\n", __LINE__);
	}
	| OP_ARITH_SUB DECIMAL
	{
		$2->decimal = -$2->decimal;
		$$ = $2;
		DEBUG_B("[#%d] (factor) -> OP_ARITH_SUB DECIMAL\n", __LINE__);
	}
	/* ----------------------------------- */
;

set_in_expression:
	set_arith_expression KY_IN set_arith_expression
	{
		struct node_s *newNode = createNode(NODE_SET_IN, "set_in_expression");
		attachNode(newNode, 2, $1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (set_in_expression) -> set_arith_expression IN set_arith_expression\n", __LINE__);
	}
;

set_arith_expression:
	simple_arith_expression
	{
		$$ = $1;
		DEBUG_B("[#%d] (set_arith_expression) -> simple_arith_expression\n", __LINE__);
	}
	| call_set_expression
	{
		$$ = $1;
		DEBUG_B("[#%d] (set_arith_expression) -> call_set_expression\n", __LINE__);
	}
;

call_set_expression:
	set_func_expression
	{
		$$ = $1;
		DEBUG_B("[#%d] (call_set_expression) -> set_func_expression\n", __LINE__);
	}
;

set_func_expression:
	KY_IS_SET COPARENT ID CCPARENT
	{
		struct node_s *newNode = createNode(NODE_IS_SET, "is_set");
		attachNode(newNode, 1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (set_func_expression) -> KY_IS_SET COPARENT ID CCPARENT\n", __LINE__);
	}
	| KY_ADD COPARENT set_in_expression CCPARENT
	{
		struct node_s *newNode = createNode(NODE_SET_ADD, "add");
		attachNode(newNode, 1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (set_func_expression) -> KY_ADD COPARENT set_in_expression CCPARENT\n", __LINE__);
	}
	| KY_REMOVE COPARENT set_in_expression CCPARENT
	{
		struct node_s *newNode = createNode(NODE_REMOVE, "remove");
		attachNode(newNode, 1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (set_func_expression) -> KY_REMOVE COPARENT set_in_expression CCPARENT\n", __LINE__);
	}
	| KY_EXISTS COPARENT set_in_expression CCPARENT
	{
		struct node_s *newNode = createNode(NODE_EXISTS, "exists");
		attachNode(newNode, 1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (set_func_expression) -> KY_EXISTS COPARENT set_in_expression CCPARENT\n", __LINE__);
	}
;

call_function:
	ID COPARENT arguments CCPARENT
	{
		struct node_s *newNode = createNode(NODE_CALL_FUNC, "call_function");

		if($3 != NULL) {
			attachNode(newNode, 2, $1, $3);
			applyParentAllChindren(newNode, $3);
		} else {
			attachNode(newNode, 1, $1);
		}

		$$ = newNode;
		DEBUG_B("[#%d] (call_function) -> ID COPARENT arguments CCPARENT\n", __LINE__);
	}
;

arguments:
	arguments_list
	{
		$$ = $1;
		DEBUG_B("[#%d] (arguments) -> arguments_list\n", __LINE__);
	}
	| {
		$$ = createNode(NODE_ARGS, "arguments_list");;
		DEBUG_B("[#%d] (arguments) -> empty\n", __LINE__);
	}
;

arguments_list:
	arguments_list CCOMA argument
	{
		struct node_s *newNode = createNode(NODE_ARGS, "arguments_list");
		struct node_s *arg = createNode(NODE_ARGUMENT, "argument");

		attachNode(arg, 1, $3);
		attachNode(newNode, 2, $1, arg);

		$$ = newNode;
		DEBUG_B("[#%d] (arguments_list) -> arguments_list CCOMA argument\n", __LINE__);
	}
	| argument
	{
		struct node_s *newNode = createNode(NODE_ARGUMENT, "argument");
		attachNode(newNode, 1, $1);

		$$ = newNode;
		DEBUG_B("[#%d] (arguments_list) -> argument\n", __LINE__);
	}
;

argument:
	simple_arith_expression
	{
		$$ = $1;
		DEBUG_B("[#%d] (argument) -> simple_arith_expression\n", __LINE__);
	}
;

loop_statement:
	KY_FORALL COPARENT set_in_expression CCPARENT statement
	{
		struct node_s *newNode = createNode(NODE_FORALL, "forall");
		attachNode(newNode, 2, $3, $5);
		applyParentAllChindren(newNode, $3);
		applyParentAllChindren(newNode, $5);

		$$ = newNode;
		DEBUG_B("[#%d] (loop_statement) -> forall\n", __LINE__);
	}
	| KY_FOR COPARENT expression_statement CSEMICOLON expression_statement CSEMICOLON expression CCPARENT statement
	{
		struct node_s *newNode = createNode(NODE_FOR, "for");

		if( $3 != NULL){
			attachNode(newNode, 1, $3);
			applyParentAllChindren(newNode, $3);
		}
			
		
		if( $5 != NULL){
			attachNode(newNode, 1, $5);
			applyParentAllChindren(newNode, $5);
		}
			
		
		if( $7 != NULL){
			attachNode(newNode, 1, $7);
			applyParentAllChindren(newNode, $7);
		}
			
	
		attachNode(newNode, 1, $9);
		applyParentAllChindren(newNode, $9);

		$$ = newNode;
		DEBUG_B("[#%d] (loop_statement) -> for\n", __LINE__);
	}
;

if_statement:
	KY_IF COPARENT expression CCPARENT statement %prec KY_THEN
	{
		struct node_s *newNode = createNode(NODE_IF, "if");
		attachNode(newNode, 2, $3, $5);
		applyParentAllChindren(newNode, $3);
		applyParentAllChindren(newNode, $5);

		$$ = newNode;
		DEBUG_B("[#%d] (if_statement) -> if\n", __LINE__);
	}
	| KY_IF COPARENT expression CCPARENT statement else_statement
	{
		struct node_s *newNode = createNode(NODE_IF, "if");
		attachNode(newNode, 3, $3, $5, $6);
		applyParentAllChindren(newNode, $3);
		applyParentAllChindren(newNode, $5);

		$$ = newNode;
		DEBUG_B("[#%d] (if_statement) -> if\n", __LINE__);
	}
;

else_statement:
	KY_ELSE statement
	{
		struct node_s *newNode = createNode(NODE_ELSE, "else");
		attachNode(newNode, 1, $2);
		applyParentAllChindren(newNode, $2);

		$$ = newNode;
		DEBUG_B("[#%d] (else_statement) -> else\n", __LINE__);
	}
;

op_log_and_operation:
	op_log_and_operation OP_LOG_AND op_log_or_operation
	{
		struct node_s *newNode = createNode(NODE_AND, "log_and");
		attachNode(newNode, 2, $1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (op_log_and_operation) -> op_log_and_operation OP_LOG_AND op_log_or_operation\n", __LINE__);
	}
	| op_log_or_operation
	{
		$$ = $1;
		DEBUG_B("[#%d] (op_log_and_operation) -> op_log_or_operation\n", __LINE__);
	}
;

op_log_or_operation:
	op_log_or_operation OP_LOG_OR op_neg_operation
	{
		struct node_s *newNode = createNode(NODE_OR, "log_or");
		attachNode(newNode, 2, $1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (op_log_or_operation) -> op_log_or_operation OP_LOG_OR op_neg_operation\n", __LINE__);
	}
	| op_neg_operation
	{
		$$ = $1;
		DEBUG_B("[#%d] (op_log_or_operation) -> op_neg_operation\n", __LINE__);
	}
;

op_neg_operation:
	OP_LOG_NEG op_neg_operation
	{
		struct node_s *newNode = createNode(NODE_NEG, "log_neg");
		attachNode(newNode, 1, $2);

		$$ = newNode;
		DEBUG_B("[#%d] (op_neg_operation) -> OP_LOG_NEG op_neg_operation\n", __LINE__);
	}
	| op_comp_operation
	{
		$$ = $1;
		DEBUG_B("[#%d] (op_neg_operation) -> op_comp_operation\n", __LINE__);
	}
;

op_comp_operation:
	op_comp_operation OP_COMP expression_or_arith
	{
		struct node_s *newNode = createNode(NODE_COMP, "op_comp");
		attachNode(newNode, 3, $1, $2, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (op_comp_operation) -> op_comp_operation OP_COMP expression_or_arith\n", __LINE__);
	}
	| expression_or_arith
	{
		$$ = $1;
		DEBUG_B("[#%d] (op_comp_operation) -> expression_or_arith\n", __LINE__);
	}
;

expression_or_arith:
	simple_arith_expression
	{
		$$ = $1;
		DEBUG_B("[#%d] (expression_or_arith) -> simple_arith_expression\n", __LINE__);
	}
	| set_in_expression
	{
		$$ = $1;
		DEBUG_B("[#%d] (expression_or_arith) -> set_in_expression\n", __LINE__);
	}
	| call_set_expression
	{
		$$ = $1;
		DEBUG_B("[#%d] (expression_or_arith) -> call_set_expression\n", __LINE__);
	}
;

set_statement:
	KY_WRITE COPARENT simple_arith_expression CCPARENT CSEMICOLON
	{
		struct node_s *newNode = createNode(NODE_WRITE, "write");
		attachNode(newNode, 1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (set_statement) -> write\n", __LINE__);
	}
	| KY_WRITELN COPARENT simple_arith_expression CCPARENT CSEMICOLON
	{
		struct node_s *newNode = createNode(NODE_WRITELN, "writeln");
		attachNode(newNode, 1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (set_statement) -> writeln\n", __LINE__);
	}
	| KY_READ COPARENT set_func_argument CCPARENT CSEMICOLON
	{
		struct node_s *newNode = createNode(NODE_READ, "read");
		attachNode(newNode, 1, $3);

		$$ = newNode;
		DEBUG_B("[#%d] (set_statement) -> read\n", __LINE__);
	}
;

set_func_argument:
	CHAR
	{
		struct node_s *newNode = createNode(NODE_ARGUMENT, "set_func_argument");
		attachNode(newNode, 1, $1);

		$$ = newNode;
		DEBUG_B("[#%d] (set_func_parameter) -> CHAR\n", __LINE__);
	}
	| STRING
	{
		struct node_s *newNode = createNode(NODE_ARGUMENT, "set_func_argument");
		attachNode(newNode, 1, $1);

		$$ = newNode;
		DEBUG_B("[#%d] (set_func_parameter) -> STRING\n", __LINE__);
	}
	| ID
	{
		struct node_s *newNode = createNode(NODE_ARGUMENT, "set_func_argument");
		attachNode(newNode, 1, $1);

		$$ = newNode;
		DEBUG_B("[#%d] (set_func_parameter) -> ID\n", __LINE__);
	}
;

%start source_program;
%%

void yyerror(const char *s) {
	fprintf(stderr, "Erro sintático em: linha %d, coluna %d:\n", line_number, colu_number);
	fprintf(stderr, "-> Mensagem: %s\n", s);
	++syntaxErrors;
}