#pragma once

#include "expression.hpp"
#include <string>

class Memory;

class Variable: public Expression
{
public:
    Variable(const std::string& name);
    virtual ~Variable();
    virtual unsigned short getValue(Memory& memory) const;
    std::string getName() const;
private:
    std::string name;
};
