#include "permutations.hpp"

#include <list>
#include <string>

using namespace std;

class PermutationCalculator
{
public:
    list<list<string>> calculate(list<string>& inputItems);

private:
    void calculatePermutations(list<string> inputItems);

    list<list<string>> allPermutations;
    list<string> actualPermutation;
};

list<list<string>> PermutationCalculator::calculate(list<string>& inputItems)
{
    calculatePermutations(inputItems);
    return allPermutations;
}

void PermutationCalculator::calculatePermutations(list<string> inputItems)
{
    if (inputItems.size() == 0 && actualPermutation.size() == 0)
    {
        return;
    }
    if (inputItems.size() == 0 && actualPermutation.size() > 0)
    {
        allPermutations.push_back(actualPermutation);
        return;
    }
    list<string> copyOfItems(inputItems);
    for (auto &inputItem : inputItems)
    {
        actualPermutation.push_back(inputItem);
        copyOfItems.remove(inputItem);
        calculatePermutations(copyOfItems);
        copyOfItems.push_back(inputItem);
        actualPermutation.remove(inputItem);
    }
}



list<list<string>> calculateAllPermutations(list<string> &inputItems)
{
    PermutationCalculator permutationCalculator;

    return permutationCalculator.calculate(inputItems);
}
