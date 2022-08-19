#include "day05.hpp"
#include <gtest/gtest.h>

#include <string>
#include <vector>

using namespace std;

TEST(Aoc2015Day05Test, textHasLessThenThreeVowelsInIt)
{
    string inputText{""};
    EXPECT_FALSE(hasAtLeastThreeVowels(inputText));
    inputText = "abcdde";
    EXPECT_FALSE(hasAtLeastThreeVowels(inputText));
    inputText = "dvszwmarrgswjxmb";
    EXPECT_FALSE(hasAtLeastThreeVowels(inputText));
}

TEST(Aoc2015Day05Test, textHasAtLeatThreeVowelsInIt)
{
    string inputText{"aei"};
    EXPECT_TRUE(hasAtLeastThreeVowels(inputText));
    inputText = "ugknbfddgicrmopn";
    EXPECT_TRUE(hasAtLeastThreeVowels(inputText));
    inputText = "xazegov";
    EXPECT_TRUE(hasAtLeastThreeVowels(inputText));
    inputText = "aeiouaeiouaeiou";
    EXPECT_TRUE(hasAtLeastThreeVowels(inputText));
    inputText = "xazagav";
    EXPECT_TRUE(hasAtLeastThreeVowels(inputText));
    inputText = "xezegev";
    EXPECT_TRUE(hasAtLeastThreeVowels(inputText));
}

TEST(Aoc2015Day05Test, textHasNoLetterThatAppearsTwiceInARow)
{
    vector<string> inputTexts{
        "",
        "abcdefghijklm",
        "ababababababa",
        "a",
        "b",
        "ab"
    };
    for (const string& text: inputTexts)
    {
        EXPECT_FALSE(hasLetterThatAppearsTwiceInARow(text));
    }
}

TEST(Aoc2015Day05Test, textHasLetterThatAppearsTwiceInARow)
{
    vector<string> inputTexts{
        "aa",
        "abcdeffghijklm",
        "ababababaababba",
        "abb",
        "baa",
        "abhksdfhweunfwncvaa"
    };
    for (const string& text: inputTexts)
    {
        EXPECT_TRUE(hasLetterThatAppearsTwiceInARow(text));
    }
}

TEST(Aoc2015Day05Test, textDoesNotContainNotAllowedParts)
{
    vector<string> inputTexts{
        "aa",
        "cadeffghijklm",
        "acbacbacbaacbadbba",
        "adbb",
        "baa",
        "adbhksdfhweunfwncvaa"
    };
    for (const string& text: inputTexts)
    {
        EXPECT_FALSE(containsNotAllowedParts(text));
    }
}

TEST(Aoc2015Day05Test, textContainsNotAllowedParts)
{
    vector<string> inputTexts{
        "ab"
        "cacdeffghijklm",
        "acbacbacbapqacbadbba",
        "adxybb",
        "abba",
        "adbhksdxyfhwepqunfwncvaa"
    };
    for (const string& text: inputTexts)
    {
        EXPECT_TRUE(containsNotAllowedParts(text));
    }
}

TEST(Aoc2015Day05Test, textHasPairAtMostOnce)
{
    vector<string> inputTexts{
        "ab"
        "cacdeffghijklm",
        "adxybb",
        "abba",
        "aaa",
        "adbhksdxyfhwepqunfwncvaa"
    };
    for (const string& text: inputTexts)
        EXPECT_FALSE(hasPairAtLeastTwice(text));
}

TEST(Aoc2015Day05Test, textHasPairAtLeastTwice)
{
    vector<string> inputTexts{
        "abab",
        "cacdeffghijklmca",
        "adxybbxy",
        "abbab",
        "aaaa",
        "xyxy",
        "adbhksdxyfhwepqunfwncvabha"
    };
    for (const string& text: inputTexts)
        EXPECT_TRUE(hasPairAtLeastTwice(text));
}

TEST(Aoc2015Day05Test, textDoesNotHaveOneCharacterBetweenRepeatedCharacter)
{
    vector<string> inputTexts{
        "ab"
        "cadeffghijklm",
        "adxybb",
        "abba",
        "adbhksdxyfhwepqunfwncvaa",
        "uurcxstgmygtbstg"
    };
    for (const string& text: inputTexts)
        EXPECT_FALSE(hasOneCharacterBetweenRepeatedCharacter(text));
}

TEST(Aoc2015Day05Test, textHasOneCharacterBetweenRepeatedCharacter)
{
    vector<string> inputTexts{
        "aba"
        "cacdefefghijklm",
        "adxybab",
        "ababa",
        "adbhksdxyfhwepuqunfwncvaa",
        "qjhvhtzxzqqjkmpb",
        "xxyxx",
        "ieodomkazucvgmuy"
    };
    for (const string& text: inputTexts)
        EXPECT_TRUE(hasOneCharacterBetweenRepeatedCharacter(text));
}