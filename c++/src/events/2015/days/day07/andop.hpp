#pragma once

#include "expression.hpp"

class Memory;

class AndOperator: public Expression
{
public:
    AndOperator(Expression* lvalue, Expression* rvalue);
    virtual ~AndOperator();
    virtual unsigned short getValue(Memory& memory) const;
private:
    Expression *lvalue, *rvalue;
};
