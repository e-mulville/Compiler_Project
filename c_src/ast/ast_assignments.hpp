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

	virtual void translate(	std::ostream &dst) const override
	{}
};

class Assign
	: public Assignment
{
public:
	
	Assign(StatementPtr _left, StatementPtr _right)
	: Assignment(_left, _right)
	{}

	virtual void translate(	std::ostream &dst) const override
	{
		left->translate(dst);
		dst << " = ";
		right->translate(dst);
	}
	
};


#endif
