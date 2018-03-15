#ifndef ast_statement_hpp
#define ast_statement_hpp

#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <memory>

class Statement;

static int var_number;
static int name_counter = 0;


typedef const Statement *StatementPtr;

class Statement
{
public:
	virtual ~Statement(){}	

	struct var_data
	{
		std::string Id;
		std::string context;
		int var_scope;
		int stack_address;
	};

	struct meta_data 
	{
		int scope;
		std::string context;
		int stack_counter;
		int stack_size;
	};


	

	//! Tell and Statement to translate to stream
	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const =0;

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const =0;

	virtual std::string getId() const { return "error";}
	virtual double getValue() const { return 99999;}
	//! Evaluate the tree using the given mapping of variables to numbers
	
	/*virtual std::string makeName(std::string name) const {
		name += "_";
		name += name_counter;
		name_counter++;
		return name;
	} weird bug */
		
	
	
	virtual std::string makeName(std::string name) const {
		std::string temp = name;
		temp += "_"; 
		temp += std::to_string(name_counter);
		name_counter++;
		return temp;
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

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
	this_statement->compile(dst, program_data, bindings);
		if (next != NULL)
		{
			next->compile(dst, program_data, bindings);
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

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
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

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		this_statement->compile(dst, program_data, bindings);
		if (next != NULL)
		{
			next->compile(dst, program_data, bindings);
		}
	}
};

#endif
