#ifndef ast_operator_hpp
#define ast_operator_hpp

#include <string>
#include <iostream>

class Operator
	: public Statement
{
protected:

	
public:
	StatementPtr left;
	StatementPtr right;

	Operator(StatementPtr _left, StatementPtr _right) :
	left(_left)
	, right(_right) {}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{}

	std::string getId() const override{
		return left->getId();
	}

	double getValue() const override
    	{ 
		return right->getValue();
	}
};

class Add
	: public Operator
{
public:
	
	Add(StatementPtr _left, StatementPtr _right)
	: Operator(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << " + ";
		right->translate(dst, scope, scope_bindings);
	}
	
};

class Sub
	: public Operator
{
public:
	
	Sub(StatementPtr _left, StatementPtr _right)
	: Operator(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << " - ";
		right->translate(dst, scope, scope_bindings);
	}
	
};

class Mult
	: public Operator
{
public:
	
	Mult(StatementPtr _left, StatementPtr _right)
	: Operator(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << " * ";
		right->translate(dst, scope, scope_bindings);
	}
	
};



#endif
