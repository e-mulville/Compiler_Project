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
	bool assigned;

	Declaration(std::string _type, StatementPtr _identifier, bool _assigned)
	: type(_type)
	, identifier(_identifier)
	, assigned(_assigned)
	{}
public:
	
	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		scope_bindings.insert( std::make_pair( getId(), scope ) );
        	identifier->translate(dst, scope, scope_bindings);
		if (assigned == 0){
			dst << "=0" << std::endl;	
		}
	}

	virtual void compile(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		scope_bindings.insert( std::make_pair( getId(), scope ) );
        	identifier->translate(dst, scope, scope_bindings);
		if (assigned == 0){
			dst << "=0" << std::endl;	
		}
	}

	std::string getId() const override{
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

	

	virtual void translate(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst<<"def ";
		scope++;
		var_dec->translate(dst, scope, scope_bindings);
		dst<<"(";
		arg_list->translate(dst, scope, scope_bindings);
		dst << "):" << std::endl;
		for (const auto& element : scope_bindings){
   			if (element.second == 0){
				for(int x = 0; x < scope; x++){
					dst << "    ";
				}
        			dst << "global " << element.first << std::endl;
			}
		}
		statement_list->translate(dst, scope, scope_bindings);
		scope--;
	}

	virtual void compile(std::ostream &dst, int &scope, std::map<std::string,double> &scope_bindings) const override
	{
		dst<<"def ";
		scope++;
		var_dec->translate(dst, scope, scope_bindings);
		dst<<"(";
		arg_list->translate(dst, scope, scope_bindings);
		dst << "):" << std::endl;
		for (const auto& element : scope_bindings){
   			if (element.second == 0){
				for(int x = 0; x < scope; x++){
					dst << "    ";
				}
        			dst << "global " << element.first << std::endl;
			}
		}
		statement_list->translate(dst, scope, scope_bindings);
		scope--;
	}
};


class IntDeclaration
	: public Declaration
{
public:
	
	IntDeclaration(StatementPtr _identifier, bool _assigned)
	: Declaration("", _identifier, _assigned) {}

};

class VoidDeclaration
	: public Declaration
{
public:
	
	VoidDeclaration(StatementPtr _identifier, bool _assigned)
	: Declaration("", _identifier, _assigned) {}

};


#endif
