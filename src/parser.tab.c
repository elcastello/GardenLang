/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 95 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TYPE = 3,                       /* TYPE  */
  YYSYMBOL_CSEMICOLON = 4,                 /* CSEMICOLON  */
  YYSYMBOL_KY_IF = 5,                      /* KY_IF  */
  YYSYMBOL_KY_THEN = 6,                    /* KY_THEN  */
  YYSYMBOL_KY_ELSE = 7,                    /* KY_ELSE  */
  YYSYMBOL_KY_FOR = 8,                     /* KY_FOR  */
  YYSYMBOL_KY_RETURN = 9,                  /* KY_RETURN  */
  YYSYMBOL_KY_EMPTY = 10,                  /* KY_EMPTY  */
  YYSYMBOL_KY_FORALL = 11,                 /* KY_FORALL  */
  YYSYMBOL_KY_READ = 12,                   /* KY_READ  */
  YYSYMBOL_KY_WRITE = 13,                  /* KY_WRITE  */
  YYSYMBOL_KY_WRITELN = 14,                /* KY_WRITELN  */
  YYSYMBOL_KY_EXISTS = 15,                 /* KY_EXISTS  */
  YYSYMBOL_KY_IN = 16,                     /* KY_IN  */
  YYSYMBOL_KY_IS_SET = 17,                 /* KY_IS_SET  */
  YYSYMBOL_KY_ADD = 18,                    /* KY_ADD  */
  YYSYMBOL_KY_REMOVE = 19,                 /* KY_REMOVE  */
  YYSYMBOL_COPARENT = 20,                  /* COPARENT  */
  YYSYMBOL_CCPARENT = 21,                  /* CCPARENT  */
  YYSYMBOL_COBRACE = 22,                   /* COBRACE  */
  YYSYMBOL_CCBRACE = 23,                   /* CCBRACE  */
  YYSYMBOL_CCOMA = 24,                     /* CCOMA  */
  YYSYMBOL_OP_ARITH_ADD = 25,              /* OP_ARITH_ADD  */
  YYSYMBOL_OP_ARITH_SUB = 26,              /* OP_ARITH_SUB  */
  YYSYMBOL_OP_ARITH_MUL = 27,              /* OP_ARITH_MUL  */
  YYSYMBOL_OP_ARITH_DIV = 28,              /* OP_ARITH_DIV  */
  YYSYMBOL_OP_LOG_OR = 29,                 /* OP_LOG_OR  */
  YYSYMBOL_OP_LOG_AND = 30,                /* OP_LOG_AND  */
  YYSYMBOL_OP_LOG_NEG = 31,                /* OP_LOG_NEG  */
  YYSYMBOL_OP_COMP = 32,                   /* OP_COMP  */
  YYSYMBOL_OP_ASSIGN = 33,                 /* OP_ASSIGN  */
  YYSYMBOL_ID = 34,                        /* ID  */
  YYSYMBOL_STRING = 35,                    /* STRING  */
  YYSYMBOL_CHAR = 36,                      /* CHAR  */
  YYSYMBOL_INTEGER = 37,                   /* INTEGER  */
  YYSYMBOL_DECIMAL = 38,                   /* DECIMAL  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_source_program = 40,            /* source_program  */
  YYSYMBOL_decl_definitions_list = 41,     /* decl_definitions_list  */
  YYSYMBOL_decl_or_func_def = 42,          /* decl_or_func_def  */
  YYSYMBOL_variable_declaration = 43,      /* variable_declaration  */
  YYSYMBOL_function_definition = 44,       /* function_definition  */
  YYSYMBOL_parameters = 45,                /* parameters  */
  YYSYMBOL_parameter_list = 46,            /* parameter_list  */
  YYSYMBOL_parameter = 47,                 /* parameter  */
  YYSYMBOL_statement_group_braces = 48,    /* statement_group_braces  */
  YYSYMBOL_statement_list = 49,            /* statement_list  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_expression_statement = 51,      /* expression_statement  */
  YYSYMBOL_return_statement = 52,          /* return_statement  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_simple_arith_expression = 54,   /* simple_arith_expression  */
  YYSYMBOL_term = 55,                      /* term  */
  YYSYMBOL_factor = 56,                    /* factor  */
  YYSYMBOL_set_in_expression = 57,         /* set_in_expression  */
  YYSYMBOL_set_arith_expression = 58,      /* set_arith_expression  */
  YYSYMBOL_call_set_expression = 59,       /* call_set_expression  */
  YYSYMBOL_set_func_expression = 60,       /* set_func_expression  */
  YYSYMBOL_call_function = 61,             /* call_function  */
  YYSYMBOL_arguments = 62,                 /* arguments  */
  YYSYMBOL_arguments_list = 63,            /* arguments_list  */
  YYSYMBOL_argument = 64,                  /* argument  */
  YYSYMBOL_loop_statement = 65,            /* loop_statement  */
  YYSYMBOL_if_statement = 66,              /* if_statement  */
  YYSYMBOL_else_statement = 67,            /* else_statement  */
  YYSYMBOL_op_log_and_operation = 68,      /* op_log_and_operation  */
  YYSYMBOL_op_log_or_operation = 69,       /* op_log_or_operation  */
  YYSYMBOL_op_neg_operation = 70,          /* op_neg_operation  */
  YYSYMBOL_op_comp_operation = 71,         /* op_comp_operation  */
  YYSYMBOL_expression_or_arith = 72,       /* expression_or_arith  */
  YYSYMBOL_set_statement = 73,             /* set_statement  */
  YYSYMBOL_set_func_argument = 74          /* set_func_argument  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   5042

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  526

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   102,   102,   113,   121,   129,   134,   142,   154,   169,
     175,   182,   190,   198,   211,   220,   228,   236,   244,   249,
     254,   259,   264,   269,   274,   279,   284,   288,   293,   301,
     309,   317,   325,   333,   341,   349,   357,   365,   373,   381,
     389,   394,   399,   404,   409,   415,   420,   426,   431,   437,
     442,   452,   463,   468,   476,   484,   492,   500,   508,   519,
     536,   541,   548,   559,   570,   578,   588,   619,   629,   642,
     654,   662,   670,   678,   686,   694,   702,   710,   718,   723,
     728,   736,   744,   752,   763,   771,   779
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TYPE", "CSEMICOLON",
  "KY_IF", "KY_THEN", "KY_ELSE", "KY_FOR", "KY_RETURN", "KY_EMPTY",
  "KY_FORALL", "KY_READ", "KY_WRITE", "KY_WRITELN", "KY_EXISTS", "KY_IN",
  "KY_IS_SET", "KY_ADD", "KY_REMOVE", "COPARENT", "CCPARENT", "COBRACE",
  "CCBRACE", "CCOMA", "OP_ARITH_ADD", "OP_ARITH_SUB", "OP_ARITH_MUL",
  "OP_ARITH_DIV", "OP_LOG_OR", "OP_LOG_AND", "OP_LOG_NEG", "OP_COMP",
  "OP_ASSIGN", "ID", "STRING", "CHAR", "INTEGER", "DECIMAL", "$accept",
  "source_program", "decl_definitions_list", "decl_or_func_def",
  "variable_declaration", "function_definition", "parameters",
  "parameter_list", "parameter", "statement_group_braces",
  "statement_list", "statement", "expression_statement",
  "return_statement", "expression", "simple_arith_expression", "term",
  "factor", "set_in_expression", "set_arith_expression",
  "call_set_expression", "set_func_expression", "call_function",
  "arguments", "arguments_list", "argument", "loop_statement",
  "if_statement", "else_statement", "op_log_and_operation",
  "op_log_or_operation", "op_neg_operation", "op_comp_operation",
  "expression_or_arith", "set_statement", "set_func_argument", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-358)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      13,    -7,    35,   125,   137,   153,   163,     6,  -358,   220,
     339,    25,    -5,    28,   325,   356,   370,    33,    73,   713,
     433,   431,  2773,  2811,    60,    67,   193,   360,    69,    71,
      74,    86,    96,    98,   110,   122,   572,   474,   140,   345,
     861,   132,   507,   522,   772,   809,  2849,  2887,  2925,  2963,
    3001,  3039,  3077,    97,     7,   824,   908,   262,   119,    49,
     115,   962,  3115,  3153,     8,    81,   120,   271,   291,  3191,
     572,   997,  3229,   168,  1312,    34,  1119,  1119,  1312,   149,
    1312,  1312,   167,  1218,  1358,  1513,  3930,    70,   186,   225,
    1270,   489,  3267,  3305,  3943,  3943,  3943,  3943,  1389,   861,
     861,  1490,   171,   210,  3343,   335,   200,   240,   205,   223,
     248,   265,    83,   283,   267,   272,   281,   290,  3957,   647,
     296,   540,   604,   330,  3972,  3987,  4002,  4017,   306,   228,
     244,   318,  1693,   997,  1812,   336,   341,   353,   139,   166,
     170,   175,  4032,  4043,  1550,   369,  3381,  3419,  3457,  3495,
     616,  1812,  3533,   572,  3571,   331,  1812,  3609,   375,  3647,
    4297,   355,   397,   419,   423,   572,   484,   557,  1459,  4267,
    4312,  4327,  4342,  4357,   443,  4372,  4387,    29,   434,    91,
     679,  4402,    27,   204,   485,   155,   731,   454,   456,   398,
     450,   458,   465,   473,   572,   562,   574,   227,   471,   502,
     633,   743,   857,  1029,   487,   492,  1049,  1232,   572,   660,
     665,  1461,  1608,  4894,  4902,  4910,  4918,  4926,  4934,  1251,
     572,   704,   720,  4758,  1591,  4766,  4774,  4782,  4790,  4798,
    4806,   782,   490,   545,   550,   559,   572,   741,   752,   402,
    1287,  1407,  1642,  4136,    15,  4144,  4154,   326,   349,  4163,
    4062,  4062,  1119,  1119,  4043,  4043,  1769,   567,  1855,   573,
     610,  1090,   618,   634,   637,   649,  3685,  1899,  1937,  1975,
    2013,  2051,   673,  2089,  2127,  2165,    10,  3723,  3761,  1312,
     651,  1312,  1312,   662,  4417,  4432,  4447,  4462,  4282,   542,
     225,   572,  4081,  4081,  4081,  4081,  1588,  1459,  1459,  1622,
     683,  1312,   671,  1312,  1312,   692,  1063,  1086,  1121,  1142,
     225,  4062,  4062,  1726,   694,  4942,  4950,  4958,  4966,   225,
    1119,  1119,   698,  4814,  4822,  4830,  4838,   225,  4043,  4043,
    1312,   703,  1312,  1312,   722,  4171,  4181,  4190,  4198,   225,
    4100,  4100,  4100,  4100,  1173,  1193,  4974,  4982,  4846,  4854,
      68,   572,   997,  2203,   760,  1312,    34,  1119,  1119,  2241,
    3799,  2279,  3837,    25,  3875,   745,   766,   771,   784,  4477,
     797,   798,  4492,  4507,  4522,  4537,  4575,   753,   783,   822,
     823,   572,   758,   778,  4565,  4585,  4595,  4605,  4615,   951,
    4625,  4635,   801,   927,  1037,  4645,   602,   646,  1163,   800,
     808,   825,   826,  1375,   834,  1445,  1664,   838,   839,   841,
     848,   394,   849,   851,   853,  4990,   854,  4998,  5006,  4862,
     867,  4870,  4878,   869,   879,   880,   885,  4208,   896,  4217,
    4225,  4235,  4244,  2317,    25,   897,   917,  2355,   902,   905,
     519,   532,  2393,   911,   724,   898,   979,  1009,  4552,  1312,
     811,  1312,  1312,   920,  4655,  4665,  4675,  4685,   225,  4119,
    4119,  4119,  4119,   913,   930,   931,   933,  1783,  1312,   916,
    1312,  1312,  5014,  4886,   366,   537,   551,   556,  4252,   947,
    1693,   997,  1693,   967,   971,   975,   952,   964,   965,   978,
     981,  4695,   982,  4705,  4715,  4725,  4735,   983,   984,   992,
     998,   974,  2431,  1014,  2469,  2507,  2545,  2583,  3913,  1175,
    1208,  1423,  1427,  4745,   999,  1000,  1003,  1008,  2621,  1693,
    2659,   572,  2697,  1015,  1693,  2735
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     1,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -358,  -358,  -358,  1039,     0,     1,  -357,  -358,  1025,   -15,
    -151,   -29,   -40,  -117,   -19,   884,   612,   -14,  1384,   970,
    1062,  1298,   323,  -285,  -358,   903,  -114,  -111,   558,   476,
     790,   -27,   526,   348,  -108,   697
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     4,    46,    47,    13,    14,    15,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,   120,   121,   122,    62,    63,   152,    64,
      65,    66,    67,    68,    69,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       5,     6,    20,     5,     6,   370,   443,    73,   278,   184,
      10,   -78,   -32,    88,   362,   271,     1,    82,   273,   -52,
      92,   274,   176,   -52,   275,   404,    11,     7,    12,    16,
     363,   103,    94,    95,   416,     8,   -78,   -78,    99,   -78,
     340,   341,   420,   184,   -52,   -52,   -10,   -52,   -32,    17,
     -79,   102,   188,   -80,   428,    19,   176,   297,   -79,   -79,
     203,   -79,   217,   217,   203,   -53,   203,   203,   108,   109,
     110,   123,   433,   130,   -41,   229,    12,   479,   -80,   -80,
      70,   -80,   126,   127,   246,   -71,   -41,    71,   434,    74,
      89,    75,   270,   145,    76,   -41,   -41,   -41,   -41,   -41,
     -41,    93,   -41,   144,   136,   146,    77,   -53,   252,   253,
     100,   -71,   -80,   272,   188,   360,    78,   269,    79,   -54,
     -80,   -80,   154,   -80,   -73,    -2,   184,   157,     1,   229,
      80,   -54,   267,   268,   155,    98,   -41,    -4,   184,   176,
      -4,   289,    81,   -58,   -54,   -54,   283,   -54,   -41,   -73,
     -73,   176,    89,    -6,   176,   -58,    -6,   -41,   -41,   -41,
     -41,   -41,   -41,    -5,   -41,    90,    -5,   184,   -58,   -58,
     -55,   -58,   104,   492,   -56,   305,   -75,    83,    84,   -57,
     176,   184,   -55,   115,   -75,   -75,   -56,   299,   118,   314,
     -74,   -57,   132,   184,   176,   -55,   -55,    72,   -55,   -56,
     -56,   322,   -56,    27,   -57,   -57,   176,   -57,    32,   184,
      33,    34,    35,    36,   133,   -74,   -74,   334,    38,    39,
      -3,   134,   176,    -3,    40,   -71,   -86,    41,    42,    43,
      44,    45,   -70,   298,   -71,   219,   203,   203,   217,   217,
     229,   229,   354,   -41,   -85,   220,   -61,   310,   -72,    92,
     221,   222,   -41,   -41,   -41,   -41,   -53,   100,   -70,   223,
     224,   225,   226,   227,   184,   203,   -79,   203,   203,   -84,
     184,   397,   371,   -72,   -72,   -75,   229,   176,   176,   176,
     374,   375,   391,   176,   176,   176,   135,   203,   138,   203,
     203,   -79,   -79,   139,   -79,   -77,   229,   405,   406,   217,
     -75,   -75,   140,   101,   137,   229,   417,   418,   252,   253,
     -51,   141,   436,   229,   421,   422,   203,   142,   203,   203,
     -77,   -77,   -76,   -77,   184,   229,   246,   246,   431,   432,
     -53,    92,   435,   188,   -31,   -51,   -51,   176,   -51,    -7,
     147,   203,    -7,   217,   217,   148,    -9,   -76,   -76,    18,
     -76,   -52,   156,   -54,   184,   -53,   -53,   149,   -53,   181,
     250,   251,   453,   271,   -40,   271,   273,   176,   273,   274,
     -58,   274,   275,   153,   275,   279,   -40,   -12,   -54,   -54,
     -12,   -54,    85,    86,   186,   -40,   -40,   -40,   -40,   -40,
     -40,   -13,   -40,   181,   -13,   -58,   -58,   206,   -58,   218,
     218,   206,   271,   206,   206,   273,   -41,   271,   274,   276,
     273,   275,   230,   274,   -40,   -52,   275,   280,   186,   252,
     253,   249,   339,   -40,   -40,   -40,   -40,   -41,   -41,   -41,
     -41,   -41,   -41,    -8,   -41,   203,    -8,   203,   203,   281,
     270,   503,   270,   282,   229,   391,   391,   495,   496,   131,
     296,   502,   -11,   504,   203,   -11,   203,   203,   -28,   -52,
     300,   272,   188,   272,   -78,   269,   230,   269,   292,   293,
     301,   508,   -78,   -78,   -15,   -78,   181,   -15,   302,   270,
     267,   268,   267,   268,   270,   303,   518,   -44,   181,   -14,
     522,   181,   -14,   304,   184,   525,   -44,   -44,   -44,   -44,
     272,   186,   523,   313,   269,   272,   -73,   176,   -54,   269,
     330,   -44,   182,   186,   -73,   -73,   186,   181,   -45,   267,
     268,   284,   285,   -44,   267,   268,   -45,   -45,   -45,   -45,
     -45,   181,   -44,   -44,   -44,   -44,   -44,   -44,   -45,   -44,
     484,   -55,   186,   181,   252,   253,   182,   -45,   -45,   -45,
     -45,   -45,   -45,   485,   -45,   -56,   186,   252,   253,   181,
     -57,   -60,   185,   -74,   143,   331,   -55,   -55,   186,   -55,
     332,   -74,   -74,   206,   206,   218,   218,   230,   230,   333,
     -56,   -56,   160,   -56,   186,   -57,   -57,   161,   -57,   162,
     163,   164,   165,   351,   286,   287,   185,   166,   167,   306,
     307,   350,   206,   168,   206,   206,   169,   170,   171,   172,
     173,   308,   309,   230,   181,   181,   181,   181,   181,   395,
     181,   181,   181,   -70,   206,   -63,   206,   206,   -63,   182,
     352,   298,   -70,   230,   206,   206,   218,   -62,   355,   186,
     -62,   182,   230,   218,   218,   186,   186,   398,   175,   -42,
     230,   230,   230,   206,   356,   206,   206,   357,   -42,   -42,
     -42,   -42,   230,   249,   249,   249,   249,   -72,   -64,   358,
     182,   -64,   254,   255,   181,   -72,   -72,   361,   206,   185,
     218,   218,   175,   369,   182,   366,   202,   -27,   216,   216,
     202,   185,   202,   202,   185,   -54,   182,   315,   316,   186,
     -54,   228,   317,   318,   181,   400,   124,   125,   -54,   -54,
     245,   -54,   182,   403,    22,   415,   158,    23,    24,   419,
     185,    25,    26,    27,    28,    29,    30,    31,    32,   186,
      33,    34,    35,    36,   185,   159,    37,   424,    38,    39,
     -58,   323,   324,   427,    40,   -58,   185,    41,    42,    43,
      44,    45,   -77,   -58,   -58,   228,   -58,   325,   326,   -43,
     -77,   -77,   185,   -77,   437,   175,   444,   182,   -43,   -43,
     -43,   -43,   206,   449,   206,   206,   -42,   175,   335,   336,
     175,   230,   395,   395,   395,   395,   -40,   445,   -42,   337,
     338,   206,   446,   206,   206,   454,   455,   -42,   -42,   -42,
     -42,   -42,   -42,   450,   -42,   447,   175,   -40,   -40,   -40,
     -40,   -40,   -40,   -43,   -40,   456,   457,   185,   448,   -31,
     175,   463,   -51,   185,   185,   -43,   183,   182,   -35,   464,
     -51,   -51,   175,   -51,   -43,   -43,   -43,   -43,   -43,   -43,
     -35,   -43,   451,   452,   181,   488,   465,   466,   175,   -35,
     -35,    96,    97,   -35,   -35,   467,   -35,   182,   468,   469,
     183,   470,   344,   345,   346,   347,   348,   349,   471,   186,
     -51,    27,   -53,   -35,   -54,   472,    32,   185,    33,    34,
      35,    36,   -35,   -35,   311,   312,    38,    39,   473,   129,
     474,   202,    40,   202,   202,    87,    42,    43,    44,    45,
     475,   476,   228,   175,   372,   373,   477,   185,   390,   175,
     175,   175,   -38,   202,   -55,   202,   202,   478,   480,   -55,
     174,   481,   228,   482,   -38,   216,   483,   -55,   -55,   -58,
     -55,   228,   486,   -38,   -38,   -38,   -38,   -38,   -38,   228,
     -38,   491,   202,   183,   202,   202,   -55,   -56,   -53,   -57,
     498,   228,   429,   430,   174,   183,   -53,   -53,   105,   -53,
     112,   113,   105,   175,   105,   105,   -46,   202,   501,   216,
     216,   505,   -52,   119,   159,   506,   459,   460,   -46,   507,
     -52,   -52,   244,   -52,   183,   509,   510,   -46,   -46,   -46,
     -46,   -46,   -46,   175,   -46,   -56,   266,   182,   183,   511,
     -56,   187,   512,   513,   514,   515,   178,    27,   -56,   -56,
     183,   -56,    32,   516,    33,    34,    35,    36,   521,   517,
     -58,   -55,    38,    39,   -56,   -57,   183,   119,    40,   -57,
     -57,    41,    42,    43,    44,    45,   524,   174,   -57,   -57,
     178,   -57,     9,    21,   204,   -38,   150,   185,   204,   174,
     204,   204,   174,   439,   -38,   -38,   -38,   -38,   -54,     0,
     520,   202,     0,   202,   202,   -46,   -54,   -54,   128,   -54,
     228,   493,   494,     0,   -46,   -46,   -46,   -46,   174,   -47,
     202,   183,   202,   202,     0,     0,     0,   396,   -47,   -47,
     -47,   -47,   174,     0,   353,     0,     0,     0,   179,     0,
      27,     0,   -49,     0,   174,    32,     0,    33,    34,    35,
      36,   -49,   -49,   -49,   -49,    38,    39,     0,     0,     0,
     174,    40,     0,   178,    41,    42,    43,    44,    45,   207,
       0,     0,   179,   175,     0,   178,   107,   -48,   178,   208,
     107,   183,   107,   107,   209,   210,   -48,   -48,   -48,   -48,
       0,     0,     0,   211,   212,   213,   214,   215,   -50,     0,
     247,     0,     0,   105,   178,   105,   105,   -50,   -50,   -50,
     -50,   183,     0,     0,   119,   174,     0,     0,   178,     0,
     389,   174,   174,   174,   -76,   105,     0,   105,   105,   -33,
     178,     0,   -76,   -76,   119,   -76,   -58,   411,   -33,   -33,
     311,   312,     0,   119,   -58,   -58,   178,   -58,     0,   -34,
       0,   119,     0,     0,   105,   179,   105,   105,   -34,   -34,
     311,   312,   -47,   119,     0,     0,     0,   179,     0,   -55,
     179,     0,     0,     0,   -47,   174,     0,   -55,   -55,   105,
     -55,   440,   441,   -47,   -47,   -47,   -47,   -47,   -47,   204,
     -47,   204,   204,   -40,     0,     0,   179,   -40,   -40,   -40,
     -40,   178,     0,     0,     0,   174,   392,   178,   178,   178,
     179,   204,   -40,   204,   204,   -40,   -40,   -40,   -40,   -40,
      27,     0,   179,   412,     0,    32,     0,    33,    34,    35,
      36,   -44,     0,     0,     0,    38,    39,     0,   179,     0,
     204,    40,   204,   204,    41,    42,    43,    44,    45,     0,
       0,   183,   -44,   -44,   -44,   -44,   -44,   -44,     0,   -44,
       0,   178,   189,     0,     0,   204,     0,   190,     0,   191,
     192,   193,   194,   105,   180,   105,   105,   195,   196,     0,
       0,   107,   119,   107,   107,     0,   197,   198,   199,   200,
     201,   178,   105,   179,   105,   105,     0,     0,   393,   179,
     179,   179,   -49,   107,     0,   107,   107,     0,   180,     0,
       0,     0,   205,     0,   -49,   413,   205,     0,   205,   205,
       0,     0,     0,   -49,   -49,   -49,   -49,   -49,   -49,     0,
     -49,   -39,   107,     0,   107,   107,   248,     0,     0,   231,
     -39,   -39,   -39,   -39,   232,   174,   233,   234,   235,   236,
       0,   -45,     0,   179,   237,   238,     0,   107,     0,   204,
     177,   204,   204,   239,   240,   241,   242,   243,     0,     0,
       0,     0,   -45,   -45,   -45,   -45,   -45,   -45,   204,   -45,
     204,   204,     0,   179,   -56,     0,     0,     0,   -57,     0,
       0,   180,   -56,   -56,   177,   -56,   -57,   -57,   106,   -57,
       0,   -36,   114,   180,   116,   117,   180,     0,     0,   160,
     -36,   -36,   -36,   -36,   161,     0,   162,   163,   164,   165,
       0,   319,   -41,     0,   166,   167,   -41,   -41,   -41,   -41,
     168,   178,   180,   288,   170,   171,   172,   173,     0,     0,
      27,     0,     0,     0,     0,    32,   180,    33,    34,    35,
      36,   107,     0,   107,   107,    38,    39,   -48,   180,     0,
       0,     0,     0,     0,    87,    42,    43,    44,    45,   -48,
     107,     0,   107,   107,   180,     0,     0,   177,   -48,   -48,
     -48,   -48,   -48,   -48,     0,   -48,     0,     0,     0,   177,
       0,   -67,   177,   -67,   -67,   -67,     0,   151,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,     0,   -67,   -67,   -67,
     -67,     0,   -67,   -67,     0,   -67,   -67,   205,   177,   205,
     205,   -67,     0,   179,   -67,   -67,   -67,   -67,   -67,   180,
       0,     0,   177,     0,   394,   180,   180,   180,   376,   205,
       0,   205,   205,   377,   177,   378,   379,   380,   381,     0,
       0,   414,   -44,   382,   383,   -44,   -44,   -44,   -44,   -44,
     177,     0,   384,   385,   386,   387,   388,     0,   205,   -44,
     205,   205,   160,   -44,   -44,   -44,   -44,   161,     0,   162,
     163,   164,   165,     0,     0,     0,   -42,   166,   167,   180,
       0,     0,     0,   205,     0,     0,   288,   170,   171,   172,
     173,     0,     0,   365,     0,   367,   368,   -42,   -42,   -42,
     -42,   -42,   -42,     0,   -42,   177,     0,     0,     0,   180,
     -37,   177,   177,   177,     0,   399,     0,   401,   402,   -37,
     -37,   -37,   -37,     0,   256,     0,   257,   258,   259,     0,
       0,   260,   261,    27,   262,   263,   264,   265,    32,     0,
      33,    34,    35,    36,   423,   266,   425,   426,    38,    39,
       0,     0,     0,     0,    40,     0,     0,    41,    42,    43,
      44,    45,     0,     0,     0,   177,   207,     0,     0,   438,
       0,   407,     0,   408,   409,   410,   208,   205,     0,   205,
     205,   209,   210,     0,     0,     0,     0,     0,     0,     0,
     211,   212,   213,   214,   215,   177,   205,     0,   205,   205,
     -26,     0,   -26,   -26,   -26,     0,   -26,   -26,   -26,   -26,
     -26,   -26,   -26,   -26,   -26,     0,   -26,   -26,   -26,   -26,
       0,   -26,   -26,     0,   -26,   -26,     0,     0,     0,   -59,
     -26,     0,     0,   -26,   -26,   -26,   -26,   -26,   -59,   -59,
     -59,   -59,     0,    22,     0,   158,    23,    24,     0,   180,
      25,    26,    27,    28,    29,    30,    31,    32,     0,    33,
      34,    35,    36,   487,   159,   489,   490,    38,    39,     0,
       0,     0,     0,    40,     0,     0,    41,    42,    43,    44,
      45,     0,   497,     0,   499,   500,   -28,     0,   -28,   -28,
     -28,     0,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,     0,   -28,   -28,   -28,   -28,     0,   -28,   -28,     0,
     -28,   -28,     0,     0,     0,     0,   -28,     0,     0,   -28,
     -28,   -28,   -28,   -28,     0,     0,     0,     0,     0,     0,
     -18,     0,   -18,   -18,   -18,   177,   -18,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,   -18,
       0,   -18,   -18,     0,   -18,   -18,     0,     0,     0,     0,
     -18,     0,     0,   -18,   -18,   -18,   -18,   -18,   -25,     0,
     -25,   -25,   -25,     0,   -25,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,     0,   -25,   -25,   -25,   -25,     0,   -25,
     -25,     0,   -25,   -25,     0,     0,     0,     0,   -25,     0,
       0,   -25,   -25,   -25,   -25,   -25,   -24,     0,   -24,   -24,
     -24,     0,   -24,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,     0,   -24,   -24,   -24,   -24,     0,   -24,   -24,     0,
     -24,   -24,     0,     0,     0,     0,   -24,     0,     0,   -24,
     -24,   -24,   -24,   -24,   -19,     0,   -19,   -19,   -19,     0,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,     0,
     -19,   -19,   -19,   -19,     0,   -19,   -19,     0,   -19,   -19,
       0,     0,     0,     0,   -19,     0,     0,   -19,   -19,   -19,
     -19,   -19,   -20,     0,   -20,   -20,   -20,     0,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,     0,   -20,   -20,
     -20,   -20,     0,   -20,   -20,     0,   -20,   -20,     0,     0,
       0,     0,   -20,     0,     0,   -20,   -20,   -20,   -20,   -20,
     -22,     0,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,
     -22,   -22,   -22,   -22,   -22,     0,   -22,   -22,   -22,   -22,
       0,   -22,   -22,     0,   -22,   -22,     0,     0,     0,     0,
     -22,     0,     0,   -22,   -22,   -22,   -22,   -22,   -23,     0,
     -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,   -23,   -23,
     -23,   -23,   -23,     0,   -23,   -23,   -23,   -23,     0,   -23,
     -23,     0,   -23,   -23,     0,     0,     0,     0,   -23,     0,
       0,   -23,   -23,   -23,   -23,   -23,   -21,     0,   -21,   -21,
     -21,     0,   -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21,     0,   -21,   -21,   -21,   -21,     0,   -21,   -21,     0,
     -21,   -21,     0,     0,     0,     0,   -21,     0,     0,   -21,
     -21,   -21,   -21,   -21,   -30,     0,   -30,   -30,   -30,     0,
     -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,   -30,     0,
     -30,   -30,   -30,   -30,     0,   -30,   -30,     0,   -30,   -30,
       0,     0,     0,     0,   -30,     0,     0,   -30,   -30,   -30,
     -30,   -30,   -15,     0,   -15,   -15,   -15,     0,   -15,   -15,
     -15,   -15,   -15,   -15,   -15,   -15,   -15,     0,   -15,   -15,
     -15,   -15,     0,   -15,   -15,     0,   -15,   -15,     0,     0,
       0,     0,   -15,     0,     0,   -15,   -15,   -15,   -15,   -15,
     -27,     0,   -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,
     -27,   -27,   -27,   -27,   -27,     0,   -27,   -27,   -27,   -27,
       0,   -27,   -27,     0,   -27,   -27,     0,     0,     0,     0,
     -27,     0,     0,   -27,   -27,   -27,   -27,   -27,    -7,     0,
      -7,    -7,    -7,     0,    -7,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,     0,    -7,    -7,    -7,    -7,     0,    -7,
      -7,     0,    -7,    -7,     0,     0,     0,     0,    -7,     0,
       0,    -7,    -7,    -7,    -7,    -7,   -29,     0,   -29,   -29,
     -29,     0,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,
     -29,     0,   -29,   -29,   -29,   -29,     0,   -29,   -29,     0,
     -29,   -29,     0,     0,     0,     0,   -29,     0,     0,   -29,
     -29,   -29,   -29,   -29,   -14,     0,   -14,   -14,   -14,     0,
     -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,   -14,     0,
     -14,   -14,   -14,   -14,     0,   -14,   -14,     0,   -14,   -14,
       0,     0,     0,     0,   -14,     0,     0,   -14,   -14,   -14,
     -14,   -14,   -67,     0,   -67,   -67,   -67,     0,   519,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,     0,   -67,   -67,
     -67,   -67,     0,   -67,   -67,     0,   -67,   -67,     0,     0,
       0,     0,   -67,     0,     0,   -67,   -67,   -67,   -67,   -67,
     -65,     0,   -65,   -65,   -65,     0,   -65,   -65,   -65,   -65,
     -65,   -65,   -65,   -65,   -65,     0,   -65,   -65,   -65,   -65,
       0,   -65,   -65,     0,   -65,   -65,     0,     0,     0,     0,
     -65,     0,     0,   -65,   -65,   -65,   -65,   -65,   -83,     0,
     -83,   -83,   -83,     0,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,     0,   -83,   -83,   -83,   -83,     0,   -83,
     -83,     0,   -83,   -83,     0,     0,     0,     0,   -83,     0,
       0,   -83,   -83,   -83,   -83,   -83,   -81,     0,   -81,   -81,
     -81,     0,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,     0,   -81,   -81,   -81,   -81,     0,   -81,   -81,     0,
     -81,   -81,     0,     0,     0,     0,   -81,     0,     0,   -81,
     -81,   -81,   -81,   -81,   -82,     0,   -82,   -82,   -82,     0,
     -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,   -82,     0,
     -82,   -82,   -82,   -82,     0,   -82,   -82,     0,   -82,   -82,
       0,     0,     0,     0,   -82,     0,     0,   -82,   -82,   -82,
     -82,   -82,    -8,     0,    -8,    -8,    -8,     0,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,     0,    -8,    -8,
      -8,    -8,     0,    -8,    -8,     0,    -8,    -8,     0,     0,
       0,     0,    -8,     0,     0,    -8,    -8,    -8,    -8,    -8,
     -68,     0,   -68,   -68,   -68,     0,   -68,   -68,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,     0,   -68,   -68,   -68,   -68,
       0,   -68,   -68,     0,   -68,   -68,     0,     0,     0,     0,
     -68,     0,     0,   -68,   -68,   -68,   -68,   -68,   -69,     0,
     -69,   -69,   -69,     0,   -69,   -69,   -69,   -69,   -69,   -69,
     -69,   -69,   -69,     0,   -69,   -69,   -69,   -69,     0,   -69,
     -69,     0,   -69,   -69,     0,     0,     0,     0,   -69,     0,
       0,   -69,   -69,   -69,   -69,   -69,   -66,     0,   -66,   -66,
     -66,     0,   -66,   -66,   -66,   -66,   -66,   -66,   -66,   -66,
     -66,     0,   -66,   -66,   -66,   -66,     0,   -66,   -66,     0,
     -66,   -66,     0,     0,     0,     0,   -66,     0,     0,   -66,
     -66,   -66,   -66,   -66,   -26,     0,   -26,   -26,   -26,     0,
       0,   -26,   -26,   -26,   -26,   -26,   -26,   -26,   -26,     0,
     -26,   -26,   -26,   -26,     0,   -26,   -26,     0,   -26,   -26,
       0,     0,     0,     0,   -26,     0,     0,   -26,   -26,   -26,
     -26,   -26,   -28,     0,   -28,   -28,   -28,     0,     0,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,   -28,     0,   -28,   -28,
     -28,   -28,     0,   -28,   -28,     0,   -28,   -28,     0,     0,
       0,     0,   -28,     0,     0,   -28,   -28,   -28,   -28,   -28,
     -18,     0,   -18,   -18,   -18,     0,     0,   -18,   -18,   -18,
     -18,   -18,   -18,   -18,   -18,     0,   -18,   -18,   -18,   -18,
       0,   -18,   -18,     0,   -18,   -18,     0,     0,     0,     0,
     -18,     0,     0,   -18,   -18,   -18,   -18,   -18,   -25,     0,
     -25,   -25,   -25,     0,     0,   -25,   -25,   -25,   -25,   -25,
     -25,   -25,   -25,     0,   -25,   -25,   -25,   -25,     0,   -25,
     -25,     0,   -25,   -25,     0,     0,     0,     0,   -25,     0,
       0,   -25,   -25,   -25,   -25,   -25,   -24,     0,   -24,   -24,
     -24,     0,     0,   -24,   -24,   -24,   -24,   -24,   -24,   -24,
     -24,     0,   -24,   -24,   -24,   -24,     0,   -24,   -24,     0,
     -24,   -24,     0,     0,     0,     0,   -24,     0,     0,   -24,
     -24,   -24,   -24,   -24,    22,     0,   158,    23,    24,     0,
       0,    25,    26,    27,    28,    29,    30,    31,    32,     0,
      33,    34,    35,    36,     0,   159,    91,     0,    38,    39,
       0,     0,     0,     0,    40,     0,     0,    41,    42,    43,
      44,    45,   -17,     0,   -17,   -17,   -17,     0,     0,   -17,
     -17,   -17,   -17,   -17,   -17,   -17,   -17,     0,   -17,   -17,
     -17,   -17,     0,   -17,   -17,     0,   -17,   -17,     0,     0,
       0,     0,   -17,     0,     0,   -17,   -17,   -17,   -17,   -17,
     -19,     0,   -19,   -19,   -19,     0,     0,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,     0,   -19,   -19,   -19,   -19,
       0,   -19,   -19,     0,   -19,   -19,     0,     0,     0,     0,
     -19,     0,     0,   -19,   -19,   -19,   -19,   -19,   -20,     0,
     -20,   -20,   -20,     0,     0,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,     0,   -20,   -20,   -20,   -20,     0,   -20,
     -20,     0,   -20,   -20,     0,     0,     0,     0,   -20,     0,
       0,   -20,   -20,   -20,   -20,   -20,   -22,     0,   -22,   -22,
     -22,     0,     0,   -22,   -22,   -22,   -22,   -22,   -22,   -22,
     -22,     0,   -22,   -22,   -22,   -22,     0,   -22,   -22,     0,
     -22,   -22,     0,     0,     0,     0,   -22,     0,     0,   -22,
     -22,   -22,   -22,   -22,   -23,     0,   -23,   -23,   -23,     0,
       0,   -23,   -23,   -23,   -23,   -23,   -23,   -23,   -23,     0,
     -23,   -23,   -23,   -23,     0,   -23,   -23,     0,   -23,   -23,
       0,     0,     0,     0,   -23,     0,     0,   -23,   -23,   -23,
     -23,   -23,   -21,     0,   -21,   -21,   -21,     0,     0,   -21,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,   -21,   -21,
     -21,   -21,     0,   -21,   -21,     0,   -21,   -21,     0,     0,
       0,     0,   -21,     0,     0,   -21,   -21,   -21,   -21,   -21,
     -30,     0,   -30,   -30,   -30,     0,     0,   -30,   -30,   -30,
     -30,   -30,   -30,   -30,   -30,     0,   -30,   -30,   -30,   -30,
       0,   -30,   -30,     0,   -30,   -30,     0,     0,     0,     0,
     -30,     0,     0,   -30,   -30,   -30,   -30,   -30,   -16,     0,
     -16,   -16,   -16,     0,     0,   -16,   -16,   -16,   -16,   -16,
     -16,   -16,   -16,     0,   -16,   -16,   -16,   -16,     0,   -16,
     -16,     0,   -16,   -16,     0,     0,     0,     0,   -16,     0,
       0,   -16,   -16,   -16,   -16,   -16,   -27,     0,   -27,   -27,
     -27,     0,     0,   -27,   -27,   -27,   -27,   -27,   -27,   -27,
     -27,     0,   -27,   -27,   -27,   -27,     0,   -27,   -27,     0,
     -27,   -27,     0,     0,     0,     0,   -27,     0,     0,   -27,
     -27,   -27,   -27,   -27,   -29,     0,   -29,   -29,   -29,     0,
       0,   -29,   -29,   -29,   -29,   -29,   -29,   -29,   -29,     0,
     -29,   -29,   -29,   -29,     0,   -29,   -29,     0,   -29,   -29,
       0,     0,     0,     0,   -29,     0,     0,   -29,   -29,   -29,
     -29,   -29,   -65,     0,   -65,   -65,   -65,     0,     0,   -65,
     -65,   -65,   -65,   -65,   -65,   -65,   -65,     0,   -65,   -65,
     -65,   -65,     0,   -65,   -65,     0,   -65,   -65,     0,     0,
       0,     0,   -65,     0,     0,   -65,   -65,   -65,   -65,   -65,
     -83,     0,   -83,   -83,   -83,     0,     0,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,     0,   -83,   -83,   -83,   -83,
       0,   -83,   -83,     0,   -83,   -83,     0,     0,     0,     0,
     -83,     0,     0,   -83,   -83,   -83,   -83,   -83,   -81,     0,
     -81,   -81,   -81,     0,     0,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,     0,   -81,   -81,   -81,   -81,     0,   -81,
     -81,     0,   -81,   -81,     0,     0,     0,     0,   -81,     0,
       0,   -81,   -81,   -81,   -81,   -81,   -82,     0,   -82,   -82,
     -82,     0,     0,   -82,   -82,   -82,   -82,   -82,   -82,   -82,
     -82,     0,   -82,   -82,   -82,   -82,     0,   -82,   -82,     0,
     -82,   -82,     0,     0,     0,     0,   -82,     0,     0,   -82,
     -82,   -82,   -82,   -82,   -68,     0,   -68,   -68,   -68,     0,
       0,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,     0,
     -68,   -68,   -68,   -68,     0,   -68,   -68,     0,   -68,   -68,
       0,     0,     0,     0,   -68,     0,     0,   -68,   -68,   -68,
     -68,   -68,   -69,     0,   -69,   -69,   -69,     0,     0,   -69,
     -69,   -69,   -69,   -69,   -69,   -69,   -69,     0,   -69,   -69,
     -69,   -69,     0,   -69,   -69,     0,   -69,   -69,     0,     0,
       0,     0,   -69,     0,     0,   -69,   -69,   -69,   -69,   -69,
     -66,     0,   -66,   -66,   -66,     0,     0,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,   -66,     0,   -66,   -66,   -66,   -66,
       0,   -66,   -66,     0,   -66,   -66,     0,     0,     0,     0,
     -66,     0,     0,   -66,   -66,   -66,   -66,   -66,    22,     0,
     158,    23,    24,     0,     0,    25,    26,    27,    28,    29,
      30,    31,    32,     0,    33,    34,    35,    36,     0,   159,
     277,     0,    38,    39,     0,     0,     0,     0,    40,     0,
       0,    41,    42,    43,    44,    45,    22,     0,   158,    23,
      24,     0,     0,    25,    26,    27,    28,    29,    30,    31,
      32,     0,    33,    34,    35,    36,     0,   159,   359,     0,
      38,    39,     0,     0,     0,     0,    40,     0,     0,    41,
      42,    43,    44,    45,   -15,     0,   -15,   -15,   -15,     0,
       0,   -15,   -15,   -15,   -15,   -15,   -15,   -15,   -15,     0,
     -15,   -15,   -15,   -15,     0,   -15,   -15,     0,   -15,   -15,
       0,     0,     0,     0,   -15,     0,     0,   -15,   -15,   -15,
     -15,   -15,    22,     0,   158,    23,    24,     0,     0,    25,
      26,    27,    28,    29,    30,    31,    32,     0,    33,    34,
      35,    36,     0,   159,   364,     0,    38,    39,     0,     0,
       0,     0,    40,     0,     0,    41,    42,    43,    44,    45,
      22,     0,   158,    23,    24,     0,     0,    25,    26,    27,
      28,    29,    30,    31,    32,     0,    33,    34,    35,    36,
       0,   159,   442,     0,    38,    39,     0,     0,     0,     0,
      40,     0,     0,    41,    42,    43,    44,    45,    -7,     0,
      -7,    -7,    -7,     0,     0,    -7,    -7,    -7,    -7,    -7,
      -7,    -7,    -7,     0,    -7,    -7,    -7,    -7,     0,    -7,
      -7,     0,    -7,    -7,     0,     0,     0,     0,    -7,     0,
       0,    -7,    -7,    -7,    -7,    -7,   -14,     0,   -14,   -14,
     -14,     0,     0,   -14,   -14,   -14,   -14,   -14,   -14,   -14,
     -14,     0,   -14,   -14,   -14,   -14,     0,   -14,   -14,     0,
     -14,   -14,     0,     0,     0,     0,   -14,     0,     0,   -14,
     -14,   -14,   -14,   -14,    -8,     0,    -8,    -8,    -8,     0,
       0,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,     0,
      -8,    -8,    -8,    -8,   -50,    -8,    -8,     0,    -8,    -8,
       0,     0,     0,     0,    -8,     0,   -50,    -8,    -8,    -8,
      -8,    -8,     0,    27,     0,   -50,   -50,   -50,   -50,   -50,
     -50,   -39,   -50,    36,     0,     0,     0,     0,    38,    39,
       0,     0,     0,   -39,     0,     0,   -33,    87,    42,    43,
      44,    45,   -39,   -39,   -39,   -39,   -39,   -39,   -33,   -39,
       0,   -34,     0,     0,     0,     0,     0,   -33,   -33,    96,
      97,   -33,   -33,   -34,   -33,     0,   -36,     0,     0,     0,
       0,     0,   -34,   -34,    96,    97,   -34,   -34,   -36,   -34,
       0,   -37,     0,     0,     0,     0,     0,   -36,   -36,   -36,
     -36,   -36,   -36,   -37,   -36,     0,   -59,     0,     0,     0,
       0,     0,   -37,   -37,   -37,   -37,   -37,   -37,   -59,   -37,
       0,     0,     0,   219,     0,     0,     0,   -59,   -59,   -59,
     -59,   -59,   -59,   220,   -59,     0,     0,     0,   221,   222,
       0,     0,   189,     0,     0,     0,     0,   223,   224,   225,
     226,   227,   194,     0,     0,     0,     0,   195,   196,     0,
       0,   160,     0,     0,     0,     0,   197,   198,   199,   200,
     201,   165,     0,     0,     0,     0,   166,   167,     0,     0,
     231,     0,     0,     0,     0,   288,   170,   171,   172,   173,
     236,     0,     0,     0,     0,   237,   238,     0,     0,   376,
       0,     0,     0,     0,   239,   240,   241,   242,   243,   381,
     -43,     0,     0,     0,   382,   383,     0,     0,   -35,     0,
       0,     0,     0,   384,   385,   386,   387,   388,   -38,     0,
       0,   -43,   -43,   -43,   -43,   -43,   -43,   -46,   -43,   -35,
     -35,   342,   343,   -35,   -35,   -47,   -35,     0,     0,   -38,
     -38,   -38,   -38,   -38,   -38,   -49,   -38,     0,   -46,   -46,
     -46,   -46,   -46,   -46,   -48,   -46,   -47,   -47,   -47,   -47,
     -47,   -47,   -50,   -47,     0,     0,   -49,   -49,   -49,   -49,
     -49,   -49,   -39,   -49,     0,   -48,   -48,   -48,   -48,   -48,
     -48,   -33,   -48,   -50,   -50,   -50,   -50,   -50,   -50,   -34,
     -50,     0,     0,   -39,   -39,   -39,   -39,   -39,   -39,   -36,
     -39,     0,   -33,   -33,   342,   343,   -33,   -33,   -37,   -33,
     -34,   -34,   342,   343,   -34,   -34,   -59,   -34,     0,     0,
     -36,   -36,   -36,   -36,   -36,   -36,     0,   -36,     0,   -37,
     -37,   -37,   -37,   -37,   -37,     0,   -37,   -59,   -59,   -59,
     -59,   -59,   -59,   -41,   -59,     0,     0,   290,   -41,     0,
       0,     0,   -41,   -41,   -41,   -41,   -41,   -41,   -41,   -41,
     291,     0,   290,   -41,     0,     0,     0,   -41,   -41,   -41,
     -41,   -41,   -41,   -40,   -41,     0,     0,     0,   -40,     0,
       0,     0,   -40,   -40,   -40,   -40,   -40,   -40,   -44,   -40,
       0,     0,     0,   -44,     0,     0,     0,   -44,   -44,   -44,
     -44,   -44,   -44,   -45,   -44,     0,     0,     0,   -45,     0,
       0,     0,   -45,   -45,   -45,   -45,   -45,   -45,   -42,   -45,
       0,     0,     0,   -42,     0,     0,     0,   -42,   -42,   -42,
     -42,   -42,   -42,   -43,   -42,     0,     0,     0,   -43,     0,
       0,     0,   -43,   -43,   -43,   -43,   -43,   -43,   -35,   -43,
       0,     0,     0,   -35,     0,     0,     0,   -35,   -35,   294,
     295,   -35,   -35,   -38,   -35,     0,     0,     0,   -38,     0,
       0,     0,   -38,   -38,   -38,   -38,   -38,   -38,   -46,   -38,
       0,     0,     0,   -46,     0,     0,     0,   -46,   -46,   -46,
     -46,   -46,   -46,   -47,   -46,     0,     0,     0,   -47,     0,
       0,     0,   -47,   -47,   -47,   -47,   -47,   -47,   -49,   -47,
       0,     0,     0,   -49,     0,     0,     0,   -49,   -49,   -49,
     -49,   -49,   -49,   -48,   -49,     0,     0,     0,   -48,     0,
       0,     0,   -48,   -48,   -48,   -48,   -48,   -48,   -50,   -48,
       0,     0,     0,   -50,     0,     0,     0,   -50,   -50,   -50,
     -50,   -50,   -50,   -39,   -50,     0,     0,     0,   -39,     0,
       0,     0,   -39,   -39,   -39,   -39,   -39,   -39,   -33,   -39,
       0,     0,     0,   -33,     0,     0,     0,   -33,   -33,   294,
     295,   -33,   -33,   -34,   -33,     0,     0,     0,   -34,     0,
       0,     0,   -34,   -34,   294,   295,   -34,   -34,   -36,   -34,
       0,     0,     0,   -36,     0,     0,     0,   -36,   -36,   -36,
     -36,   -36,   -36,   -37,   -36,     0,     0,     0,   -37,     0,
       0,     0,   -37,   -37,   -37,   -37,   -37,   -37,   -59,   -37,
       0,     0,     0,   -59,     0,     0,     0,   -59,   -59,   -59,
     -59,   -59,   -59,     0,   -59,   458,   -41,     0,     0,     0,
     -41,   -41,   -41,   -41,   -41,   -41,   -40,   -41,     0,     0,
     -40,   -40,   -40,   -40,   -40,   -40,   -44,   -40,     0,     0,
     -44,   -44,   -44,   -44,   -44,   -44,   -45,   -44,     0,     0,
     -45,   -45,   -45,   -45,   -45,   -45,   -42,   -45,     0,     0,
     -42,   -42,   -42,   -42,   -42,   -42,   -43,   -42,     0,     0,
     -43,   -43,   -43,   -43,   -43,   -43,   -35,   -43,     0,     0,
     -35,   -35,   461,   462,   -35,   -35,   -38,   -35,     0,     0,
     -38,   -38,   -38,   -38,   -38,   -38,   -46,   -38,     0,     0,
     -46,   -46,   -46,   -46,   -46,   -46,   -47,   -46,     0,     0,
     -47,   -47,   -47,   -47,   -47,   -47,   -49,   -47,     0,     0,
     -49,   -49,   -49,   -49,   -49,   -49,   -48,   -49,     0,     0,
     -48,   -48,   -48,   -48,   -48,   -48,   -50,   -48,     0,     0,
     -50,   -50,   -50,   -50,   -50,   -50,   -39,   -50,     0,     0,
     -39,   -39,   -39,   -39,   -39,   -39,   -33,   -39,     0,     0,
     -33,   -33,   461,   462,   -33,   -33,   -34,   -33,     0,     0,
     -34,   -34,   461,   462,   -34,   -34,   -36,   -34,     0,     0,
     -36,   -36,   -36,   -36,   -36,   -36,   -37,   -36,     0,     0,
     -37,   -37,   -37,   -37,   -37,   -37,   -59,   -37,     0,     0,
     -59,   -59,   -59,   -59,   -59,   -59,     0,   -59,   327,   -41,
       0,     0,   -41,   -41,   -41,   -41,   -41,   -45,     0,     0,
     -45,   -45,   -45,   -45,   -45,   -42,     0,     0,   -42,   -42,
     -42,   -42,   -42,   -43,     0,     0,   -43,   -43,   -43,   -43,
     -43,   -35,     0,     0,   -35,   -35,   -35,   328,   329,   -38,
       0,     0,   -38,   -38,   -38,   -38,   -38,   -46,     0,     0,
     -46,   -46,   -46,   -46,   -46,   -47,     0,     0,   -47,   -47,
     -47,   -47,   -47,   -49,     0,     0,   -49,   -49,   -49,   -49,
     -49,   -48,     0,     0,   -48,   -48,   -48,   -48,   -48,   -50,
       0,     0,   -50,   -50,   -50,   -50,   -50,   -33,     0,     0,
     -33,   -33,   -33,   328,   329,   -34,     0,     0,   -34,   -34,
     -34,   328,   329,   -39,     0,     0,   -39,   -39,   -39,   -39,
     -39,   -36,     0,     0,   -36,   -36,   -36,   -36,   -36,   -37,
       0,     0,   -37,   -37,   -37,   -37,   -37,   -59,     0,     0,
     -59,   -59,   -59,   -59,   -59,   -45,     0,     0,     0,   -45,
     -45,   -45,   -45,   -42,     0,     0,     0,   -42,   -42,   -42,
     -42,   -43,     0,     0,     0,   -43,   -43,   -43,   -43,   -35,
       0,     0,     0,   -35,   -35,   320,   321,   -38,     0,     0,
       0,   -38,   -38,   -38,   -38,   -46,     0,     0,     0,   -46,
     -46,   -46,   -46,   -47,     0,     0,     0,   -47,   -47,   -47,
     -47,   -49,     0,     0,     0,   -49,   -49,   -49,   -49,   -48,
       0,     0,     0,   -48,   -48,   -48,   -48,   -50,     0,     0,
       0,   -50,   -50,   -50,   -50,   -33,     0,     0,     0,   -33,
     -33,   320,   321,   -34,     0,     0,     0,   -34,   -34,   320,
     321,   -39,     0,     0,     0,   -39,   -39,   -39,   -39,   -36,
       0,     0,     0,   -36,   -36,   -36,   -36,   -37,     0,     0,
       0,   -37,   -37,   -37,   -37,   -59,     0,     0,     0,   -59,
     -59,   -59,   -59
};

static const yytype_int16 yycheck[] =
{
       0,     0,    17,     3,     3,   290,   363,    26,   159,    36,
       4,     4,     4,    40,     4,   132,     3,    36,   132,     4,
      49,   132,    36,    16,   132,   310,    20,    34,     3,    34,
      20,    71,    25,    26,   319,     0,    29,    30,    30,    32,
      25,    26,   327,    70,    29,    30,    21,    32,    21,    21,
      21,    70,    71,     4,   339,    22,    70,    30,    29,    30,
      74,    32,    76,    77,    78,    16,    80,    81,    34,    35,
      36,    90,     4,   100,     4,    89,     3,   434,    29,    30,
      20,    32,    96,    97,    98,     4,    16,    20,    20,    20,
      20,    20,   132,   133,    20,    25,    26,    27,    28,    29,
      30,     4,    32,   132,    21,   134,    20,    16,    25,    26,
      29,    30,    21,   132,   133,   266,    20,   132,    20,     4,
      29,    30,   151,    32,     4,     0,   153,   156,     3,   143,
      20,    16,   132,   132,   153,    16,     4,     0,   165,   153,
       3,   168,    20,     4,    29,    30,   165,    32,    16,    29,
      30,   165,    20,     0,   168,    16,     3,    25,    26,    27,
      28,    29,    30,     0,    32,    33,     3,   194,    29,    30,
       4,    32,     4,   458,     4,   194,    21,    37,    38,     4,
     194,   208,    16,    34,    29,    30,    16,    32,    21,   208,
       4,    16,    21,   220,   208,    29,    30,     4,    32,    29,
      30,   220,    32,    10,    29,    30,   220,    32,    15,   236,
      17,    18,    19,    20,     4,    29,    30,   236,    25,    26,
       0,    21,   236,     3,    31,    21,    21,    34,    35,    36,
      37,    38,     4,    29,    30,    10,   250,   251,   252,   253,
     254,   255,   261,    16,    21,    20,    21,    20,     4,   278,
      25,    26,    25,    26,    27,    28,    16,    29,    30,    34,
      35,    36,    37,    38,   291,   279,     4,   281,   282,    21,
     297,   298,   291,    29,    30,     4,   290,   291,   292,   293,
     294,   295,   296,   297,   298,   299,    21,   301,    21,   303,
     304,    29,    30,    21,    32,     4,   310,   311,   312,   313,
      29,    30,    21,    32,    21,   319,   320,   321,    25,    26,
       4,    21,   352,   327,   328,   329,   330,    21,   332,   333,
      29,    30,     4,    32,   351,   339,   340,   341,   342,   343,
       4,   360,   351,   352,     4,    29,    30,   351,    32,     0,
       4,   355,     3,   357,   358,     4,    21,    29,    30,    24,
      32,    16,    21,     4,   381,    29,    30,     4,    32,    36,
      25,    26,   381,   480,     4,   482,   480,   381,   482,   480,
       4,   482,   480,     4,   482,    20,    16,    21,    29,    30,
      24,    32,    37,    38,    36,    25,    26,    27,    28,    29,
      30,    21,    32,    70,    24,    29,    30,    74,    32,    76,
      77,    78,   519,    80,    81,   519,     4,   524,   519,    34,
     524,   519,    89,   524,    16,    21,   524,    20,    70,    25,
      26,    98,    20,    25,    26,    27,    28,    25,    26,    27,
      28,    29,    30,     0,    32,   449,     3,   451,   452,    20,
     480,   481,   482,    20,   458,   459,   460,   461,   462,   101,
      16,   480,    21,   482,   468,    24,   470,   471,     4,    16,
       4,   480,   481,   482,    21,   480,   143,   482,    25,    26,
      20,   486,    29,    30,     0,    32,   153,     3,    20,   519,
     480,   480,   482,   482,   524,    20,   501,    16,   165,     0,
     519,   168,     3,    20,   521,   524,    25,    26,    27,    28,
     519,   153,   521,    16,   519,   524,    21,   521,    16,   524,
      20,     4,    36,   165,    29,    30,   168,   194,    16,   519,
     519,    37,    38,    16,   524,   524,     4,    25,    26,    27,
      28,   208,    25,    26,    27,    28,    29,    30,    16,    32,
      21,     4,   194,   220,    25,    26,    70,    25,    26,    27,
      28,    29,    30,    21,    32,     4,   208,    25,    26,   236,
       4,    21,    36,    21,    24,    20,    29,    30,   220,    32,
      20,    29,    30,   250,   251,   252,   253,   254,   255,    20,
      29,    30,    10,    32,   236,    29,    30,    15,    32,    17,
      18,    19,    20,    20,    37,    38,    70,    25,    26,    37,
      38,    34,   279,    31,   281,   282,    34,    35,    36,    37,
      38,    37,    38,   290,   291,   292,   293,   294,   295,   296,
     297,   298,   299,    21,   301,    21,   303,   304,    24,   153,
      20,    29,    30,   310,   311,   312,   313,    21,    20,   291,
      24,   165,   319,   320,   321,   297,   298,   299,    36,    16,
     327,   328,   329,   330,    20,   332,   333,    20,    25,    26,
      27,    28,   339,   340,   341,   342,   343,    21,    21,    20,
     194,    24,    25,    26,   351,    29,    30,     4,   355,   153,
     357,   358,    70,    21,   208,    34,    74,     4,    76,    77,
      78,   165,    80,    81,   168,    16,   220,    37,    38,   351,
      21,    89,    37,    38,   381,    34,    94,    95,    29,    30,
      98,    32,   236,    21,     1,    21,     3,     4,     5,    21,
     194,     8,     9,    10,    11,    12,    13,    14,    15,   381,
      17,    18,    19,    20,   208,    22,    23,    34,    25,    26,
      16,    37,    38,    21,    31,    21,   220,    34,    35,    36,
      37,    38,    21,    29,    30,   143,    32,    37,    38,    16,
      29,    30,   236,    32,     4,   153,    21,   291,    25,    26,
      27,    28,   449,    20,   451,   452,     4,   165,    37,    38,
     168,   458,   459,   460,   461,   462,     4,    21,    16,    37,
      38,   468,    21,   470,   471,    37,    38,    25,    26,    27,
      28,    29,    30,    20,    32,    21,   194,    25,    26,    27,
      28,    29,    30,     4,    32,    37,    38,   291,    21,    21,
     208,    21,    21,   297,   298,    16,    36,   351,     4,    21,
      29,    30,   220,    32,    25,    26,    27,    28,    29,    30,
      16,    32,    20,    20,   521,    34,    21,    21,   236,    25,
      26,    27,    28,    29,    30,    21,    32,   381,    20,    20,
      70,    20,   250,   251,   252,   253,   254,   255,    20,   521,
      21,    10,    21,    16,    21,    21,    15,   351,    17,    18,
      19,    20,    25,    26,    27,    28,    25,    26,    21,    99,
      21,   279,    31,   281,   282,    34,    35,    36,    37,    38,
      21,    21,   290,   291,   292,   293,    21,   381,   296,   297,
     298,   299,     4,   301,    16,   303,   304,    21,    21,    21,
      36,     4,   310,    21,    16,   313,    21,    29,    30,    16,
      32,   319,    21,    25,    26,    27,    28,    29,    30,   327,
      32,    21,   330,   153,   332,   333,    16,    16,    21,    16,
      34,   339,   340,   341,    70,   165,    29,    30,    74,    32,
      76,    77,    78,   351,    80,    81,     4,   355,    21,   357,
     358,     4,    21,    89,    22,     4,    25,    26,    16,     4,
      29,    30,    98,    32,   194,    21,    21,    25,    26,    27,
      28,    29,    30,   381,    32,    16,    22,   521,   208,    21,
      21,     4,    21,    21,    21,    21,    36,    10,    29,    30,
     220,    32,    15,    21,    17,    18,    19,    20,     4,    21,
      21,    21,    25,    26,    21,    16,   236,   143,    31,    21,
      21,    34,    35,    36,    37,    38,    21,   153,    29,    30,
      70,    32,     3,    18,    74,    16,   143,   521,    78,   165,
      80,    81,   168,   356,    25,    26,    27,    28,    21,    -1,
     502,   449,    -1,   451,   452,    16,    29,    30,    98,    32,
     458,   459,   460,    -1,    25,    26,    27,    28,   194,    16,
     468,   291,   470,   471,    -1,    -1,    -1,   297,    25,    26,
      27,    28,   208,    -1,     4,    -1,    -1,    -1,    36,    -1,
      10,    -1,    16,    -1,   220,    15,    -1,    17,    18,    19,
      20,    25,    26,    27,    28,    25,    26,    -1,    -1,    -1,
     236,    31,    -1,   153,    34,    35,    36,    37,    38,    10,
      -1,    -1,    70,   521,    -1,   165,    74,    16,   168,    20,
      78,   351,    80,    81,    25,    26,    25,    26,    27,    28,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    16,    -1,
      98,    -1,    -1,   279,   194,   281,   282,    25,    26,    27,
      28,   381,    -1,    -1,   290,   291,    -1,    -1,   208,    -1,
     296,   297,   298,   299,    21,   301,    -1,   303,   304,    16,
     220,    -1,    29,    30,   310,    32,    21,   313,    25,    26,
      27,    28,    -1,   319,    29,    30,   236,    32,    -1,    16,
      -1,   327,    -1,    -1,   330,   153,   332,   333,    25,    26,
      27,    28,     4,   339,    -1,    -1,    -1,   165,    -1,    21,
     168,    -1,    -1,    -1,    16,   351,    -1,    29,    30,   355,
      32,   357,   358,    25,    26,    27,    28,    29,    30,   279,
      32,   281,   282,    21,    -1,    -1,   194,    25,    26,    27,
      28,   291,    -1,    -1,    -1,   381,   296,   297,   298,   299,
     208,   301,    21,   303,   304,    24,    25,    26,    27,    28,
      10,    -1,   220,   313,    -1,    15,    -1,    17,    18,    19,
      20,     4,    -1,    -1,    -1,    25,    26,    -1,   236,    -1,
     330,    31,   332,   333,    34,    35,    36,    37,    38,    -1,
      -1,   521,    25,    26,    27,    28,    29,    30,    -1,    32,
      -1,   351,    10,    -1,    -1,   355,    -1,    15,    -1,    17,
      18,    19,    20,   449,    36,   451,   452,    25,    26,    -1,
      -1,   279,   458,   281,   282,    -1,    34,    35,    36,    37,
      38,   381,   468,   291,   470,   471,    -1,    -1,   296,   297,
     298,   299,     4,   301,    -1,   303,   304,    -1,    70,    -1,
      -1,    -1,    74,    -1,    16,   313,    78,    -1,    80,    81,
      -1,    -1,    -1,    25,    26,    27,    28,    29,    30,    -1,
      32,    16,   330,    -1,   332,   333,    98,    -1,    -1,    10,
      25,    26,    27,    28,    15,   521,    17,    18,    19,    20,
      -1,     4,    -1,   351,    25,    26,    -1,   355,    -1,   449,
      36,   451,   452,    34,    35,    36,    37,    38,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,   468,    32,
     470,   471,    -1,   381,    21,    -1,    -1,    -1,    21,    -1,
      -1,   153,    29,    30,    70,    32,    29,    30,    74,    32,
      -1,    16,    78,   165,    80,    81,   168,    -1,    -1,    10,
      25,    26,    27,    28,    15,    -1,    17,    18,    19,    20,
      -1,    20,    21,    -1,    25,    26,    25,    26,    27,    28,
      31,   521,   194,    34,    35,    36,    37,    38,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    15,   208,    17,    18,    19,
      20,   449,    -1,   451,   452,    25,    26,     4,   220,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    16,
     468,    -1,   470,   471,   236,    -1,    -1,   153,    25,    26,
      27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,   165,
      -1,     1,   168,     3,     4,     5,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    -1,    17,    18,    19,
      20,    -1,    22,    23,    -1,    25,    26,   279,   194,   281,
     282,    31,    -1,   521,    34,    35,    36,    37,    38,   291,
      -1,    -1,   208,    -1,   296,   297,   298,   299,    10,   301,
      -1,   303,   304,    15,   220,    17,    18,    19,    20,    -1,
      -1,   313,    21,    25,    26,    24,    25,    26,    27,    28,
     236,    -1,    34,    35,    36,    37,    38,    -1,   330,    21,
     332,   333,    10,    25,    26,    27,    28,    15,    -1,    17,
      18,    19,    20,    -1,    -1,    -1,     4,    25,    26,   351,
      -1,    -1,    -1,   355,    -1,    -1,    34,    35,    36,    37,
      38,    -1,    -1,   279,    -1,   281,   282,    25,    26,    27,
      28,    29,    30,    -1,    32,   291,    -1,    -1,    -1,   381,
      16,   297,   298,   299,    -1,   301,    -1,   303,   304,    25,
      26,    27,    28,    -1,     1,    -1,     3,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,   330,    22,   332,   333,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,    -1,    -1,    -1,   351,    10,    -1,    -1,   355,
      -1,    15,    -1,    17,    18,    19,    20,   449,    -1,   451,
     452,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      34,    35,    36,    37,    38,   381,   468,    -1,   470,   471,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    16,
      31,    -1,    -1,    34,    35,    36,    37,    38,    25,    26,
      27,    28,    -1,     1,    -1,     3,     4,     5,    -1,   521,
       8,     9,    10,    11,    12,    13,    14,    15,    -1,    17,
      18,    19,    20,   449,    22,   451,   452,    25,    26,    -1,
      -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,
      38,    -1,   468,    -1,   470,   471,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,
       1,    -1,     3,     4,     5,   521,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,     1,    -1,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
       1,    -1,     3,     4,     5,    -1,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,     1,    -1,     3,     4,     5,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
       1,    -1,     3,     4,     5,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,     1,    -1,     3,     4,     5,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
       1,    -1,     3,     4,     5,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,     1,    -1,     3,     4,     5,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
       1,    -1,     3,     4,     5,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,     1,    -1,     3,     4,     5,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
       1,    -1,     3,     4,     5,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,     1,    -1,     3,     4,     5,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
       1,    -1,     3,     4,     5,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,    -1,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    -1,    34,    35,    36,
      37,    38,     1,    -1,     3,     4,     5,    -1,    -1,     8,
       9,    10,    11,    12,    13,    14,    15,    -1,    17,    18,
      19,    20,    -1,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    31,    -1,    -1,    34,    35,    36,    37,    38,
       1,    -1,     3,     4,     5,    -1,    -1,     8,     9,    10,
      11,    12,    13,    14,    15,    -1,    17,    18,    19,    20,
      -1,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,
      31,    -1,    -1,    34,    35,    36,    37,    38,     1,    -1,
       3,     4,     5,    -1,    -1,     8,     9,    10,    11,    12,
      13,    14,    15,    -1,    17,    18,    19,    20,    -1,    22,
      23,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    -1,
      -1,    34,    35,    36,    37,    38,     1,    -1,     3,     4,
       5,    -1,    -1,     8,     9,    10,    11,    12,    13,    14,
      15,    -1,    17,    18,    19,    20,    -1,    22,    23,    -1,
      25,    26,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    36,    37,    38,     1,    -1,     3,     4,     5,    -1,
      -1,     8,     9,    10,    11,    12,    13,    14,    15,    -1,
      17,    18,    19,    20,     4,    22,    23,    -1,    25,    26,
      -1,    -1,    -1,    -1,    31,    -1,    16,    34,    35,    36,
      37,    38,    -1,    10,    -1,    25,    26,    27,    28,    29,
      30,     4,    32,    20,    -1,    -1,    -1,    -1,    25,    26,
      -1,    -1,    -1,    16,    -1,    -1,     4,    34,    35,    36,
      37,    38,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,     4,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,    -1,    -1,    10,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    20,    32,    -1,    -1,    -1,    25,    26,
      -1,    -1,    10,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,
      -1,    10,    -1,    -1,    -1,    -1,    34,    35,    36,    37,
      38,    20,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      20,    -1,    -1,    -1,    -1,    25,    26,    -1,    -1,    10,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    20,
       4,    -1,    -1,    -1,    25,    26,    -1,    -1,     4,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,     4,    -1,
      -1,    25,    26,    27,    28,    29,    30,     4,    32,    25,
      26,    27,    28,    29,    30,     4,    32,    -1,    -1,    25,
      26,    27,    28,    29,    30,     4,    32,    -1,    25,    26,
      27,    28,    29,    30,     4,    32,    25,    26,    27,    28,
      29,    30,     4,    32,    -1,    -1,    25,    26,    27,    28,
      29,    30,     4,    32,    -1,    25,    26,    27,    28,    29,
      30,     4,    32,    25,    26,    27,    28,    29,    30,     4,
      32,    -1,    -1,    25,    26,    27,    28,    29,    30,     4,
      32,    -1,    25,    26,    27,    28,    29,    30,     4,    32,
      25,    26,    27,    28,    29,    30,     4,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    -1,    32,    -1,    25,
      26,    27,    28,    29,    30,    -1,    32,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,    -1,    20,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      33,    -1,    20,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    16,    32,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    16,    32,
      -1,    -1,    -1,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    29,    30,    -1,    32,    20,    21,    -1,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    21,    32,    -1,    -1,
      25,    26,    27,    28,    29,    30,    -1,    32,    20,    21,
      -1,    -1,    24,    25,    26,    27,    28,    21,    -1,    -1,
      24,    25,    26,    27,    28,    21,    -1,    -1,    24,    25,
      26,    27,    28,    21,    -1,    -1,    24,    25,    26,    27,
      28,    21,    -1,    -1,    24,    25,    26,    27,    28,    21,
      -1,    -1,    24,    25,    26,    27,    28,    21,    -1,    -1,
      24,    25,    26,    27,    28,    21,    -1,    -1,    24,    25,
      26,    27,    28,    21,    -1,    -1,    24,    25,    26,    27,
      28,    21,    -1,    -1,    24,    25,    26,    27,    28,    21,
      -1,    -1,    24,    25,    26,    27,    28,    21,    -1,    -1,
      24,    25,    26,    27,    28,    21,    -1,    -1,    24,    25,
      26,    27,    28,    21,    -1,    -1,    24,    25,    26,    27,
      28,    21,    -1,    -1,    24,    25,    26,    27,    28,    21,
      -1,    -1,    24,    25,    26,    27,    28,    21,    -1,    -1,
      24,    25,    26,    27,    28,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    21,    -1,    -1,    -1,    25,    26,    27,    28,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    21,    -1,    -1,
      -1,    25,    26,    27,    28,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    21,    -1,    -1,    -1,    25,    26,    27,    28,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    21,    -1,    -1,
      -1,    25,    26,    27,    28,    21,    -1,    -1,    -1,    25,
      26,    27,    28,    21,    -1,    -1,    -1,    25,    26,    27,
      28,    21,    -1,    -1,    -1,    25,    26,    27,    28,    21,
      -1,    -1,    -1,    25,    26,    27,    28,    21,    -1,    -1,
      -1,    25,    26,    27,    28,    21,    -1,    -1,    -1,    25,
      26,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    40,    41,    42,    43,    44,    34,     0,    42,
       4,    20,     3,    45,    46,    47,    34,    21,    24,    22,
      48,    47,     1,     4,     5,     8,     9,    10,    11,    12,
      13,    14,    15,    17,    18,    19,    20,    23,    25,    26,
      31,    34,    35,    36,    37,    38,    43,    44,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    65,    66,    68,    69,    70,    71,    72,    73,
      20,    20,     4,    53,    20,    20,    20,    20,    20,    20,
      20,    20,    53,    37,    38,    37,    38,    34,    70,    20,
      33,    23,    50,     4,    25,    26,    27,    28,    16,    30,
      29,    32,    53,    51,     4,    54,    57,    59,    34,    35,
      36,    74,    54,    54,    57,    34,    57,    57,    21,    54,
      62,    63,    64,    53,    55,    55,    56,    56,    58,    69,
      70,    72,    21,     4,    21,    21,    21,    21,    21,    21,
      21,    21,    21,    24,    50,    51,    50,     4,     4,     4,
      64,     7,    67,     4,    50,    53,    21,    50,     3,    22,
      10,    15,    17,    18,    19,    20,    25,    26,    31,    34,
      35,    36,    37,    38,    54,    55,    56,    57,    58,    59,
      60,    61,    68,    69,    70,    71,    72,     4,    53,    10,
      15,    17,    18,    19,    20,    25,    26,    34,    35,    36,
      37,    38,    55,    56,    58,    60,    61,    10,    20,    25,
      26,    34,    35,    36,    37,    38,    55,    56,    61,    10,
      20,    25,    26,    34,    35,    36,    37,    38,    55,    56,
      61,    10,    15,    17,    18,    19,    20,    25,    26,    34,
      35,    36,    37,    38,    54,    55,    56,    59,    60,    61,
      25,    26,    25,    26,    25,    26,     1,     3,     4,     5,
       8,     9,    11,    12,    13,    14,    22,    43,    44,    48,
      51,    52,    53,    65,    66,    73,    34,    23,    49,    20,
      20,    20,    20,    53,    37,    38,    37,    38,    34,    70,
      20,    33,    25,    26,    27,    28,    16,    30,    29,    32,
       4,    20,    20,    20,    20,    53,    37,    38,    37,    38,
      20,    27,    28,    16,    53,    37,    38,    37,    38,    20,
      27,    28,    53,    37,    38,    37,    38,    20,    27,    28,
      20,    20,    20,    20,    53,    37,    38,    37,    38,    20,
      25,    26,    27,    28,    55,    55,    55,    55,    55,    55,
      34,    20,    20,     4,    53,    20,    20,    20,    20,    23,
      49,     4,     4,    20,    23,    57,    34,    57,    57,    21,
      62,    53,    55,    55,    56,    56,    10,    15,    17,    18,
      19,    20,    25,    26,    34,    35,    36,    37,    38,    54,
      55,    56,    58,    59,    60,    61,    69,    70,    72,    57,
      34,    57,    57,    21,    62,    56,    56,    15,    17,    18,
      19,    54,    58,    59,    60,    21,    62,    56,    56,    21,
      62,    56,    56,    57,    34,    57,    57,    21,    62,    55,
      55,    56,    56,     4,    20,    53,    51,     4,    57,    74,
      54,    54,    23,    45,    21,    21,    21,    21,    21,    20,
      20,    20,    20,    53,    37,    38,    37,    38,    20,    25,
      26,    27,    28,    21,    21,    21,    21,    21,    20,    20,
      20,    20,    21,    21,    21,    21,    21,    21,    21,    45,
      21,     4,    21,    21,    21,    21,    21,    57,    34,    57,
      57,    21,    62,    55,    55,    56,    56,    57,    34,    57,
      57,    21,    50,    51,    50,     4,     4,     4,    48,    21,
      21,    21,    21,    21,    21,    21,    21,    21,    48,     7,
      67,     4,    50,    53,    21,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    44,    45,
      45,    46,    46,    47,    48,    48,    49,    49,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    53,    54,    54,    54,    55,    55,    55,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    57,    58,    58,    59,    60,    60,    60,    60,    61,
      62,    62,    63,    63,    64,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      72,    73,    73,    73,    74,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       0,     3,     1,     2,     3,     2,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       2,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     2,
       2,     3,     1,     1,     1,     4,     4,     4,     4,     4,
       1,     0,     3,     1,     1,     5,     9,     5,     6,     2,
       3,     1,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     5,     5,     5,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* source_program: decl_definitions_list  */
