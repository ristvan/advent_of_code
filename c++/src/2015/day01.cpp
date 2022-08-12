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
    int index = 1;
    int level = 0;
    int firstMinusOne = -1;
    for (char c : line)
    {
        if (c == ')') --level;
        if (c == '(') ++level;
        if (level == -1 && firstMinusOne == -1) firstMinusOne = index;
        ++index;
    }
    cout << "Day 01" << endl;
    cout << "  * Part 1: " << level << endl;
    cout << "  * Part 2: " << firstMinusOne << endl;
}
