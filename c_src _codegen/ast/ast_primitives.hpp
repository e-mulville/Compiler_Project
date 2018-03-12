#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>

class Variable
	: public Statement
{
private:
	std::string id;
public:
	Variable(const std::string &_id)
		: id(_id)
	{}

	std::string getId() const override
	{ return id; }

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << getId();
	}

	virtual void compile(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << getId();
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

	virtual void compile(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst<<value;
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

	virtual void compile (std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		identifier->translate(dst, scope, scope_bindings);
		dst << "(";
		arg_list->translate(dst, scope, scope_bindings);
		dst << ")";
	}
	
};

class empty
	: public Statement
{
public:

	empty(){}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{}

	virtual void compile(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{}
};

#endif
