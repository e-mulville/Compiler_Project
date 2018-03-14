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
%token T_INT T_VOID
%token T_RETURN
%token T_IF T_ELSE T_WHILE
%token T_AND T_OR
%token T_ADD T_SUB T_MULT T_DIV T_MOD
%token T_EQUAL T_NOTEQUAL T_LESS T_EQLT T_GREATER T_EQGT
%token T_NUMBER T_VARIABLE
%type <statement> PROGRAM STATEMENT STATEMENT_LIST DECLARATION  ASSIGNMENT JUMP FUNC_DECLARATION VAR_DECLARATION ARGUMENT_LIST LOGIC LOGIC2 LOGIC3 LOGIC4 LOGIC5 EXPR EXPR2 EXPR3 VALUE ARGUMENT RETURN ASSIGN CONTROL IF  FUNC_EVOKE VALUE_WITH_FUNC VALUE_FOR_STORE
%type <number> T_NUMBER 
%type <string> T_VARIABLE T_INT T_RETURN

%start ROOT

%%

//comma lists (x+2, x+b)


ROOT : PROGRAM { g_root = $1; }

PROGRAM : %empty { $$ = new empty();}
	| PROGRAM STATEMENT { $$ = new ProgramPair($1, $2) ;}

STATEMENT: DECLARATION { $$ = $1; }
	| ASSIGNMENT { $$ = $1; }
	| JUMP { $$ = $1; }
	| CONTROL { $$ = $1; }

STATEMENT_LIST : %empty { $$ = new empty();}
	| STATEMENT_LIST STATEMENT { $$ = new StatementPair($1, $2) ;}

DECLARATION : FUNC_DECLARATION { $$ = $1; }
	| VAR_DECLARATION { $$ = $1;}



FUNC_DECLARATION : VAR_DECLARATION T_LBRACKET ARGUMENT_LIST T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new FuncDeclaration($1, $3, $6) ;}

VAR_DECLARATION : T_INT VALUE { $$ = new IntDeclaration($2, 1) ; }
		| T_INT VALUE T_SEMICOLON { $$ = new IntDeclaration($2, 0) ; }
		| T_VOID VALUE { $$ = new VoidDeclaration($2, 1) ; }
		| T_VOID VALUE T_SEMICOLON { $$ = new VoidDeclaration($2, 0) ; }



ARGUMENT_LIST : %empty { $$ = new empty();}
	| ARGUMENT { $$ = $1; }
	| ARGUMENT_LIST T_COMMA ARGUMENT { $$ = new ArgumentPair($1, $3); }

ARGUMENT : VAR_DECLARATION {$$ = $1;} //
	| VALUE { $$ = $1; } ////////////////////////////



ASSIGNMENT : ASSIGN {$$ = $1;}

ASSIGN : VAR_DECLARATION T_ASSIGN EXPR T_SEMICOLON { $$ = new Assign($1,$3); }
	| VALUE_FOR_STORE T_ASSIGN EXPR T_SEMICOLON { $$ = new Assign($1, $3); }



JUMP : RETURN { $$ = $1; }
	| FUNC_EVOKE T_SEMICOLON { $$ = $1; }

RETURN : T_RETURN LOGIC T_SEMICOLON { $$ = new Return($2); }



CONTROL : IF { $$ = $1; }
	| IF T_ELSE T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new IfElse($1, $4); }
	| IF T_ELSE STATEMENT { $$ = new IfElse($1, $3); }
	| T_WHILE T_LBRACKET LOGIC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new While($3, $6); }

IF : T_IF T_LBRACKET LOGIC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new If($3, $6); }
	| T_IF T_LBRACKET LOGIC T_RBRACKET STATEMENT { $$ = new If($3, $5); }



LOGIC : LOGIC2 { $$ = $1; }
	| LOGIC T_OR LOGIC2 {$$ = new Or($1, $3);}

LOGIC2 : LOGIC3 { $$ = $1; }
	| LOGIC2 T_AND LOGIC3 {$$ = new And($1, $3);}

LOGIC3 : LOGIC4 { $$ = $1; }
	| LOGIC3 T_EQUAL LOGIC4 {$$ = new Equal($1, $3);}
	| LOGIC3 T_NOTEQUAL LOGIC4 {$$ = new NotEqual($1, $3);}

LOGIC4 : LOGIC5 { $$ = $1; }
	| LOGIC4 T_GREATER LOGIC5 {$$ = new GreaterThan($1, $3);}
	| LOGIC4 T_EQGT LOGIC5 {$$ = new GreaterThanOrEqual($1, $3);}
	| LOGIC4 T_LESS LOGIC5 {$$ = new LessThan($1, $3);}
	| LOGIC4 T_EQLT LOGIC5 {$$ = new LessThanOrEqual($1, $3);}

LOGIC5:	EXPR  { $$ = $1; }
	| T_LBRACKET LOGIC T_RBRACKET {$$ = new Parentheses($2);}


EXPR : EXPR2 { $$ = $1; }
	| EXPR T_ADD EXPR2 {$$ = new Add($1, $3);}
	| EXPR T_SUB EXPR2 {$$ = new Sub($1, $3);}
	

EXPR2 : EXPR3 { $$ = $1; }
	| EXPR2 T_MULT EXPR3 {$$ = new Mult($1, $3);}
	| EXPR2 T_DIV EXPR3 {$$ = new Div($1, $3);}
	| EXPR2 T_MOD EXPR3 {$$ = new Mod($1, $3);}

EXPR3: VALUE_WITH_FUNC { $$ = $1; }
	| T_LBRACKET EXPR T_RBRACKET {$$ = new Parentheses($2);}
	

VALUE_WITH_FUNC : VALUE { $$ = $1; }
	| FUNC_EVOKE { $$ = $1; }

VALUE : T_NUMBER {$$ = new Number ($1);}
	| T_SUB T_NUMBER {$$ = new Number ($2 * -1);}
	| T_VARIABLE {$$ = new Variable (*$1, 0);}

VALUE_FOR_STORE: T_VARIABLE {$$ = new Variable (*$1, 1);}

FUNC_EVOKE : VALUE T_LBRACKET ARGUMENT_LIST T_RBRACKET { $$ = new FunctionEvocation($1, $3); }


%%

const Statement *g_root; // Definition of variable (to match declaration earlier)

const Statement *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
