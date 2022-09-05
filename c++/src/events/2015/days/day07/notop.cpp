#include "notop.hpp"
#include "memory.hpp"


NotOperator::NotOperator(Expression* expression): expression(expression)
{
}

NotOperator::~NotOperator()
{
    delete expression;
}

unsigned short NotOperator::getValue(Memory& memory) const
{
    return ~ expression->getValue(memory);
}
