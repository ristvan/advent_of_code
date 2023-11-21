#include "permutations.hpp"

#include <gtest/gtest.h>
#include <list>
#include <string>

using namespace std;

void expectListOfListsEqual(const list<list<string>>& first, const list<list<string>>& second);
bool areListsEqual(const list<string>& first, const list<string>& second);

TEST(PermutationTest, whenNoItemsInTheList)
{
    list<string> input;
    list<list<string>> actualResult = calculateAllPermutations(input);

    EXPECT_EQ(0, actualResult.size());
}

TEST(PermutationTest, whenOneItemInTheList)
{
    list<string> input = {string("A")};
    list<list<string>> actualResult = calculateAllPermutations(input);

    EXPECT_EQ(1, actualResult.size());
}

TEST(PermutationTest, whenTwoItemsInTheList)
{
    list<string> input = {string("A"), string("B")};
    list<list<string>> actualResult = calculateAllPermutations(input);

    list<list<string>> expectedResult = {
        { string("A"), string("B") },
        { string("B"), string("A") }
    };

    expectListOfListsEqual(expectedResult, actualResult);
}

void expectListOfListsEqual(const list<list<string>>& first, const list<list<string>>& second)
{
    EXPECT_EQ(first.size(), second.size());
    for (auto& first_items: first)
    {
        bool hasMatching = false;
        for (auto& second_items: second)
        {
            hasMatching = areListsEqual(first_items, second_items);
        }
        EXPECT_TRUE(hasMatching);
    }
}

bool areListsEqual(const list<string>& first, const list<string>& second)
{
    return true;
}
