#include "variable.hpp"
#include "memory.hpp"
#include <string>

using namespace std;


Variable::Variable(const string& name) : name(name)
{
}

Variable::~Variable()
{
}

unsigned short Variable::getValue(Memory& memory) const
{
    return memory.get(name);
}

string Variable::getName() const
{
    return name;
}
