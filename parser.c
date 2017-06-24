/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 13 "parser.y" /* yacc.c:339  */


#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
#include "literalsTable.h"
#include "symbolsTable.h"

#define VARIABLE 0
#define FUNCTION 1

int yylex(void);
void yyerror(char const *s);

void verify_symbol(int, BT*, int, int, int);
void new_symbol(int, BT*, int, int, int);

extern int yylineno;

BT *tree;
SymbolsTable *ft;
SymbolsTable *vt;
LiteralsTable *lt;

int aridadeDeclarada = 0;
int aridadeChamada = 0;
int escopo = 0;


#line 96 "parser.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.h".  */
#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    VOID = 259,
    COMMA = 260,
    SEMI = 261,
    STRING = 262,
    IF = 263,
    WHILE = 264,
    INPUT = 265,
    OUTPUT = 266,
    WRITE = 267,
    ASSIGN = 268,
    RETURN = 269,
    LPAREN = 270,
    LBRACE = 271,
    LBRACK = 272,
    NUM = 273,
    ID = 274,
    ELSE = 275,
    RPAREN = 276,
    RBRACE = 277,
    RBRACK = 278,
    NEQ = 279,
    EQ = 280,
    LT = 281,
    LE = 282,
    GT = 283,
    GE = 284,
    PLUS = 285,
    MINUS = 286,
    TIMES = 287,
    OVER = 288
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef BT* YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 181 "parser.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
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
#define YYLAST   122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  34
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    69,    69,    73,    74,    78,    82,    86,    90,    91,
      95,    96,   100,   101,   105,   106,   110,   111,   115,   116,
     120,   121,   125,   129,   133,   134,   138,   139,   140,   141,
     142,   146,   150,   151,   152,   156,   157,   161,   165,   166,
     170,   171,   172,   176,   180,   184,   188,   192,   193,   197,
     198,   203,   204,   205,   206,   207,   208,   213,   214,   215,
     216,   217,   218,   219,   220,   221
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "VOID", "COMMA", "SEMI", "STRING",
  "IF", "WHILE", "INPUT", "OUTPUT", "WRITE", "ASSIGN", "RETURN", "LPAREN",
  "LBRACE", "LBRACK", "NUM", "ID", "ELSE", "RPAREN", "RBRACE", "RBRACK",
  "NEQ", "EQ", "LT", "LE", "GT", "GE", "PLUS", "MINUS", "TIMES", "OVER",
  "$accept", "program", "func-decl-list", "func-decl", "func-header",
  "func-body", "opt-var-decl", "ret-type", "params", "param-list", "param",
  "var-decl-list", "var-decl", "block", "opt-stmt-list", "stmt-list",
  "stmt", "assign-stmt", "lval", "if-stmt", "while-stmt", "return-stmt",
  "func-call", "input-call", "output-call", "write-call", "user-func-call",
  "opt-arg-list", "arg-list", "bool-expr", "arith-expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288
};
# endif

