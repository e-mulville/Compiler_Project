/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 1 "c_parser.y" /* yacc.c:1909  */

	#include "ast.hpp"

	#include <cassert>

	extern const Statement *g_root; // A way of getting the AST out

	int yylex(void);
	void yyerror(const char *);

#line 55 "c_parser.tab.hpp" /* yacc.c:1909  */

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
#line 14 "c_parser.y" /* yacc.c:1909  */

	const Statement *statement;
	double number;
	std::string *string;

#line 132 "c_parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_PARSER_TAB_HPP_INCLUDED  */
