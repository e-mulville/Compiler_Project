%code requires{
	#include "ast.hpp"

	#include <cassert>

	extern const Statement *g_root; // A way of getting the AST out

	int yylex(void);
	void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
	const Statement *statement;
	double number;
	std::string *string;
}

%token T_ASSIGN 
%token T_LBRACKET T_RBRACKET T_LCURLBRACKET T_RCURLBRACKET
%token T_SEMICOLON T_COLON T_COMMA //not sure how to use semicolon
%token T_INT T_RETURN

%token  T_NUMBER T_VARIABLE
%type <statement> PROGRAM STATEMENT STATEMENT_LIST DECLARATION  ASSIGNMENT JUMP FUNC_DECLARATION VAR_DECLARATION ARGUMENT_LIST EXPR VALUE ARGUMENT
%type <number> T_NUMBER
%type <string> T_VARIABLE

%start ROOT

%%




ROOT : PROGRAM { g_root = $1; }

PROGRAM : %empty {;}
	| PROGRAM STATEMENT { $$ = $2; }

STATEMENT:DECLARATION { $$ = $1; }
	| ASSIGNMENT { $$ = $1; }
	| JUMP { $$ = $1; }

STATEMENT_LIST : %empty {;}
	| STATEMENT_LIST STATEMENT

DECLARATION : FUNC_DECLARATION { $$ = $1; }
	| VAR_DECLARATION T_SEMICOLON { $$ = $1; }

FUNC_DECLARATION : TYPE T_VARIABLE T_LBRACKET ARGUMENT_LIST T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new FuncDeclaration($7, $4) ;}

ARGUMENT_LIST : %empty {;}
	| ARGUMENT
	| ARGUMENT_LIST T_COMMA ARGUMENT

ARGUMENT : TYPE T_VARIABLE { ;}

TYPE : T_INT { std::cout << "Int";}

ASSIGNMENT : VAR_DECLARATION ASSIGN_OPERATOR EXPR T_SEMICOLON
	| T_VARIABLE ASSIGN_OPERATOR EXPR T_SEMICOLON { std::cout << "assignment";}

VAR_DECLARATION : TYPE VALUE { std::cout << "Var_Dec" ;}

ASSIGN_OPERATOR : T_ASSIGN {std::cout << "=" ;}

JUMP : RETURN

RETURN : T_RETURN VALUE T_SEMICOLON { std::cout << "return";}

EXPR : VALUE

VALUE : T_NUMBER {std::cout << "Num" ;}
	| T_VARIABLE {std::cout << "Var";}

%%

const Statement *g_root; // Definition of variable (to match declaration earlier)

const Statement *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
