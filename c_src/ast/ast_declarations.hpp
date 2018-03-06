#ifndef ast_declaration_hpp
#define ast_declaration_hpp

#include <string>
#include <iostream>

class Declaration
	: public Statement
{
protected:
	std::string type;
	StatementPtr identifier;

	Declaration(std::string _type, StatementPtr _identifier)
	: type(_type)
	, identifier(_identifier)
	{}
public:
	
	virtual void translate(std::ostream &dst, int &scope) const override
	{
		dst<< type << " ";
        	identifier->translate(dst, scope);
	}

	std::string getId() const override {
		return identifier->getId();
	}
};





class FuncDeclaration
	: public Statement
{
public:
	StatementPtr var_dec;
	StatementPtr arg_list;
	StatementPtr statement_list;
	
	FuncDeclaration(StatementPtr _var_dec, StatementPtr _arg_list, StatementPtr _statement_list)
	: var_dec(_var_dec)
	, arg_list(_arg_list)
	, statement_list(_statement_list)
	{}

	

	virtual void translate(std::ostream &dst, int &scope) const override
	{
		dst<<"def";
		var_dec->translate(dst, scope);
		dst<<" (";
		arg_list->translate(dst, scope);
		dst << "):" << std::endl;
		scope++;
		statement_list->translate(dst, scope);
		scope--;
	}
};


class IntDeclaration
	: public Declaration
{
public:
	
	IntDeclaration(StatementPtr _identifier)
	: Declaration("", _identifier) {}

};


#endif
