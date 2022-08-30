#include "helpers.hpp"
#include <gtest/gtest.h>
#include <string>

using namespace std;

TEST(Aoc2015Day05HelpersTest, inputHasTypeTurnOn)
{
    string inputText{"turn on 599,989 through 806,993"};
    Rectangle rectangle(599, 989, 806, 993);
    TurnOn expected(rectangle);
    Action *actual = convert_line(inputText);
    EXPECT_EQ(expected, *actual);
}

TEST(Aoc2015Day05HelpersTest, inputHasTypeTurnOff)
{
    string inputText{"turn off 370,39 through 425,839"};
    Rectangle rectangle(370, 39, 425, 839);
    TurnOff expected(rectangle);
    Action *actual = convert_line(inputText);
    EXPECT_EQ(expected, *actual);
}

TEST(Aoc2015Day05HelpersTest, inputHasTypeToggle)
{
    string inputText{"toggle 461,550 through 564,900"};
    Rectangle rectangle(461, 550, 564, 900);
    Toggle expected(rectangle);
    Action *actual = convert_line(inputText);
    EXPECT_EQ(expected, *actual);
}

TEST(Aoc2015Day05HelpersTest, actionsAreEqualsWhenTheyHaveTheSameType)
{
    Rectangle rectangle;

    TurnOn turnOn(rectangle);
    TurnOn turnOn2(rectangle);
    TurnOff turnOff(rectangle);
    Toggle toggle(rectangle);

    EXPECT_NE(turnOff, turnOn);
    EXPECT_NE(turnOn, toggle);
    EXPECT_NE(turnOff, toggle);
    EXPECT_EQ(turnOn, turnOn2);
}

TEST(Aoc2015Day05HelpersTest, actionsDifferWhenTheyHaveDifferentRectangleCoordinates)
{
    Rectangle rectangle1(0, 0, 10, 10);
    Rectangle rectangle2(5, 5, 15, 15);

    TurnOn turnOn(rectangle1);
    TurnOn turnOn2(rectangle2);
    TurnOff turnOff(rectangle1);
    TurnOff turnOff2(rectangle2);
    Toggle toggle(rectangle1);
    Toggle toggle2(rectangle2);

    EXPECT_NE(turnOn, turnOn2);
    EXPECT_NE(turnOff, turnOff2);
    EXPECT_NE(toggle, toggle2);
}

TEST(Aoc2015Day05HelpersTest, inputHasWrongCommand)
{
    string inputText{"trun on 599,989 through 806,993"};
    Action *actual = convert_line(inputText);
    EXPECT_TRUE(nullptr == actual);

    inputText = "turn of 599,989 through 806,993";
    actual = convert_line(inputText);
    EXPECT_TRUE(nullptr == actual);
}

TEST(Aoc2015Day05HelpersTest, inputHasWrongCoordinatesSeperation)
{
    string inputText{"trun on 599,989 thrugh 806,993"};
    Action *actual = convert_line(inputText);
    EXPECT_TRUE(nullptr == actual);

    inputText = "turn of 599,989 throught 806,993";
    actual = convert_line(inputText);
    EXPECT_TRUE(nullptr == actual);
}

TEST(Aoc2015Day05HelpersTest, inputHasWrongNumberSeperation)
{
    string inputText{"trun on 599.989 thrugh 806,993"};
    Action *actual = convert_line(inputText);
    EXPECT_TRUE(nullptr == actual);

    inputText = "turn of 599,989 throught 806.993";
    actual = convert_line(inputText);
    EXPECT_TRUE(nullptr == actual);

    inputText = "turn of 599,989 throught 806;993";
    actual = convert_line(inputText);
    EXPECT_TRUE(nullptr == actual);

    inputText = "turn of 599;989 throught 806,993";
    actual = convert_line(inputText);
    EXPECT_TRUE(nullptr == actual);
}
