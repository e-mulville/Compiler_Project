#include "ast.hpp"

#include <iomanip>

int yyparse();

int main(int argc, char **argv)
{	
	const Statement *ast=parseAST();
	int scope = 0;
	
	std::map<std::string,double> scope_bindings;	

	ast->translate(std::cout, scope, scope_bindings);
	std::cout << std::endl << "if __name__ == \"__main__\":" << std::endl;
	std::cout << "	import sys" << std::endl << "	ret=main()" << std::endl << "	sys.exit(ret)" << std::endl;

	
	return 0;
}
