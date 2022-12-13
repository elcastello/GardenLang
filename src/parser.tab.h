/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TYPE = 258,                    /* TYPE  */
    CSEMICOLON = 259,              /* CSEMICOLON  */
    KY_IF = 260,                   /* KY_IF  */
    KY_THEN = 261,                 /* KY_THEN  */
    KY_ELSE = 262,                 /* KY_ELSE  */
    KY_FOR = 263,                  /* KY_FOR  */
    KY_RETURN = 264,               /* KY_RETURN  */
    KY_EMPTY = 265,                /* KY_EMPTY  */
    KY_FORALL = 266,               /* KY_FORALL  */
    KY_READ = 267,                 /* KY_READ  */
    KY_WRITE = 268,                /* KY_WRITE  */
    KY_WRITELN = 269,              /* KY_WRITELN  */
    KY_EXISTS = 270,               /* KY_EXISTS  */
    KY_IN = 271,                   /* KY_IN  */
    KY_IS_SET = 272,               /* KY_IS_SET  */
    KY_ADD = 273,                  /* KY_ADD  */
    KY_REMOVE = 274,               /* KY_REMOVE  */
    COPARENT = 275,                /* COPARENT  */
    CCPARENT = 276,                /* CCPARENT  */
    COBRACE = 277,                 /* COBRACE  */
    CCBRACE = 278,                 /* CCBRACE  */
    CCOMA = 279,                   /* CCOMA  */
    OP_ARITH_ADD = 280,            /* OP_ARITH_ADD  */
    OP_ARITH_SUB = 281,            /* OP_ARITH_SUB  */
    OP_ARITH_MUL = 282,            /* OP_ARITH_MUL  */
    OP_ARITH_DIV = 283,            /* OP_ARITH_DIV  */
    OP_LOG_OR = 284,               /* OP_LOG_OR  */
    OP_LOG_AND = 285,              /* OP_LOG_AND  */
    OP_LOG_NEG = 286,              /* OP_LOG_NEG  */
    OP_COMP = 287,                 /* OP_COMP  */
    OP_ASSIGN = 288,               /* OP_ASSIGN  */
    ID = 289,                      /* ID  */
    STRING = 290,                  /* STRING  */
    CHAR = 291,                    /* CHAR  */
    INTEGER = 292,                 /* INTEGER  */
    DECIMAL = 293                  /* DECIMAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 95 "parser.y"

	struct node_s *node;

#line 106 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
