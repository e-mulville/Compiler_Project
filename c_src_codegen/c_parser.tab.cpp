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
    T_CHAR_PRIMITIVE = 313,
    T_ADDRESS = 314
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

#line 186 "c_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 203 "c_parser.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   739

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  233

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   314

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
      55,    56,    57,    58,    59
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    39,    39,    41,    42,    44,    45,    46,    47,    50,
      51,    53,    54,    58,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    77,    78,
      79,    81,    82,    83,    85,    86,    88,    90,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   106,   107,   108,   112,   113,   114,   115,   117,   122,
     123,   124,   125,   126,   127,   129,   130,   132,   133,   134,
     135,   137,   138,   139,   141,   143,   144,   146,   147,   149,
     150,   152,   153,   155,   156,   158,   159,   161,   162,   163,
     165,   166,   167,   168,   169,   171,   172,   173,   175,   176,
     177,   179,   180,   181,   182,   184,   185,   187,   188,   189,
     190,   191,   192,   193,   196,   198,   199,   201,   203
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
  "T_CHAR_PRIMITIVE", "T_ADDRESS", "$accept", "ROOT", "PROGRAM",
  "STATEMENT", "STATEMENT_LIST", "DECLARATION", "FUNC_DECLARATION",
  "VAR_DECLARATION", "ARGUMENT_LIST_DEC", "ARGUMENT_LIST_CALL",
  "ARGUMENT_DEC", "ARGUMENT_CALL", "ASSIGNMENT", "ASSIGN", "CONTAINER",
  "JUMP", "RETURN", "CONTROL", "IF", "ELSE", "ELSE_IF_LIST", "ELSE_IF",
  "LOGIC", "LOGIC2", "LOGIC3", "LOGIC4", "LOGIC5", "LOGIC6", "LOGIC7",
  "LOGIC8", "SHIFT", "EXPR", "EXPR2", "VALUE_WITH_FUNC", "VALUE", "ARRAY",
  "VALUE_FOR_STORE", "ARRAY_FOR_STORE", "FUNC_EVOKE", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314
};
# endif

#define YYPACT_NINF -113

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-113)))

