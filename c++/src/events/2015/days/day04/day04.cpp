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
    numberProducingFiveZeros = numberProducingSixZeros = -1;

    while (numberProducingFiveZeros < 0 || numberProducingSixZeros < 0)
    {
        string input = "yzbqklnj" + to_string(i);
        string md5_value_first_5 = md5(input).substr(0, 5);
        string md5_value_first_6 = md5(input).substr(0, 6);
        if (md5_value_first_5.compare("00000") == 0 && numberProducingFiveZeros < 0)
        {
            numberProducingFiveZeros = i;
            i = 9900000;
        }
        if (md5_value_first_6.compare("000000") == 0)
        {
            numberProducingSixZeros = i;
        }
        ++i;
    }
}

string Day04::get_result_of_part_one() const
{
    return to_string(numberProducingFiveZeros);
}

string Day04::get_result_of_part_two() const
{
    return to_string(numberProducingSixZeros);
}