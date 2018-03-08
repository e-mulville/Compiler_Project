#include "ast.hpp"

#include <iomanip>


int yyparse();
extern FILE * yyin;

int main(int argc, char **argv)
{	
	int scope = 0;
	

	std::map<std::string,double> scope_bindings;	
	
	FILE *myfile = fopen(argv[2], "r");
	if (!myfile) {
		std::cout << "I can't open the file!" << std::endl;
		return -1;
	}
	yyin = myfile;
	
	std::ofstream outputFile;
	
	outputFile.open(std::string(argv[4]));

	const Statement *ast=parseAST();

	if (std::string(argv[1]) == "--translate"){
		ast->translate(outputFile, scope, scope_bindings);
	}
	
	outputFile << "# Boilerplate" << std::endl << "if __name__ == \"__main__\":" << std::endl;
	outputFile << "    import sys" << std::endl << "    ret=main()" << std::endl << "    sys.exit(ret)" << std::endl;

	
	return 0;
}
