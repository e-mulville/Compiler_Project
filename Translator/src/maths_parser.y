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

STATEMENT : STATEMENT_SEQUENCE 
	| DECLARATION
	| ASSIGNMENT
	| CONTROL

STATEMENT_SEQUENCE : STATEMENT T_SEMICOLON
	| STATEMENT_SEQUENCE STATEMENT T_SEMICOLON
	

CONTROL : SELECT_STATEMENT
	| LOOP_STATEMENT

SELECT_STATEMENT : T_IF T_LBRACKET EXPR T_RBRACKET STATEMENT T_ELSE STATEMENT
	| T_IF T_LBRACKET EXPR T_RBRACKET STATEMENT

DECLARATION : FUNC_DECLARATION
	| VAR_DECLARATION

FUNC_DECLARATION

VAR_DECLARATION : DATA_TYPE T_VARIABLE T_SEMICOLON
	| DATA_TYPE T_VARIABLE
	

ASSIGNMENT : IDENTIFIER ASSIGN_OPERATOR EXPRESSION T_SEMICOLON

ASSIGN_OPERATOR : T_ASSIGN
	| T_ADDASSIGN
	| T_SUBASSIGN
	| T_MULASSIGN
	| T_DIVASSIGN
	| T_MODASSIGN
	| T_XORASSIGN
	| T_ORASSIGN
	| T_RIGHTASSIGN
	| T_LEFTASSIGN

IDENTIFIER : T_VARIABLE
	| VAR_DECLARATION

EXPR : LOGIC_EXPR
	| OPERATOR
	| VALUE

LOGIC_EXPR : EXPR T_GT EXPR
	| EXPR T_GTOE EXPR
	| EXPR T_LT EXPR
	| EXPR T_LTOE EXPR 
	| EXPR T_NOT EXPR 
	| EXPR T_NOTEQUALS EXPR
	| EXPR T_EQUALS EXPR
	| EXPR T_AND EXPR
	| EXPR T_OR EXPR
	| EXPR T_XOR EXPR

OPERATOR : EXPR T_MUL EXPR {   $$ = new MulOperator( $1, $3 ); }
	| EXPR T_DIV EXPR {   $$ = new DivOperator( $1, $3 ); }
	| EXPR T_ADD EXPR {   $$ = new AddOperator( $1, $3 ); }
	| EXPR T_SUB EXPR {   $$ = new SubOperator( $1, $3 ); }
	| EXPR T_MOD EXPR {   $$ = new RemainOperator( $1, $3 ); }
	| EXPR T_INCREMENT {   $$ = new IncrementOperator( $1 ); }
	| EXPR T_DECREMENT {   $$ = new DecrementOperator( $1 ); }
	| EXPR T_LAND EXPR {   $$ = new LogicalAndOperator( $1, $3 ); }

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
