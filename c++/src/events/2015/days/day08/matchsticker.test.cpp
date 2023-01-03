#include "matchsticker.hpp"

#include <gtest/gtest.h>
#include <string>
#include <map>
#include <iostream>

using namespace std;


TEST(Aoc2015Day08LengthTest, whenSimpleTextIsGiven)
{
    map<string, int> inputs;
    inputs = {
        {"\"azlgxdbljwygyttzkfwuxv\"", 22},
        {"\"merxdhj\"", 7},
        {"\"pcrtfb\"", 6},
        {"\"vhioftcosshaqtnz\"", 16},
        {"\"dwz\"", 3},
        {"\"d\"", 1}
    };

    for (auto const& [input, expectedResult] : inputs) {
        EXPECT_EQ(expectedResult, memory_length(input));
    }
}

TEST(Aoc2015Day08LengthTest, whenEscapedQuotationMarkIsGiven)
{
    map<string, int> inputs;
    inputs = {
        {"\"d\\\"\"", 2},
        {"\"qte\\\"q\"", 5},
        {"\"jcrkptrsasjp\\\\\\\"cwigzynjgspxxv\\\\vyb\"", 32}
    };

    for (auto const& [input, expectedResult] : inputs) {
        cout << input << endl;
        EXPECT_EQ(expectedResult, memory_length(input));
    }
}

TEST(Aoc2015Day08LengthTest, whenEscapedHexaDecimalIsGiven)
{
    map<string, int> inputs;
    inputs = {
        {"\"\\x27\"", 1},
        {"\"qte\\x27\"", 4}
    };

    for (auto const& [input, expectedResult] : inputs) {
        cout << input << endl;
        EXPECT_EQ(expectedResult, memory_length(input));
    }
}

TEST(Aoc2015Day08LengthTest, whenSeveralEscapedCharactersAreGiven)
{
    map<string, int> inputs;
    inputs = {
        {"\"\\x83qg\\\"nwgugfmfpzlrvty\\\"ryoxm\"", 25}
    };
    for (auto const& [input, expectedResult] : inputs) {
        cout << input << endl;
        EXPECT_EQ(expectedResult, memory_length(input));
    }
}

TEST(Aoc2015Day08EncodingTest, when)
{
    map<string, string> inputs;
    inputs = {
        {"", "\"\""},
        {"\"\"", "\"\\\"\\\"\""},
        {"\"abc\"", "\"\\\"abc\\\"\""},
        {"\"aaa\\\"aaa\"", "\"\\\"aaa\\\\\\\"aaa\\\"\""},
        {"\"\\x27\"", "\"\\\"\\\\x27\\\"\""}
    };
    for (auto const& [input, expectedResult] : inputs) {
        cout << input << endl;
        EXPECT_EQ(expectedResult, encode_string(input));
    }
}
