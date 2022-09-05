#pragma once

#include "expression.hpp"

class Memory;

class OrOperator: public Expression
{
public:
    OrOperator(Expression* lvalue, Expression* rvalue);
    virtual ~OrOperator();
    virtual unsigned short getValue(Memory& memory) const;
private:
    Expression *lvalue, *rvalue;
};
