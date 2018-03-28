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
		int x = 8;
		std::string not_label = makeName("not_start");
		std::string end_label = makeName("not_end");

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);



			dst << "bne	$2, $" << x << ", " << not_label << std::endl;;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;

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

			dst << "bne	$2, $3, " << not_label << std::endl;;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;
			dst << "addu	$2, $2, $3" << std::endl;
		}

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
				int x = 8;
		std::string not_label = makeName("not_start");
		std::string end_label = makeName("not_end");

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);



			dst << "beq	$2, $" << x << ", " << not_label << std::endl;;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;

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

			dst << "beq	$2, $3, " << not_label << std::endl;;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;
			dst << "addu	$2, $2, $3" << std::endl;
		}

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
		int x = 8;

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);
			dst << "slt	$2, $" << x << ", $2" << std::endl; //do this

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
			dst << "addu	$2, $3, $2" << std::endl;
		}

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
		int x = 8;
		std::string not_label = makeName("not_start");
		std::string end_label = makeName("not_end");

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);


			dst << "slt	$2, $2, $" << x << std::endl;
			dst << "bne	$2, $0, " << not_label << std::endl;;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move	$2, $0" << std::endl;
			dst << end_label << ":" << std::endl;

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

			dst << "slt	$2, $2, $3" << std::endl;
			dst << "bne	$2, $3, " << not_label << std::endl;;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;
			dst << "addu	$2, $2, $3" << std::endl;
		}

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
		int x = 8;

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);
			dst << "slt	$2, $2, $" << x << std::endl;

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
			dst << "slt	$2, $2, $3" << std::endl;
		}

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
		int x = 8;
		std::string not_label = makeName("not_start");
		std::string end_label = makeName("not_end");

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);


			dst << "slt	$2, $" << x << ", $2" << std::endl;
			dst << "bne	$2, $0, " << not_label << std::endl;;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;

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

			dst << "slt	$2, $3, $2" << std::endl;
			dst << "bne	$2, $3, " << not_label << std::endl;;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;
			dst << "addu	$2, $2, $3" << std::endl;
		}
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
		int x = 8;
		std::string not_label = makeName("not_start");
		std::string end_label = makeName("not_end");

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);


			dst << "slt	$2, $0, $2" << std::endl;
			dst << "beq	$2, $0, " << not_label << std::endl;
			dst << "nop" << std::endl;
			dst << "slt	$2, $0, $" << x << std::endl;
			dst << "beq	$2, $0, " << not_label << std::endl;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;

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

			dst << "slt	$2, $0, $2" << std::endl;
			dst << "bne	$2, $0, " << not_label << std::endl;
			dst << "nop" << std::endl;
			dst << "slt	$2, $0, $3" << std::endl;
			dst << "bne	$2, $0, " << not_label << std::endl;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;
			dst << "addu	$2, $2, $3" << std::endl;
		}
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
		int x = 8;
		std::string not_label = makeName("not_start");
		std::string end_label = makeName("not_end");

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);


			dst << "slt	$2, $0, $2" << std::endl;
			dst << "slt	$" << x << ", $0, $" << x << std::endl;
			dst << "or	$2, $2, $" << x << std::endl;
			dst << "beq	$2, $0, " << not_label << std::endl;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;

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

			dst << "slt	$2, $0, $2" << std::endl;
			dst << "slt	$3, $0, $3" << std::endl;
			dst << "or	$2, $2, $3" << std::endl;
			dst << "bne	$2, $0, " << not_label << std::endl;
			dst << "nop" << std::endl;
			dst << "li	$2, 1" << std::endl;
			dst << "beq	$0, $0, " << end_label << std::endl;
			dst << "nop" << std::endl;
			dst << not_label << ":" << std::endl;
			dst << "move $2, $0" << std::endl;
			dst << end_label << ":" << std::endl;
			dst << "addu	$2, $2, $3" << std::endl;
		}

	}

};

class BitwiseAnd
	: public Logic
{
public:

	BitwiseAnd(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{

		int x = 8;

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }
		program_data.used_registers[x] = 1;

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);

			dst << "and	$2, $2, $" << x << std::endl;

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

			dst << "and	$2, $2, $3" << std::endl;
		}
	}
};

class BitwiseOr
	: public Logic
{
public:

	BitwiseOr(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{

		int x = 8;

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }
		program_data.used_registers[x] = 1;

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);

			dst << "or	$2, $2, $" << x << std::endl;

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

			dst << "or	$2, $2, $3" << std::endl;
		}
	}
};


class BitwiseXor
	: public Logic
{
public:

	BitwiseXor(StatementPtr _left, StatementPtr _right)
	: Logic(_left, _right)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{

		int x = 8;

		right->compile(dst, program_data, bindings);

		while (program_data.used_registers[x] == 1) { x++; }
		program_data.used_registers[x] = 1;

		if (x <= 25){
			program_data.used_registers[x] = 1;

			dst << "move	$" << x;
			dst<< ", $2" << std::endl;

			left->compile(dst, program_data, bindings);

			dst << "xor	$2, $2, $" << x << std::endl;

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

			dst << "xor	$2, $2, $3" << std::endl;
		}
	}
};



#endif
