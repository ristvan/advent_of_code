#include "memory.hpp"
#include "expression.hpp"

#include <map>
#include <iostream>

using namespace std;

Memory::Memory()
{
}

Memory::~Memory()
{
    for (auto [variableName, expression]: values)
        delete expression;
}

void Memory::add(const std::string& variableName, Expression* expression)
{
    if (values.count(variableName) > 0)
    {
        delete values[variableName];
        cache.clear();
    }
    values[variableName] = expression;
}


unsigned short Memory::get(const std::string& variableName)
{
    auto value = cache.find(variableName);
    unsigned short result = 0;
    if (value == cache.end())
    {
        result = values[variableName]->getValue(*this);
        cache[variableName] = result;
    }
    else
    {
        result = cache[variableName];
    }
    return result;
}
