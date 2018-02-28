%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

%%
[+]             { return T_ADD; }
[-]		{ return T_SUB; }
[/]		{ return T_DIV; }
[*]             { return T_MUL; }
[%]		{ return T_MOD; }
[=]		{ return T_ASSIGN; }
[&]		{ return T_LAND; }
[+=]		{ return T_ADDASSIGN; }
[-=]		{ return T_SUBASSIGN; }
[++]		{ return T_INCREMENT; }
[--]		{ return T_DECREMENT; }
[*=]		{ return T_MULASSIGN; }
[/=]		{ return T_DIVASSIGN; }
[%=]		{ return T_MODASSIGN; }
[^=]		{ return T_XORASSIGN; }
[|=]		{ return T_ORASSIGN; }
[>>=]		{ return T_RIGHTASSIGN; }
[<<=]		{ return T_LEFTASSIGN; }
[>]		{ return T_GT; }
[>=]		{ return T_GTOE; }
[<]		{ return T_LT; }
[<=]		{ return T_LTOE; }
[!]		{ return T_NOT; }
[!=]		{ return T_NOTEQUALS; }
[==]		{ return T_EQUALS; }
[&&]		{ return T_AND; }
[||]		{ return T_OR; }
[\^]		{ return T_XOR; }
[//]		{ return T_COMMENT; }
[;]		{ return T_SEMICOLON; }
[:]		{ return T_COLON; }
[,]		{ return T_COMMA; }

int		{ return T_INT; }
double		{ return T_DOUBLE; }
short		{ return T_SHORT; }
long		{ return T_LONG; }
char		{ return T_CHAR; }
float		{ return T_FLOAT; }
signed		{ return T_SIGNED; }
unsigned	{ return T_UNSIGNED; }
struct		{ return T_STRUCT; }
void		{ return T_VOID; }
register	{ return T_REGISTER; } //hints to put variable in regiser

for		{ return T_FOR; }
if		{ return T_IF; }
else		{ return T_ELSE; }
while		{ return T_WHILE; }
do		{ return T_DO; }

goto		{ return T_GOTO; }
return		{ return T_RETURN; }

switch		{ return T_SWITCH;} //kinda like if-else
case		{ return T_CASE; } //used with switch
default		{ return T_DEFAULT; } //used with switch

auto		{;} //does nothing at all
break		{ return T_BREAK; }//breaks out of loops
continue	{ return T_CONTINUE; } //opposite of break

const


enum		{ return T_ENUM; } //some funky list thing
extern		{ return T_EXTERN; }//funky variable declaring thing
sizeof		{ return T_SIZEOF; }


typedef		{ return T_TYPEDEF; }
union		{ return T_UNION; }
volatile	{;} //prabably ignore it


[(]             { return T_LBRACKET; }
[)]             { return T_RBRACKET; }
[{]		{ return T_LCURLBRACKET; }
[}]		{ return T_RCURLBRACKET; }
[\[]		{ return T_LSQRBRACKET; }
[]]		{ return T_RSQRLBRACKET; }
	



[-]?[0-9]+([.][0-9]*)? { yylval.number=strtod(yytext, 0); return T_NUMBER; }
[a-zA-Z]+[0-9a-zA-Z]*  { yylval.string=new std::string(yytext); return T_VARIABLE; }

[ \t\r\n]+		{;}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }
%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
