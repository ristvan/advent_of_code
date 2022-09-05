#include "orop.hpp"
#include "memory.hpp"

OrOperator::OrOperator(Expression* lvalue, Expression* rvalue): lvalue(lvalue), rvalue(rvalue)
{
}

OrOperator::~OrOperator()
{
    delete lvalue;
    delete rvalue;
}

unsigned short OrOperator::getValue(Memory& memory) const
{
    return lvalue->getValue(memory) | rvalue->getValue(memory);
}