#line 103 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_SOURCE, "source_program");
		attachNode(newNode, 1, (yyvsp[0].node));
		cst_root = newNode;

		DEBUG_B("[#%d] (source_program) -> decl_definitions_list\n", __LINE__);
	}
#line 2632 "parser.tab.c"
    break;

  case 3: /* decl_definitions_list: decl_definitions_list decl_or_func_def  */
#line 114 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_DECL_LIST, "decl_definitions_list");
		attachNode(newNode, 2, (yyvsp[-1].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (decl_definitions_list) -> decl_definitions_list decl_or_func_def\n", __LINE__);
	}
#line 2644 "parser.tab.c"
    break;

  case 4: /* decl_definitions_list: decl_or_func_def  */
#line 122 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (decl_definitions_list) -> decl_or_func_def\n", __LINE__);
	}
#line 2653 "parser.tab.c"
    break;

  case 5: /* decl_or_func_def: function_definition  */
#line 130 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (decl_or_func_def) -> function_definition\n", __LINE__);
	}
#line 2662 "parser.tab.c"
    break;

  case 6: /* decl_or_func_def: variable_declaration  */
#line 135 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (decl_or_func_def) -> variable_declaration\n", __LINE__);
	}
#line 2671 "parser.tab.c"
    break;

  case 7: /* variable_declaration: TYPE ID CSEMICOLON  */
