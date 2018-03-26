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

#line 67 "c_parser.tab.cpp" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "c_parser.tab.hpp".  */
#ifndef YY_YY_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_C_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "c_parser.y" /* yacc.c:355  */

	#include "ast.hpp"

	#include <cassert>

	extern const Statement *g_root; // A way of getting the AST out

	int yylex(void);
	void yyerror(const char *);

#line 108 "c_parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_ASSIGN = 258,
    T_ADDASSIGN = 259,
    T_SUBASSIGN = 260,
    T_MULTASSIGN = 261,
    T_DIVASSIGN = 262,
    T_MODASSIGN = 263,
    T_ANDASSIGN = 264,
    T_ORASSIGN = 265,
    T_XORASSIGN = 266,
    T_SLLASSIGN = 267,
    T_SRLASSIGN = 268,
    T_LBRACKET = 269,
    T_RBRACKET = 270,
    T_LCURLBRACKET = 271,
    T_RCURLBRACKET = 272,
    T_LSQR = 273,
    T_RSQR = 274,
    T_SEMICOLON = 275,
    T_COLON = 276,
    T_COMMA = 277,
    T_INT = 278,
    T_VOID = 279,
    T_CHAR = 280,
    T_SHORT = 281,
    T_RETURN = 282,
    T_GOTO = 283,
    T_IF = 284,
    T_ELSE = 285,
    T_WHILE = 286,
    T_FOR = 287,
    T_DO = 288,
    T_ELSEIF = 289,
    T_AND = 290,
    T_OR = 291,
    T_BITAND = 292,
    T_BITOR = 293,
    T_BITXOR = 294,
    T_SLL = 295,
    T_SRL = 296,
    T_ADD = 297,
    T_SUB = 298,
    T_MULT = 299,
    T_DIV = 300,
    T_MOD = 301,
    T_INCREMENT = 302,
    T_DECREMENT = 303,
    T_EQUAL = 304,
    T_NOTEQUAL = 305,
    T_LESS = 306,
    T_EQLT = 307,
    T_GREATER = 308,
    T_EQGT = 309,
    T_NUMBER = 310,
    T_VARIABLE = 311,
    T_LABEL = 312,
    T_CHAR_PRIMITIVE = 313
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "c_parser.y" /* yacc.c:355  */

	const Statement *statement;
	double number;
	std::string *string;

#line 185 "c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 202 "c_parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   443

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  226

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   313

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    39,    39,    41,    42,    44,    45,    46,    47,    49,
      50,    52,    53,    57,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    76,    77,
      78,    80,    81,    82,    84,    85,    87,    91,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   107,   108,   109,   113,   114,   115,   116,   118,   123,
     124,   125,   126,   127,   129,   130,   132,   133,   134,   135,
     137,   138,   139,   141,   143,   144,   146,   147,   149,   150,
     152,   153,   155,   156,   158,   159,   161,   162,   163,   165,
     166,   167,   168,   169,   171,   172,   173,   175,   176,   177,
     179,   180,   181,   182,   184,   185,   187,   188,   189,   190,
     191,   194,   196,   198,   200
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_ASSIGN", "T_ADDASSIGN", "T_SUBASSIGN",
  "T_MULTASSIGN", "T_DIVASSIGN", "T_MODASSIGN", "T_ANDASSIGN",
  "T_ORASSIGN", "T_XORASSIGN", "T_SLLASSIGN", "T_SRLASSIGN", "T_LBRACKET",
  "T_RBRACKET", "T_LCURLBRACKET", "T_RCURLBRACKET", "T_LSQR", "T_RSQR",
  "T_SEMICOLON", "T_COLON", "T_COMMA", "T_INT", "T_VOID", "T_CHAR",
  "T_SHORT", "T_RETURN", "T_GOTO", "T_IF", "T_ELSE", "T_WHILE", "T_FOR",
  "T_DO", "T_ELSEIF", "T_AND", "T_OR", "T_BITAND", "T_BITOR", "T_BITXOR",
  "T_SLL", "T_SRL", "T_ADD", "T_SUB", "T_MULT", "T_DIV", "T_MOD",
  "T_INCREMENT", "T_DECREMENT", "T_EQUAL", "T_NOTEQUAL", "T_LESS",
  "T_EQLT", "T_GREATER", "T_EQGT", "T_NUMBER", "T_VARIABLE", "T_LABEL",
  "T_CHAR_PRIMITIVE", "$accept", "ROOT", "PROGRAM", "STATEMENT",
  "STATEMENT_LIST", "DECLARATION", "FUNC_DECLARATION", "VAR_DECLARATION",
  "ARGUMENT_LIST_DEC", "ARGUMENT_LIST_CALL", "ARGUMENT_DEC",
  "ARGUMENT_CALL", "ASSIGNMENT", "ASSIGN", "CONTAINER", "JUMP", "RETURN",
  "CONTROL", "IF", "ELSE", "ELSE_IF_LIST", "ELSE_IF", "LOGIC", "LOGIC2",
  "LOGIC3", "LOGIC4", "LOGIC5", "LOGIC6", "LOGIC7", "LOGIC8", "SHIFT",
  "EXPR", "EXPR2", "VALUE_WITH_FUNC", "VALUE", "ARRAY", "VALUE_FOR_STORE",
  "ARRAY_FOR_STORE", "FUNC_EVOKE", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313
};
# endif

