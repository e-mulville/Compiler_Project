#ifndef ast_jumps_hpp
#define ast_jumps_hpp

#include <string>
#include <iostream>

class Jump
	: public Statement
{
public:
	
	virtual void translate(std::ostream &dst, int &scope) const override
	{}
};

class Return
	: public Jump
{
public:
	StatementPtr value;
	
	Return(StatementPtr _value)
	: value(_value) {}

	virtual void translate(std::ostream &dst, int &scope) const override
	{
		dst << "return ";
		value->translate(dst, scope);
	}
	
};


#endif
