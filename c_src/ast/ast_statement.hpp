#ifndef ast_statement_hpp
#define ast_statement_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Statement;



typedef const Statement *StatementPtr;

class Statement
{
public:
    virtual ~Statement()
    {}

    //! Tell and Statement to translate to stream
    virtual void translate(std::ostream &dst) const =0;

    //! Evaluate the tree using the given mapping of variables to numbers
};


class StatementPair
	: public Statement
{
public:

	StatementPtr this_statement;
	StatementPtr next = NULL;

	StatementPair(StatementPtr _this_statement, StatementPtr _next) :
		this_statement(_this_statement)
		,next(_next)
	{}

	virtual void translate(	std::ostream &dst) const override
	{
		this_statement->translate(dst);
		if (next != NULL)
		{	
			next->translate(dst);
			dst << ";" << std::endl;
			
		} 
	}
};

class ArgumentPair
	: public Statement
{
public:

	StatementPtr this_statement;
	StatementPtr next = NULL;

	ArgumentPair(StatementPtr _this_statement, StatementPtr _next) :
		this_statement(_this_statement)
		,next(_next)
	{}

	virtual void translate(	std::ostream &dst) const override
	{
		this_statement->translate(dst);
		if (next != NULL)
		{
			dst << ", ";
			next->translate(dst);
		}
	}
};

#endif
