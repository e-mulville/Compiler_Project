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

    const std::string getId() const
    { return id; }

    virtual void translate(std::ostream &dst, int &scope) const override
    {
        dst<<id;
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

    double getValue() const
    { return value; }

    virtual void translate(std::ostream &dst, int &scope) const override
    {
        dst<<value;
    }
};


class DataType
	: public Statement
{
public:
	
	std::string type;

	DataType(): type(){}

	virtual void translate(std::ostream &dst, int &scope) const override
	{
		dst<< type;
	}
};

class empty
	: public Statement
{
public:

	empty() {}

	virtual void translate(std::ostream &dst, int &scope) const override
	{}
};

#endif
