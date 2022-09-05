#pragma once

#include "expression.hpp"

class Memory;

class LeftShiftOperator: public Expression
{
public:
    LeftShiftOperator(Expression* lvalue, Expression* rvalue);
    virtual ~LeftShiftOperator();
    virtual unsigned short getValue(Memory& memory) const;
private:
    Expression *lvalue, *rvalue;
};
