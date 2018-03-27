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

%token T_ASSIGN T_ADDASSIGN T_SUBASSIGN T_MULTASSIGN T_DIVASSIGN T_MODASSIGN T_ANDASSIGN T_ORASSIGN T_XORASSIGN T_SLLASSIGN T_SRLASSIGN
%token T_LBRACKET T_RBRACKET T_LCURLBRACKET T_RCURLBRACKET T_LSQR T_RSQR
%token T_SEMICOLON T_COLON T_COMMA
%token T_INT T_VOID T_CHAR T_SHORT
%token T_RETURN T_GOTO
%token T_IF T_ELSE T_WHILE T_FOR T_DO T_ELSEIF
%token T_AND T_OR T_BITAND T_BITOR T_BITXOR T_SLL T_SRL
%token T_ADD T_SUB T_MULT T_DIV T_MOD T_INCREMENT T_DECREMENT
%token T_EQUAL T_NOTEQUAL T_LESS T_EQLT T_GREATER T_EQGT
%token T_NUMBER T_VARIABLE T_LABEL T_CHAR_PRIMITIVE T_ADDRESS T_POINTER
%type <statement> PROGRAM STATEMENT STATEMENT_LIST DECLARATION  ASSIGNMENT JUMP FUNC_DECLARATION VAR_DECLARATION ARGUMENT_LIST_DEC ARGUMENT_LIST_CALL LOGIC LOGIC2 LOGIC3 LOGIC4 LOGIC5 LOGIC6 LOGIC7 LOGIC8 EXPR EXPR2 VALUE ARGUMENT_DEC ARGUMENT_CALL RETURN ASSIGN CONTROL IF ELSE ELSE_IF ELSE_IF_LIST FUNC_EVOKE VALUE_WITH_FUNC VALUE_FOR_STORE ARRAY ARRAY_FOR_STORE CONTAINER SHIFT
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LABEL T_INT T_RETURN T_CHAR_PRIMITIVE T_ADDRESS T_POINTER

%start ROOT

%%


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



FUNC_DECLARATION : VAR_DECLARATION T_LBRACKET ARGUMENT_LIST_DEC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new FuncDeclaration($1, $3, $6) ;}

VAR_DECLARATION : T_INT VALUE_FOR_STORE { $$ = new IntDeclaration($2, 1); }
	| T_INT VALUE_FOR_STORE T_SEMICOLON { $$ = new IntDeclaration($2, 0); }
	| T_VOID VALUE_FOR_STORE { $$ = new VoidDeclaration($2, 1); }
	| T_VOID VALUE_FOR_STORE T_SEMICOLON { $$ = new VoidDeclaration($2, 0); }
	| T_CHAR VALUE_FOR_STORE { $$ = new CharDeclaration($2, 1); }
	| T_CHAR VALUE_FOR_STORE T_SEMICOLON { $$ = new CharDeclaration($2, 0); }
	| T_SHORT VALUE_FOR_STORE { $$ = new ShortDeclaration($2, 1); }
	| T_SHORT VALUE_FOR_STORE T_SEMICOLON { $$ = new ShortDeclaration($2, 0); }
	| T_INT ARRAY_FOR_STORE { $$ = new ArrayDeclaration("int", $2, 1); }
	| T_INT ARRAY_FOR_STORE T_SEMICOLON { $$ = new ArrayDeclaration("int", $2, 0); }
	| T_CHAR ARRAY_FOR_STORE { $$ = new ArrayDeclaration("char", $2, 1); }
	| T_CHAR ARRAY_FOR_STORE T_SEMICOLON { $$ = new ArrayDeclaration("char", $2, 0); }
	| T_SHORT ARRAY_FOR_STORE { $$ = new ArrayDeclaration("short", $2, 1); }
	| T_SHORT ARRAY_FOR_STORE T_SEMICOLON { $$ = new ArrayDeclaration("short", $2, 0); }



ARGUMENT_LIST_DEC : %empty { $$ = new empty();}
	| ARGUMENT_DEC { $$ = new ArgumentPair(NULL, $1, "dec");  }
	| ARGUMENT_LIST_DEC T_COMMA ARGUMENT_DEC { $$ = new ArgumentPair($1, $3, "dec"); }

