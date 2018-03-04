#ifndef ast_statement_hpp
#define ast_statement_hpp

#include <string>
#include <iostream>
#include <map>

#include <memory>

class Statement;

typedef const Statement *StatementPtr;

class Statement
{
public:
    virtual ~Statement()
    {}

    //! Tell and Statement to translate to stream
    virtual void translate(std::ostream &dst) const =0;

    //! Evaluate the tree using the given mapping of variables to numbers
};


#endif
