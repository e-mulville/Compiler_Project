#include "ast.hpp"

#include <iomanip>
#include <vector>


int yyparse();
extern FILE * yyin;

int main(int argc, char **argv)
{
	int scope = 0;


	Statement::meta_data program_data;

	program_data.scope = 0;
	program_data.context = "global";
	program_data.stack_counter = 0;

	std::vector<Statement::var_data> bindings;

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

		outputFile << "# Boilerplate" << std::endl << "if __name__ == \"__main__\":" << std::endl;
		outputFile << "    import sys" << std::endl << "    ret=main()" << std::endl << "    sys.exit(ret)" << std::endl;
	}
	if (std::string(argv[1]) == "-S"){
		ast->compile(outputFile, program_data, bindings);
	}




	return 0;
}
