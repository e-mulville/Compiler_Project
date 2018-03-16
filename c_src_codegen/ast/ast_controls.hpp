#ifndef ast_controls_hpp
#define ast_controls_hpp

#include <string>
#include <iostream>

extern int name_counter;

class Control
	: public Statement
{
protected:

	
public:

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{}
	
	
	

	/*std::string getId() const override{
		return left->getId();
	}

	double getValue() const override
    	{ 
		return right->getValue();
	}*/
};

class If
	: public Control
{
public:
	StatementPtr condition;
	StatementPtr body;

	If(StatementPtr _condition, StatementPtr _body) :
	condition(_condition)
	, body(_body) {}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << "if(";
		condition->translate(dst, scope, scope_bindings);
		dst << "):" << std::endl;
		scope++;
		body->translate(dst, scope, scope_bindings);
		scope--;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		condition->compile(dst, program_data, bindings);
		std::string if_label = makeName("if_end");
		
		dst << "beq	$2, $0, " << if_label << std::endl;
		dst << "nop" << std::endl;
		body->compile(dst, program_data, bindings);
		dst << if_label << ":" << std::endl;
	}
	
};

class IfElse
	: public Control
{
public:
	StatementPtr if_condition;
	StatementPtr if_body;
	StatementPtr else_body;

	IfElse(StatementPtr _if_condition, StatementPtr _if_body, StatementPtr _else_body) :
	if_condition(_if_condition)
	, if_body(_if_body)	
	, else_body(_else_body) {}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << "if(";
		if_condition->translate(dst, scope, scope_bindings);
		dst << "):" << std::endl;
		scope++;
		if_body->translate(dst, scope, scope_bindings);
		scope--;
		for(int x = 0; x < scope; x++){
			dst << "	";
		}
		dst << "else:" << std::endl;		
		scope++;
		for(int x = 0; x < scope; x++){
			dst << "	";
		}
		else_body->translate(dst, scope, scope_bindings);
		scope--;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		if_condition->compile(dst, program_data, bindings);
		std::string if_label = makeName("if_end");
		std::string else_label = makeName("else_end");
		
		dst << "beq	$2, $0, " << if_label << std::endl;
		dst << "nop" << std::endl;
		if_body->compile(dst, program_data, bindings);
		dst << "beq	$0, $0, " << else_label << std::endl;
		dst << "nop" << std::endl;
		dst << if_label << ":" << std::endl;
		
		else_body->compile(dst, program_data, bindings);
		dst << else_label << ":" << std::endl;
	}
	
};

class While
	: public Control
{
public:
	StatementPtr condition;
	StatementPtr body;

	While(StatementPtr _condition, StatementPtr _body) :
	condition(_condition)
	, body(_body) {}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << "while (";
		condition->translate(dst, scope, scope_bindings);
		dst << "):" << std::endl;	
		scope++;
		for(int x = 0; x < scope; x++){
			dst << "	";
		}
		body->translate(dst, scope, scope_bindings);
		scope--;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		condition->compile(dst, program_data, bindings);
		std::string start_label = makeName("while_start");
		std::string end_label = makeName("while_end");
		

		dst << start_label << ":" << std::endl;
		condition->compile(dst, program_data, bindings);
		dst << "beq	$2, $0, " << end_label << std::endl;
		dst << "nop" << std::endl;
		body->compile(dst, program_data, bindings);
		dst << "beq	$0, $0, " << start_label << std::endl;
		dst << end_label << ":" << std::endl;
		
	}

	
	
};



#endif
