%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

%%
[*]             { return T_TIMES; }
[+]             { return T_PLUS; }
[-]		{ return T_MINUS; }
[\^]            { return T_EXPONENT; }
[/]		{ return T_DIVIDE; }
[%]		{ return T_REMAINDER; }
[=]		{ return T_ASSIGN; }
[&]		{ return T_LAND; }
[+=]		{ return T_ADDASSIGN; }
[-=]		{ return T_SUBASSIGN; }
[++]		{ return T_INCREMENT; }
[--]		{ return T_DECREMENT; }
[>]		{ return T_GT; }
[>=]		{ return T_GTOE; }
[<]		{ return T_LT; }
[!]		{ return T_NOT; }
[<=]		{ return T_LTOE; }
[!=]		{ return T_NOTEQUALS; }
[==]		{ return T_EQUALS; }
[&&]		{ return T_AND; }
[||]		{ return T_OR; }
[^]		{ return T_XOR; }
[//]		{ return T_COMMENT; }
[#]		{ return T_HASH; }
[;]		{ return T_SEMICOLON; }
[:]		{ return T_COLON; }
[,]		{ return T_COMMA; }

int		{ return T_INT; }
double		{ return T_DOUBLE; }
short		{ return T_SHORT; }
long		{ return T_LONG; }
char		{ return T_CHAR; }

for		{ return T_FOR; }
if		{ return T_IF; }
else		{ return T_ELSE; }
while		{ return T_WHILE; }
do		{ return T_DO; }

goto
return

[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[{]		{ return T_LCURLBRACKET; }
[}]		{ return T_RCURLBRACKET; }
[\[]		{ return T_RSQRBRACKET; }
[]]		{ return T_RSQRLBRACKET; }

log             { return T_LOG;   }
exp             { return T_EXP; }
sqrt            { return T_SQRT; }
		
	



[-]?[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[a-z]+          { yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