#line 143 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_VAR_DECL, "variable_declaration");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[-1].node));
		newNode->pTable = insertSymbol(symbolTab, newNode);

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (variable_declaration) -> TYPE ID CSEMICOLON\n", __LINE__);
	}
#line 2684 "parser.tab.c"
    break;

  case 8: /* function_definition: TYPE ID COPARENT parameters CCPARENT statement_group_braces  */
#line 155 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_FUNC_DEF, "function_definition");
		attachNode(newNode, 4, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
		newNode->pTable = findSymbolOrInsert(newNode);

		applyParentAllChindren((yyvsp[0].node), (yyvsp[-2].node));
		applyParentAllChindren(newNode, (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (function_definition) -> TYPE ID COPARENT parameters CCPARENT statement_group_braces\n", __LINE__);
	}
#line 2700 "parser.tab.c"
    break;

  case 9: /* parameters: parameter_list  */
#line 170 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (parameters) -> (parameter_list)\n", __LINE__);
	}
#line 2709 "parser.tab.c"
    break;

  case 10: /* parameters: %empty  */
#line 175 "parser.y"
        {
		(yyval.node) = createNode(NODE_PARAMS, "parameter_list");
		DEBUG_B("[#%d] (parameters) -> EMPTY\n", __LINE__);
	}
#line 2718 "parser.tab.c"
    break;

  case 11: /* parameter_list: parameter_list CCOMA parameter  */
#line 183 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_PARAMS, "parameter_list");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (parameter_list) -> parameter_list CCOMA parameter\n", __LINE__);
	}
