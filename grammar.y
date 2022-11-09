source_program:
	decl_definitions_list
;

decl_definitions_list:
	decl_definitions_list decl_or_func_def
	| decl_or_func_def
;

decl_or_func_def:
	function_definition
	| variable_declaration
;

variable_declaration:
	TYPE ID CSEMICOLON
;

function_definition:
	TYPE ID COPARENT parameters CCPARENT statement_group_braces
;

parameters:
	parameter_list
	|
;

parameter_list:
	parameter_list CCOMA parameter
	| parameter
;

parameter:
	TYPE ID
;

statement_group_or_statement:
	statement_group_braces
	| statement
;

statement_group_braces:
	COBRACE statement_list CCBRACE
;

statement_list:
	statement_list statement
	| statement
;

statement:
	variable_declaration
	| expression_statement CSEMICOLON
	| return_statement CSEMICOLON
	| set_statement CSEMICOLON
	| loop_statement
	| if_statement
;

expression_statement:
	expression
;

return_statement:
	KY_RETURN set_arith_expression
;

expression:
	ID OP_ASSIGN simple_arith_expression
	| ID OP_ASSIGN call_function
	| call_function
	| ID OP_ARITH_ADD OP_ASSIGN simple_arith_expression
	| ID OP_ARITH_SUB OP_ASSIGN simple_arith_expression
;

simple_arith_expression:
	simple_arith_expression OP_ARITH_ADD term
	| simple_arith_expression OP_ARITH_SUB term
	| term
;

term:
	term OP_ARITH_MUL factor
	| term OP_ARITH_DIV factor
	| factor
;

factor:
	COPARENT simple_arith_expression CCPARENT
	| KY_EMPTY
	| ID
	| INTEGER
	| DECIMAL
	/* For special cases: -5.0+2-3 */
	| OP_ARITH_ADD INTEGER
	| OP_ARITH_SUB INTEGER
	| OP_ARITH_ADD DECIMAL
	| OP_ARITH_SUB DECIMAL
	/* ----------------------------------- */
;

set_in_expression:
	set_arith_expression KY_IN set_arith_expression
;

set_arith_expression:
	simple_arith_expression
	| call_set_expression
;

call_set_expression:
	set_func_expression
	| COPARENT set_func_expression CCPARENT
	| call_function
;

set_func_expression:
	KY_IS_SET COPARENT ID CCPARENT
	| KY_ADD COPARENT set_in_expression CCPARENT
	| KY_REMOVE COPARENT set_in_expression CCPARENT
	| KY_EXISTS COPARENT set_in_expression CCPARENT
;

call_function:
	ID COPARENT arguments CCPARENT
;

arguments:
	| arguments_list
;

arguments_list:
	arguments_list CCOMA argument
	| argument
;

argument:
	simple_arith_expression
;

loop_statement:
	KY_FORALL COPARENT set_in_expression CCPARENT statement_group_or_statement
;

if_statement:
	KY_IF COPARENT op_log_and_operation CCPARENT statement_group_or_statement %prec THEN
	| KY_IF COPARENT op_log_and_operation CCPARENT statement_group_or_statement KY_ELSE statement_group_or_statement
;

op_log_and_operation:
	op_log_and_operation OP_LOG_AND op_log_or_operation
	| op_log_or_operation
;

op_log_or_operation:
	op_log_or_operation OP_LOG_OR op_neg_operation
	| op_neg_operation
;

op_neg_operation:
	OP_LOG_NEG op_neg_operation
	| op_comp_operation
;

op_comp_operation:
	op_comp_operation OP_COMP expression_or_arith
	| expression_or_arith
;

expression_or_arith:
	simple_arith_expression
	| set_in_expression
	| call_set_expression
;

set_statement:
	KY_WRITE COPARENT char_or_string CCPARENT
	| KY_WRITELN COPARENT char_or_string CCPARENT
	| KY_READ COPARENT char_or_string CCPARENT
	| set_func_expression
;

char_or_string:
	CHAR
	| STRING 
;