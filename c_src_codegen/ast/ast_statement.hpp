#ifndef ast_statement_hpp
#define ast_statement_hpp


#include "includes.hpp"
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
		bool used_registers[32] {0};
		
	};


	

	//! Tell and Statement to translate to stream
	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const =0;

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const =0;

	virtual std::string getId() const { return "error";}
	virtual double getValue() const { return 99999;}


	virtual void GetStore(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings, std::string id) const
	{
		for (int x = (bindings.size()-1); x >= 0; x--){
			if ((bindings[x].Id == id) && (bindings[x].context == program_data.context) && (bindings[x].var_scope <= program_data.scope)){
				dst << "sw	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
			}
		}
	}

	virtual void GetLoad(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings, std::string id) const
	{
		for (int x = (bindings.size()-1); x >= 0; x--){
			if ((bindings[x].Id == id) && (bindings[x].context == program_data.context) && (bindings[x].var_scope <= program_data.scope)){
				dst << "lw	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
			}
		}
	}
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

	StatementPtr prev_statement;
	StatementPtr this_statement = NULL;
	std::string type;

	ArgumentPair(StatementPtr _prev_statement, StatementPtr _this_statement, std::string _type) :
		prev_statement(_prev_statement)
		, this_statement(_this_statement)
		, type(_type)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		if (prev_statement != NULL){
			prev_statement->translate(dst, scope, scope_bindings);
		}
		if (prev_statement == NULL){
			this_statement->translate(dst, scope, scope_bindings);	
		}
		else
		{	
			dst << ",";
			this_statement->translate(dst, scope, scope_bindings);	
		}
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		if (prev_statement != NULL){
			prev_statement->compile(dst, program_data, bindings);
		}
		
		if (type == "dec") {
				int x = 4;
				while (program_data.used_registers[x] == 1) { x++; }
				program_data.used_registers[x] = 1;

				if (x < 8){
				
					dst << "move	$2, $" << x << std::endl; 
				}
				
				this_statement->compile(dst, program_data, bindings);
		}
		if (type == "call") {
				this_statement->compile(dst, program_data, bindings);			
				
				int x = 4;
				while (program_data.used_registers[x] == 1) { x++; }
				program_data.used_registers[x] = 1;

				if (x < 8){
					dst << "move	$2, $" << x << std::endl; 
				}
		}
	}
};

class ProgramPair
	: public Statement
{
public:

	StatementPtr prev_statement;
	StatementPtr this_statement = NULL;

	ProgramPair(StatementPtr _prev_statement, StatementPtr _this_statement) :
		prev_statement(_prev_statement)
		,this_statement(_this_statement)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		prev_statement->translate(dst, scope, scope_bindings);
		if (this_statement != NULL)
		{
			this_statement->translate(dst, scope, scope_bindings);
			dst << std::endl;
		}
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		prev_statement->compile(dst, program_data, bindings);
		if (this_statement != NULL)
		{
			this_statement->compile(dst, program_data, bindings);
		}
	}
};

#endif
