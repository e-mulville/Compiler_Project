%code requires{
  #include "ast.hpp"

  #include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
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

%token T_TIMES T_DIVIDE T_ADD T_SUB T_MOD T_INCREMENT T_DECREMENT T_LAND
%token T_ASSIGN T_ADDASSIGN  T_SUBASSIGN T_MULASSIGN T_DIVASSIGN T_MODASSIGN T_XORASSIGN T_ORASSIGN T_RIGHTASSIGN T_LEFTASSIGN
%token T_GT T_GTOE T_LT T_LTOE T_NOT T_NOTEQUALS T_EQUALS T_AND T_OR T_XOR
%token T_LBRACKET T_RBRACKET T_LCURLBRACKET T_RCURLBRACKET T_LSQRBRACKET T_RSQRBRACKET
%token T_SEMICOLON T_COLON T_COMMA //not sure how to use semicolon
%token T_INT T_DOUBLE T_SHORT T_LONG T_CHAR T_FLOAT T_SIGNED T_UNSIGNED
%token T_STRUCT T_UNION T_VOID
%token T_FOR T_IF T_ELSE T_DO T_WHILE
%token T_GOTO T_RETURN
%token T_SWITCH T_CASE T_DEFAULT
%token T_BREAK T_CONTINUE
%token T_ENUM T_EXTERN T_SIZEOF T_TYPEDEF

%token  T_NUMBER T_VARIABLE

%type <expr> EXPR TERM FACTOR OPERATOR ASSIGNMENT CONTAINER FUNCTION LOGIC
%type <number> T_NUMBER
%type <string> T_VARIABLE

%start ROOT

%%




ROOT : STATEMENT { g_root = $1; }

STATEMENT : STATEMENT_LIST
	| DECLARATION
	| ASSIGNMENT
	| CONTROL

STATEMENT_LIST : STATEMENT T_SEMICOLON
	| STATEMENT_LIST STATEMENT T_SEMICOLON
	

DECLARATION : FUNC_DECLARATION
	| VAR_DECLARATION T_SEMICOLON

FUNC_DECLARATION : TYPE T_VARIABLE T_LBRACKET ARGUMENT_LIST T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET

ARGUMENT_LIST : ARGUMENT
	| ARGUMENT_LIST T_COMMA ARGUMENT

ARGUMENT : TYPE T_VARIABLE

TYPE : T_INT

ASSIGNMENT : VAR_DECLARATION ASSIGN_OPERATOR EXPR T_SEMICOLON
	| T_VARIABLE ASSIGN_OPERATOR EXPR T_SEMICOLON

VAR_DECLARATION : DATA_TYPE T_VARIABLE

ASSIGN_OPERATOR : T_ASSIGN


EXPR : VALUE

VALUE : T_NUMBER
	| T_VARIABLE

/* TODO-5 : Add support log(x), by modifying the rule for FACTOR. */

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