#line 2730 "parser.tab.c"
    break;

  case 12: /* parameter_list: parameter  */
#line 191 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (parameter_list) -> parameter\n", __LINE__);
	}
#line 2739 "parser.tab.c"
    break;

  case 13: /* parameter: TYPE ID  */
#line 199 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_PARAMETER, "parameter");
		attachNode(newNode, 2, (yyvsp[-1].node), (yyvsp[0].node));

		newNode->pTable = insertSymbol(symbolTab, newNode);

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (parameter) -> TYPE ID\n", __LINE__);
	}
#line 2753 "parser.tab.c"
    break;

  case 14: /* statement_group_braces: COBRACE statement_list CCBRACE  */
#line 212 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_SCOPE, "scope");
		attachNode(newNode, 1, (yyvsp[-1].node));
		applyParentAllChindren(newNode, (yyvsp[-1].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (statement_group_braces) -> {statement_list}\n", __LINE__);
	}
#line 2766 "parser.tab.c"
    break;

  case 15: /* statement_group_braces: COBRACE CCBRACE  */
#line 221 "parser.y"
        {
		(yyval.node) = createNode(NODE_SCOPE, "scope");
		DEBUG_B("[#%d] (statement_group_braces) -> {}\n", __LINE__);
	}
#line 2775 "parser.tab.c"
    break;

  case 16: /* statement_list: statement_list statement  */
#line 229 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_STMT_LIST, "statement_list");
		attachNode(newNode, 2, (yyvsp[-1].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (statement_list) -> statement_list statement\n", __LINE__);
	}
#line 2787 "parser.tab.c"
    break;

  case 17: /* statement_list: statement  */
#line 237 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (statement_list) -> statement\n", __LINE__);
	}
#line 2796 "parser.tab.c"
    break;

  case 18: /* statement: variable_declaration  */
#line 245 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (statement) -> variable_declaration\n", __LINE__);
	}
