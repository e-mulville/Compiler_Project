#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include <string>
#include <iostream>
#include "includes.hpp"

extern int var_number;

class Declaration
	: public Statement
{
protected:
	std::string type;
	StatementPtr identifier;
	bool assigned;

	Declaration(std::string _type, StatementPtr _identifier, bool _assigned)
	: type(_type)
	, identifier(_identifier)
	, assigned(_assigned)
	{}
public:
	
	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		scope_bindings.insert( std::make_pair( getId(), scope ) );
        	identifier->translate(dst, scope, scope_bindings);
		if (assigned == 0){
			dst << "=0" << std::endl;	
		}
	}

	virtual void compile(std::ostream &dst, int &scope, std::string &context, std::vector<meta_data> &bindings) const override
	{

	}

	std::string getId() const override{
		return identifier->getId();
	}
};





class FuncDeclaration
	: public Statement
{
public:
	StatementPtr var_dec;
	StatementPtr arg_list;
	StatementPtr statement_list;
	int num;
	
	FuncDeclaration(StatementPtr _var_dec, StatementPtr _arg_list, StatementPtr _statement_list)
	: var_dec(_var_dec)
	, arg_list(_arg_list)
	, statement_list(_statement_list)
	{num = var_number; std::cout << var_number; var_number = 0; }


	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst<<"def ";
		scope++;
		var_dec->translate(dst, scope, scope_bindings);
		dst<<"(";
		arg_list->translate(dst, scope, scope_bindings);
		dst << "):" << std::endl;
		for (const auto& element : scope_bindings){
   			if (element.second == 0){
				for(int x = 0; x < scope; x++){
					dst << "    ";
				}
        			dst << "global " << element.first << std::endl;
			}
		}
		statement_list->translate(dst, scope, scope_bindings);
		scope--;
	}

	virtual void compile(std::ostream &dst, int &scope, std::string &context, std::vector<meta_data> &bindings) const override
	{
		int stack_move = num*4;
		context = var_dec->getId();
		dst << context << ":" << std::endl;
		arg_list->compile(dst, scope, context, bindings); //will do linking/map stuff copying but changing context to current context
		dst << "addiu	$sp,$sp,-" << stack_move << std::endl;
		dst << "sw	$fp," << stack_move-4 << "($sp)" << std::endl;
		 
		
		//moving number to pass through the declarations and use in bindings - use meta_data?
		statement_list->compile(dst, scope, context, bindings); 

		dst << "sw	$fp," << stack_move-4 << "($sp)" << std::endl;
		dst << "addiu	$sp,$sp," << stack_move << std::endl;
		dst << "j $31" << std::endl;
		dst << "nop" << std::endl;
		context = "global";
		
	}
};


class IntDeclaration
	: public Declaration
{
public:
	
	IntDeclaration(StatementPtr _identifier, bool _assigned)
	: Declaration("", _identifier, _assigned) {var_number++;}

	virtual void compile(std::ostream &dst, int &scope, std::string &context, std::vector<meta_data> &bindings) const override
	{
		meta_data data;
		meta_data data_last = bindings.back();
		data.Id = getId();
		data.context = context;
		data.var_scope = scope;
		if(bindings.size() != 0){
			data.stack_address = (data_last.stack_address+4);
		}
		else {
			data.stack_address = 0;
		}
		
	}

};

class VoidDeclaration
	: public Declaration
{
public:
	
	VoidDeclaration(StatementPtr _identifier, bool _assigned)
	: Declaration("", _identifier, _assigned) {}

};


#endif
