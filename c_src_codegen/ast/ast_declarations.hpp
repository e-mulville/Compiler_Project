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

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
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
	{num = var_number; var_number = 0; }


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

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		int stack_move = (num+4)*4;
		program_data.context = var_dec->getId();
		program_data.stack_counter = 0;
		program_data.stack_size = stack_move;

		dst << std::endl << program_data.context << ":" << std::endl;
		dst << "addiu	$sp,$sp,-" << stack_move << std::endl;
		dst << "sw	$fp," << stack_move-4 << "($sp)" << std::endl;
		dst << "sw	$31," << stack_move-8 << "($sp)" << std::endl;
		dst << "move	$fp,$sp" << std::endl;
	
		program_data.stack_counter = stack_move; //so i can put above the stack
		arg_list->compile(dst, program_data, bindings); //will do save the first 4 arg in the space above the stack allocated.
		program_data.stack_counter = 8; //so i can allocate in the stack 
		//moving number to pass through the declarations and use in bindings - use meta_data?
		statement_list->compile(dst, program_data, bindings); 

		dst << "move	$2, $0" << std::endl; //default return 0
		dst << "move	$fp,$sp" << std::endl;
		dst << "lw	$31," << stack_move-8 << "($sp)" << std::endl;
		dst << "lw	$fp," << stack_move-4 << "($sp)" << std::endl;
		dst << "addiu	$sp,$sp," << stack_move << std::endl;
		dst << "j	$31" << std::endl;
		dst << "nop" << std::endl;
		program_data.context = "global";
		
		for (int x = 4; x < 8; x++){
			program_data.used_registers[x] = 0; //cleaning up for argument passing 
		}		
	}
};


class IntDeclaration
	: public Declaration
{
public:
	
	IntDeclaration(StatementPtr _identifier, bool _assigned)
	: Declaration("int", _identifier, _assigned) {var_number++;}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		if (assigned == 0){
			if (program_data.context == "global"){
				dst << ".comm	" << getId() << ",4,4";
			}
			var_data data;
			data.Id = getId();
			data.context = program_data.context;
			data.var_scope = program_data.scope;
			data.stack_address = program_data.stack_counter;
			data.type = type;
			bindings.push_back(data);
			program_data.stack_counter += 4;
			return;
			//dst << "declared variable id:" << data.Id << " context: " << data.context << " scope: " << data.var_scope << std::endl;
		}
		else if (assigned == 1){

			var_data data;
			data.Id = getId();

			if (program_data.context == "global"){
				dst << "	.data" << std::endl;
				dst << "	.align	2" << std::endl;
				dst << "	.type	" << data.Id << ", @object" << std::endl;
				dst << "	.size	" << data.Id << ", 4" << std::endl;
				dst << data.Id << ":" << std::endl;
				dst << "	.word	"; //neeeeed value maybe what if not assiged just declare		
			}

			data.context = program_data.context;
			data.var_scope = program_data.scope;
			data.stack_address = program_data.stack_counter;
			data.type = type;
			program_data.stack_counter += 4;
			bindings.push_back(data);
			if (program_data.context != "global"){
				identifier->compile(dst, program_data, bindings);
			}
			return;

			//dst << "declared variable id:" << data.Id << " context: " << data.context << " scope: " << data.var_scope << std::endl;
		}
	}

};

