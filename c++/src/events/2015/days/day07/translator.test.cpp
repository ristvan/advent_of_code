#include "translator.hpp"
#include "variable.hpp"
#include "memory.hpp"
#include "number.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

using namespace std;

TEST(Aoc2015Day07TranslatorTest, whenSimpleAssignmentIsGiven)
{
    string inputText = "lg -> a";
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("a", actualOutput.variable);
    EXPECT_EQ("lg", static_cast<Variable*>(actualOutput.expression)->getName());
}

TEST(Aoc2015Day07TranslatorTest, whenAnothersimpleAssignmentIsGiven)
{
    string inputText = "lg -> b";
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("b", actualOutput.variable);
    EXPECT_EQ("lg", static_cast<Variable*>(actualOutput.expression)->getName());
}

TEST(Aoc2015Day07TranslatorTest, whenANumberAssignedToAVariable)
{
    Memory memory;
    string inputText = "628 -> b";
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("b", actualOutput.variable);
    EXPECT_EQ(628, actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenANumberNegatedItsResultShouldBeTheNegatedValue)
{
    Memory memory;
    string inputText = "NOT 628 -> b";
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("b", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(64907), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenAVariableIsNegatedTheResultShouldBeTheNegatedValueOfTheVariable)
{
    string inputText = "NOT ib -> b";
    Memory memory;
    memory.add("ib", new Number(28));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("b", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(65507), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenTwoNumbersAreANDedTheResultShouldBeABitwiseAND)
{
    Memory memory;
    string inputText = "3 AND 2 -> and";
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("and", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(2), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenFirstAVariableANDedWithANumberTheResultShouldBeCorrect)
{
    string inputText = "a AND 2 -> and";
    Memory memory;
    memory.add("a", new Number(30));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("and", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(2), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenFirstANumberANDedWithAVariableTheResultShouldBeCorrect)
{
    string inputText = "3 AND b -> and";
    Memory memory;
    memory.add("b", new Number(29));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("and", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(1), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenBothVariablesAreANDedTheResultShouldBeCorrect)
{
    string inputText = "a AND b -> and";
    Memory memory;
    memory.add("a", new Number(28));
    memory.add("b", new Number(7));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("and", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(4), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenTwoNumbersAreORedTheResultShouldBeABitwiseOR)
{
    string inputText = "1 OR 2 -> result";
    Memory memory;
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(3), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenFirstAVariableORedWithANumberTheResultShouldBeCorrect)
{
    string inputText = "a OR 2 -> result";
    Memory memory;
    memory.add("a", new Number(28));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(30), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenFirstANumberORedWithAVariableTheResultShouldBeCorrect)
{
    string inputText = "3 OR b -> result";
    Memory memory;
    memory.add("b", new Number(28));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(31), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenBothVariablesAreORedTheResultShouldBeCorrect)
{
    string inputText = "a OR b -> result";
    Memory memory;
    memory.add("a", new Number(123));
    memory.add("b", new Number(456));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(507), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenTwoNumbersAreLeftShiftedTheResultShouldBeCorrect)
{
    string inputText = "123 LSHIFT 2 -> result";
    Memory memory;
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(492), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenAVariableIsLeftShiftedWithANumberTheResultShouldBeCorrect)
{
    string inputText = "var1 LSHIFT 2 -> result";
    Memory memory;
    memory.add("var1", new Number(123));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(492), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenANumberIsLeftShiftedWithAVariableTheResultShouldBeCorrect)
{
    string inputText = "5 LSHIFT var2 -> result";
    Memory memory;
    memory.add("var2", new Number(2));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(20), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenAVariableIsLeftShiftedWithAnOtherVariableTheResultShouldBeCorrect)
{
    string inputText = "var1 LSHIFT var2 -> result";
    Memory memory;
    memory.add("var2", new Number(2));
    memory.add("var1", new Number(123));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(492), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenANumberIsRightShiftedWithAnOtherNumberTheResultShouldBeCorrect)
{
    string inputText = "456 RSHIFT 2 -> result";
    Memory memory;
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(114), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenAVariableIsRightShiftedWithANumberTheResultShouldBeCorrect)
{
    string inputText = "var1 RSHIFT 2 -> result";
    Memory memory;
    memory.add("var1", new Number(456));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(114), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenANumberIsRightShiftedWithAVariableTheResultShouldBeCorrect)
{
    string inputText = "1024 RSHIFT var2 -> result";
    Memory memory;
    memory.add("var2", new Number(4));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(64), actualOutput.expression->getValue(memory));
}

TEST(Aoc2015Day07TranslatorTest, whenAVariableIsRightShiftedWithAnOtherVariableTheResultShouldBeCorrect)
{
    string inputText = "var1 RSHIFT var2 -> result";
    Memory memory;
    memory.add("var1", new Number(65535));
    memory.add("var2", new Number(6));
    Assignment actualOutput = translate(inputText);
    EXPECT_EQ("result", actualOutput.variable);
    EXPECT_EQ(static_cast<unsigned short>(1023), actualOutput.expression->getValue(memory));
}


TEST(Aoc2015Day07TranslatorTest, whenAComplexInputIsGivenTheResultShouldBeCorrect)
{
    vector<string> inputLines{
        "123 -> x",
        "456 -> y",
        "x AND y -> d",
        "y OR x -> e",
        "x LSHIFT 2 -> f",
        "y RSHIFT 2 -> g",
        "NOT x -> h",
        "NOT y -> i"
    };
    Memory memory;
    for (const string& line: inputLines)
    {
        Assignment assignment = translate(line);
        memory.add(assignment.variable, assignment.expression);
    }
    EXPECT_EQ(static_cast<unsigned short>(72), memory.get("d"));
    EXPECT_EQ(static_cast<unsigned short>(507), memory.get("e"));
    EXPECT_EQ(static_cast<unsigned short>(492), memory.get("f"));
    EXPECT_EQ(static_cast<unsigned short>(114), memory.get("g"));
    EXPECT_EQ(static_cast<unsigned short>(65412), memory.get("h"));
    EXPECT_EQ(static_cast<unsigned short>(65079), memory.get("i"));
    EXPECT_EQ(static_cast<unsigned short>(123), memory.get("x"));
    EXPECT_EQ(static_cast<unsigned short>(456), memory.get("y"));
}

TEST(Aoc2015Day07TranslatorTest, whenAnExpressionIsChangedTheOutputShouldBeChangedAlso)
{
    vector<string> inputLines{
        "10149 -> a",
        "23406 -> b",
        "9223 -> c",
        "4233 -> d",
        "a AND b -> e",
        "c OR d -> f",
        "NOT f -> g",
        "e AND g -> h"
    };
    Memory memory;
    for (const string& line: inputLines)
    {
        Assignment assignment = translate(line);
        memory.add(assignment.variable, assignment.expression);
    }
    EXPECT_EQ(static_cast<unsigned short>(804), memory.get("e"));
    EXPECT_EQ(static_cast<unsigned short>(13455), memory.get("f"));
    EXPECT_EQ(static_cast<unsigned short>(52080), memory.get("g"));
    EXPECT_EQ(static_cast<unsigned short>(800), memory.get("h"));
    EXPECT_EQ(static_cast<unsigned short>(10149), memory.get("a"));
    memory.add("a", new Number(800));
    EXPECT_EQ(static_cast<unsigned short>(800), memory.get("a"));
    EXPECT_EQ(static_cast<unsigned short>(800), memory.get("e"));
    EXPECT_EQ(static_cast<unsigned short>(13455), memory.get("f"));
    EXPECT_EQ(static_cast<unsigned short>(52080), memory.get("g"));
    EXPECT_EQ(static_cast<unsigned short>(800), memory.get("h"));
}