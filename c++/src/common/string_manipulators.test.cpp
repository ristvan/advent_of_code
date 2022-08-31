#include "string_manipulators.hpp"

#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

TEST(AocCommon_StringManipulatorsTest, whenEmptyStringIsGivenItIsSplitIntoOneToken)
{
    string inputText{""};

    vector<string> tokens = split(inputText, " ");
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("", tokens[0]);
}

TEST(AocCommon_StringManipulatorsTest, whenOneTokenIsInTheStringIsGivenItIsSplitIntoOneToken)
{
    string inputText{"Hello"};

    vector<string> tokens = split(inputText, " ");
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("Hello", tokens[0]);
}

TEST(AocCommon_StringManipulatorsTest, whenTwoTokensAreInTheStringIsGivenItIsSplitIntoTwoTokens)
{
    string inputText{"Hello World"};

    vector<string> tokens = split(inputText, " ");
    EXPECT_EQ(2, tokens.size());
    EXPECT_EQ("Hello", tokens[0]);
    EXPECT_EQ("World", tokens[1]);
}

TEST(AocCommon_StringManipulatorsTest, whenThreeTokensAreInTheStringIsGivenItIsSplitIntoThreeTokens)
{
    string inputText{"Hello Super World"};

    vector<string> tokens = split(inputText, " ");
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("Hello", tokens[0]);
    EXPECT_EQ("Super", tokens[1]);
    EXPECT_EQ("World", tokens[2]);
}

TEST(AocCommon_StringManipulatorsTest, whenThreeTokensAreInTheStringAndNotSpaceDelimiterAreGivenItIsSplitIntoThreeTokens)
{
    string inputText{"Hello+Super+World"};

    vector<string> tokens = split(inputText, "+");
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("Hello", tokens[0]);
    EXPECT_EQ("Super", tokens[1]);
    EXPECT_EQ("World", tokens[2]);
}

TEST(AocCommon_StringManipulatorsTest, whenLongDelimiterIsGivenItIsWordkingCorrectly)
{
    string inputText{"Hello separate Super separate World"};

    vector<string> tokens = split(inputText, " separate ");
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("Hello", tokens[0]);
    EXPECT_EQ("Super", tokens[1]);
    EXPECT_EQ("World", tokens[2]);
}
