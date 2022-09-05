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

TEST(AocCommon_StringManipulators_IsNumberTest, whenEmptyStringIsGivenItIsNotANumber)
{
    string inputText{""};

    EXPECT_FALSE(isNumber(inputText));
}

TEST(AocCommon_StringManipulators_IsNumberTest, whenStringWithoutNumberIsGivenItIsNotANumber)
{
    vector<string> inputTexts{
        "abcdefghijklm",
        "ababababababa",
        "a",
        "b",
        "ab",
        "HELLO",
        "NOT",
        "RSHIFT"
    };
    for (const string& text: inputTexts)
    {
        EXPECT_FALSE(isNumber(text));
    }
}

TEST(AocCommon_StringManipulators_IsNumberTest, whenStringWithNumbersAndCharactersIsGivenItIsNotANumber)
{
    vector<string> inputTexts{
        "1abcdefghijklm",
        "a2b3a54ba6babababa",
        "a125",
        "13b",
        "a13b",
        "H69ELLO890",
        "NOT1234567890",
        "1R2S3H4I5F6T7"
    };
    for (const string& text: inputTexts)
    {
        EXPECT_FALSE(isNumber(text));
    }
}

TEST(AocCommon_StringManipulators_IsNumberTest, whenStringWithOnlyNumbersIsGivenItIsANumber)
{
    vector<string> inputTexts{
        "1",
        "0",
        "125",
        "13",
        "813",
        "69890",
        "1234567890",
        "01234567"
    };
    for (const string& text: inputTexts)
    {
        EXPECT_TRUE(isNumber(text));
    }
}
