#ifndef ast_assignments_hpp
#define ast_assignments_hpp

#include <string>
#include <iostream>

class Assignment
	: public Statement
{
protected:

	
public:
	StatementPtr left;
	StatementPtr right;

	Assignment(StatementPtr _left, StatementPtr _right) :
	left(_left)
	, right(_right) {}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{}

	virtual void compile(std::ostream &dst, int &scope, std::string &context, std::vector<meta_data> &bindings) const override
	{}

	std::string getId() const override{
		return left->getId();
	}

	double getValue() const override
    	{ 
		return right->getValue();
	}
};

class Assign
	: public Assignment
{
public:
	
	Assign(StatementPtr _left, StatementPtr _right)
	: Assignment(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "=";
		right->translate(dst, scope, scope_bindings);
		dst << std::endl;
	}

	virtual void compile(std::ostream &dst, int &scope, std::string &context, std::vector<meta_data> &bindings) const override
	{

	}
	
};


#endif
