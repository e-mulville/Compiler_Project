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
	virtual ~Statement(){}	

	int scope;


	//! Tell and Statement to translate to stream
	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const =0;

	virtual std::string getId() const { return "error";}
	virtual double getValue() const { return 99999;}
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

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		this_statement->translate(dst, scope, scope_bindings);
		if (next != NULL)
		{	
			for(int x = 0; x < scope; x++){
				dst << "    ";
			}
			next->translate(dst, scope, scope_bindings);

			
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

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		this_statement->translate(dst, scope, scope_bindings);
		if (next != NULL)
		{
			dst << ",";
			next->translate(dst, scope, scope_bindings);
		}
	}
};

class ProgramPair
	: public Statement
{
public:

	StatementPtr this_statement;
	StatementPtr next = NULL;

	ProgramPair(StatementPtr _this_statement, StatementPtr _next) :
		this_statement(_this_statement)
		,next(_next)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		this_statement->translate(dst, scope, scope_bindings);
		if (next != NULL)
		{
			next->translate(dst, scope, scope_bindings);
			dst << std::endl;
		}
	}
};

#endif