#define YYPACT_NINF -139

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-139)))

#define YYTABLE_NINF -112

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -139,    24,   373,  -139,    -7,    12,    -7,    -7,    -4,    16,
      65,    99,   113,   115,    30,  -139,    26,  -139,  -139,  -139,
    -139,  -139,   429,  -139,  -139,   414,  -139,  -139,  -139,  -139,
    -139,   -10,  -139,  -139,  -139,   121,   131,   133,   148,  -139,
     150,   153,   159,   161,   166,    -4,   174,    33,  -139,   104,
     157,   158,   173,   -38,   154,    69,   160,   200,  -139,   201,
    -139,   197,    -4,    -4,    -4,  -139,  -139,   164,    80,    -4,
      -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,    -4,
     129,   207,   215,  -139,   192,  -139,  -139,  -139,  -139,  -139,
    -139,  -139,    10,   213,  -139,   129,   129,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   129,   129,   129,
     129,   129,   129,  -139,    47,    71,    92,   205,   237,  -139,
       0,  -139,  -139,    94,    96,    97,    98,   101,   102,   120,
     135,   144,   146,   147,     1,  -139,  -139,  -139,  -139,   258,
    -139,   269,   104,   157,   158,   173,   -38,   154,   154,    69,
      69,    69,    69,   160,   160,   200,   200,  -139,  -139,  -139,
      32,   273,   373,   267,  -139,    29,   291,    80,  -139,  -139,
    -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
     129,  -139,  -139,  -139,   274,  -139,   294,   296,  -139,  -139,
    -139,   226,   305,   -17,  -139,   247,   312,    -4,   268,   274,
      -4,    68,  -139,  -139,  -139,    83,  -139,   -16,    93,  -139,
    -139,   289,   309,   119,   314,   310,  -139,  -139,  -139,  -139,
    -139,  -139,   331,   352,  -139,  -139
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,   112,    56,   110,     4,
       5,    11,    12,     6,    37,     0,     7,    54,     8,    60,
      59,     0,   106,    52,    53,     0,   112,    14,    22,   112,
      16,    18,    24,    20,    26,     0,   109,     0,    74,    76,
      78,    80,    82,    84,    86,    89,    94,    97,   100,   105,
     104,     0,     0,     0,     0,     9,   108,     0,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,     0,    55,     0,    15,    23,    17,    19,    25,
      21,    27,     0,     0,    58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,    34,
       0,    29,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    32,    36,    49,    50,     0,
      75,     0,    77,    79,    81,    83,    85,    87,    88,    92,
      93,    90,    91,    95,    96,    98,    99,   101,   102,   103,
       0,     0,     0,     0,    10,   113,     0,     0,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,   114,
       0,   113,   111,     9,    70,     9,     0,     0,     9,    30,
      33,     0,     0,    65,    71,     0,     0,     0,     0,    70,
       0,     0,    72,    61,     9,     0,    13,    64,     0,     9,
      69,     0,     0,     0,     0,     0,    62,    63,     9,    68,
       9,    67,     0,     0,    66,    73
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -139,  -139,  -139,    -1,  -138,  -139,  -139,   -65,  -139,  -139,
     182,   151,  -139,  -139,  -139,  -139,  -139,  -139,  -139,  -139,
     141,  -126,   -43,  -139,   255,   256,   254,   263,   271,   -59,
     137,   117,   178,   155,    -2,  -139,     2,   184,     3
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   164,   117,    20,    21,    22,   120,   134,
     121,   135,    23,    24,    25,    26,    27,    28,    29,    30,
     193,   194,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    32,    33,    34,    60
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    19,    92,   119,    80,    35,    37,    40,    41,    43,
      45,   100,   101,   201,   213,   166,   179,   192,   192,   114,
     115,   116,   167,   180,     3,   140,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,    81,    82,    14,
    -109,   147,   148,  -111,    67,   191,    95,   195,   183,    36,
     198,    15,    46,    94,    18,     4,     5,     6,     7,     8,
       9,    10,   160,    11,    12,    13,   211,   202,    39,    95,
     122,   215,    61,  -109,  -109,    14,  -111,  -111,   136,    62,
     222,   202,   223,    95,   209,    66,   161,    15,    16,    17,
      18,     4,     5,     6,     7,     8,     9,    10,   212,    11,
      12,    13,   119,     4,     5,     6,     7,    95,   214,   106,
     107,    14,   162,    63,   168,    31,   169,   170,   171,    95,
      35,   172,   173,    15,    16,    17,    18,    64,    95,    95,
      95,    65,    95,    95,    95,   218,    39,    95,    95,    96,
     174,    83,     4,     5,     6,     7,     8,     9,    10,    84,
      11,    12,    13,    85,   205,   175,    95,   208,    31,   184,
      31,   186,    14,    35,   176,    35,   177,   178,    86,   122,
      87,    95,    14,    88,    15,    16,    17,    18,   136,    89,
      95,    90,    95,    95,    15,    46,    91,    18,    38,    31,
      42,    44,    93,    31,    35,    97,    31,    98,    35,    31,
     210,    35,   108,   109,    35,   102,   103,   104,   105,    31,
      99,    31,   219,    31,    35,    80,    35,   113,    35,   118,
      31,    31,   163,   153,   154,    35,    35,   137,     4,     5,
       6,     7,     8,     9,    10,   138,    11,    12,    13,   149,
     150,   151,   152,   199,   110,   111,   112,   139,    14,     4,
       5,     6,     7,     8,     9,    10,   165,    11,    12,    13,
      15,    16,    17,    18,   203,   157,   158,   159,   141,    14,
       4,     5,     6,     7,     8,     9,    10,   181,    11,    12,
      13,    15,    16,    17,    18,   206,   155,   156,   182,   185,
      14,     4,     5,     6,     7,     8,     9,    10,   187,    11,
      12,    13,    15,    16,    17,    18,   216,   188,   192,   196,
     197,    14,     4,     5,     6,     7,     8,     9,    10,   200,
      11,    12,    13,    15,    16,    17,    18,   221,   204,   217,
     220,   190,    14,     4,     5,     6,     7,     8,     9,    10,
     207,    11,    12,    13,    15,    16,    17,    18,   224,   189,
     142,   144,   143,    14,     4,     5,     6,     7,     8,     9,
      10,   145,    11,    12,    13,    15,    16,    17,    18,   225,
     146,     0,     0,     0,    14,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,    15,    16,    17,    18,
       0,     0,     0,     0,     0,    14,     4,     5,     6,     7,
       8,     9,    10,     0,    11,    12,    13,    15,    16,    17,
      18,     0,     0,     0,     0,     0,    14,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    15,    16,
      17,    18,   -51,   -51,   -51,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,    68
};

