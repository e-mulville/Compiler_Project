#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>

class Variable
	: public Statement
{
private:
	std::string id;
	bool store;
public:
	Variable(const std::string &_id, bool _store)
		: id(_id)
		, store(_store) 
	{}

	std::string getId() const override
	{ return id; }
	

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << getId();
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		for (int x = (bindings.size()-1); x >= 0; x--){
			if ((bindings[x].Id == id) && (bindings[x].context == program_data.context) && (bindings[x].var_scope <= program_data.scope)){
				if (store == 1){
					dst << "sw	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
				}
				else if(store == 0){
					dst << "lw	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
				}
			}
			else if ((bindings[x].Id == id) && (bindings[x].context == "global")){
				if (store == 1){
					dst << "sw	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
				}
				else if(store == 0){
					dst << "lw	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
				}
			}
		}
		
		
	}


};

class Number
	: public Statement
{
private:
	double value;
public:
	Number(double _value)
		: value(_value)
	{}

	double getValue() const override
	{ return value; }

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst<<value;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		dst<< "li	$2, " << value << std::endl;	
	}
};

class FunctionEvocation
	: public Statement
{
public:
	StatementPtr identifier;
	StatementPtr arg_list;
		
	FunctionEvocation(StatementPtr _identifier, StatementPtr _arg_list)
	: identifier(_identifier)
	, arg_list(_arg_list)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		identifier->translate(dst, scope, scope_bindings);
		dst << "(";
		arg_list->translate(dst, scope, scope_bindings);
		dst << ")";
	}

	virtual void compile (std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{ 
		meta_data saved_context = program_data;
		std::string function_name = identifier->getId();
		program_data.context = function_name;
		program_data.scope = 0;
		program_data.stack_counter = 0;
		program_data.stack_size = 0;
		
		dst << "addiu	$sp,$sp,-76" << std::endl;
		int y = 1;
		for (int x = 8; x < 26; x++){
			dst << "sw	$" << x << ", " << y*4 << "($sp)" << std::endl;
			y++;
		}

		//save and restore program data
		//and the registers apart from 2 and 3
		dst << 	"lw	$2, %got(" << function_name << ")($28)" << std::endl;
		dst << "jalr	$2" << std::endl;

		y = 18;
		for (int x = 25; x > 7; x--){
			dst << "lw	$" << x << ", " << y*4 << "($sp)" << std::endl;
			y--;
		}
		dst << "addiu	$sp,$sp, 76" << std::endl;

		program_data = saved_context;
	}
	
};

class empty
	: public Statement
{
public:

	empty(){}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		dst << "nop" << std::endl;	
	}
};

#endif