class CharDeclaration
	: public Declaration
{
public:
	
	CharDeclaration(StatementPtr _identifier, bool _assigned)
	: Declaration("char", _identifier, _assigned) {var_number++;}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		if (assigned == 0){
			if (program_data.context == "global"){
				dst << ".comm	" << getId() << ",4,4";
			}
			var_data data;
			data.Id = getId();
			data.context = program_data.context;
			data.var_scope = program_data.scope;
			data.stack_address = program_data.stack_counter;
			data.type = type;
			bindings.push_back(data);
			program_data.stack_counter += 4;
			return;
			//dst << "declared variable id:" << data.Id << " context: " << data.context << " scope: " << data.var_scope << std::endl;
		}
		else if (assigned == 1){

			var_data data;
			data.Id = getId();

			if (program_data.context == "global"){
				dst << "	.data" << std::endl;
				dst << "	.align	2" << std::endl;
				dst << "	.type	" << data.Id << ", @object" << std::endl;
				dst << "	.size	" << data.Id << ", 1" << std::endl;
				dst << data.Id << ":" << std::endl;
				dst << "	.byte	"; //neeeeed value maybe what if not assiged just declare		
			}

			data.context = program_data.context;
			data.var_scope = program_data.scope;
			data.stack_address = program_data.stack_counter;
			data.type = type;
			program_data.stack_counter += 4;
			bindings.push_back(data);
			if (program_data.context != "global"){
				identifier->compile(dst, program_data, bindings);
			}
			return;
			//dst << "declared variable id:" << data.Id << " context: " << data.context << " scope: " << data.var_scope << std::endl;
		}
	}
};

class ShortDeclaration
	: public Declaration
{
public:
	
	ShortDeclaration(StatementPtr _identifier, bool _assigned)
	: Declaration("short", _identifier, _assigned) {var_number++;}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		if (assigned == 0){
			if (program_data.context == "global"){
				dst << ".comm	" << getId() << ",4,4";
			}
			var_data data;
			data.Id = getId();
			data.context = program_data.context;
			data.var_scope = program_data.scope;
			data.stack_address = program_data.stack_counter;
			data.type = type;
			bindings.push_back(data);
			program_data.stack_counter += 4;
			return;
			//dst << "declared variable id:" << data.Id << " context: " << data.context << " scope: " << data.var_scope << std::endl;
		}
		else if (assigned == 1){

			var_data data;
			data.Id = getId();

			if (program_data.context == "global"){
				dst << "	.data" << std::endl;
				dst << "	.align	2" << std::endl;
				dst << "	.type	" << data.Id << ", @object" << std::endl;
				dst << "	.size	" << data.Id << ", 2" << std::endl;
				dst << data.Id << ":" << std::endl;
				dst << "	.word	"; //neeeeed value maybe what if not assiged just declare		
			}

			data.context = program_data.context;
			data.var_scope = program_data.scope;
			data.stack_address = program_data.stack_counter;
			data.type = type;
			program_data.stack_counter += 4;
			bindings.push_back(data);
			if (program_data.context != "global"){
				identifier->compile(dst, program_data, bindings);
			}
			return;
			//dst << "declared variable id:" << data.Id << " context: " << data.context << " scope: " << data.var_scope << std::endl;
		}
	}
};

class ArrayDeclaration
	: public Declaration
{
public:
	
	ArrayDeclaration(std::string _type, StatementPtr _identifier, bool _assigned)
	: Declaration(_type, _identifier, _assigned) {var_number += _identifier->getValue();}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		if (assigned == 0){
			if (program_data.context == "global"){
				dst << "	.comm	" << getId() << "," << identifier->getValue()*4 << ",4" << std::endl;
				var_data data;
				data.Id = getId();
				data.context = program_data.context;
				data.var_scope = program_data.scope;
				data.stack_address = program_data.stack_counter;
				data.type = type;
				bindings.push_back(data);
				program_data.stack_counter += 4;
				return;
			}
			else {
				for (double x = identifier->getValue(); x >= 0; x--){
					var_data data;
					std::string tempId = getId();
					tempId += "[" + std::to_string(x) + "]";
					data.Id = tempId;
					data.context = program_data.context;
					data.var_scope = program_data.scope;
					data.stack_address = program_data.stack_counter;
					data.type = type;
					bindings.push_back(data);
					program_data.stack_counter += 4;
				}
				return;
			}
			//dst << "declared variable id:" << data.Id << " context: " << data.context << " scope: " << data.var_scope << std::endl;
		}
		else if (assigned == 1){
			return;

			//dst << "declared variable id:" << data.Id << " context: " << data.context << " scope: " << data.var_scope << std::endl;
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
