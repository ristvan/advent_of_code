#include "lshiftop.hpp"
#include "memory.hpp"

LeftShiftOperator::LeftShiftOperator(Expression* lvalue, Expression* rvalue): lvalue(lvalue), rvalue(rvalue)
{
}

LeftShiftOperator::~LeftShiftOperator()
{
    delete lvalue;
    delete rvalue;
}

unsigned short LeftShiftOperator::getValue(Memory& memory) const
{
    return lvalue->getValue(memory) << rvalue->getValue(memory);
}
