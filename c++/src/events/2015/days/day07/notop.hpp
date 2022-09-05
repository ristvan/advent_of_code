#pragma once

#include "expression.hpp"

class Memory;

class NotOperator: public Expression
{
public:
    NotOperator(Expression* expression);
    virtual ~NotOperator();
    virtual unsigned short getValue(Memory& memory) const;
private:
    Expression *expression;
};
