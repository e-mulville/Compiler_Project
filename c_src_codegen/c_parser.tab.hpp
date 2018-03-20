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
    T_LBRACKET = 259,
    T_RBRACKET = 260,
    T_LCURLBRACKET = 261,
    T_RCURLBRACKET = 262,
    T_SEMICOLON = 263,
    T_COLON = 264,
    T_COMMA = 265,
    T_INT = 266,
    T_VOID = 267,
    T_RETURN = 268,
    T_IF = 269,
    T_ELSE = 270,
    T_WHILE = 271,
    T_AND = 272,
    T_OR = 273,
    T_ADD = 274,
    T_SUB = 275,
    T_MULT = 276,
    T_DIV = 277,
    T_MOD = 278,
    T_EQUAL = 279,
    T_NOTEQUAL = 280,
    T_LESS = 281,
    T_EQLT = 282,
    T_GREATER = 283,
    T_EQGT = 284,
    T_NUMBER = 285,
    T_VARIABLE = 286
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

#line 105 "c_parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_C_PARSER_TAB_HPP_INCLUDED  */