#line 2805 "parser.tab.c"
    break;

  case 19: /* statement: expression_statement  */
#line 250 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (statement) -> expression_statement;\n", __LINE__);
	}
#line 2814 "parser.tab.c"
    break;

  case 20: /* statement: return_statement  */
#line 255 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (statement) -> return_statement;\n", __LINE__);
	}
#line 2823 "parser.tab.c"
    break;

  case 21: /* statement: set_statement  */
#line 260 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (statement) -> set_statement;\n", __LINE__);
	}
#line 2832 "parser.tab.c"
    break;

  case 22: /* statement: loop_statement  */
#line 265 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (statement) -> loop_statement\n", __LINE__);
	}
#line 2841 "parser.tab.c"
    break;

  case 23: /* statement: if_statement  */
#line 270 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (statement) -> if_statement\n", __LINE__);
	}
#line 2850 "parser.tab.c"
    break;

  case 24: /* statement: statement_group_braces  */
#line 275 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (statement) -> statement_group_braces\n", __LINE__);
	}
#line 2859 "parser.tab.c"
    break;

  case 25: /* statement: function_definition  */
#line 280 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (statement) -> function_definition\n", __LINE__);
	}
#line 2868 "parser.tab.c"
    break;

  case 26: /* statement: error  */
#line 284 "parser.y"
                { yyerrok; }
