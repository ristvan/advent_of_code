#include "andop.hpp"
#include "memory.hpp"

AndOperator::AndOperator(Expression* lvalue, Expression* rvalue): lvalue(lvalue), rvalue(rvalue)
{
}

AndOperator::~AndOperator()
{
    delete lvalue;
    delete rvalue;
}

unsigned short AndOperator::getValue(Memory& memory) const
{
    return lvalue->getValue(memory) & rvalue->getValue(memory);
}

