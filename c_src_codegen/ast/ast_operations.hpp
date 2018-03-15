#ifndef ast_operator_hpp
#define ast_operator_hpp

#include <string>
#include <iostream>

class Operator
	: public Statement
{
protected:

	
public:
	StatementPtr left;
	StatementPtr right;

	Operator(StatementPtr _left, StatementPtr _right) :
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

class Add
	: public Operator
{
public:
	
	Add(StatementPtr _left, StatementPtr _right)
	: Operator(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "+";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		
		right->compile(dst, program_data, bindings);
		dst << "mov	$3, $2" << std::endl;
		left->compile(dst, program_data, bindings);
		dst << "addu	$2, $2, $3" << std::endl;
	}
	
};

class Sub
	: public Operator
{
public:
	
	Sub(StatementPtr _left, StatementPtr _right)
	: Operator(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "-";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		
	}
	
};

class Mult
	: public Operator
{
public:
	
	Mult(StatementPtr _left, StatementPtr _right)
	: Operator(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "*";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		
	}
	
};

class Div
	: public Operator
{
public:
	
	Div(StatementPtr _left, StatementPtr _right)
	: Operator(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "/";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		

	}
	
};

class Mod
	: public Operator
{
public:
	
	Mod(StatementPtr _left, StatementPtr _right)
	: Operator(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "%";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		

	}
	
};

class Parentheses
	: public Statement
{
public:
	
	StatementPtr expr;
		
	Parentheses(StatementPtr _expr)
	: expr(_expr)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << "(";
		expr->translate(dst, scope, scope_bindings);
		dst << ")";
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{

	}
	
	
};



#endif
