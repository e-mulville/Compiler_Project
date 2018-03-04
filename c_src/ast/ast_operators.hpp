#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>

class Operator
    : public Statement
{
protected:
    StatementPtr left;
    StatementPtr right;

    Operator(StatementPtr _left, StatementPtr _right)
        : left(_left)
        , right(_right)
    {}
public:
    virtual const char *getOpcode() const =0;

    StatementPtr getLeft() const
    { return left; }

    StatementPtr getRight() const
    { return right; }

    virtual void translate(std::ostream &dst) const override
    {
        dst<<"( ";
        left->translate(dst);
        dst<<" ";
        dst<<getOpcode();
        dst<<" ";
        right->translate(dst);
        dst<<" )";
    }
};

class AddOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "+"; }
public:
    AddOperator(StatementPtr _left, StatementPtr _right)
        : Operator(_left, _right)
    {}
};

class SubOperator
    : public Operator
{
protected:
    virtual const char *getOpcode() const override
    { return "-"; }
public:
    SubOperator(StatementPtr _left, StatementPtr _right)
        : Operator(_left, _right)
    {}
};


#endif
