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
		//save and restore program data
		//and the registers apart from 2 and 3
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
	{}
};

#endif
