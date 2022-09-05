#pragma once

#include <string>

class Expression;

struct Assignment
{
    std::string variable;
    Expression *expression;
};

Assignment translate(const std::string& line);
