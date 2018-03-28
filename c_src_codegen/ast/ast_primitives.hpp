#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>

class Variable
	: public Statement
{
private:
	std::string id;
	bool store;
public:
	Variable(const std::string &_id, bool _store)
		: id(_id)
		, store(_store)
	{}

	std::string getId() const override
	{ return id; }


	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << getId();
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		for (int x = (bindings.size()-1); x >= 0; x--){
			if ((bindings[x].Id == id) && (bindings[x].context == program_data.context) && (bindings[x].var_scope <= program_data.scope)){
				if (bindings[x].type == "int"){
					if (store == 1){
						dst << "sw	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
						return;
					}
					else if(store == 0){
						dst << "lw	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
						return;
					}
				}
				if (bindings[x].type == "char"){
					if (store == 1){
						dst << "sb	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
						return;
					}
					else if(store == 0){
						dst << "lb	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
						return;
					}
				}
				if (bindings[x].type == "short"){
					if (store == 1){
						dst << "sh	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
						return;
					}
					else if(store == 0){
						dst << "lh	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
						return;
					}
				}
			}
			else if ((bindings[x].Id == id) && (bindings[x].context == "global")){
				if(bindings[x].type == "int"){
					if (store == 1){
						dst << "lui	$3,%hi(" << id << ")" << std::endl;
						dst << "addiu	$3,$3,%lo(" << id << ")" << std::endl;
						dst << "sw	$2,  0($3)" << std::endl;
						return;
					}
					else if(store == 0){
						dst << "lui	$2,%hi(" << id << ")" << std::endl;
						dst << "lw	$2,%lo(" << id << ")($2)" << std::endl;
						return;
					}
				}
				if(bindings[x].type == "char"){
					if (store == 1){
						dst << "lui	$3,%hi(" << id << ")" << std::endl;
						dst << "addiu	$3,$3,%lo(" << id << ")" << std::endl;
						dst << "sb	$2,  0($3)" << std::endl;
						return;
					}
					else if(store == 0){
						dst << "lui	$2,%hi(" << id << ")" << std::endl;
						dst << "lb	$2,%lo(" << id << ")($2)" << std::endl;
						return;
					}
				}
				if(bindings[x].type == "short"){
					if (store == 1){
						dst << "lui	$3,%hi(" << id << ")" << std::endl;
						dst << "addiu	$3,$3,%lo(" << id << ")" << std::endl;
						dst << "sh	$2,  0($3)" << std::endl;
						return;
					}
					else if(store == 0){
						dst << "lui	$2,%hi(" << id << ")" << std::endl;
						dst << "lh	$2,%lo(" << id << ")($2)" << std::endl;
						return;
					}
				}
			}
		}
		dst << "cant find variable id:" << id << " context: " << program_data.context << " scope: " << program_data.scope << std::endl;
	}
};

class Pointer
	: public Statement
{
private:
	std::string id;
	bool store;
public:
	Pointer(const std::string &_id, bool _store)
		: id(_id)
		, store(_store)
	{}

	std::string getId() const override
	{
	return id;
	}


	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << getId();
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		for (int x = (bindings.size()-1); x >= 0; x--){
			if ((bindings[x].Id == getId()) && (bindings[x].context == program_data.context) && (bindings[x].var_scope <= program_data.scope)){
				if (bindings[x].type == "int"){
					if (store == 1){
						dst << "move	$3, $2" << std::endl;
						GetLoad(dst, program_data, bindings, getId());
						dst << "sw	$3, ($2)" << std::endl;
						return;
					}
					else if(store == 0){
						GetLoad(dst, program_data, bindings, getId());
						dst << "lw	$2, ($2)" << std::endl;
						return;
					}
				}
				if (bindings[x].type == "char"){
					if (store == 1){
						dst << "move	$3, $2" << std::endl;
						GetLoad(dst, program_data, bindings, getId());
						dst << "sb	$3, ($2)" << std::endl;
						return;
					}
					else if(store == 0){
						GetLoad(dst, program_data, bindings, getId());
						dst << "lb	$2, ($2)" << std::endl;
						return;
					}
				}
				if (bindings[x].type == "short"){
					if (store == 1){
						dst << "move	$3, $2" << std::endl;
						GetLoad(dst, program_data, bindings, getId());
						dst << "sh	$3, ($2)" << std::endl;
						return;
					}
					else if(store == 0){
						GetLoad(dst, program_data, bindings, getId());
						dst << "lh	$2, ($2)" << std::endl;
						return;
					}
				}
			}
		}
		dst << "cant find variable id:" << id << " context: " << program_data.context << " scope: " << program_data.scope << std::endl;
	}
};

