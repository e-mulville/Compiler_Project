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

	virtual void translate(std::ostream &dst, int &scope) const override
	{}
};

class Assign
	: public Assignment
{
public:
	
	Assign(StatementPtr _left, StatementPtr _right)
	: Assignment(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope) const override
	{
		dst<< left->getId() << "=" << right->getValue();
		left->translate(dst, scope);
		dst << " = ";
		right->translate(dst, scope);
	}
	
};


#endif
