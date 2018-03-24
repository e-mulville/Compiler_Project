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

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{}

	std::string getId() const override{
		return left->getId();
	}

	double getValue() const override
    	{ 
		return right->getValue();
	}
};

class Assign
	: public Assignment
{
public:
	
	Assign(StatementPtr _left, StatementPtr _right)
	: Assignment(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "=";
		right->translate(dst, scope, scope_bindings);
		dst << std::endl;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		
		if (program_data.context == "global"){
			dst << "	.abicalls" << std::endl;
			left->compile(dst, program_data, bindings);
			dst << getValue() << std::endl;
			dst << "	.text" << std::endl;
		}
		else {	
			right->compile(dst, program_data, bindings);	
			left->compile(dst, program_data, bindings);
		}
	}
	
};

class AddAssign
	: public Assignment
{
public:
	
	AddAssign(StatementPtr _left, StatementPtr _right)
	: Assignment(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "+=";
		right->translate(dst, scope, scope_bindings);
		dst << std::endl;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		right->compile(dst, program_data, bindings);
		dst << "move	$3, $2" << std::endl;
		GetLoad(dst, program_data, bindings, getId());
		dst << "addu	$2, $2, $3" << std::endl;
		left->compile(dst, program_data, bindings);
	}
	
};

class SubAssign
	: public Assignment
{
public:
	
	SubAssign(StatementPtr _left, StatementPtr _right)
	: Assignment(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "=";
		right->translate(dst, scope, scope_bindings);
		dst << std::endl;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{	
		right->compile(dst, program_data, bindings);
		dst << "move	$3, $2" << std::endl;
		GetLoad(dst, program_data, bindings, getId());
		dst << "subu	$2, $2, $3" << std::endl;
		left->compile(dst, program_data, bindings);
	}
	
};

class MultAssign
	: public Assignment
{
public:
	
	MultAssign(StatementPtr _left, StatementPtr _right)
	: Assignment(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "=";
		right->translate(dst, scope, scope_bindings);
		dst << std::endl;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		right->compile(dst, program_data, bindings);
		dst << "move	$3, $2" << std::endl;
		GetLoad(dst, program_data, bindings, getId());
		dst << "mult	$2, $3" << std::endl;
		dst << "mflo	$2" << std::endl;
		left->compile(dst, program_data, bindings);
	}
	
};

class DivAssign
	: public Assignment
{
public:
	
	DivAssign(StatementPtr _left, StatementPtr _right)
	: Assignment(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "=";
		right->translate(dst, scope, scope_bindings);
		dst << std::endl;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		
		right->compile(dst, program_data, bindings);
		dst << "move	$3, $2" << std::endl;
		GetLoad(dst, program_data, bindings, getId());
		dst << "div	$2, $3" << std::endl;
		dst << "mflo	$2" << std::endl;
		left->compile(dst, program_data, bindings);
	}
	
};

class ModAssign
	: public Assignment
{
public:
	
	ModAssign(StatementPtr _left, StatementPtr _right)
	: Assignment(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "=";
		right->translate(dst, scope, scope_bindings);
		dst << std::endl;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		
		right->compile(dst, program_data, bindings);
		dst << "move	$3, $2" << std::endl;
		GetLoad(dst, program_data, bindings, getId());
		dst << "rem	$2, $2, $3" << std::endl;
		left->compile(dst, program_data, bindings);
	}
	
};


#endif
