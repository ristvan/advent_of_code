#pragma once

#include "expression.hpp"
#include <string>

class Memory;

class Number: public Expression
{
public:
    Number(unsigned short value);
    virtual ~Number();
    virtual unsigned short getValue(Memory& memory) const;
private:
    unsigned short value;
};
