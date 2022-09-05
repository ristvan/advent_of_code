#include "rshiftop.hpp"
#include "expression.hpp"
#include "memory.hpp"

RightShiftOperator::RightShiftOperator(Expression* lvalue, Expression* rvalue): lvalue(lvalue), rvalue(rvalue)
{
}

RightShiftOperator::~RightShiftOperator()
{
    delete lvalue;
    delete rvalue;
}

unsigned short RightShiftOperator::getValue(Memory& memory) const
{
    return lvalue->getValue(memory) >> rvalue->getValue(memory);
}
