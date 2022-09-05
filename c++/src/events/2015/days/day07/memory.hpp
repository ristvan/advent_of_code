#pragma once

#include <map>
#include <string>

class Expression;

class Memory
{
public:
    Memory();
    ~Memory();
    void add(const std::string& variableName, Expression* expression);
    unsigned short get(const std::string& variableName);

private:
    std::map<std::string, Expression*> values;
    std::map<std::string, unsigned short> cache;
};
