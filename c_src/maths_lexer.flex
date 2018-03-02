%option noyywrap

%{
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

%%

[=]		{ return T_ASSIGN; }
[;]		{ return T_SEMICOLON; }
[:]		{ return T_COLON; }
[,]		{ return T_COMMA; }

int		{ return T_INT; }

return		{ return T_RETURN; }

[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[{]		{ return T_LCURLBRACKET; }
[}]		{ return T_RCURLBRACKET; }
	



[-]?[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[a-zA-Z_][0-9a-zA-Z]*  { yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