#define YYTABLE_NINF -118

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -113,    13,   619,  -113,   -41,   -39,   -41,   -41,     5,   -38,
      26,    28,    37,    11,   -10,    -3,  -113,   676,  -113,  -113,
    -113,  -113,  -113,  -113,   692,  -113,    45,   704,  -113,  -113,
    -113,  -113,  -113,    38,  -113,  -113,  -113,   101,    41,   100,
     103,   111,  -113,   138,   141,   161,   162,   165,     5,   132,
     171,    -8,  -113,   164,   159,   169,   166,    67,    90,    69,
      92,   120,  -113,   195,  -113,   190,     5,     5,     0,  -113,
    -113,   715,   156,   113,  -113,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,   128,  -113,  -113,  -113,
    -113,   157,  -113,  -113,  -113,  -113,  -113,  -113,  -113,    31,
    -113,   163,  -113,   128,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   128,   128,   128,   128,   128,
     128,  -113,    32,    76,  -113,   194,    21,    38,   286,   201,
    -113,    72,  -113,  -113,   186,   186,   186,   186,   186,   186,
     186,   186,   186,   186,   186,    85,  -113,  -113,   205,  -113,
     210,   164,   159,   169,   166,    67,    90,    90,    69,    69,
      69,    69,    92,    92,   120,   120,  -113,  -113,  -113,    46,
     214,     5,   104,   203,  -113,   726,   226,   113,  -113,   128,
    -113,  -113,  -113,   213,  -113,    60,   231,    98,   234,  -113,
    -113,  -113,   323,   235,    20,  -113,   360,   104,   236,     5,
     397,   213,     5,   212,  -113,  -113,   238,  -113,    77,  -113,
      65,    78,  -113,  -113,   241,   434,   230,   249,   242,   471,
    -113,  -113,  -113,  -113,  -113,  -113,  -113,   508,   545,   582,
    -113,  -113,  -113
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   108,   110,    56,   112,
     113,     4,     5,    11,    12,     6,     0,     0,     8,    54,
       7,    60,    59,     0,   107,    52,    53,     0,     0,   115,
      14,    22,   115,    16,    18,    24,    20,    26,     0,     0,
     110,     0,    75,    77,    79,    81,    83,    85,    87,    90,
      95,    98,   101,   106,   105,     0,     0,     0,     0,     9,
     109,   111,     0,    28,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    31,    49,    50,    55,
     116,     0,    15,    23,    17,    19,    25,    21,    27,     0,
     111,     0,    58,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,     0,    51,     0,     0,   106,     0,     0,
      34,     0,    29,    35,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,     0,    32,    36,     0,    76,
       0,    78,    80,    82,    84,    86,    88,    89,    93,    94,
      91,    92,    96,    97,    99,   100,   102,   103,   104,     0,
       0,     0,     0,     0,    10,   114,     0,     0,   118,     0,
     117,   114,     9,    71,     9,     0,     0,     0,     0,     9,
      30,    33,     0,     0,    66,    72,     0,     0,     0,     0,
       0,    71,     0,     0,    73,    61,     0,     9,     0,    13,
      65,     0,     9,    70,     0,     0,     0,     0,     0,     0,
       9,    63,    64,     9,    69,     9,    68,     0,     0,     0,
      62,    67,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -113,  -113,  -113,    -1,  -101,  -113,  -113,   -57,  -113,  -113,
      74,    75,  -113,   -64,  -113,  -113,  -113,  -113,  -113,  -113,
      58,  -112,   -46,  -113,   158,   160,   155,   173,   176,    66,
      39,    40,    89,    73,    -2,  -113,     3,   172,     4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   174,   128,    22,    23,    24,   131,   145,
     132,   146,    25,    26,    27,    28,    29,    30,    31,    32,
     194,   195,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    34,    35,    36,    64
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      33,    21,    99,    38,   125,    38,    37,    40,    43,    44,
      46,   124,   102,     3,    48,    39,   130,    42,    65,    48,
     122,   123,   126,     4,     5,     6,     7,    69,   103,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
      66,   172,    67,    14,    15,    70,   149,   169,    14,    49,
     203,    68,    86,    71,   193,    16,    17,   103,    19,    20,
      16,    50,   182,    19,    20,    74,   127,   103,   103,     4,
       5,     6,     7,     8,     9,    10,   133,    11,    12,    13,
     197,   192,   204,   196,   147,    87,    88,   176,   200,    14,
      15,   170,   216,   218,   177,   217,   103,    90,   204,   193,
     178,    16,    17,    18,    19,    20,   215,   179,   186,   114,
     115,   219,   103,   103,   103,   124,   108,   109,    91,   227,
     130,    89,   228,    92,   229,   185,    33,     4,     5,     6,
       7,    93,    37,   206,   116,   117,     4,     5,     6,     7,
     124,   110,   111,   112,   113,    87,    88,    14,    15,   158,
     159,   160,   161,   208,   162,   163,   211,    38,    94,    16,
      17,    95,    19,    20,   118,   119,   120,    33,   183,    42,
     187,    14,    49,    37,   156,   157,    41,   147,    45,    47,
     133,    96,    97,    16,    50,    98,    19,    20,   100,   101,
      33,   166,   167,   168,    33,   187,    37,   105,    33,   104,
      37,    33,   213,   107,    37,   164,   165,    37,   106,    86,
     121,   129,   148,    33,   171,    33,   224,    33,   150,    37,
     175,    37,   103,    37,   180,    33,    33,    33,   212,   181,
     184,    37,    37,    37,   188,     4,     5,     6,     7,     8,
       9,    10,   189,    11,    12,    13,   198,   193,   199,   202,
     222,   190,   207,   214,   191,    14,    15,   220,   225,   210,
     153,   151,     0,     0,   152,   223,     0,    16,    17,    18,
      19,    20,     4,     5,     6,     7,     8,     9,    10,   154,
      11,    12,    13,   155,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,    16,    17,    18,    19,    20,     4,
       5,     6,     7,     8,     9,    10,     0,    11,    12,    13,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    14,
      15,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     201,    16,    17,    18,    19,    20,     4,     5,     6,     7,
       8,     9,    10,     0,    11,    12,    13,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   205,    16,    17,
      18,    19,    20,     4,     5,     6,     7,     8,     9,    10,
       0,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    14,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   209,    16,    17,    18,    19,    20,
       4,     5,     6,     7,     8,     9,    10,     0,    11,    12,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      14,    15,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   221,    16,    17,    18,    19,    20,     4,     5,     6,
       7,     8,     9,    10,     0,    11,    12,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   226,    16,
      17,    18,    19,    20,     4,     5,     6,     7,     8,     9,
      10,     0,    11,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   230,    16,    17,    18,    19,
      20,     4,     5,     6,     7,     8,     9,    10,     0,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    14,    15,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   231,    16,    17,    18,    19,    20,     4,     5,
       6,     7,     8,     9,    10,     0,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,    15,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   232,
      16,    17,    18,    19,    20,     4,     5,     6,     7,     8,
       9,    10,     0,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    17,    18,
      19,    20,     4,     5,     6,     7,     8,     9,    10,     0,
      11,    12,    13,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    14,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,    20,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
       0,     0,     0,     0,    72,   -51,   -51,   -51,   -51,   -51,
     -51,   -51,   -51,   -51,   -51,   -51,    73,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -117,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117
};

