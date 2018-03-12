#ifndef ast_controls_hpp
#define ast_controls_hpp

#include <string>
#include <iostream>

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

	virtual void compile(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst << "if(";
		condition->translate(dst, scope, scope_bindings);
		dst << "):" << std::endl;
		scope++;
		body->translate(dst, scope, scope_bindings);
		scope--;
	}
	
};

class IfElse
	: public Control
{
public:
	StatementPtr _if;
	StatementPtr body;

	IfElse(StatementPtr __if, StatementPtr _body) :
	_if(__if)	
	, body(_body) {}

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		_if->translate(dst, scope, scope_bindings);
		for(int x = 0; x < scope; x++){
			dst << "	";
		}
		dst << "else:" << std::endl;		
		scope++;
		for(int x = 0; x < scope; x++){
			dst << "	";
		}
		body->translate(dst, scope, scope_bindings);
		scope--;
	}

	virtual void compile(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		_if->translate(dst, scope, scope_bindings);
		for(int x = 0; x < scope; x++){
			dst << "	";
		}
		dst << "else:" << std::endl;		
		scope++;
		for(int x = 0; x < scope; x++){
			dst << "	";
		}
		body->translate(dst, scope, scope_bindings);
		scope--;
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

	virtual void compile(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
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

	
	
};



#endif
