#include "number.hpp"
#include "memory.hpp"

Number::Number(unsigned short value) : value(value)
{
}

Number::~Number()
{
}

unsigned short Number::getValue(Memory& memory) const
{
    return value;
}
