#ifndef ast_statement_hpp
#define ast_statement_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

class Statement;

static int var_number;


typedef const Statement *StatementPtr;

class Statement
{
public:
	virtual ~Statement(){}	

	int scope;
	std::string context;

	struct meta_data 
	{
		std::string Id;
		std::string context;
		int var_scope;
		int stack_address;
	};


	//! Tell and Statement to translate to stream
	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const =0;

	virtual void compile(std::ostream &dst, int &scope, std::string &context, std::vector<meta_data> &bindings) const =0;

	virtual std::string getId() const { return "error";}
	virtual double getValue() const { return 99999;}
	//! Evaluate the tree using the given mapping of variables to numbers
	
	virtual std::string makeName(std::string name, int scope) const{
		name += "_" + scope;
		return name;
	}
		
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

	virtual void compile(std::ostream &dst, int &scope, std::string &context, std::vector<meta_data> &bindings) const override
	{

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

	virtual void compile(std::ostream &dst, int &scope, std::string &context, std::vector<meta_data> &bindings) const override
	{

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

	virtual void compile(std::ostream &dst, int &scope, std::string &context, std::vector<meta_data> &bindings) const override
	{
		this_statement->compile(dst, scope, context, bindings);
		if (next != NULL)
		{
			next->compile(dst, scope, context, bindings);
			dst << std::endl;
		}
	}
};

#endif
