%{
    #include "tree.h"
    #include "parser.tab.h"
    int colu_number = 1;
    int line_number = 1;
    int lexicalErrors = 0;

    #define INC_COLUMN colu_number += strlen(yytext)

    void saveTokenStr(enum node_type type_node);
    void saveTokenDecimal(enum node_type type_node);
    void saveTokenInteger(enum node_type type_node);

#ifdef DEBUG_FLEX
	#define DEBUG_F(...) printf(__VA_ARGS__)
#else
	#define DEBUG_F(...)
#endif
%}

%option noinput nounput

%x COMMENT

LETTER      [a-zA-Z]
DIGIT       [0-9]
INTEGER     {DIGIT}+
DECIMAL     ({DIGIT}+)?\.{DIGIT}+
WHITESPACE  [ \t]+
RG_TYPE     int|float|elem|set
RG_ID       (_|{LETTER})({LETTER}|{DIGIT}|_)*
STRING      \"[^"]*\"
CHAR        \'[^']?\'|\'\\[^']\'

%%

("//").*[^\n]  BEGIN(COMMENT); INC_COLUMN; DEBUG_F("<com, %s>\n", yytext);
<COMMENT>\n    BEGIN(0); line_number++;

{RG_TYPE}   { DEBUG_F("<TYPE, %s>\n", yytext); saveTokenStr(NODE_TYPE); INC_COLUMN; return TYPE; }

"if"        { DEBUG_F("<if>\n");        INC_COLUMN; return KY_IF;     }
"else"      { DEBUG_F("<else>\n");      INC_COLUMN; return KY_ELSE;   }
"for"       { DEBUG_F("<for>\n");       INC_COLUMN; return KY_FOR;    }
"return"    { DEBUG_F("<return>\n");    INC_COLUMN; return KY_RETURN; }

"add"       { DEBUG_F("<add>\n");       INC_COLUMN; return KY_ADD;    }
"remove"    { DEBUG_F("<remove>\n");    INC_COLUMN; return KY_REMOVE; }
"in"        { DEBUG_F("<in>\n");        INC_COLUMN; return KY_IN;     }
"forall"    { DEBUG_F("<forall>\n");    INC_COLUMN; return KY_FORALL; }
"write"     { DEBUG_F("<write>\n");     INC_COLUMN; return KY_WRITE;  }
"writeln"   { DEBUG_F("<writeln>\n");   INC_COLUMN; return KY_WRITELN;}
"exists"    { DEBUG_F("<exists>\n");    INC_COLUMN; return KY_EXISTS; }
"EMPTY"     { DEBUG_F("<EMPTY>\n");     INC_COLUMN; return KY_EMPTY;  }
"is_set"    { DEBUG_F("<is_set>\n");    INC_COLUMN; return KY_IS_SET; }

";"         { DEBUG_F("<;>\n");    INC_COLUMN; return CSEMICOLON;}
","         { DEBUG_F("<,>\n");    INC_COLUMN; return CCOMA;     }
"("         { DEBUG_F("<(>\n");    INC_COLUMN; return COPARENT;  }
")"         { DEBUG_F("<)>\n");    INC_COLUMN; return CCPARENT;  }
"{"         { DEBUG_F("<{>\n");    INC_COLUMN; return COBRACE;   }
"}"         { DEBUG_F("<}>\n");    INC_COLUMN; return CCBRACE;   }

"+"         { DEBUG_F("<add, %s>\n", yytext); INC_COLUMN; return OP_ARITH_ADD; }
"-"         { DEBUG_F("<sub, %s>\n", yytext); INC_COLUMN; return OP_ARITH_SUB; }
"*"         { DEBUG_F("<mul, %s>\n", yytext); INC_COLUMN; return OP_ARITH_MUL; }
"/"         { DEBUG_F("<div, %s>\n", yytext); INC_COLUMN; return OP_ARITH_DIV; }

"||"        { DEBUG_F("<op_or, %s>\n", yytext);  INC_COLUMN; return OP_LOG_OR;    }
"&&"        { DEBUG_F("<op_and, %s>\n", yytext); INC_COLUMN; return OP_LOG_AND;   }

"=="        { DEBUG_F("<op_eq, %s>\n", yytext);  INC_COLUMN; saveTokenStr(NODE_COMP_OP); return OP_COMP; }
"!="        { DEBUG_F("<op_neq,%s>\n", yytext);  INC_COLUMN; saveTokenStr(NODE_COMP_OP); return OP_COMP; }
">"         { DEBUG_F("<op_gt,%s>\n",  yytext);  INC_COLUMN; saveTokenStr(NODE_COMP_OP); return OP_COMP; }
"<"         { DEBUG_F("<op_lt,%s>\n",  yytext);  INC_COLUMN; saveTokenStr(NODE_COMP_OP); return OP_COMP; }
">="        { DEBUG_F("<op_gte,%s>\n", yytext);  INC_COLUMN; saveTokenStr(NODE_COMP_OP); return OP_COMP; }
"<="        { DEBUG_F("<op_lte,%s>\n", yytext);  INC_COLUMN; saveTokenStr(NODE_COMP_OP); return OP_COMP; }
"!"         { DEBUG_F("<op_neg,%s>\n", yytext);  INC_COLUMN; return OP_LOG_NEG; }

"="         { DEBUG_F("<op_assign,%s>\n", yytext); INC_COLUMN; return OP_ASSIGN;}

{INTEGER}   { DEBUG_F("<inteiro,%s>\n", yytext); INC_COLUMN; saveTokenInteger(NODE_INTEGER); return INTEGER; }
{DECIMAL}   { DEBUG_F("<decimal,%s>\n", yytext); INC_COLUMN; saveTokenDecimal(NODE_DECIMAL); return DECIMAL; }

{CHAR}      { DEBUG_F("<char,%s>\n", yytext);   INC_COLUMN; saveTokenStr(NODE_CHAR);   return CHAR;  }
{STRING}    { DEBUG_F("<string,%s>\n", yytext); INC_COLUMN; saveTokenStr(NODE_STRING); return STRING;}

{RG_ID}     { DEBUG_F("<id,%s>\n", yytext); INC_COLUMN; saveTokenStr(NODE_ID); return ID; }

{WHITESPACE} { INC_COLUMN; }

"\n" {line_number++; colu_number = 1;}

. {
    INC_COLUMN;
    ++lexicalErrors;
    fprintf(stderr, "[FLEX] character not recognized: %s (%d, %d)\n", yytext, line_number, colu_number);
} 


%%

void saveTokenStr(enum node_type type_node){
    struct node_s *node = createNode(type_node, NULL);
    node->linha = line_number;
    node->coluna = colu_number;
    node->nodeName = (char *) malloc((yyleng + 1) * sizeof(char));

    strcpy(node->nodeName, yytext);

    yylval.node = node;
}

void saveTokenDecimal(enum node_type type_node){
    struct node_s *node = createNode(type_node, NULL);
    node->linha = line_number;
    node->coluna = colu_number;
    node->decimal = atof(yytext);
    yylval.node = node;
}
void saveTokenInteger(enum node_type type_node){
    struct node_s *node = createNode(type_node, NULL);
    node->linha = line_number;
    node->coluna = colu_number;
    node->integer = atof(yytext);
    yylval.node = node;
}