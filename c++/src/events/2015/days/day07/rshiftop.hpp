#pragma once

#include "expression.hpp"

class Memory;

class RightShiftOperator: public Expression
{
public:
    RightShiftOperator(Expression* lvalue, Expression* rvalue);
    virtual ~RightShiftOperator();
    virtual unsigned short getValue(Memory& memory) const;
private:
    Expression *lvalue, *rvalue;
};

