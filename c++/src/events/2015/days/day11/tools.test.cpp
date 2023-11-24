#include "tools.hpp"

#include <gtest/gtest.h>
#include <list>
#include <string>

using namespace std;

TEST(Aoc2015Day11IsValidPasswordTest, emptyPasswordIsInvalid)
{
    EXPECT_FALSE(isValidPassword(string("")));
}

TEST(Aoc2015Day11IsValidPasswordTest, invalidPasswordsAreInvalid)
{
    list<string> invalidPasswords = {
        "hijklmmn",
        "abbceffg",
        "abbcegjk",
        "abcdefgh",
        "ghijklmn"
    };

    for (auto& invalidPassword: invalidPasswords)
    {
        EXPECT_FALSE(isValidPassword(invalidPassword)) << "Password: '" << invalidPassword << "' should be invalid!";
    }
}

TEST(Aoc2015Day11IsValidPasswordTest, validPasswordsAreValid)
{
    list<string> validPasswords = {
        "abcdffaa",
        "ghjaabcc"
    };

    for (auto& validPassword: validPasswords)
    {
        EXPECT_TRUE(isValidPassword(validPassword)) << "Password: '" << validPassword << "' should be valid!";
    }
}

TEST(Aoc2015Day11NextPasswordCandidateTest, nextOfEmptyPasswordCandidateIsEmpty)
{
    EXPECT_EQ(string(""), nextPasswordCandidate(string("")));
}

TEST(Aoc2015Day11NextPasswordCandidateTest, nextOfOneLetterPasswordCandidateIsTheNextCharacter)
{
    EXPECT_EQ(string("b"), nextPasswordCandidate(string("a")));
    EXPECT_EQ(string("c"), nextPasswordCandidate(string("b")));
    EXPECT_EQ(string("d"), nextPasswordCandidate(string("c")));
    EXPECT_EQ(string("e"), nextPasswordCandidate(string("d")));
    EXPECT_EQ(string("f"), nextPasswordCandidate(string("e")));
    EXPECT_EQ(string("g"), nextPasswordCandidate(string("f")));
    EXPECT_EQ(string("h"), nextPasswordCandidate(string("g")));
    EXPECT_EQ(string("i"), nextPasswordCandidate(string("h")));
    EXPECT_EQ(string("j"), nextPasswordCandidate(string("i")));
    EXPECT_EQ(string("k"), nextPasswordCandidate(string("j")));
    EXPECT_EQ(string("l"), nextPasswordCandidate(string("k")));
    EXPECT_EQ(string("m"), nextPasswordCandidate(string("l")));
    EXPECT_EQ(string("n"), nextPasswordCandidate(string("m")));
    EXPECT_EQ(string("o"), nextPasswordCandidate(string("n")));
    EXPECT_EQ(string("p"), nextPasswordCandidate(string("o")));
    EXPECT_EQ(string("q"), nextPasswordCandidate(string("p")));
    EXPECT_EQ(string("r"), nextPasswordCandidate(string("q")));
    EXPECT_EQ(string("s"), nextPasswordCandidate(string("r")));
    EXPECT_EQ(string("t"), nextPasswordCandidate(string("s")));
    EXPECT_EQ(string("u"), nextPasswordCandidate(string("t")));
    EXPECT_EQ(string("v"), nextPasswordCandidate(string("u")));
    EXPECT_EQ(string("w"), nextPasswordCandidate(string("v")));
    EXPECT_EQ(string("x"), nextPasswordCandidate(string("w")));
    EXPECT_EQ(string("y"), nextPasswordCandidate(string("x")));
    EXPECT_EQ(string("z"), nextPasswordCandidate(string("y")));
}

TEST(Aoc2015Day11NextPasswordCandidateTest, nextOfTwoLetterPasswordCandidateNoRolloverIsTheNextSequence)
{
    EXPECT_EQ(string("ab"), nextPasswordCandidate(string("aa")));
    EXPECT_EQ(string("ac"), nextPasswordCandidate(string("ab")));
    EXPECT_EQ(string("bh"), nextPasswordCandidate(string("bg")));
    EXPECT_EQ(string("gh"), nextPasswordCandidate(string("gg")));
}

TEST(Aoc2015Day11NextPasswordCandidateTest, nextOfTwoLetterPasswordCandidateWithRolloverIsTheNextSequence)
{
    EXPECT_EQ(string("ba"), nextPasswordCandidate(string("az")));
    EXPECT_EQ(string("da"), nextPasswordCandidate(string("cz")));
    EXPECT_EQ(string("ha"), nextPasswordCandidate(string("gz")));
    EXPECT_EQ(string("ya"), nextPasswordCandidate(string("xz")));
}

TEST(Aoc2015Day11NextPasswordCandidateTest, nextOfThreeOrMoreLetterPasswordCandidateWithRolloverShouldResultTheNextSequence)
{
    EXPECT_EQ(string("aba"), nextPasswordCandidate(string("aaz")));
    EXPECT_EQ(string("baa"), nextPasswordCandidate(string("azz")));
    EXPECT_EQ(string("asdfgia"), nextPasswordCandidate(string("asdfghz")));
    EXPECT_EQ(string("daaaaaa"), nextPasswordCandidate(string("czzzzzz")));
    EXPECT_EQ(string("kbzzzaa"), nextPasswordCandidate(string("kbzzyzz")));
}

TEST(Aoc2015Day11FindTheNextValidPasswordTest, nextValidPasswordIsCorrect)
{
    EXPECT_EQ(string("abcdffaa"), findTheNextValidPassword(string("abcdefgh")));
    EXPECT_EQ(string("ghjaabcc"), findTheNextValidPassword(string("ghijklmn")));
}