#define YYPACT_NINF -96

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-96)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       2,   -96,   -96,     9,     2,   -96,   -14,    -4,   -96,   -96,
      20,   -96,    12,    10,   -96,    20,   -96,    16,    -3,    -1,
      59,   -96,    23,   -96,    26,    47,   -96,   -96,    36,   -96,
      40,    51,    54,    75,    -2,    -5,   -96,   -96,    78,   -96,
     -96,   -96,    86,   -96,   -96,   -96,    76,   -96,    92,    73,
      79,    79,    79,    93,   -96,    84,    79,   -96,   -96,   -96,
     -96,     1,    79,     6,    79,   -96,    80,   -96,    95,    81,
      55,    83,    18,    85,    87,    32,   -96,    79,    79,    79,
      79,    88,   100,    44,    89,    90,     5,   -96,   -96,    91,
      79,    79,    79,    79,    79,    79,    91,   -96,   -96,   -96,
     -96,     8,     8,   -96,   -96,   -96,    79,   -96,   -96,   -96,
     -96,    94,    44,    44,    44,    44,    44,    44,   -96,    44,
      96,    91,   -96,   -96
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    10,    11,     0,     2,     3,     0,     0,     1,     4,
       8,     5,     0,     0,    24,     9,    18,     0,     0,     0,
      23,    19,     0,    12,     0,    13,    14,    20,     0,     7,
       0,     0,     0,     0,     0,    32,    25,    26,     0,    27,
      28,    29,     0,    40,    41,    42,    16,     6,     0,     0,
       0,     0,     0,     0,    38,     0,     0,    57,    59,    58,
      60,     0,    47,     0,     0,    30,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,     0,     0,
       0,     0,    48,    49,     0,     0,     0,    17,    21,     0,
       0,     0,     0,     0,     0,     0,     0,    44,    45,    43,
      61,    62,    63,    64,    65,    46,     0,    33,    34,    31,
      24,    35,    56,    55,    51,    52,    53,    54,    37,    50,
       0,     0,    22,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,   -96,   106,   -96,   -96,   -96,   -96,   -96,   -96,
      63,   -96,   101,   -95,     7,   -96,   -96,   -96,    99,   -96,
     -96,   -96,   -96,   -96,   -96,   -96,   102,   -96,   -96,    64,
     -34
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    11,    14,     7,    24,    25,
      26,    15,    16,   111,    19,    20,    36,    37,    58,    39,
      40,    41,    42,    59,    43,    44,    60,    81,    82,    69,
      70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      61,   118,    10,    27,    54,     1,     2,    76,    55,     8,
      62,   109,    63,    56,    28,    12,    57,    35,    72,    22,
      23,    29,    75,    13,    84,    85,   123,    17,    83,    18,
      86,    77,    78,    79,    80,    77,    78,    79,    80,    97,
      79,    80,    46,   101,   102,   103,   104,    47,    77,    78,
      79,    80,    48,   100,    49,    50,   112,   113,   114,   115,
     116,   117,    77,    78,    79,    80,    51,    30,    31,    52,
      32,    33,   119,    34,    77,    78,    79,    80,    35,    90,
      91,    92,    93,    94,    95,    77,    78,    79,    80,    55,
      53,    64,    65,    66,    56,    22,    68,    57,    35,    74,
      73,    88,    89,    87,    96,   106,    98,   110,    99,   105,
       9,    67,   107,   108,   121,    71,    21,   120,   122,    38,
       0,     0,    45
};