ARGUMENT_LIST_CALL : %empty { $$ = new empty();}
	| ARGUMENT_CALL { $$ = new ArgumentPair(NULL, $1, "call"); }
	| ARGUMENT_LIST_CALL T_COMMA ARGUMENT_CALL { $$ = new ArgumentPair($1, $3, "call"); }

ARGUMENT_DEC : VAR_DECLARATION {$$ = $1;} //
	| VALUE_FOR_STORE { $$ = $1; } ////////////////////////////

ARGUMENT_CALL : VALUE { $$ = $1; } ////////////////////////////



ASSIGNMENT : ASSIGN {$$ = $1; }

ASSIGN : CONTAINER T_ASSIGN LOGIC T_SEMICOLON { $$ = new Assign($1, $3); }
	| CONTAINER T_ADDASSIGN LOGIC T_SEMICOLON { $$ = new AddAssign($1, $3); }
	| CONTAINER T_SUBASSIGN LOGIC T_SEMICOLON { $$ = new SubAssign($1, $3); }
	| CONTAINER T_MULTASSIGN LOGIC T_SEMICOLON { $$ = new MultAssign($1, $3); }
	| CONTAINER T_DIVASSIGN LOGIC T_SEMICOLON { $$ = new DivAssign($1, $3); }
	| CONTAINER T_MODASSIGN LOGIC T_SEMICOLON { $$ = new ModAssign($1, $3); }
	| CONTAINER T_ANDASSIGN LOGIC T_SEMICOLON { $$ = new AndAssign($1, $3); }
	| CONTAINER T_ORASSIGN LOGIC T_SEMICOLON { $$ = new OrAssign($1, $3); }
	| CONTAINER T_XORASSIGN LOGIC T_SEMICOLON { $$ = new XorAssign($1, $3); }
	| CONTAINER T_SLLASSIGN LOGIC T_SEMICOLON { $$ = new LeftShiftAssign($1, $3); }
	| CONTAINER T_SRLASSIGN LOGIC T_SEMICOLON { $$ = new RightShiftAssign($1, $3); }
	| VALUE T_INCREMENT T_SEMICOLON{ $$ = new Increment($1); }
	| VALUE T_DECREMENT T_SEMICOLON{ $$ = new Decrement($1); }

CONTAINER: VAR_DECLARATION { $$ = $1; }
	| VALUE_FOR_STORE { $$ = $1; }
	| ARRAY_FOR_STORE { $$ = $1; }



JUMP : RETURN { $$ = $1; }
	| FUNC_EVOKE T_SEMICOLON { $$ = $1; }
	| T_LABEL { $$ = new Label(*$1); }
	| T_GOTO T_VARIABLE T_SEMICOLON { $$ = new Goto(*$2); }

RETURN : T_RETURN LOGIC T_SEMICOLON { $$ = new Return($2); }




CONTROL : ELSE { $$ = $1; }
	| IF { $$ = $1; }
	| T_WHILE T_LBRACKET LOGIC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new While($3, $6); }
	| T_FOR T_LBRACKET LOGIC T_SEMICOLON STATEMENT T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new For($3, $5, $8); }
	| T_DO T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET T_WHILE T_LBRACKET LOGIC T_RBRACKET T_SEMICOLON { $$ = new DoWhile($3, $7); }

IF : T_IF T_LBRACKET LOGIC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET ELSE_IF_LIST { $$ = new If($3, $6, $8); }
	| T_IF T_LBRACKET LOGIC T_RBRACKET STATEMENT ELSE_IF_LIST { $$ = new If($3, $5, $6); }

ELSE : T_IF T_LBRACKET LOGIC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET ELSE_IF_LIST T_ELSE T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new IfElse($3, $6, $8, $11); }
 	| T_IF T_LBRACKET LOGIC T_RBRACKET STATEMENT ELSE_IF_LIST T_ELSE T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new IfElse($3, $5, $6, $9); }
	| T_IF T_LBRACKET LOGIC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET ELSE_IF_LIST T_ELSE STATEMENT { $$ = new IfElse($3, $6, $8 ,$10); }
	| T_IF T_LBRACKET LOGIC T_RBRACKET STATEMENT ELSE_IF_LIST T_ELSE STATEMENT { $$ = new IfElse($3, $5, $6, $8); }

