
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "syntaxique.y"

  #include <stdio.h>
  #include "syntaxique.tab.h"  


  int nb_ligne = 1;
  char SaveType[20];
  int langBIB = 0;
  int IOBIB = 0;
  int checkBIB = 0 ;
  int checkInput = 0 ;
  int checkWrite = 0 ;
  int ValueCount = 0;
  int CurrentArraySize = 0;



/* Line 189 of yacc.c  */
#line 91 "syntaxique.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BIB_LANG = 258,
     IMPORT = 259,
     BIB_IO = 260,
     pvg = 261,
     err = 262,
     FIN_PG = 263,
     COMMA = 264,
     ACO_R = 265,
     ACO_C = 266,
     ADDOP = 267,
     MULOP = 268,
     DIVOP = 269,
     START_PG = 270,
     KEY_WORD_PDec = 271,
     KEY_WORD_Programme = 272,
     Equal = 273,
     PRINT = 274,
     Print_CORE = 275,
     FOR = 276,
     ENDFOR = 277,
     DO = 278,
     R_BRCKET = 279,
     L_BRCKET = 280,
     SEPAR = 281,
     FINAL = 282,
     ASSIGN = 283,
     L_PARENT = 284,
     R_PARENT = 285,
     ORFER = 286,
     INCR_OP = 287,
     DECR_OP = 288,
     SUP = 289,
     INF = 290,
     SUP_EG = 291,
     INF_EG = 292,
     NOT_EQUAL = 293,
     REFER = 294,
     EQ_OP = 295,
     INPUT = 296,
     WRITE = 297,
     FS = 298,
     space = 299,
     IF = 300,
     ELSE = 301,
     ENDIF = 302,
     NOT = 303,
     TYPE_FLOAT = 304,
     TYPE_INT = 305,
     Idf = 306,
     INT_CONST = 307,
     FLOAT_CONST = 308,
     core_write = 309
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 17 "syntaxique.y"
 
  int entier;
  char* str;
  float Tfloat;
  struct Node* node;