static const yytype_int8 yycheck[] =
{
      34,    96,    16,     6,     6,     3,     4,     6,    10,     0,
      15,     6,    17,    15,    17,    19,    18,    19,    52,     3,
       4,    22,    56,     3,    18,    19,   121,    15,    62,    19,
      64,    30,    31,    32,    33,    30,    31,    32,    33,    21,
      32,    33,    19,    77,    78,    79,    80,    21,    30,    31,
      32,    33,     5,    21,    18,    15,    90,    91,    92,    93,
      94,    95,    30,    31,    32,    33,    15,     8,     9,    15,
      11,    12,   106,    14,    30,    31,    32,    33,    19,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    10,
      15,    13,     6,    17,    15,     3,    23,    18,    19,    15,
       7,     6,    21,    23,    21,     5,    21,    16,    21,    21,
       4,    48,    23,    23,    20,    51,    15,   110,    22,    20,
      -1,    -1,    20
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    35,    36,    37,    38,    41,     0,    37,
      16,    39,    19,     3,    40,    45,    46,    15,    19,    48,
      49,    46,     3,     4,    42,    43,    44,     6,    17,    22,
       8,     9,    11,    12,    14,    19,    50,    51,    52,    53,
      54,    55,    56,    58,    59,    60,    19,    21,     5,    18,
      15,    15,    15,    15,     6,    10,    15,    18,    52,    57,
      60,    64,    15,    17,    13,     6,    17,    44,    23,    63,
      64,    63,    64,     7,    15,    64,     6,    30,    31,    32,
      33,    61,    62,    64,    18,    19,    64,    23,     6,    21,
      24,    25,    26,    27,    28,    29,    21,    21,    21,    21,
      21,    64,    64,    64,    64,    21,     5,    23,    23,     6,
      16,    47,    64,    64,    64,    64,    64,    64,    47,    64,
      48,    20,    22,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    34,    35,    36,    36,    37,    38,    39,    40,    40,
      41,    41,    42,    42,    43,    43,    44,    44,    45,    45,
      46,    46,    47,    48,    49,    49,    50,    50,    50,    50,
      50,    51,    52,    52,    52,    53,    53,    54,    55,    55,
      56,    56,    56,    57,    58,    59,    60,    61,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     5,     4,     0,     1,
       1,     1,     1,     1,     1,     3,     2,     4,     1,     2,
       3,     6,     3,     1,     0,     2,     1,     1,     1,     1,
       2,     4,     1,     4,     4,     5,     7,     5,     2,     3,
       1,     1,     1,     3,     4,     4,     4,     0,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      YY_LAC_DISCARD ("YYBACKUP");                              \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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

/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return 1 if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yytype_int16 **yybottom,
                      yytype_int16 *yybottom_no_free,
                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
{
  YYSIZE_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYSIZE_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYSIZE_T yyalloc = 2 * yysize_new;
      yytype_int16 *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return 1;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                         \
do {                                                             \
  if (!yy_lac_established)                                       \
    {                                                            \
      YYDPRINTF ((stderr,                                        \
                  "LAC: initial context established for %s\n",   \
                  yytname[yytoken]));                            \
      yy_lac_established = 1;                                    \
      {                                                          \
        int yy_lac_status =                                      \
          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
        if (yy_lac_status == 2)                                  \
          goto yyexhaustedlab;                                   \
        if (yy_lac_status == 1)                                  \
          goto yyerrlab;                                         \
      }                                                          \
    }                                                            \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      if (yydebug)                                                       \
        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
                   Event "\n");                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return 2 if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  yytype_int16 *yyes_prev = yyssp;
  yytype_int16 *yyesp = yyes_prev;
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
  if (yytoken == YYUNDEFTOK)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          yyrule = yydefact[*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      {
        YYSIZE_T yylen = yyr2[yyrule];
        YYDPRINTF ((stderr, " R%d", yyrule - 1));
        if (yyesp != yyes_prev)
          {
            YYSIZE_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yylen -= yysize;
                yyesp = yyes_prev;
              }
          }
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      {
        int yystate;
        {
          int yylhs = yyr1[yyrule] - YYNTOKENS;
          yystate = yypgoto[yylhs] + *yyesp;
          if (yystate < 0 || YYLAST < yystate
              || yycheck[yystate] != *yyesp)
            yystate = yydefgoto[yylhs];
          else
            yystate = yytable[yystate];
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            *yyesp = yystate;
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return 2;
              }
            *++yyesp = yystate;
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store or if
   yy_lac returned 2.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyesa, yytype_int16 **yyes,
                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          int yyx;

          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
              {
                {
                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
                                              yyssp, yyx);
                  if (yy_lac_status == 2)
                    return 2;
                  if (yy_lac_status == 1)
                    continue;
                }
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
# if YYDEBUG
      else if (yydebug)
        YYFPRINTF (stderr, "No expected tokens.\n");
# endif
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

    yytype_int16 yyesa[20];
    yytype_int16 *yyes;
    YYSIZE_T yyes_capacity;

  int yy_lac_established = 0;
  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  yyes = yyesa;
  yyes_capacity = sizeof yyesa / sizeof *yyes;
  if (YYMAXDEPTH < yyes_capacity)
    yyes_capacity = YYMAXDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      YY_LAC_ESTABLISH;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  YY_LAC_DISCARD ("shift");

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
          case 2:
#line 69 "parser.y" /* yacc.c:1661  */
    { tree = (yyvsp[0]); }
#line 1577 "parser.c" /* yacc.c:1661  */
    break;

  case 3:
#line 73 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(FUNC_DECL_LIST_NODE, 1, (yyvsp[0])); }
#line 1583 "parser.c" /* yacc.c:1661  */
    break;

  case 4:
#line 74 "parser.y" /* yacc.c:1661  */
    { (yyval) = add_child((yyval), (yyvsp[0])); }
#line 1589 "parser.c" /* yacc.c:1661  */
    break;

  case 5:
#line 78 "parser.y" /* yacc.c:1661  */
    { escopo++; (yyval) = new_node(FUNC_DECL_NODE, 2, (yyvsp[-1]), (yyvsp[0])); }
#line 1595 "parser.c" /* yacc.c:1661  */
    break;

  case 6:
#line 82 "parser.y" /* yacc.c:1661  */
    { new_symbol(FUNCTION, (yyvsp[-3]), yylineno, -1, aridadeDeclarada); aridadeDeclarada = 0;  (yyval) = new_node(FUNC_HEADER_NODE, 3, (yyvsp[-4]), new_leaf(ID_NODE, get_symbol_index(ft, get_name(ft, (yyvsp[-3])->data), -1)), (yyvsp[-1])); }
#line 1601 "parser.c" /* yacc.c:1661  */
    break;

  case 7:
#line 86 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(FUNC_BODY_NODE, 2, (yyvsp[-2]), (yyvsp[-1])); }
#line 1607 "parser.c" /* yacc.c:1661  */
    break;

  case 8:
#line 90 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(VAR_LIST_NODE, 0); }
#line 1613 "parser.c" /* yacc.c:1661  */
    break;

  case 9:
#line 91 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1619 "parser.c" /* yacc.c:1661  */
    break;

  case 10:
#line 95 "parser.y" /* yacc.c:1661  */
    { (yyval) = create_node(INT_NODE); }
#line 1625 "parser.c" /* yacc.c:1661  */
    break;

  case 11:
#line 96 "parser.y" /* yacc.c:1661  */
    { (yyval) = create_node(VOID_NODE); }
#line 1631 "parser.c" /* yacc.c:1661  */
    break;

  case 12:
#line 100 "parser.y" /* yacc.c:1661  */
    { (yyval) = create_node(VOID_NODE); }
#line 1637 "parser.c" /* yacc.c:1661  */
    break;

  case 13:
#line 101 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1643 "parser.c" /* yacc.c:1661  */
    break;

  case 14:
#line 105 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(PARAM_NODE, 1, (yyvsp[0])); }
#line 1649 "parser.c" /* yacc.c:1661  */
    break;

  case 15:
#line 106 "parser.y" /* yacc.c:1661  */
    { (yyval) = add_child((yyval), (yyvsp[0])); }
#line 1655 "parser.c" /* yacc.c:1661  */
    break;

  case 16:
#line 110 "parser.y" /* yacc.c:1661  */
    { aridadeDeclarada++; new_symbol(VARIABLE, (yyvsp[0]), yylineno, escopo, -1); (yyval) = new_leaf(SVAR_NODE, get_symbol_index(vt, get_name(vt, (yyvsp[0])->data), escopo)); }
#line 1661 "parser.c" /* yacc.c:1661  */
    break;

  case 17:
#line 111 "parser.y" /* yacc.c:1661  */
    { aridadeDeclarada++; new_symbol(VARIABLE, (yyvsp[-2]), yylineno, escopo, -1); (yyval) = new_leaf(CVAR_NODE, get_symbol_index(vt, get_name(vt, (yyvsp[-2])->data), escopo)); }
#line 1667 "parser.c" /* yacc.c:1661  */
    break;

  case 18:
#line 115 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(VAR_LIST_NODE, 1, (yyvsp[0])); }
#line 1673 "parser.c" /* yacc.c:1661  */
    break;

  case 19:
#line 116 "parser.y" /* yacc.c:1661  */
    { (yyval) = add_child((yyval), (yyvsp[0])); }
#line 1679 "parser.c" /* yacc.c:1661  */
    break;

  case 20:
#line 120 "parser.y" /* yacc.c:1661  */
    { new_symbol(VARIABLE, (yyvsp[-1]), yylineno, escopo, -1); (yyval) = new_leaf(SVAR_NODE, get_symbol_index(vt, get_name(vt, (yyvsp[-1])->data), escopo));  }
#line 1685 "parser.c" /* yacc.c:1661  */
    break;

  case 21:
#line 121 "parser.y" /* yacc.c:1661  */
    { new_symbol(VARIABLE, (yyvsp[-4]), yylineno, escopo, -1); BT* var_dec_node = new_leaf(CVAR_NODE, get_symbol_index(vt, get_name(vt, (yyvsp[-4])->data), escopo)); (yyval) = add_child(var_dec_node, new_leaf(NUM_NODE, (yyvsp[-2])->data)); }
#line 1691 "parser.c" /* yacc.c:1661  */
    break;

  case 22:
#line 125 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 1697 "parser.c" /* yacc.c:1661  */
    break;

  case 23:
#line 129 "parser.y" /* yacc.c:1661  */
    { }
#line 1703 "parser.c" /* yacc.c:1661  */
    break;

  case 24:
#line 133 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(STMT_LIST_NODE, 0); }
#line 1709 "parser.c" /* yacc.c:1661  */
    break;

  case 25:
#line 134 "parser.y" /* yacc.c:1661  */
    { (yyval) = add_child((yyval), (yyvsp[0])); }
#line 1715 "parser.c" /* yacc.c:1661  */
    break;

  case 26:
#line 138 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1721 "parser.c" /* yacc.c:1661  */
    break;

  case 27:
#line 139 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1727 "parser.c" /* yacc.c:1661  */
    break;

  case 28:
#line 140 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1733 "parser.c" /* yacc.c:1661  */
    break;

  case 29:
#line 141 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1739 "parser.c" /* yacc.c:1661  */
    break;

  case 30:
#line 142 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 1745 "parser.c" /* yacc.c:1661  */
    break;

  case 31:
#line 146 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(ASSIGN_NODE, 2, (yyvsp[-3]), (yyvsp[-1])); }
#line 1751 "parser.c" /* yacc.c:1661  */
    break;

  case 32:
#line 150 "parser.y" /* yacc.c:1661  */
    { verify_symbol(VARIABLE, (yyvsp[0]), yylineno, escopo, -1); (yyval) = new_leaf(SVAR_NODE, get_symbol_index(vt, get_name(vt, (yyvsp[0])->data), escopo)); }
#line 1757 "parser.c" /* yacc.c:1661  */
    break;

  case 33:
#line 151 "parser.y" /* yacc.c:1661  */
    { verify_symbol(VARIABLE, (yyvsp[-3]), yylineno, escopo, -1); }
#line 1763 "parser.c" /* yacc.c:1661  */
    break;

  case 34:
#line 152 "parser.y" /* yacc.c:1661  */
    { verify_symbol(VARIABLE, (yyvsp[-3]), yylineno, escopo, -1);  verify_symbol(VARIABLE, (yyvsp[-1]), yylineno, escopo, -1); BT* lval_node = new_leaf(CVAR_NODE, get_symbol_index(vt, get_name(vt, (yyvsp[-3])->data), escopo)); add_child(lval_node, (yyval) = new_leaf(SVAR_NODE, get_symbol_index(vt, get_name(vt, (yyvsp[-1])->data), escopo))); (yyval) = lval_node; }
#line 1769 "parser.c" /* yacc.c:1661  */
    break;

  case 35:
#line 156 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(IF_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1775 "parser.c" /* yacc.c:1661  */
    break;

  case 36:
#line 157 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(IF_NODE, 3, (yyvsp[-4]), (yyvsp[-2]), (yyvsp[0])); }
#line 1781 "parser.c" /* yacc.c:1661  */
    break;

  case 37:
#line 161 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(WHILE_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1787 "parser.c" /* yacc.c:1661  */
    break;

  case 38:
#line 165 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(RETURN_NODE, 0); }
#line 1793 "parser.c" /* yacc.c:1661  */
    break;

  case 39:
#line 166 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(RETURN_NODE, 1, (yyvsp[-1])); }
#line 1799 "parser.c" /* yacc.c:1661  */
    break;

  case 40:
#line 170 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1805 "parser.c" /* yacc.c:1661  */
    break;

  case 41:
#line 171 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1811 "parser.c" /* yacc.c:1661  */
    break;

  case 42:
#line 172 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1817 "parser.c" /* yacc.c:1661  */
    break;

  case 43:
#line 176 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-2]); }
#line 1823 "parser.c" /* yacc.c:1661  */
    break;

  case 44:
#line 180 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(OUTPUT_NODE, 1, (yyvsp[-1])); }
#line 1829 "parser.c" /* yacc.c:1661  */
    break;

  case 45:
#line 184 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(WRITE_NODE, 1, new_leaf(STRING_NODE, get_literal_index(lt, get_literal(lt, (yyvsp[-1])->data)))); }
#line 1835 "parser.c" /* yacc.c:1661  */
    break;

  case 46:
#line 188 "parser.y" /* yacc.c:1661  */
    { verify_symbol(FUNCTION, (yyvsp[-3]), yylineno, -1, aridadeChamada); aridadeChamada = 0; BT* func_call = new_leaf(FCALL_NODE, get_symbol_index(ft, get_name(ft, (yyvsp[-3])->data), escopo)); (yyval) = add_child(func_call, (yyvsp[-1])); }
#line 1841 "parser.c" /* yacc.c:1661  */
    break;

  case 47:
#line 192 "parser.y" /* yacc.c:1661  */
    { }
#line 1847 "parser.c" /* yacc.c:1661  */
    break;

  case 48:
#line 193 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1853 "parser.c" /* yacc.c:1661  */
    break;

  case 49:
#line 197 "parser.y" /* yacc.c:1661  */
    { aridadeChamada++; (yyval) = new_node(ARG_LIST_NODE, 1, (yyvsp[0])); }
#line 1859 "parser.c" /* yacc.c:1661  */
    break;

  case 50:
#line 198 "parser.y" /* yacc.c:1661  */
    { aridadeChamada++; (yyval) = add_child((yyval), (yyvsp[0])); }
#line 1865 "parser.c" /* yacc.c:1661  */
    break;

  case 51:
#line 203 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(LT_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1871 "parser.c" /* yacc.c:1661  */
    break;

  case 52:
#line 204 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(LEQ_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1877 "parser.c" /* yacc.c:1661  */
    break;

  case 53:
#line 205 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(GT_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1883 "parser.c" /* yacc.c:1661  */
    break;

  case 54:
#line 206 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(GEQ_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1889 "parser.c" /* yacc.c:1661  */
    break;

  case 55:
#line 207 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(EQ_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1895 "parser.c" /* yacc.c:1661  */
    break;

  case 56:
#line 208 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(NEQ_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1901 "parser.c" /* yacc.c:1661  */
    break;

  case 57:
#line 213 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_leaf(NUM_NODE, (yyvsp[0])->data); }
#line 1907 "parser.c" /* yacc.c:1661  */
    break;

  case 58:
#line 214 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1913 "parser.c" /* yacc.c:1661  */
    break;

  case 59:
#line 215 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1919 "parser.c" /* yacc.c:1661  */
    break;

  case 60:
#line 216 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[0]); }
#line 1925 "parser.c" /* yacc.c:1661  */
    break;

  case 61:
#line 217 "parser.y" /* yacc.c:1661  */
    { (yyval) = (yyvsp[-1]); }
#line 1931 "parser.c" /* yacc.c:1661  */
    break;

  case 62:
#line 218 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(PLUS_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1937 "parser.c" /* yacc.c:1661  */
    break;

  case 63:
#line 219 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(MINUS_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1943 "parser.c" /* yacc.c:1661  */
    break;

  case 64:
#line 220 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(TIMES_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1949 "parser.c" /* yacc.c:1661  */
    break;

  case 65:
#line 221 "parser.y" /* yacc.c:1661  */
    { (yyval) = new_node(OVER_NODE, 2, (yyvsp[-2]), (yyvsp[0])); }
#line 1955 "parser.c" /* yacc.c:1661  */
    break;


#line 1959 "parser.c" /* yacc.c:1661  */
        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyesa, &yyes, &yyes_capacity, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 224 "parser.y" /* yacc.c:1906  */


int main() {
    yydebug = 0; // Toggle this variable to enter debug mode.

    vt = create_sym_table();
    ft = create_sym_table();
    lt = create_lit_table();


    if (yyparse() == 0) {
        printf("PARSE SUCCESSFUL!\n");
        //printf("AST of given expression:\n");
        //print_tree(tree);
        //print_dot(tree);
        free_tree(tree);
    }

    free_literals_table(lt);
    free_sym_table(vt);
    free_sym_table(ft);

    return 0;
}

//precisa recriar as funcoes aqui chamadas, ex getSymbol name vai usar das funcoes lookup_var e get_name da biblioteca que o prof deu
void verify_symbol(int type, BT* node, int line, int escopo, int aridadeChamada) {
  char* node_name = node2str(node);

  if(type == VARIABLE){
		if(!lookup_var(vt, node_name)){
			printf("SEMANTIC ERROR (%d): variable '%s' was not declared.\n", line, node_name);
			exit(1);
		}
  }

	if(type == FUNCTION){
		if(!lookup_var(ft, node_name)){
			printf("SEMANTIC ERROR (%d): function '%s' was not declared.\n", line, node_name);
			exit(1);
		}

		int aridadeDeclarada = get_symbol_arity(ft, node_name);

		if(aridadeChamada != aridadeDeclarada){
			printf("SEMANTIC ERROR (%d): function '%s' was called with %d arguments but declared with %d parameters.\n", line, node_name, aridadeChamada, aridadeDeclarada);
			exit(1);
		}
	}
}

void new_symbol(int type, BT* node, int line, int escopo, int aridadeDeclarada) {
  char* node_name = node2str(node);

  if(type == VARIABLE){
		if (lookup_var(vt, node_name) && escopo == get_symbol_escope(vt, node_name)) {
        printf("SEMANTIC ERROR (%d): variable '%s' already declared at line %d.\n",
            line, node_name, lookup_var(vt, node_name));
        exit(1);
    }

    add_var(vt, node_name, line, escopo, aridadeDeclarada);
  }

  if(type == FUNCTION){
      if (lookup_var(ft, node_name)) {
        printf("SEMANTIC ERROR (%d): function '%s' already declared at line %d.\n",
            line, node_name, lookup_var(ft, node_name));
        exit(1);
    }

    add_var(ft, node_name, line, escopo, aridadeDeclarada);

  }
}

//Trata erro e sai do programa
void yyerror (char const *s) {
	printf("PARSE ERROR (%d): %s\n", yylineno, s);
	exit(0);
}

//tem que rever os vt e ft, tinha colocado tudo um só
