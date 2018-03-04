#include "ast.hpp"

#include <iomanip>

int yyparse();

int main(int argc, char **argv)
{	
	const Statement *ast=parseAST();

	ast->translate(std::cout);
	std::cout<<std::endl;
	
	return 0;
}