ELSE_IF_LIST : %empty { $$ = new empty();}
	| ELSE_IF { $$ = $1;  }
	| ELSE_IF_LIST ELSE_IF { $$ = new ElseIfPair($1, $2); }

ELSE_IF : T_ELSEIF T_LBRACKET LOGIC T_RBRACKET T_LCURLBRACKET STATEMENT_LIST T_RCURLBRACKET { $$ = new ElseIf($3, $6); }

LOGIC: LOGIC2 { $$ = $1; }
	| T_LBRACKET LOGIC T_RBRACKET {$$ = new Parentheses($2); }

LOGIC2 : LOGIC3 { $$ = $1; }
	| LOGIC T_OR LOGIC3 { $$ = new Or($1, $3); }

LOGIC3 : LOGIC4 { $$ = $1; }
	| LOGIC3 T_AND LOGIC4 { $$ = new And($1, $3); }

LOGIC4 : LOGIC5 { $$ = $1; }
	| LOGIC4 T_BITOR LOGIC5 { $$ = new BitwiseOr($1, $3); }

LOGIC5 : LOGIC6 { $$ = $1; }
	| LOGIC5 T_BITXOR LOGIC6 { $$ = new BitwiseXor($1, $3); }

LOGIC6:	LOGIC7 { $$ = $1; }
	| LOGIC6 T_BITAND LOGIC7 { $$ = new BitwiseAnd($1, $3); }

LOGIC7: LOGIC8 { $$ = $1; }
	| LOGIC7 T_EQUAL LOGIC8 { $$ = new Equal($1, $3); }
	| LOGIC7 T_NOTEQUAL LOGIC8 { $$ = new NotEqual($1, $3); }

LOGIC8: SHIFT  { $$ = $1; }
	| LOGIC8 T_GREATER SHIFT { $$ = new GreaterThan($1, $3); }
	| LOGIC8 T_EQGT SHIFT { $$ = new GreaterThanOrEqual($1, $3); }
	| LOGIC8 T_LESS SHIFT { $$ = new LessThan($1, $3); }
	| LOGIC8 T_EQLT SHIFT { $$ = new LessThanOrEqual($1, $3); }

SHIFT : EXPR { $$ = $1; }
	| SHIFT T_SLL EXPR { $$ = new ShiftLeft($1, $3);}
	| SHIFT T_SRL EXPR { $$ = new ShiftRight($1, $3);}

EXPR : EXPR2 { $$ = $1; }
	| EXPR T_ADD EXPR2 { $$ = new Add($1, $3);}
	| EXPR T_SUB EXPR2 { $$ = new Sub($1, $3);}

EXPR2 : VALUE_WITH_FUNC { $$ = $1; }
	| EXPR2 T_MULT VALUE_WITH_FUNC {$$ = new Mult($1, $3);}
	| EXPR2 T_DIV VALUE_WITH_FUNC {$$ = new Div($1, $3);}
	| EXPR2 T_MOD VALUE_WITH_FUNC {$$ = new Mod($1, $3);}

VALUE_WITH_FUNC : FUNC_EVOKE { $$ = $1; }
	| VALUE { $$ = $1; }

VALUE : ARRAY { $$ = $1; }
	| T_NUMBER {$$ = new Number ($1); }
	| T_SUB T_NUMBER {$$ = new Number ($2 * -1); }
	| T_VARIABLE {$$ = new Variable (*$1, 0); }
	| T_POINTER { $$ = new Pointer(*$1, 0); }
	| T_CHAR_PRIMITIVE {$$ = new Char (*$1); }
	| T_ADDRESS { $$ = new Address(*$1); }


ARRAY : T_VARIABLE T_LSQR T_NUMBER T_RSQR { $$ = new Array(*$1, 0, $3); }

VALUE_FOR_STORE: T_VARIABLE { $$ = new Variable (*$1, 1); }
	| T_POINTER { $$ = new Pointer(*$1, 1); }

ARRAY_FOR_STORE : T_VARIABLE T_LSQR T_NUMBER T_RSQR { $$ = new Array(*$1, 1, $3); }

FUNC_EVOKE : VALUE T_LBRACKET ARGUMENT_LIST_CALL T_RBRACKET { $$ = new FunctionEvocation($1, $3); }


%%

const Statement *g_root; // Definition of variable (to match declaration earlier)

const Statement *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
