#include "translator.hpp"
#include "common/string_manipulators.hpp"
#include "expression.hpp"
#include "number.hpp"
#include "variable.hpp"
#include "notop.hpp"
#include "andop.hpp"
#include "orop.hpp"
#include "rshiftop.hpp"
#include "lshiftop.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


Expression* getValue(const string& token)
{
    Expression *value = nullptr;
    if (isNumber(token))
        value = new Number((unsigned short) stoi(token));
    else
        value = new Variable(token);

    return value;
}

Assignment translate(const string& line)
{
    vector<string> tokens = split(line, " ");
    size_t length = tokens.size();
    Expression *value = nullptr;
    if (length == 3) {
        value = getValue(tokens[0]);
    }
    else if (length == 4)
    {
        if (tokens[0] == "NOT")
        {
            Expression *rvalue = getValue(tokens[1]);
            value = new NotOperator(rvalue);
        }
        else
            cerr << "ERROR: Invalid Operator" << endl;
    }
    else if (length == 5)
    {
        Expression *lvalue = getValue(tokens[0]);
        Expression *rvalue = getValue(tokens[2]);
        if ("AND" == tokens[1])
        {
            value = new AndOperator(lvalue, rvalue);
        }
        else if ("OR" == tokens[1])
        {
            value = new OrOperator(lvalue, rvalue);
        }
        else if ("LSHIFT" == tokens[1])
        {
            value = new LeftShiftOperator(lvalue, rvalue);
        }
        else if ("RSHIFT" == tokens[1])
        {
            value = new RightShiftOperator(lvalue, rvalue);
        }
        else
            cerr << "ERROR: Invalid Operator (2 arguments)" << endl;

    }
    else
        cout << "ERROR" << endl;

    Assignment assignment;
    assignment.variable = tokens[tokens.size() - 1];
    assignment.expression = value;
    return assignment;
}