/* Line 214 of yacc.c  */
#line 190 "syntaxique.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 202 "syntaxique.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   240

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNRULES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    10,    11,    12,    16,    17,    21,
      24,    27,    29,    30,    34,    37,    39,    43,    50,    57,
      61,    65,    67,    69,    71,    74,    79,    83,    87,    91,
      98,   102,   106,   110,   112,   114,   116,   118,   122,   125,
     127,   129,   131,   133,   135,   140,   151,   159,   161,   165,
     169,   173,   177,   181,   185,   189,   193,   197,   201,   205,
     208,   210,   212,   214,   222,   230,   234,   238,   242,   248,
     252,   256,   260,   266,   270,   274,   280,   284,   287,   290,
     292,   294,   296,   299
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    57,    62,    64,    -1,     4,    58,    -1,
      -1,    -1,     3,    59,    61,    -1,    -1,     5,    60,    61,
      -1,     6,    57,    -1,    17,    63,    -1,    51,    -1,    -1,
      16,    65,    73,    -1,    65,    66,    -1,    66,    -1,    72,
      67,     6,    -1,    27,    72,    51,    18,    52,     6,    -1,
      27,    72,    51,    18,    53,     6,    -1,    67,    26,    68,
      -1,    67,    26,    70,    -1,    68,    -1,    70,    -1,    51,
      -1,    51,    69,    -1,    69,    25,    52,    24,    -1,    25,
      52,    24,    -1,    51,    18,    52,    -1,    51,    18,    53,
      -1,    51,    69,    18,    25,    71,    24,    -1,    51,    18,
      51,    -1,    71,     9,    52,    -1,    71,     9,    53,    -1,
      52,    -1,    53,    -1,    50,    -1,    49,    -1,    15,    74,
       8,    -1,    74,    75,    -1,    75,    -1,    76,    -1,    77,
      -1,    81,    -1,    78,    -1,    51,    28,    82,     6,    -1,
      21,    29,    76,    80,     6,    82,    30,    23,    74,    22,
      -1,    45,    29,    80,    30,    23,    74,    79,    -1,    47,
      -1,    46,    74,    47,    -1,    80,    34,    80,    -1,    80,
      35,    80,    -1,    80,    18,    80,    -1,    80,    36,    80,
      -1,    80,    37,    80,    -1,    80,    38,    80,    -1,    80,
      40,    80,    -1,    80,    39,    80,    -1,    80,    31,    80,
      -1,    29,    80,    30,    -1,    48,    51,    -1,    51,    -1,
      52,    -1,    53,    -1,    42,    29,    54,     9,    51,    30,
       6,    -1,    41,    29,    54,     9,    51,    30,     6,    -1,
      82,    12,    52,    -1,    82,    12,    53,    -1,    82,    12,
      51,    -1,    82,    12,    29,    82,    30,    -1,    82,    13,
      52,    -1,    82,    13,    53,    -1,    82,    13,    51,    -1,
      82,    13,    29,    82,    30,    -1,    82,    14,    52,    -1,
      82,    14,    51,    -1,    82,    14,    29,    82,    30,    -1,
      29,    82,    30,    -1,    12,    52,    -1,    12,    53,    -1,
      51,    -1,    52,    -1,    53,    -1,    51,    32,    -1,    51,
      33,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    52,    52,    59,    60,    63,    63,    64,    64,    67,
      70,    73,    74,    77,    82,    83,    86,    87,    88,    90,
      91,    92,    93,    95,   100,   105,   106,   109,   114,   119,
     124,   133,   134,   135,   136,   139,   140,   145,   148,   149,
     152,   152,   152,   152,   155,   166,   168,   170,   171,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   190,   197,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BIB_LANG", "IMPORT", "BIB_IO", "pvg",
  "err", "FIN_PG", "COMMA", "ACO_R", "ACO_C", "ADDOP", "MULOP", "DIVOP",
  "START_PG", "KEY_WORD_PDec", "KEY_WORD_Programme", "Equal", "PRINT",
  "Print_CORE", "FOR", "ENDFOR", "DO", "R_BRCKET", "L_BRCKET", "SEPAR",
  "FINAL", "ASSIGN", "L_PARENT", "R_PARENT", "ORFER", "INCR_OP", "DECR_OP",
  "SUP", "INF", "SUP_EG", "INF_EG", "NOT_EQUAL", "REFER", "EQ_OP", "INPUT",
  "WRITE", "FS", "space", "IF", "ELSE", "ENDIF", "NOT", "TYPE_FLOAT",
  "TYPE_INT", "Idf", "INT_CONST", "FLOAT_CONST", "core_write", "$accept",
  "Z", "IMP", "BIB", "$@1", "$@2", "T", "PROGRMME_NAME", "PROG_NAME",
  "P_DECL", "DECLARATIONS", "DECLARATION", "NAMES", "VARIABLE", "ARRAY",
  "INIT", "VALUES", "TYPE", "DEBUT_PROGRAMME", "STATEMENTS", "STATEMENT",
  "AFFECTATIONS", "for_statement", "if_statement", "optional_else",
  "EXPRESSION", "printf_statement", "AFFECTATION", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    59,    58,    60,    58,    61,
      62,    63,    63,    64,    65,    65,    66,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    71,    71,    71,    71,    72,    72,    73,    74,    74,
      75,    75,    75,    75,    76,    77,    78,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     2,     0,     0,     3,     0,     3,     2,
       2,     1,     0,     3,     2,     1,     3,     6,     6,     3,
       3,     1,     1,     1,     2,     4,     3,     3,     3,     6,
       3,     3,     3,     1,     1,     1,     1,     3,     2,     1,
       1,     1,     1,     1,     4,    10,     7,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       1,     1,     1,     7,     7,     3,     3,     3,     5,     3,
       3,     3,     5,     3,     3,     5,     3,     2,     2,     1,
       1,     1,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     5,     7,     3,     1,    12,     0,
       0,     0,    11,    10,     0,     2,     4,     6,     8,     0,
      36,    35,     0,    15,     0,     9,     0,     0,    14,    13,
      23,     0,    21,    22,     0,     0,     0,     0,     0,     0,
       0,    39,    40,    41,    43,    42,     0,     0,    24,    16,
       0,     0,     0,     0,     0,     0,     0,    37,    38,    30,
      27,    28,     0,     0,     0,    19,    20,     0,     0,     0,
       0,     0,     0,     0,    60,    61,    62,     0,     0,     0,
      79,    80,    81,     0,    26,     0,     0,    17,    18,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78,     0,    82,    83,    44,
       0,     0,     0,    33,    34,     0,    25,     0,     0,     0,
      58,    51,     0,    57,    49,    50,    52,    53,    54,    56,
      55,    76,     0,    67,    65,    66,     0,    71,    69,    70,
       0,    74,    73,     0,    29,     0,     0,     0,     0,     0,
       0,     0,    31,    32,     0,    64,    63,     0,    47,    46,
      68,    72,    75,     0,     0,     0,    48,    45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,    10,    11,    17,     9,    13,    15,
      22,    23,    31,    32,    48,    33,   115,    24,    29,    40,
      41,    42,    43,    44,   159,    77,    45,    83
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -114
static const yytype_int16 yypact[] =
{
      20,    48,    31,    68,  -114,  -114,  -114,  -114,    60,    78,
     124,   124,  -114,  -114,   -23,  -114,    20,  -114,  -114,   -38,
    -114,  -114,    -2,  -114,   101,  -114,   112,    65,  -114,  -114,
      -4,     4,  -114,  -114,   161,   171,   173,   174,   182,    91,
      -5,  -114,  -114,  -114,  -114,  -114,    62,   149,    -3,  -114,
     101,   -35,   163,   164,   165,    16,   -10,  -114,  -114,  -114,
    -114,  -114,   189,   190,   168,  -114,  -114,   210,   211,    16,
     212,   213,    16,   175,  -114,  -114,  -114,   108,    13,   -10,
      96,  -114,  -114,   192,  -114,    88,   199,  -114,  -114,    53,
     176,   177,   119,  -114,    16,   201,    16,    16,    16,    16,
      16,    16,    16,    16,  -114,  -114,    -7,  -114,  -114,  -114,
      80,    83,    71,  -114,  -114,    11,  -114,   -10,   195,   200,
    -114,   133,    65,   159,   172,   151,    23,    32,   191,   146,
    -114,  -114,   -10,  -114,  -114,  -114,   -10,  -114,  -114,  -114,
     -10,  -114,  -114,   113,  -114,    43,   223,   226,   -13,    90,
     148,   162,  -114,  -114,   214,  -114,  -114,    65,  -114,  -114,
    -114,  -114,  -114,    65,    54,    76,  -114,  -114
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -114,  -114,   217,  -114,  -114,  -114,   224,  -114,  -114,  -114,
    -114,   216,  -114,   184,  -114,   186,  -114,   220,  -114,  -113,
     -40,   188,  -114,  -114,  -114,   -20,  -114,   -78
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      58,   106,    78,    57,    19,   110,   111,   112,    35,   148,
      49,    20,    21,    27,    46,    63,    35,    67,    68,    79,
     143,    47,    64,   131,     1,    19,    20,    21,    36,    37,
      50,     7,    38,   157,   158,   144,    36,    37,    39,   145,
      38,    80,    81,    82,   164,    72,    39,    20,    21,    89,
     165,     4,    92,     5,   149,   110,   111,   112,   150,   117,
     100,   101,   151,   103,    73,   104,   105,    74,    75,    76,
     101,    94,   103,   154,   121,    35,   123,   124,   125,   126,
     127,   128,   129,   130,    96,     8,    35,    97,    98,    99,
     100,   101,   102,   103,    14,    36,    37,    35,   167,    38,
     140,   166,   110,   111,   112,    39,    36,    37,    58,   132,
      38,    12,   136,    59,    60,    61,    39,    36,    37,    56,
     160,    38,   141,   142,    58,    58,    94,    39,   107,   108,
      16,   133,   134,   135,   137,   138,   139,    94,    95,    96,
     113,   114,    97,    98,    99,   100,   101,   102,   103,   120,
      96,    94,    30,    97,    98,    99,   100,   101,   102,   103,
     110,   111,   112,    34,    96,   152,   153,    97,    98,    99,
     100,   101,   102,   103,   110,   111,   112,    96,   161,    51,
      97,    98,    99,   100,   101,   102,   103,    99,   100,   101,
      96,   103,   162,    97,    98,    99,   100,   101,   109,   103,
      52,    62,    53,    54,   110,   111,   112,    98,    99,   100,
     101,    55,   103,    84,    39,    85,    87,    88,    70,    71,
      86,    90,    91,   116,   122,   146,    93,   118,   119,   155,
     147,   103,   156,    25,    65,    18,    66,   163,    28,    26,
      69
};

