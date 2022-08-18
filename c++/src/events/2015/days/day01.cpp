#include "day01.hpp"

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

Day01::~Day01()
{
}

void Day01::solve()
{
    string line;
    ifstream inputFile;
    inputFile.open("inputs/day_01.txt");
    if (inputFile.is_open())
    {
        inputFile >> line;
        inputFile.close();
    }
    long long int index = 1;
    long long int level = 0;
    long long int firstMinusOne = -1;
    for (char c : line)
    {
        if (c == ')') --level;
        if (c == '(') ++level;
        if (level == -1 && firstMinusOne == -1) firstMinusOne = index;
        ++index;
    }
    this->level = level;
    this->firstMinusOne = firstMinusOne;
}

long long Day01::get_result_of_part_one() const
{
    return this->level;
}

long long Day01::get_result_of_part_two() const
{
    return this->firstMinusOne;
}