class Char
	: public Statement
{
private:
	std::string value;
public:
	Char(const std::string &_value)
		: value(_value)
	{}

	double getValue() const override
	{
	char temp = value[1];
	return temp; }

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst<<value;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{

		dst<< "li	$2, " << value << std::endl;
	}
};

class Address
	: public Statement
{
private:
	std::string value;
public:
	Address(const std::string &_value)
		: value(_value)
	{}

	std::string getId() const override
	{
	std::string id = value;
	id.erase(0, 1);
	return id;
	}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst<<value;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		for (int x = (bindings.size()-1); x >= 0; x--){
			if ((bindings[x].Id == getId()) && (bindings[x].context == program_data.context) && (bindings[x].var_scope <= program_data.scope)){
				dst << "move	$2, $fp" << std::endl;
				dst << "addiu $2, $2, " << bindings[x].stack_address << std::endl;
				return;
			}
			else if ((bindings[x].Id == getId()) && (bindings[x].context == "global")){
				dst << "lui	$2,%hi(" << getId() << ")" << std::endl;
				dst << "addiu	$2,$2,%lo(" << getId() << ")" << std::endl;
				return;
			}
		}
	}
};


class Number
	: public Statement
{
private:
	double value;
public:
	Number(double _value)
		: value(_value)
	{}

	double getValue() const override
	{ return value; }

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst<<value;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		dst<< "li	$2, " << value << std::endl;
	}
};

class FunctionEvocation
	: public Statement
{
public:
	StatementPtr identifier;
	StatementPtr arg_list;

	FunctionEvocation(StatementPtr _identifier, StatementPtr _arg_list)
	: identifier(_identifier)
	, arg_list(_arg_list)
	{}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		identifier->translate(dst, scope, scope_bindings);
		dst << "(";
		arg_list->translate(dst, scope, scope_bindings);
		dst << ")";
	}

	virtual void compile (std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		meta_data saved_context = program_data;
		std::string function_name = identifier->getId();
		/*program_data.context = function_name;
		program_data.scope = 0;
		program_data.stack_counter = 0;
		program_data.stack_size = 0;*/

		dst << "addiu	$sp,$sp,-76" << std::endl;
		int y = 1;
		for (int x = 8; x < 26; x++){
			dst << "sw	$" << x << ", " << y*4 << "($sp)" << std::endl;
			y++;
		}
		arg_list->compile(dst, program_data, bindings);
		//save and restore program data
		//and the registers apart from 2 and 3
		dst << "jal	" << function_name << std::endl;

		y = 18;
		for (int x = 25; x > 7; x--){
			dst << "lw	$" << x << ", " << y*4 << "($sp)" << std::endl;
			y--;
		}
		dst << "addiu	$sp,$sp, 76" << std::endl;

		program_data = saved_context;
	}

};


class Label
	: public Statement
{
private:
	std::string id;
public:
	Label(const std::string &_id)
		: id(_id)
	{}

	std::string getId() const override
	{
		std::string temp = id;
		temp.pop_back();
		return temp;
	}


	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << getId();
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		dst << id << std::endl;
	}
};

class Array
	: public Statement
{
private:
	std::string id;
	bool store;
	double position;
public:
	Array(const std::string &_id, bool _store, double _position)
	: id(_id)
	, store(_store)
	, position(_position)
	{}

	std::string getId() const override
	{
		return id;
	}

	double getValue() const override
	{
		return position;
	}


	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << id;
	}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		for (int x = (bindings.size()-1); x >= 0; x--){
			std::string tempId = getId();
			tempId += "[" + std::to_string(position) + "]";
			if ((bindings[x].Id == tempId) && (bindings[x].context == program_data.context) && (bindings[x].var_scope <= program_data.scope)){
				if (store == 1){
					dst << "sw	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
					return;
				}
				else if(store == 0){
					dst << "lw	$2, " << bindings[x].stack_address << "($fp)" << std::endl;
					return;
				}

			}
			else if ((bindings[x].Id == id) && (bindings[x].context == "global")) {
				dst << "la	$3," << id << std::endl;
				if (store == 1){
					dst << "sw	$2," << position*4 << "($3)" << std::endl;
					dst << "cant find variable id:" << tempId << " context: " << program_data.context << " scope: " << program_data.scope << std::endl;
					return;
				}
				else if(store == 0){
					dst << "lw	$2," << position*4 << "($3)" << std::endl;
					dst << "cant find variable id:" << tempId << " context: " << program_data.context << " scope: " << program_data.scope << std::endl;
					return;
				}

			}
		}
	}
};

class empty
	: public Statement
{
public:

	empty(){}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{}

	virtual void compile(std::ostream &dst, meta_data &program_data, std::vector<var_data> &bindings) const override
	{
		dst << "nop" << std::endl;
	}
};

#endif
