#include "day04.hpp"
#include "md5.hpp"

#include <iostream>
#include <string>

using namespace std;

Day04::~Day04()
{
}

void Day04::solve()
{
    long long int i = 250000;
    long long int first_solution = -1;
    long long int second_solution = -1;
    while (first_solution < 0 || second_solution < 0)
    {
        string input = "yzbqklnj" + to_string(i);
        string md5_value_first_5 = md5(input).substr(0, 5);
        string md5_value_first_6 = md5(input).substr(0, 6);
        if (md5_value_first_5.compare("00000") == 0 && first_solution < 0)
        {
            first_solution = i;
            i = 9900000;
        }
        if (md5_value_first_6.compare("000000") == 0)
        {
            second_solution = i;
        }
        ++i;
    }
    cout << "Day 04" << endl;
    cout << "  * Part 1: " << first_solution << endl;
    cout << "  * Part 2: " << second_solution << endl;
}