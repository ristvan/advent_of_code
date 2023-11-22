#include "day10.hpp"

#include <string>
#include <vector>
#include <iostream>


using namespace std;

Day10::Day10(): valueOfA(0), valueOfRevisedA(0)
{
}

Day10::~Day10()
{
}

void Day10::solve()
{
    vector<int> sequence = {1, 1, 1, 3, 2, 2, 2, 1, 1, 3};
    for (int i = 0; i < 50; ++i)
    {
        int numberOfOccurencies = 0;
        int previousNumber = 0;
        vector<int> newSequence;
        for (auto& number : sequence)
        {
            if (number != previousNumber)
            {
                if (numberOfOccurencies > 0)
                {
                    newSequence.push_back(numberOfOccurencies);
                    newSequence.push_back(previousNumber);
                }
                previousNumber = number;
                numberOfOccurencies = 0;
            }
            numberOfOccurencies ++;
        }
        if (numberOfOccurencies > 0)
        {
            newSequence.push_back(numberOfOccurencies);
            newSequence.push_back(previousNumber);
        }
        sequence.swap(newSequence);
        if (i == 39) valueOfA = sequence.size();
    }
    valueOfRevisedA = sequence.size();
}

long long Day10::get_result_of_part_one() const
{
    return valueOfA;
}

long long Day10::get_result_of_part_two() const
{
    return valueOfRevisedA;
}