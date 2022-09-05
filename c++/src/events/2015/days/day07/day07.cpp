#include "day07.hpp"
#include "common/file_handler.hpp"
#include "translator.hpp"
#include "memory.hpp"
#include "expression.hpp"
#include "number.hpp"
#include <string>
#include <vector>


using namespace std;


Day07::Day07(): valueOfA(0)
{
}

Day07::~Day07()
{
}

void Day07::solve()
{
    vector<string> lines = read_file("inputs/day_07.txt");
    Memory memory;
    Expression *expressionOfA = nullptr;
    for (string& line : lines)
    {
        Assignment assignment = translate(line);
        memory.add(assignment.variable, assignment.expression);
        if (assignment.variable == "a")
            expressionOfA = assignment.expression;
    }
    valueOfA = expressionOfA->getValue(memory);
    memory.add("b", new Number(valueOfA));
    valueOfRevisedA = expressionOfA->getValue(memory);
}

long long Day07::get_result_of_part_one() const
{
    return valueOfA;
}

long long Day07::get_result_of_part_two() const
{
    return valueOfRevisedA;
}
