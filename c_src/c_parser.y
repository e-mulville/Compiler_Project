%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

%token T_ASSIGN 
%token T_LBRACKET T_RBRACKET T_LCURLBRACKET T_RCURLBRACKET
%token T_SEMICOLON T_COLON T_COMMA //not sure how to use semicolon
%token T_INT

%token  T_NUMBER T_VARIABLE
%type <expr> PROGRAM STATEMENT STATEMENT_LIST DECLARATION FUNC_DECLARATION VAR_DECLARATION ARGUMENT_LIST  ASSIGNMENT EXPR VALUE ARGUMENT
%type <number> T_NUMBER
%type <string> T_VARIABLE

%start ROOT

%%




ROOT : PROGRAM { g_root = $1; }

PROGRAM : %empty {;}
	| PROGRAM STATEMENT

STATEMENT:DECLARATION
	| ASSIGNMENT

STATEMENT_LIST : STATEMENT {;}
	| STATEMENT_LIST STATEMENT

DECLARATION : FUNC_DECLARATION
	| VAR_DECLARATION T_SEMICOLON

FUNC_DECLARATION : TYPE T_VARIABLE T_LBRACKET ARGUMENT_LIST T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { ;}

ARGUMENT_LIST : ARGUMENT
	| ARGUMENT_LIST T_COMMA ARGUMENT

ARGUMENT : TYPE T_VARIABLE { ;}

TYPE : T_INT { ;}

ASSIGNMENT : VAR_DECLARATION ASSIGN_OPERATOR EXPR T_SEMICOLON
	| T_VARIABLE ASSIGN_OPERATOR EXPR T_SEMICOLON { ;}

VAR_DECLARATION : TYPE T_VARIABLE { ;}

ASSIGN_OPERATOR : T_ASSIGN { ;}


EXPR : VALUE

VALUE : T_NUMBER { ;}
	| T_VARIABLE { ;}

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