static const yytype_int16 yycheck[] =
{
       2,     2,    48,    44,    68,    44,     2,     4,     5,     6,
       7,    68,    20,     0,    14,    56,    73,    56,    56,    14,
      66,    67,    68,    23,    24,    25,    26,    16,    36,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      14,    20,    14,    43,    44,    55,    15,    15,    43,    44,
      30,    14,    14,    56,    34,    55,    56,    36,    58,    59,
      55,    56,    16,    58,    59,    20,    68,    36,    36,    23,
      24,    25,    26,    27,    28,    29,    73,    31,    32,    33,
      20,   182,   194,   184,    86,    47,    48,    15,   189,    43,
      44,    15,    15,    15,    22,    30,    36,    56,   210,    34,
      15,    55,    56,    57,    58,    59,   207,    22,   172,    40,
      41,   212,    36,    36,    36,   172,    49,    50,    18,   220,
     177,    20,   223,    20,   225,   171,   128,    23,    24,    25,
      26,    20,   128,   197,    42,    43,    23,    24,    25,    26,
     197,    51,    52,    53,    54,    47,    48,    43,    44,   110,
     111,   112,   113,   199,   114,   115,   202,    44,    20,    55,
      56,    20,    58,    59,    44,    45,    46,   169,   169,    56,
     172,    43,    44,   169,   108,   109,     4,   179,     6,     7,
     177,    20,    20,    55,    56,    20,    58,    59,    56,    18,
     192,   118,   119,   120,   196,   197,   192,    38,   200,    35,
     196,   203,   203,    37,   200,   116,   117,   203,    39,    14,
      20,    55,    55,   215,    20,   217,   217,   219,    55,   215,
      19,   217,    36,   219,    19,   227,   228,   229,    16,    19,
      16,   227,   228,   229,    31,    23,    24,    25,    26,    27,
      28,    29,    16,    31,    32,    33,    15,    34,    14,    14,
      20,   177,    16,    15,   179,    43,    44,    16,    16,   201,
     105,   103,    -1,    -1,   104,    16,    -1,    55,    56,    57,
      58,    59,    23,    24,    25,    26,    27,    28,    29,   106,
      31,    32,    33,   107,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    55,    56,    57,    58,    59,    23,
      24,    25,    26,    27,    28,    29,    -1,    31,    32,    33,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      17,    55,    56,    57,    58,    59,    23,    24,    25,    26,
      27,    28,    29,    -1,    31,    32,    33,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    55,    56,
      57,    58,    59,    23,    24,    25,    26,    27,    28,    29,
      -1,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    17,    55,    56,    57,    58,    59,
      23,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    17,    55,    56,    57,    58,    59,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    33,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,    55,
      56,    57,    58,    59,    23,    24,    25,    26,    27,    28,
      29,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,    55,    56,    57,    58,
      59,    23,    24,    25,    26,    27,    28,    29,    -1,    31,
      32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    17,    55,    56,    57,    58,    59,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      55,    56,    57,    58,    59,    23,    24,    25,    26,    27,
      28,    29,    -1,    31,    32,    33,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    56,    57,
      58,    59,    23,    24,    25,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    55,    56,    57,    58,    59,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      -1,    -1,    -1,    -1,    18,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    61,    62,     0,    23,    24,    25,    26,    27,    28,
      29,    31,    32,    33,    43,    44,    55,    56,    57,    58,
      59,    63,    65,    66,    67,    72,    73,    74,    75,    76,
      77,    78,    79,    94,    95,    96,    97,    98,    44,    56,
      96,    97,    56,    96,    96,    97,    96,    97,    14,    44,
      56,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    98,    56,    14,    14,    14,    16,
      55,    56,    18,    14,    20,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    47,    48,    20,
      56,    18,    20,    20,    20,    20,    20,    20,    20,    82,
      56,    18,    20,    36,    35,    38,    39,    37,    49,    50,
      51,    52,    53,    54,    40,    41,    42,    43,    44,    45,
      46,    20,    82,    82,    67,    73,    82,    94,    64,    55,
      67,    68,    70,    96,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    69,    71,    94,    55,    15,
      55,    84,    85,    86,    87,    88,    89,    89,    90,    90,
      90,    90,    91,    91,    92,    92,    93,    93,    93,    15,
      15,    20,    20,    17,    63,    19,    15,    22,    15,    22,
      19,    19,    16,    63,    16,    82,    73,    94,    31,    16,
      70,    71,    64,    34,    80,    81,    64,    20,    15,    14,
      64,    17,    14,    30,    81,    17,    73,    16,    82,    17,
      80,    82,    16,    63,    15,    64,    15,    30,    15,    64,
      16,    17,    20,    16,    63,    16,    17,    64,    64,    64,
      17,    17,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    60,    61,    62,    62,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    67,    67,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    68,    68,
      68,    69,    69,    69,    70,    70,    71,    72,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    74,    75,    75,    75,    75,    76,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    79,
      79,    80,    80,    80,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    88,    88,    88,
      89,    89,    89,    89,    89,    90,    90,    90,    91,    91,
      91,    92,    92,    92,    92,    93,    93,    94,    94,    94,
      94,    94,    94,    94,    95,    96,    96,    97,    98
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     0,
       2,     1,     1,     7,     2,     3,     2,     3,     2,     3,
       2,     3,     2,     3,     2,     3,     2,     3,     0,     1,
       3,     0,     1,     3,     1,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     1,     1,     1,     1,     2,     1,     3,     3,     1,
       1,     7,    11,     9,     9,     8,     6,    12,    10,    10,
       8,     0,     1,     2,     7,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     1,     1,     2,
       1,     2,     1,     1,     4,     1,     2,     4,     4
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
#line 1549 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 41 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new empty();}
#line 1555 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 42 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ProgramPair((yyvsp[-1].statement), (yyvsp[0].statement)) ;}
#line 1561 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 44 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1567 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 45 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1573 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 46 "c_parser.y" /* yacc.c:1646  */
    {  (yyval.statement) = (yyvsp[0].statement); }
#line 1579 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 47 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1585 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 50 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new empty();}
#line 1591 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 51 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new StatementPair((yyvsp[-1].statement), (yyvsp[0].statement)) ;}
#line 1597 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 53 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1603 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 54 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement);}
#line 1609 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 58 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new FuncDeclaration((yyvsp[-6].statement), (yyvsp[-4].statement), (yyvsp[-1].statement)) ;}
#line 1615 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 60 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IntDeclaration((yyvsp[0].statement), 1); }
#line 1621 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 61 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IntDeclaration((yyvsp[-1].statement), 0); }
#line 1627 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 62 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new VoidDeclaration((yyvsp[0].statement), 1); }
#line 1633 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 63 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new VoidDeclaration((yyvsp[-1].statement), 0); }
#line 1639 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 64 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new CharDeclaration((yyvsp[0].statement), 1); }
#line 1645 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 65 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new CharDeclaration((yyvsp[-1].statement), 0); }
#line 1651 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 66 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ShortDeclaration((yyvsp[0].statement), 1); }
#line 1657 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 67 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ShortDeclaration((yyvsp[-1].statement), 0); }
#line 1663 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 68 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("int", (yyvsp[0].statement), 1); }
#line 1669 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 69 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("int", (yyvsp[-1].statement), 0); }
#line 1675 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 70 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("char", (yyvsp[0].statement), 1); }
#line 1681 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 71 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("char", (yyvsp[-1].statement), 0); }
#line 1687 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 72 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("short", (yyvsp[0].statement), 1); }
#line 1693 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 73 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArrayDeclaration("short", (yyvsp[-1].statement), 0); }
#line 1699 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 77 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new empty();}
#line 1705 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 78 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArgumentPair(NULL, (yyvsp[0].statement), "dec");  }
#line 1711 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 79 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArgumentPair((yyvsp[-2].statement), (yyvsp[0].statement), "dec"); }
#line 1717 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 81 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new empty();}
#line 1723 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 82 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArgumentPair(NULL, (yyvsp[0].statement), "call"); }
#line 1729 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 83 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ArgumentPair((yyvsp[-2].statement), (yyvsp[0].statement), "call"); }
#line 1735 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 85 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = (yyvsp[0].statement);}
#line 1741 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 86 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1747 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 88 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1753 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 90 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = (yyvsp[-1].statement); }
#line 1759 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 92 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Assign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1765 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 93 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new AddAssign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1771 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 94 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new SubAssign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1777 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 95 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new MultAssign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1783 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 96 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new DivAssign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1789 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 97 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ModAssign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1795 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 98 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new AndAssign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1801 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 99 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new OrAssign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1807 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 100 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new XorAssign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1813 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 101 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new LeftShiftAssign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1819 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 102 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new RightShiftAssign((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1825 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 103 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Increment((yyvsp[-1].statement)); }
#line 1831 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 104 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Decrement((yyvsp[-1].statement)); }
#line 1837 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 106 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1843 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 107 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1849 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 108 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1855 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 112 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1861 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 113 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[-1].statement); }
#line 1867 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 114 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Label(*(yyvsp[0].string)); }
#line 1873 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 115 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Goto(*(yyvsp[-1].string)); }
#line 1879 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 117 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Return((yyvsp[-1].statement)); }
#line 1885 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 122 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1891 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 123 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1897 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 124 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new While((yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1903 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 125 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ForWithAssign((yyvsp[-8].statement), (yyvsp[-6].statement), (yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1909 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 126 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new For ((yyvsp[-6].statement), (yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1915 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 127 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new DoWhile((yyvsp[-6].statement), (yyvsp[-2].statement)); }
#line 1921 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 129 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new If((yyvsp[-5].statement), (yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1927 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 130 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new If((yyvsp[-3].statement), (yyvsp[-1].statement), (yyvsp[0].statement)); }
#line 1933 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 132 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfElse((yyvsp[-9].statement), (yyvsp[-6].statement), (yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1939 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 133 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfElse((yyvsp[-7].statement), (yyvsp[-5].statement), (yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1945 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 134 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfElse((yyvsp[-7].statement), (yyvsp[-4].statement), (yyvsp[-2].statement) ,(yyvsp[0].statement)); }
#line 1951 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 135 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new IfElse((yyvsp[-5].statement), (yyvsp[-3].statement), (yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 1957 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 137 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new empty();}
#line 1963 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 138 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement);  }
#line 1969 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 139 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ElseIfPair((yyvsp[-1].statement), (yyvsp[0].statement)); }
#line 1975 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 141 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ElseIf((yyvsp[-4].statement), (yyvsp[-1].statement)); }
#line 1981 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 143 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1987 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 144 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Parentheses((yyvsp[-1].statement)); }
#line 1993 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 146 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 1999 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 147 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Or((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2005 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 149 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2011 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 150 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new And((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2017 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 152 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2023 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 153 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new BitwiseOr((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2029 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 155 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2035 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 156 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new BitwiseXor((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2041 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 158 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2047 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 159 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new BitwiseAnd((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2053 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 161 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2059 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 162 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Equal((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2065 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 163 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new NotEqual((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2071 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 165 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2077 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 166 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new GreaterThan((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2083 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 167 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new GreaterThanOrEqual((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2089 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 168 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new LessThan((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2095 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 169 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new LessThanOrEqual((yyvsp[-2].statement), (yyvsp[0].statement)); }
#line 2101 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 171 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2107 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 172 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ShiftLeft((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2113 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 173 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new ShiftRight((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2119 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 175 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2125 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 176 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Add((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2131 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 177 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Sub((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2137 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 179 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2143 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 180 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Mult((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2149 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 181 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Div((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2155 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 182 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Mod((yyvsp[-2].statement), (yyvsp[0].statement));}
#line 2161 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 184 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2167 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 185 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2173 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 187 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = (yyvsp[0].statement); }
#line 2179 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 188 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Number ((yyvsp[0].number)); }
#line 2185 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 189 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Number ((yyvsp[0].number) * -1); }
#line 2191 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 190 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Variable (*(yyvsp[0].string), 0); }
#line 2197 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 191 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Pointer(*(yyvsp[0].string), 0); }
#line 2203 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 192 "c_parser.y" /* yacc.c:1646  */
    {(yyval.statement) = new Char (*(yyvsp[0].string)); }
#line 2209 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 193 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Address(*(yyvsp[0].string)); }
#line 2215 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 196 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Array(*(yyvsp[-3].string), 0, (yyvsp[-1].number)); }
#line 2221 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 198 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Variable (*(yyvsp[0].string), 1); }
#line 2227 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 199 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Pointer(*(yyvsp[0].string), 1); }
#line 2233 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 201 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new Array(*(yyvsp[-3].string), 1, (yyvsp[-1].number)); }
#line 2239 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 203 "c_parser.y" /* yacc.c:1646  */
    { (yyval.statement) = new FunctionEvocation((yyvsp[-3].statement), (yyvsp[-1].statement)); }
#line 2245 "c_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2249 "c_parser.tab.cpp" /* yacc.c:1646  */
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
#line 206 "c_parser.y" /* yacc.c:1906  */


const Statement *g_root; // Definition of variable (to match declaration earlier)

const Statement *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
