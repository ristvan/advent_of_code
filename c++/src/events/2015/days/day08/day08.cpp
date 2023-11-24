#include "day08.hpp"
#include "matchsticker.hpp"
#include "common/file_handler.hpp"
#include <string>
#include <vector>
#include <iostream>


using namespace std;


Day08::Day08(): valueOfA(0), valueOfRevisedA(0)
{
}

Day08::~Day08()
{
}

void Day08::solve()
{
    vector<string> lines = read_file("inputs/day_08.txt");
    for (string& line : lines)
    {
        valueOfA += line.length() - memory_length(line);
        valueOfRevisedA += encode_string(line).length() - line.length();
    }
}

string Day08::get_result_of_part_one() const
{
    return to_string(valueOfA);
}

string Day08::get_result_of_part_two() const
{
    return to_string(valueOfRevisedA);
}
