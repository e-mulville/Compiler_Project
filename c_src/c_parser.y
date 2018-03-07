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
%token T_ADD T_SUB T_MULT
%token T_EQUAL T_LESS T_EQLT
%token  T_NUMBER T_VARIABLE
%type <statement> PROGRAM STATEMENT STATEMENT_LIST DECLARATION  ASSIGNMENT JUMP FUNC_DECLARATION VAR_DECLARATION ARGUMENT_LIST EXPR EXPR2 VALUE ARGUMENT RETURN ASSIGN CONTROL IF LOGIC
%type <number> T_NUMBER 
%type <string> T_VARIABLE T_INT T_RETURN

%start ROOT

%%




ROOT : PROGRAM { g_root = $1; }

PROGRAM : %empty {$$ = new empty();}
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



ASSIGNMENT : ASSIGN {$$ = $1;}

ASSIGN : VAR_DECLARATION T_ASSIGN EXPR T_SEMICOLON { $$ = new Assign($1,$3); }
	| VALUE T_ASSIGN EXPR T_SEMICOLON { $$ = new Assign($1, $3); }



JUMP : RETURN { $$ = $1; }

RETURN : T_RETURN VALUE T_SEMICOLON { $$ = new Return($2); }



CONTROL : IF { $$ = $1; }
	| IF T_ELSE T_LBRACKET LOGIC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new IfElse($1, $4, $7); }
	| T_WHILE T_LBRACKET LOGIC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new While($3, $6); }

IF : T_IF T_LBRACKET LOGIC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new If($3, $6); }



LOGIC : EXPR { $$ = $1; }
	| LOGIC T_EQUAL EXPR {$$ = new Equal($1, $3);}
	| LOGIC T_LESS EXPR {$$ = new LessThan($1, $3);}
	| LOGIC T_EQLT EXPR {$$ = new EqualOrLessThan($1, $3);}
	| LOGIC T_AND EXPR {$$ = new And($1, $3);}
	| LOGIC T_OR EXPR {$$ = new Or($1, $3);}



EXPR : EXPR2 { $$ = $1; }
	| EXPR T_MULT EXPR2 {$$ = new Mult($1, $3);} //change value to lower priority

EXPR2 : VALUE { $$ = $1; }
	| EXPR T_ADD VALUE {$$ = new Add($1, $3);}
	| EXPR T_SUB VALUE {$$ = new Sub($1, $3);}

VALUE : T_NUMBER {$$ = new Number ($1);}
	| T_VARIABLE {$$ = new Variable (*$1);}

%%

const Statement *g_root; // Definition of variable (to match declaration earlier)

const Statement *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
