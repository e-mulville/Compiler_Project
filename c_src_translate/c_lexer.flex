%option noyywrap

%{
extern "C" int fileno(FILE *stream);
int line;
#include "c_parser.tab.hpp"
%}

%x COMMENT
%x SINGLE_COMMENT

%%

"/*"            { BEGIN(COMMENT); }
<COMMENT>"*/" { BEGIN(INITIAL); }
<COMMENT>.    { }

"//"		{ BEGIN(SINGLE_COMMENT); }
<SINGLE_COMMENT>"\n" { BEGIN(INITIAL); }
<SINGLE_COMMENT>. { }

"=="		{ return T_EQUAL;}
"!="		{ return T_NOTEQUAL; }
"<"		{ return T_LESS; }
"<="		{ return T_EQLT; }
">"		{ return T_GREATER; }
">="		{ return T_EQGT; }

"&&"		{ return T_AND; }
"||"		{ return T_OR; }

[+]		{ return T_ADD; }
[-]		{ return T_SUB; }
[*]		{ return T_MULT; }
[/]		{ return T_DIV; }
[%]		{ return T_MOD; }

[=]		{ return T_ASSIGN;}
[;]		{ return T_SEMICOLON; }
[:]		{ return T_COLON; }
[,]		{ return T_COMMA; }



if		{ return T_IF; }
else		{ return T_ELSE; }
while		{ return T_WHILE; }

int		{ return T_INT; }
void		{ return T_VOID; }

return		{ return T_RETURN; }

[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[{]		{ return T_LCURLBRACKET; }
[}]		{ return T_RCURLBRACKET; }
	
[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER;  }
[a-zA-Z_][0-9a-zA-Z]*  { yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+	{ line++;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
    std::cout << "Failed at: " <<  line << std::endl;
  exit(1);
}
