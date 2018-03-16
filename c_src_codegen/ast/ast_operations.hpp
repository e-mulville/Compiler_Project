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
		int x = 8;

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }
		
		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);
			dst << "addu	$2, $2, $" << x << std::endl;

			program_data.used_registers[x] = 0;
		}
		else {
			program_data.stack_size += 4;
			int current_stack = program_data.stack_size;
			dst << "addu	$sp, $sp, -4" << std::endl;			
			dst << "sw	$2, 8($sp)" << std::endl;
			left->compile(dst, program_data, bindings);
			dst << "lw	$3," << (program_data.stack_size-current_stack)+8 << "($sp)" << std::endl;
			dst << "addu	$sp, $sp, 4" << std::endl;
			program_data.stack_size -= 4;
			dst << "addu	$2, $2, $3" << std::endl;
		}
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
		int x = 8;

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }
		
		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);
			dst << "subu	$2, $2, $" << x << std::endl;

			program_data.used_registers[x] = 0;
		}
		else {
			program_data.stack_size += 4;
			int current_stack = program_data.stack_size;
			dst << "addu	$sp, $sp, -4" << std::endl;			
			dst << "sw	$2, 8($sp)" << std::endl;
			left->compile(dst, program_data, bindings);
			dst << "lw	$3," << (program_data.stack_size-current_stack)+8 << "($sp)" << std::endl;
			dst << "addu	$sp, $sp, 4" << std::endl;
			program_data.stack_size -= 4;
			dst << "subu	$2, $2, $3" << std::endl;
		}			
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

		int x = 8;

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }
		
		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);
			dst << "mult	$2, $" << x << std::endl;
			dst << "mflo	$2" << std::endl; 

			program_data.used_registers[x] = 0;
		}
		else {
			program_data.stack_size += 4;
			int current_stack = program_data.stack_size;
			dst << "addu	$sp, $sp, -4" << std::endl;			
			dst << "sw	$2, 8($sp)" << std::endl;
			left->compile(dst, program_data, bindings);
			dst << "lw	$3," << (program_data.stack_size-current_stack)+8 << "($sp)" << std::endl;
			dst << "addu	$sp, $sp, 4" << std::endl;
			program_data.stack_size -= 4;
			dst << "mult	$2, $3" << x << std::endl;
			dst << "mflo	$2" << std::endl; 
		}
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
		int x = 8;

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }
		program_data.used_registers[x] = 1;

		dst << "move	$" << x;
		dst<< ", $2" << std::endl;

		left->compile(dst, program_data, bindings);
		dst << "mult	$2, $" << x << std::endl;
		dst << "mflo	$2" << std::endl; 

		program_data.used_registers[x] = 0;		

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