#line 2874 "parser.tab.c"
    break;

  case 27: /* expression_statement: expression CSEMICOLON  */
#line 289 "parser.y"
        {
		(yyval.node) = (yyvsp[-1].node);
		DEBUG_B("[#%d] (expression_statement) -> expression\n", __LINE__);
	}
#line 2883 "parser.tab.c"
    break;

  case 28: /* expression_statement: CSEMICOLON  */
#line 294 "parser.y"
        {
		(yyval.node) = createNode(NODE_UNKNOWN, "expression");
		DEBUG_B("[#%d] (expression_statement) -> empty\n", __LINE__);
	}
#line 2892 "parser.tab.c"
    break;

  case 29: /* return_statement: KY_RETURN expression CSEMICOLON  */
#line 302 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_RETURN, "return");
		attachNode(newNode, 1, (yyvsp[-1].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (return_statement) -> KY_RETURN expression CSEMICOLON", __LINE__);
	}
#line 2904 "parser.tab.c"
    break;

  case 30: /* return_statement: KY_RETURN CSEMICOLON  */
#line 310 "parser.y"
        {
		(yyval.node) = createNode(NODE_RETURN, "return");
		DEBUG_B("[#%d] (return_statement) -> KY_RETURN CSEMICOLON", __LINE__);
	}
#line 2913 "parser.tab.c"
    break;

  case 31: /* expression: ID OP_ASSIGN expression  */
#line 318 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ASSIGN, "exp_assign");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (expression) -> ID OP_ASSIGN expression\n", __LINE__);
	}
