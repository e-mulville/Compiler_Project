#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>

class Declaration
	: public Statement
{
protected:
	StatementPtr left;
	StatementPtr right;

	Declaration(StatementPtr _left, StatementPtr _right)
	: left(_left)
	, right(_right)
	{}
public:

	StatementPtr getLeft() const
	{ return left; }

	StatementPtr getRight() const
	{ return right; }
	
	virtual void translate(	std::ostream &dst) const override
	{
		throw std::runtime_error("FunctionOperator::evaluate is not implemented.");
	}
};







class FuncDeclaration
	: public Declaration
{
public:
	FuncDeclaration(StatementPtr _left, StatementPtr _right)
		: Declaration(_left, _right)
	{}

	virtual void translate(std::ostream &dst) const override
	{
		dst << "AYYYYY";
	}
};


#endif