static const yytype_int16 yycheck[] =
{
       2,     2,    45,    68,    14,     2,     4,     5,     6,     7,
      14,    49,    50,    30,    30,    15,    15,    34,    34,    62,
      63,    64,    22,    22,     0,    15,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    47,    48,    43,
      14,   100,   101,    14,    18,   183,    36,   185,    16,    56,
     188,    55,    56,    20,    58,    23,    24,    25,    26,    27,
      28,    29,    15,    31,    32,    33,   204,   193,    56,    36,
      68,   209,    56,    47,    48,    43,    47,    48,    80,    14,
     218,   207,   220,    36,    16,    55,    15,    55,    56,    57,
      58,    23,    24,    25,    26,    27,    28,    29,    15,    31,
      32,    33,   167,    23,    24,    25,    26,    36,    15,    40,
      41,    43,    20,    14,    20,   117,    20,    20,    20,    36,
     117,    20,    20,    55,    56,    57,    58,    14,    36,    36,
      36,    16,    36,    36,    36,    16,    56,    36,    36,    35,
      20,    20,    23,    24,    25,    26,    27,    28,    29,    18,
      31,    32,    33,    20,   197,    20,    36,   200,   160,   160,
     162,   162,    43,   160,    20,   162,    20,    20,    20,   167,
      20,    36,    43,    20,    55,    56,    57,    58,   180,    20,
      36,    20,    36,    36,    55,    56,    20,    58,     4,   191,
       6,     7,    18,   195,   191,    38,   198,    39,   195,   201,
     201,   198,    42,    43,   201,    51,    52,    53,    54,   211,
      37,   213,   213,   215,   211,    14,   213,    20,   215,    55,
     222,   223,    17,   106,   107,   222,   223,    20,    23,    24,
      25,    26,    27,    28,    29,    20,    31,    32,    33,   102,
     103,   104,   105,    17,    44,    45,    46,    55,    43,    23,
      24,    25,    26,    27,    28,    29,    19,    31,    32,    33,
      55,    56,    57,    58,    17,   110,   111,   112,    55,    43,
      23,    24,    25,    26,    27,    28,    29,    19,    31,    32,
      33,    55,    56,    57,    58,    17,   108,   109,    19,    16,
      43,    23,    24,    25,    26,    27,    28,    29,    31,    31,
      32,    33,    55,    56,    57,    58,    17,    16,    34,    15,
      14,    43,    23,    24,    25,    26,    27,    28,    29,    14,
      31,    32,    33,    55,    56,    57,    58,    17,    16,    20,
      16,   180,    43,    23,    24,    25,    26,    27,    28,    29,
     199,    31,    32,    33,    55,    56,    57,    58,    17,   167,
      95,    97,    96,    43,    23,    24,    25,    26,    27,    28,
      29,    98,    31,    32,    33,    55,    56,    57,    58,    17,
      99,    -1,    -1,    -1,    43,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    55,    56,    57,    58,
      -1,    -1,    -1,    -1,    -1,    43,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    55,    56,    57,
      58,    -1,    -1,    -1,    -1,    -1,    43,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    55,    56,
      57,    58,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    60,    61,     0,    23,    24,    25,    26,    27,    28,
      29,    31,    32,    33,    43,    55,    56,    57,    58,    62,
      64,    65,    66,    71,    72,    73,    74,    75,    76,    77,
      78,    93,    94,    95,    96,    97,    56,    95,    96,    56,
      95,    95,    96,    95,    96,    14,    56,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      97,    56,    14,    14,    14,    16,    55,    18,    14,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    47,    48,    20,    18,    20,    20,    20,    20,    20,
      20,    20,    81,    18,    20,    36,    35,    38,    39,    37,
      49,    50,    51,    52,    53,    54,    40,    41,    42,    43,
      44,    45,    46,    20,    81,    81,    81,    63,    55,    66,
      67,    69,    95,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    68,    70,    93,    20,    20,    55,
      15,    55,    83,    84,    85,    86,    87,    88,    88,    89,
      89,    89,    89,    90,    90,    91,    91,    92,    92,    92,
      15,    15,    20,    17,    62,    19,    15,    22,    20,    20,
      20,    20,    20,    20,    20,    20,    20,    20,    20,    15,
      22,    19,    19,    16,    62,    16,    62,    31,    16,    69,
      70,    63,    34,    79,    80,    63,    15,    14,    63,    17,
      14,    30,    80,    17,    16,    81,    17,    79,    81,    16,
      62,    63,    15,    30,    15,    63,    17,    20,    16,    62,
      16,    17,    63,    63,    17,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    62,    63,
      63,    64,    64,    65,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    67,    67,
      67,    68,    68,    68,    69,    69,    70,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    73,    73,    73,    74,    74,    74,    74,    75,    76,
      76,    76,    76,    76,    77,    77,    78,    78,    78,    78,
      79,    79,    79,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    87,    88,
      88,    88,    88,    88,    89,    89,    89,    90,    90,    90,
      91,    91,    91,    91,    92,    92,    93,    93,    93,    93,
      93,    94,    95,    96,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     0,
       2,     1,     1,     7,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     0,     1,
       3,     0,     1,     3,     1,     1,     1,     1,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       3,     1,     1,     1,     1,     2,     1,     3,     3,     1,
       1,     7,     9,     9,     8,     6,    12,    10,    10,     8,
       0,     1,     2,     7,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     1,     1,     2,     1,
       1,     4,     1,     4,     4
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
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
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
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

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
  switch (yyn)
    {
        case 2:
#line 39 "c_parser.y" /* yacc.c:1646  */
    { g_root = (yyvsp[0].statement); }
#line 1487 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 41 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new empty();}
#line 1493 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 42 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ProgramPair((yyvsp[-1].statement), (yyvsp[0].statement)) ;}
#line 1499 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 44 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1505 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1511 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 46 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1517 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 47 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1523 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 49 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new empty();}
#line 1529 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 50 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new StatementPair((yyvsp[-1].statement), (yyvsp[0].statement)) ;}
#line 1535 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 52 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1541 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 53 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement);}
#line 1547 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 57 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new FuncDeclaration((yyvsp[-6].statement), (yyvsp[-4].statement), (yyvsp[-1].statement)) ;}
#line 1553 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 59 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IntDeclaration((yyvsp[0].statement), 1); }
#line 1559 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 60 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IntDeclaration((yyvsp[-1].statement), 0); }
#line 1565 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 61 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new VoidDeclaration((yyvsp[0].statement), 1); }
#line 1571 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 62 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new VoidDeclaration((yyvsp[-1].statement), 0); }
#line 1577 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 63 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new CharDeclaration((yyvsp[0].statement), 1); }
#line 1583 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 64 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new CharDeclaration((yyvsp[-1].statement), 0); }
#line 1589 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 65 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ShortDeclaration((yyvsp[0].statement), 1); }
#line 1595 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 66 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ShortDeclaration((yyvsp[-1].statement), 0); }
#line 1601 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 67 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("int", (yyvsp[0].statement), 1); }
#line 1607 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 68 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("int", (yyvsp[-1].statement), 0); }
#line 1613 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 69 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("char", (yyvsp[0].statement), 1); }
#line 1619 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 70 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("char", (yyvsp[-1].statement), 0); }
#line 1625 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 71 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("short", (yyvsp[0].statement), 1); }
#line 1631 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 72 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("short", (yyvsp[-1].statement), 0); }
#line 1637 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 76 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new empty();}
#line 1643 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 77 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArgumentPair(NULL, (yyvsp[0].statement), "dec");  }
#line 1649 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 78 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArgumentPair((yyvsp[-2].statement), (yyvsp[0].statement), "dec"); }
#line 1655 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 80 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new empty();}
#line 1661 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 81 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArgumentPair(NULL, (yyvsp[0].statement), "call"); }
#line 1667 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 82 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArgumentPair((yyvsp[-2].statement), (yyvsp[0].statement), "call"); }
#line 1673 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 84 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = (yyvsp[0].statement);}
#line 1679 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 85 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1685 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 87 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1691 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 91 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = (yyvsp[0].statement); }
#line 1697 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 93 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Assign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1703 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 94 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new AddAssign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1709 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 95 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new SubAssign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1715 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 96 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new MultAssign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1721 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 97 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new DivAssign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1727 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 98 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ModAssign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1733 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 99 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new AndAssign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1739 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 100 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new OrAssign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1745 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 101 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new XorAssign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1751 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 102 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new LeftShiftAssign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1757 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 103 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new RightShiftAssign((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 1763 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 104 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Increment((yyvsp[-2].statement)); }
#line 1769 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 105 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Decrement((yyvsp[-2].statement)); }
#line 1775 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 107 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1781 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 108 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1787 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 109 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1793 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 113 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1799 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 114 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[-1].statement); }
#line 1805 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 115 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Label(*(yyvsp[0].string)); }
#line 1811 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 116 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Goto(*(yyvsp[-1].string)); }
#line 1817 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 118 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Return((yyvsp[-1].statement)); }
#line 1823 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 123 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1829 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 124 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1835 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 125 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new While((yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1841 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 126 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new For((yyvsp[-6].statement), (yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1847 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 127 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new DoWhile((yyvsp[-6].statement), (yyvsp[-2].statement)); }
#line 1853 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 129 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new If((yyvsp[-5].statement), (yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1859 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 130 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new If((yyvsp[-3].statement), (yyvsp[-1].statement), (yyvsp[0].statement)); }
#line 1865 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 132 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfElse((yyvsp[-9].statement), (yyvsp[-6].statement), (yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1871 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 133 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfElse((yyvsp[-7].statement), (yyvsp[-5].statement), (yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1877 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 134 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfElse((yyvsp[-7].statement), (yyvsp[-4].statement), (yyvsp[-2].statement) ,(yyvsp[0].statement)); }
#line 1883 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 135 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfElse((yyvsp[-5].statement), (yyvsp[-3].statement), (yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1889 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 137 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new empty();}
#line 1895 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 138 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement);  }
#line 1901 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 139 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ElseIfPair((yyvsp[-1].statement), (yyvsp[0].statement)); }
#line 1907 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 141 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ElseIf((yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1913 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 143 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1919 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 144 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Parentheses((yyvsp[-1].statement)); }
#line 1925 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 146 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1931 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 147 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Or((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1937 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 149 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1943 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 150 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new And((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1949 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 152 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1955 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 153 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new BitwiseOr((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1961 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 155 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1967 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 156 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new BitwiseXor((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1973 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 158 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1979 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 159 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new BitwiseAnd((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1985 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 161 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1991 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 162 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Equal((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1997 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 163 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new NotEqual((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2003 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 165 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2009 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 166 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new GreaterThan((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2015 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 167 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new GreaterThanOrEqual((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2021 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 168 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new LessThan((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2027 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 169 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new LessThanOrEqual((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2033 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 171 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2039 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 172 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ShiftLeft((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2045 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 173 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ShiftRight((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2051 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 175 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2057 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 176 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Add((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2063 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 177 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Sub((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2069 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 179 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2075 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 180 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Mult((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2081 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 181 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Div((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2087 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 182 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Mod((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2093 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 184 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2099 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 185 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2105 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 187 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2111 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 188 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Number ((yyvsp[0].number)); }
#line 2117 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 189 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Number ((yyvsp[0].number) * -1); }
#line 2123 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 190 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Variable (*(yyvsp[0].string), 0); }
#line 2129 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 191 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Char (*(yyvsp[0].string)); }
#line 2135 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 194 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Array(*(yyvsp[-3].string), 0, (yyvsp[-1].number)); }
#line 2141 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 196 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Variable (*(yyvsp[0].string), 1); }
#line 2147 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 198 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Array(*(yyvsp[-3].string), 1, (yyvsp[-1].number)); }
#line 2153 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 200 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new FunctionEvocation((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 2159 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2163 "c_parser.tab.cpp" /* yacc.c:1646  */
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
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
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

#if !defined yyoverflow || YYERROR_VERBOSE
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
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 203 "c_parser.y" /* yacc.c:1906  */


const Statement *g_root; // Definition of variable (to match declaration earlier)

const Statement *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