static const yytype_uint8 yycheck[] =
{
      40,    79,    12,     8,    27,    12,    13,    14,    21,   122,
       6,    49,    50,    15,    18,    18,    21,    52,    53,    29,
       9,    25,    25,    30,     4,    27,    49,    50,    41,    42,
      26,     0,    45,    46,    47,    24,    41,    42,    51,   117,
      45,    51,    52,    53,   157,    29,    51,    49,    50,    69,
     163,     3,    72,     5,   132,    12,    13,    14,   136,     6,
      37,    38,   140,    40,    48,    52,    53,    51,    52,    53,
      38,    18,    40,    30,    94,    21,    96,    97,    98,    99,
     100,   101,   102,   103,    31,    17,    21,    34,    35,    36,
      37,    38,    39,    40,    16,    41,    42,    21,    22,    45,
      29,    47,    12,    13,    14,    51,    41,    42,   148,    29,
      45,    51,    29,    51,    52,    53,    51,    41,    42,    28,
      30,    45,    51,    52,   164,   165,    18,    51,    32,    33,
       6,    51,    52,    53,    51,    52,    53,    18,    30,    31,
      52,    53,    34,    35,    36,    37,    38,    39,    40,    30,
      31,    18,    51,    34,    35,    36,    37,    38,    39,    40,
      12,    13,    14,    51,    31,    52,    53,    34,    35,    36,
      37,    38,    39,    40,    12,    13,    14,    31,    30,    18,
      34,    35,    36,    37,    38,    39,    40,    36,    37,    38,
      31,    40,    30,    34,    35,    36,    37,    38,     6,    40,
      29,    52,    29,    29,    12,    13,    14,    35,    36,    37,
      38,    29,    40,    24,    51,    25,     6,     6,    54,    54,
      52,     9,     9,    24,    23,    30,    51,    51,    51,     6,
      30,    40,     6,    16,    50,    11,    50,    23,    22,    19,
      52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    56,    57,     3,     5,    58,     0,    17,    62,
      59,    60,    51,    63,    16,    64,     6,    61,    61,    27,
      49,    50,    65,    66,    72,    57,    72,    15,    66,    73,
      51,    67,    68,    70,    51,    21,    41,    42,    45,    51,
      74,    75,    76,    77,    78,    81,    18,    25,    69,     6,
      26,    18,    29,    29,    29,    29,    28,     8,    75,    51,
      52,    53,    52,    18,    25,    68,    70,    52,    53,    76,
      54,    54,    29,    48,    51,    52,    53,    80,    12,    29,
      51,    52,    53,    82,    24,    25,    52,     6,     6,    80,
       9,     9,    80,    51,    18,    30,    31,    34,    35,    36,
      37,    38,    39,    40,    52,    53,    82,    32,    33,     6,
      12,    13,    14,    52,    53,    71,    24,     6,    51,    51,
      30,    80,    23,    80,    80,    80,    80,    80,    80,    80,
      80,    30,    29,    51,    52,    53,    29,    51,    52,    53,
      29,    51,    52,     9,    24,    82,    30,    30,    74,    82,
      82,    82,    52,    53,    30,     6,     6,    46,    47,    79,
      30,    30,    30,    23,    74,    74,    47,    22
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 53 "syntaxique.y"
    {
    printf("Assignment successful\n");
    YYACCEPT;
  ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 63 "syntaxique.y"
    {langBIB = 1;;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 64 "syntaxique.y"
    {IOBIB = 1;;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 87 "syntaxique.y"
    {setConst_Finel((yyvsp[(3) - (6)].str));handleDeclaration((yyvsp[(3) - (6)].str), SaveType);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 88 "syntaxique.y"
    {setConst_Finel((yyvsp[(3) - (6)].str)); handleDeclaration((yyvsp[(3) - (6)].str), SaveType);;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 96 "syntaxique.y"
    {
                handleDeclaration((yyvsp[(1) - (1)].str), SaveType);
                
              ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 101 "syntaxique.y"
    {
                handleDeclaration((yyvsp[(1) - (2)].str), SaveType);
              ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 106 "syntaxique.y"
    {CurrentArraySize = (yyvsp[(2) - (3)].entier);}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 110 "syntaxique.y"
    {
                handleDeclaration((yyvsp[(1) - (3)].str), SaveType);
                Incompatible_type(getType((yyvsp[(1) - (3)].str)) , "Integer" , nb_ligne);
              ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 115 "syntaxique.y"
    {
                handleDeclaration((yyvsp[(1) - (3)].str), SaveType);
                Incompatible_type(getType((yyvsp[(1) - (3)].str)) , "Float" , nb_ligne);
              ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 120 "syntaxique.y"
    {
                handleDeclaration((yyvsp[(1) - (6)].str), SaveType);
                depassmentDeTaille(CurrentArraySize , ValueCount , nb_ligne);
              ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 125 "syntaxique.y"
    {
                handleDeclaration((yyvsp[(1) - (3)].str), SaveType);
                Incompatible_type(getType((yyvsp[(1) - (3)].str)) , getType((yyvsp[(3) - (3)].str)) , nb_ligne);
              ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 133 "syntaxique.y"
    {ValueCount++;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 134 "syntaxique.y"
    {ValueCount++;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 135 "syntaxique.y"
    {ValueCount++;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 136 "syntaxique.y"
    {ValueCount++;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 139 "syntaxique.y"
    {strcpy(SaveType , (yyvsp[(1) - (1)].str));;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 140 "syntaxique.y"
    {strcpy(SaveType , (yyvsp[(1) - (1)].str));;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 156 "syntaxique.y"
    {
                      Non_declare((yyvsp[(1) - (4)].str) , nb_ligne);
                      Modify_Const((yyvsp[(1) - (4)].str));
                      if(langBIB == 0 && checkBIB == 0){
                        printf("Erreur : if faut declare le biblioteque 'ISIL_LANG' pour excuter cette opération");
                        checkBIB = 1;
                      }
                    ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 190 "syntaxique.y"
    {
                        if(IOBIB == 0 && checkInput == 0){
                          printf("Erreur Symantique : Pour utiliser 'Input' il faut declare 'ISIL_IO'\n");
                          checkInput = 1;
                        }
                        SymantiqueFormatage((yyvsp[(3) - (7)].str) , (yyvsp[(5) - (7)].str) , nb_ligne);
                ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 197 "syntaxique.y"
    {
                        if(IOBIB == 0 && checkWrite == 0){
                          printf("Erreur Symantique : Pour utiliser 'Write' il faut declare 'ISIL_IO'\n");
                          checkWrite = 1;
                        }
                        SymantiqueFormatage((yyvsp[(3) - (7)].str) , (yyvsp[(5) - (7)].str) , nb_ligne);
                ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 218 "syntaxique.y"
    {
                    divide_zero((yyvsp[(3) - (3)].entier) , nb_ligne);
                 ;}
    break;



/* Line 1455 of yacc.c  */
#line 1757 "syntaxique.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 236 "syntaxique.y"


main()
{
yyparse(); 
displaySymbolTable();
printf("size : %d" , CurrentArraySize);
printf("values : %d" , ValueCount);
}
syywrap()
{}
int yyErreur (char *msg)
{
  fprintf(stderr, "Syntax Erreur at line %d\n", nb_ligne);
  exit(1);
}






