#include "ast.hpp"

#include <iomanip>

int yyparse();

int main(int argc, char **argv)
{	
	const Statement *ast=parseAST();
	int scope = 0;
	
	struct translate_pair {
		int scope;
		int identifier;
	}

	

	ast->translate(std::cout, scope);
	std::cout << std::endl << "if __name__ == \"__main__\":" << std::endl;
	std::cout << "import sys" << std::endl << "ret=main()" << std::endl << "sys.exit(ret)";

	
	return 0;
}
