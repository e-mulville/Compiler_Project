%option noyywrap

%{
/* Now in a section of C that will be embedded
   into the auto-generated code. Flex will not
   try to interpret code surrounded by %{ ... %} */

/* Bring in our declarations for token types and
   the yylval variable. */
#include "histogram.hpp"
#include <string>
#include <cstring>
#include <iostream>


// This is to work around an irritating bug in Flex
// https://stackoverflow.com/questions/46213840/get-rid-of-warning-implicit-declaration-of-function-fileno-in-flex
extern "C" int fileno(FILE *stream);

/* End the embedded code section. */
%}


%%

[[][^\n\]]*[]]     {fprintf(stderr, "Wordsq : %s\n", yytext);  yylval.wordValue = new std::string(yytext); yylval.wordValue->erase(0,1);yylval.wordValue->erase(yylval.wordValue->length()-1,1); fprintf(stderr, "Wordsq : %s\n", yytext); return Word;}



([-]?[0-9]+[.][0-9]*|[-]?[0-9]+)[/]([0-9]+[.][0-9]*|[0-9]+) { fprintf(stderr, "Fraction : %s\n", yytext); 
			std::string number(yytext);
			std::string numerator;
			std::string denominator;
			int temp;
			
			for (int x = 0; number[x] != '/'; x++){
				numerator += number[x];
				temp = x;
			}
			
			for (int x = temp + 2; x != number.size(); x++){
				denominator += number[x];
			}

			yylval.numberValue = (std::stod(numerator) / std::stod(denominator)); return Number; 
			
			} 

[-]?[0-9]+          { fprintf(stderr, "Number : %s\n", yytext); yylval.numberValue = std::atoi(yytext); return Number; }

[-]?[0-9]+[.][0-9]* { fprintf(stderr, "Number : %s\n", yytext); yylval.numberValue = std::atof(yytext); return Number; } 




[A-Za-z]+          { fprintf(stderr, "Word : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[+]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[-]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[/]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[*]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[%]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[=]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[&]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[+=]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[-=]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[++]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[--]		{ fprintf(stderr, "Operator : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[>]		{ fprintf(stderr, "Logic : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[>=]		{ fprintf(stderr, "Logic : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[<]		{ fprintf(stderr, "Logic : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[!]		{ fprintf(stderr, "Logic : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[<=]		{ fprintf(stderr, "Logic : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[!=]		{ fprintf(stderr, "Logic : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[==]		{ fprintf(stderr, "Logic : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[&&]		{ fprintf(stderr, "Logic : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[||]		{ fprintf(stderr, "Logic : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[^]		{ fprintf(stderr, "Logic : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[(]		{ fprintf(stderr, "Symbol : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[)]		{ fprintf(stderr, "Symbol : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[{]		{ fprintf(stderr, "Symbol : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[}]		{ fprintf(stderr, "Symbol : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

[//]		{ fprintf(stderr, "Symbol : %s\n", yytext); yylval.wordValue = new std::string(yytext); return Word; }

\n              { fprintf(stderr, "Newline\n"); }

. {}

%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}
