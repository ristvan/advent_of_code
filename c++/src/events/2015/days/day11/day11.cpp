#include "day11.hpp"
#include "tools.hpp"

#include <string>
#include <vector>

using namespace std;

Day11::Day11(): firstPassword("-"), secondPassword("-")
{
}

Day11::~Day11()
{
}

void Day11::solve()
{
    string password = "vzbxkghb";
    firstPassword = findTheNextValidPassword(password);
    secondPassword = findTheNextValidPassword(firstPassword);
}

string Day11::get_result_of_part_one() const
{
    return firstPassword;
}

string Day11::get_result_of_part_two() const
{
    return secondPassword;
}