#line 2925 "parser.tab.c"
    break;

  case 32: /* expression: op_log_and_operation  */
#line 326 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (expression) -> op_log_and_operation\n", __LINE__);
	}
#line 2934 "parser.tab.c"
    break;

  case 33: /* simple_arith_expression: simple_arith_expression OP_ARITH_ADD term  */
#line 334 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ARITH_ADD, "op_add");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (simple_arith_expression) -> simple_arith_expression OP_ARITH_ADD term\n", __LINE__);
	}
#line 2946 "parser.tab.c"
    break;

  case 34: /* simple_arith_expression: simple_arith_expression OP_ARITH_SUB term  */
#line 342 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ARITH_SUB, "op_sub");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (simple_arith_expression) -> simple_arith_expression OP_ARITH_SUB term\n", __LINE__);
	}
#line 2958 "parser.tab.c"
    break;

  case 35: /* simple_arith_expression: term  */
#line 350 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (simple_arith_expression) -> term\n", __LINE__);
	}
#line 2967 "parser.tab.c"
    break;

  case 36: /* term: term OP_ARITH_MUL factor  */
#line 358 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ARITH_MUL, "op_mul");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (term) -> (term OP_ARITH_MUL factor)\n", __LINE__);
	}
#line 2979 "parser.tab.c"
    break;

  case 37: /* term: term OP_ARITH_DIV factor  */
#line 366 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ARITH_DIV, "op_div");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (term) -> (term OP_ARITH_DIV factor)\n", __LINE__);
	}
#line 2991 "parser.tab.c"
    break;

  case 38: /* term: factor  */
#line 374 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (term) -> (factor)\n", __LINE__);
	}
#line 3000 "parser.tab.c"
    break;

  case 39: /* factor: COPARENT expression CCPARENT  */
#line 382 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_FACTOR, "factor");
		attachNode(newNode, 1, (yyvsp[-1].node));
		
		(yyval.node) = newNode;
		DEBUG_B("[#%d] (factor) -> (expression)\n", __LINE__);
	}
#line 3012 "parser.tab.c"
    break;

  case 40: /* factor: KY_EMPTY  */
#line 390 "parser.y"
        {
		(yyval.node) = createNode(NODE_EMPTY, "EMPTY");
		DEBUG_B("[#%d] (factor) -> KY_EMPTY\n", __LINE__);
	}
#line 3021 "parser.tab.c"
    break;

  case 41: /* factor: ID  */
#line 395 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (factor) -> ID\n", __LINE__);
	}
#line 3030 "parser.tab.c"
    break;

  case 42: /* factor: INTEGER  */
#line 400 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (factor) -> INTEGER\n", __LINE__);
	}
#line 3039 "parser.tab.c"
    break;

  case 43: /* factor: DECIMAL  */
#line 405 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (factor) -> DECIMAL\n", __LINE__);
	}
#line 3048 "parser.tab.c"
    break;

  case 44: /* factor: STRING  */
#line 410 "parser.y"
        {
		// procurar string na tabela. Se não achar, insere!
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (factor) -> STRING\n", __LINE__);
	}
#line 3058 "parser.tab.c"
    break;

  case 45: /* factor: CHAR  */
#line 416 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (factor) -> CHAR\n", __LINE__);
	}
#line 3067 "parser.tab.c"
    break;

  case 46: /* factor: call_function  */
#line 421 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (factor) -> call_function\n", __LINE__);
	}
