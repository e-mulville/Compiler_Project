#ifndef ast_logics_hpp
#define ast_logics_hpp

#include <string>
#include <iostream>

class Logic
	: public Statement
{
protected:

	
public:
	StatementPtr left;
	StatementPtr right;

	Logic(StatementPtr _left, StatementPtr _right) :
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

class Equal
	: public Logic
{
public:
	
	Equal(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "==";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		

	}
	
};

class NotEqual
	: public Logic
{
public:
	
	NotEqual(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "!=";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		

	}
	
};

class GreaterThan
	: public Logic
{
public:
	
	GreaterThan(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << ">";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		

	}
	
};

class GreaterThanOrEqual
	: public Logic
{
public:
	
	GreaterThanOrEqual(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << ">=";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		

	}
	
};

class LessThan
	: public Logic
{
public:
	
	LessThan(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "<";
		right->translate(dst, scope, scope_bindings);
	}
	
	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		

	}
};

class LessThanOrEqual
	: public Logic
{
public:
	
	LessThanOrEqual(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "<=";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		
	}
	
	
};

class And
	: public Logic
{
public:
	
	And(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		left->translate(dst, scope, scope_bindings);
		dst << "&&";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{

	}
	
};

class Or
	: public Logic
{
public:
	
	Or(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		
		left->translate(dst, scope, scope_bindings);
		dst << "||";
		right->translate(dst, scope, scope_bindings);
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		

	}
	
};


#endif