#line 3076 "parser.tab.c"
    break;

  case 47: /* factor: OP_ARITH_ADD INTEGER  */
#line 427 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (factor) -> OP_ARITH_ADD INTEGER\n", __LINE__);
	}
#line 3085 "parser.tab.c"
    break;

  case 48: /* factor: OP_ARITH_SUB INTEGER  */
#line 432 "parser.y"
        {
		(yyvsp[0].node)->integer = -(yyvsp[0].node)->integer;
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (factor) -> OP_ARITH_SUB INTEGER\n", __LINE__);
	}
#line 3095 "parser.tab.c"
    break;

  case 49: /* factor: OP_ARITH_ADD DECIMAL  */
#line 438 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (factor) -> OP_ARITH_ADD DECIMAL\n", __LINE__);
	}
#line 3104 "parser.tab.c"
    break;

  case 50: /* factor: OP_ARITH_SUB DECIMAL  */
#line 443 "parser.y"
        {
		(yyvsp[0].node)->decimal = -(yyvsp[0].node)->decimal;
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (factor) -> OP_ARITH_SUB DECIMAL\n", __LINE__);
	}
#line 3114 "parser.tab.c"
    break;

  case 51: /* set_in_expression: set_arith_expression KY_IN set_arith_expression  */
#line 453 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_SET_IN, "set_in_expression");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_in_expression) -> set_arith_expression IN set_arith_expression\n", __LINE__);
	}
#line 3126 "parser.tab.c"
    break;

  case 52: /* set_arith_expression: simple_arith_expression  */
#line 464 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (set_arith_expression) -> simple_arith_expression\n", __LINE__);
	}
#line 3135 "parser.tab.c"
    break;

  case 53: /* set_arith_expression: call_set_expression  */
#line 469 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (set_arith_expression) -> call_set_expression\n", __LINE__);
	}
#line 3144 "parser.tab.c"
    break;

  case 54: /* call_set_expression: set_func_expression  */
#line 477 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (call_set_expression) -> set_func_expression\n", __LINE__);
	}
#line 3153 "parser.tab.c"
    break;

  case 55: /* set_func_expression: KY_IS_SET COPARENT ID CCPARENT  */
#line 485 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_IS_SET, "is_set");
		attachNode(newNode, 1, (yyvsp[-1].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_func_expression) -> KY_IS_SET COPARENT ID CCPARENT\n", __LINE__);
	}
#line 3165 "parser.tab.c"
    break;

  case 56: /* set_func_expression: KY_ADD COPARENT set_in_expression CCPARENT  */
#line 493 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_SET_ADD, "add");
		attachNode(newNode, 1, (yyvsp[-1].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_func_expression) -> KY_ADD COPARENT set_in_expression CCPARENT\n", __LINE__);
	}
#line 3177 "parser.tab.c"
    break;

  case 57: /* set_func_expression: KY_REMOVE COPARENT set_in_expression CCPARENT  */
#line 501 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_REMOVE, "remove");
		attachNode(newNode, 1, (yyvsp[-1].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_func_expression) -> KY_REMOVE COPARENT set_in_expression CCPARENT\n", __LINE__);
	}
#line 3189 "parser.tab.c"
    break;

  case 58: /* set_func_expression: KY_EXISTS COPARENT set_in_expression CCPARENT  */
#line 509 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_EXISTS, "exists");
		attachNode(newNode, 1, (yyvsp[-1].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_func_expression) -> KY_EXISTS COPARENT set_in_expression CCPARENT\n", __LINE__);
	}
#line 3201 "parser.tab.c"
    break;

  case 59: /* call_function: ID COPARENT arguments CCPARENT  */
#line 520 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_CALL_FUNC, "call_function");

		if((yyvsp[-1].node) != NULL) {
			attachNode(newNode, 2, (yyvsp[-3].node), (yyvsp[-1].node));
			applyParentAllChindren(newNode, (yyvsp[-1].node));
		} else {
			attachNode(newNode, 1, (yyvsp[-3].node));
		}

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (call_function) -> ID COPARENT arguments CCPARENT\n", __LINE__);
	}
#line 3219 "parser.tab.c"
    break;

  case 60: /* arguments: arguments_list  */
#line 537 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (arguments) -> arguments_list\n", __LINE__);
	}
#line 3228 "parser.tab.c"
    break;

  case 61: /* arguments: %empty  */
#line 541 "parser.y"
          {
		(yyval.node) = createNode(NODE_ARGS, "arguments_list");;
		DEBUG_B("[#%d] (arguments) -> empty\n", __LINE__);
	}
#line 3237 "parser.tab.c"
    break;

  case 62: /* arguments_list: arguments_list CCOMA argument  */
#line 549 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ARGS, "arguments_list");
		struct node_s *arg = createNode(NODE_ARGUMENT, "argument");

		attachNode(arg, 1, (yyvsp[0].node));
		attachNode(newNode, 2, (yyvsp[-2].node), arg);

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (arguments_list) -> arguments_list CCOMA argument\n", __LINE__);
	}
#line 3252 "parser.tab.c"
    break;

  case 63: /* arguments_list: argument  */
#line 560 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ARGUMENT, "argument");
		attachNode(newNode, 1, (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (arguments_list) -> argument\n", __LINE__);
	}
#line 3264 "parser.tab.c"
    break;

  case 64: /* argument: simple_arith_expression  */
#line 571 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (argument) -> simple_arith_expression\n", __LINE__);
	}
#line 3273 "parser.tab.c"
    break;

  case 65: /* loop_statement: KY_FORALL COPARENT set_in_expression CCPARENT statement  */
#line 579 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_FORALL, "forall");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));
		applyParentAllChindren(newNode, (yyvsp[-2].node));
		applyParentAllChindren(newNode, (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (loop_statement) -> forall\n", __LINE__);
	}
#line 3287 "parser.tab.c"
    break;

  case 66: /* loop_statement: KY_FOR COPARENT expression_statement CSEMICOLON expression_statement CSEMICOLON expression CCPARENT statement  */
#line 589 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_FOR, "for");

		if( (yyvsp[-6].node) != NULL){
			attachNode(newNode, 1, (yyvsp[-6].node));
			applyParentAllChindren(newNode, (yyvsp[-6].node));
		}
			
		
		if( (yyvsp[-4].node) != NULL){
			attachNode(newNode, 1, (yyvsp[-4].node));
			applyParentAllChindren(newNode, (yyvsp[-4].node));
		}
			
		
		if( (yyvsp[-2].node) != NULL){
			attachNode(newNode, 1, (yyvsp[-2].node));
			applyParentAllChindren(newNode, (yyvsp[-2].node));
		}
			
	
		attachNode(newNode, 1, (yyvsp[0].node));
		applyParentAllChindren(newNode, (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (loop_statement) -> for\n", __LINE__);
	}
#line 3319 "parser.tab.c"
    break;

  case 67: /* if_statement: KY_IF COPARENT expression CCPARENT statement  */
#line 620 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_IF, "if");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));
		applyParentAllChindren(newNode, (yyvsp[-2].node));
		applyParentAllChindren(newNode, (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (if_statement) -> if\n", __LINE__);
	}
#line 3333 "parser.tab.c"
    break;

  case 68: /* if_statement: KY_IF COPARENT expression CCPARENT statement else_statement  */
#line 630 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_IF, "if");
		attachNode(newNode, 3, (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node));
		applyParentAllChindren(newNode, (yyvsp[-3].node));
		applyParentAllChindren(newNode, (yyvsp[-1].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (if_statement) -> if\n", __LINE__);
	}
#line 3347 "parser.tab.c"
    break;

  case 69: /* else_statement: KY_ELSE statement  */
#line 643 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ELSE, "else");
		attachNode(newNode, 1, (yyvsp[0].node));
		applyParentAllChindren(newNode, (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (else_statement) -> else\n", __LINE__);
	}
#line 3360 "parser.tab.c"
    break;

  case 70: /* op_log_and_operation: op_log_and_operation OP_LOG_AND op_log_or_operation  */
#line 655 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_AND, "log_and");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (op_log_and_operation) -> op_log_and_operation OP_LOG_AND op_log_or_operation\n", __LINE__);
	}
#line 3372 "parser.tab.c"
    break;

  case 71: /* op_log_and_operation: op_log_or_operation  */
#line 663 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (op_log_and_operation) -> op_log_or_operation\n", __LINE__);
	}
#line 3381 "parser.tab.c"
    break;

  case 72: /* op_log_or_operation: op_log_or_operation OP_LOG_OR op_neg_operation  */
#line 671 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_OR, "log_or");
		attachNode(newNode, 2, (yyvsp[-2].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (op_log_or_operation) -> op_log_or_operation OP_LOG_OR op_neg_operation\n", __LINE__);
	}
#line 3393 "parser.tab.c"
    break;

  case 73: /* op_log_or_operation: op_neg_operation  */
#line 679 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (op_log_or_operation) -> op_neg_operation\n", __LINE__);
	}
#line 3402 "parser.tab.c"
    break;

  case 74: /* op_neg_operation: OP_LOG_NEG op_neg_operation  */
#line 687 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_NEG, "log_neg");
		attachNode(newNode, 1, (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (op_neg_operation) -> OP_LOG_NEG op_neg_operation\n", __LINE__);
	}
#line 3414 "parser.tab.c"
    break;

  case 75: /* op_neg_operation: op_comp_operation  */
#line 695 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (op_neg_operation) -> op_comp_operation\n", __LINE__);
	}
#line 3423 "parser.tab.c"
    break;

  case 76: /* op_comp_operation: op_comp_operation OP_COMP expression_or_arith  */
#line 703 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_COMP, "op_comp");
		attachNode(newNode, 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (op_comp_operation) -> op_comp_operation OP_COMP expression_or_arith\n", __LINE__);
	}
#line 3435 "parser.tab.c"
    break;

  case 77: /* op_comp_operation: expression_or_arith  */
#line 711 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (op_comp_operation) -> expression_or_arith\n", __LINE__);
	}
#line 3444 "parser.tab.c"
    break;

  case 78: /* expression_or_arith: simple_arith_expression  */
#line 719 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (expression_or_arith) -> simple_arith_expression\n", __LINE__);
	}
#line 3453 "parser.tab.c"
    break;

  case 79: /* expression_or_arith: set_in_expression  */
#line 724 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (expression_or_arith) -> set_in_expression\n", __LINE__);
	}
#line 3462 "parser.tab.c"
    break;

  case 80: /* expression_or_arith: call_set_expression  */
#line 729 "parser.y"
        {
		(yyval.node) = (yyvsp[0].node);
		DEBUG_B("[#%d] (expression_or_arith) -> call_set_expression\n", __LINE__);
	}
#line 3471 "parser.tab.c"
    break;

  case 81: /* set_statement: KY_WRITE COPARENT simple_arith_expression CCPARENT CSEMICOLON  */
#line 737 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_WRITE, "write");
		attachNode(newNode, 1, (yyvsp[-2].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_statement) -> write\n", __LINE__);
	}
#line 3483 "parser.tab.c"
    break;

  case 82: /* set_statement: KY_WRITELN COPARENT simple_arith_expression CCPARENT CSEMICOLON  */
#line 745 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_WRITELN, "writeln");
		attachNode(newNode, 1, (yyvsp[-2].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_statement) -> writeln\n", __LINE__);
	}
#line 3495 "parser.tab.c"
    break;

  case 83: /* set_statement: KY_READ COPARENT set_func_argument CCPARENT CSEMICOLON  */
#line 753 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_READ, "read");
		attachNode(newNode, 1, (yyvsp[-2].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_statement) -> read\n", __LINE__);
	}
#line 3507 "parser.tab.c"
    break;

  case 84: /* set_func_argument: CHAR  */
#line 764 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ARGUMENT, "set_func_argument");
		attachNode(newNode, 1, (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_func_parameter) -> CHAR\n", __LINE__);
	}
#line 3519 "parser.tab.c"
    break;

  case 85: /* set_func_argument: STRING  */
#line 772 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ARGUMENT, "set_func_argument");
		attachNode(newNode, 1, (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_func_parameter) -> STRING\n", __LINE__);
	}
#line 3531 "parser.tab.c"
    break;

  case 86: /* set_func_argument: ID  */
#line 780 "parser.y"
        {
		struct node_s *newNode = createNode(NODE_ARGUMENT, "set_func_argument");
		attachNode(newNode, 1, (yyvsp[0].node));

		(yyval.node) = newNode;
		DEBUG_B("[#%d] (set_func_parameter) -> ID\n", __LINE__);
	}
#line 3543 "parser.tab.c"
    break;


#line 3547 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 790 "parser.y"


void yyerror(const char *s) {
	fprintf(stderr, "Erro sintático em: linha %d, coluna %d:\n", line_number, colu_number);
	fprintf(stderr, "-> Mensagem: %s\n", s);
	++syntaxErrors;
}
