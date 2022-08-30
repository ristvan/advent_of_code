#include <lightgrid.hpp>
#include <gtest/gtest.h>


using namespace std;

TEST(Aoc2015Day05LightGridTest, testWhenLightGridIsCreatedAllLightsAreOut)
{
    OnOffLightGrid lightGrid;
    EXPECT_EQ(0, lightGrid.countLitLights());
}

TEST(Aoc2015Day05LightGridTest, testWhenOneLightTurnedOnTheCountIsOne)
{
    OnOffLightGrid lightGrid;
    lightGrid.turnOn(3, 3);
    EXPECT_EQ(1, lightGrid.countLitLights());
}

TEST(Aoc2015Day05LightGridTest, testWhenDifferentLightsAreTurnedOnTheCountIsEqualToTheNumberOfCalls)
{
    OnOffLightGrid lightGrid;
    for (int i = 0; i < 500; ++i)
    {
        lightGrid.turnOn(i, i);
        EXPECT_EQ(i + 1, lightGrid.countLitLights());
    }
}

TEST(Aoc2015Day05LightGridTest, testWhenTheSameLightsAreTurnedOnTheCountIsEqualToTheNumberOfDifferentLights)
{
    OnOffLightGrid lightGrid;
    lightGrid.turnOn(0, 1);
    EXPECT_EQ(1, lightGrid.countLitLights());
    lightGrid.turnOn(0, 1);
    EXPECT_EQ(1, lightGrid.countLitLights());
    lightGrid.turnOn(5, 1);
    EXPECT_EQ(2, lightGrid.countLitLights());
    lightGrid.turnOn(0, 1);
    EXPECT_EQ(2, lightGrid.countLitLights());
    lightGrid.turnOn(5, 1);
    EXPECT_EQ(2, lightGrid.countLitLights());
    lightGrid.turnOn(1, 1);
    EXPECT_EQ(3, lightGrid.countLitLights());
    lightGrid.turnOn(1, 1);
    EXPECT_EQ(3, lightGrid.countLitLights());
    lightGrid.turnOn(999, 514);
    EXPECT_EQ(4, lightGrid.countLitLights());
    lightGrid.turnOn(999, 515);
    EXPECT_EQ(5, lightGrid.countLitLights());
    lightGrid.turnOn(999, 516);
    EXPECT_EQ(6, lightGrid.countLitLights());
    lightGrid.turnOn(999, 515);
    EXPECT_EQ(6, lightGrid.countLitLights());
    lightGrid.turnOn(999, 516);
    EXPECT_EQ(6, lightGrid.countLitLights());
    lightGrid.turnOn(999, 514);
    EXPECT_EQ(6, lightGrid.countLitLights());
}

TEST(Aoc2015Day05LightGridTest, testWhenOneLightTurnedOffTheCountIsZero)
{
    OnOffLightGrid lightGrid;
    lightGrid.turnOn(3, 3);
    EXPECT_EQ(1, lightGrid.countLitLights());
    lightGrid.turnOff(3, 3);
    EXPECT_EQ(0, lightGrid.countLitLights());
}

void turnOnAllLights(LightGrid& lightGrid, int rows, int columns)
{
    for (int row = 0; row < rows; ++row)
        for(int column = 0; column < columns; ++column)
            lightGrid.turnOn(row, column);
}

TEST(Aoc2015Day05LightGridTest, testWhenDifferentLightsAreTurnedOffTheCountTellsTheCorrenctNumber)
{
    OnOffLightGrid lightGrid;
    const int TEST_GRID_SIZE = 100;
    turnOnAllLights(lightGrid, TEST_GRID_SIZE, TEST_GRID_SIZE);
    for (int i = 0; i < TEST_GRID_SIZE; ++i)
    {
        lightGrid.turnOff(i, i);
        EXPECT_EQ(TEST_GRID_SIZE * TEST_GRID_SIZE - i - 1, lightGrid.countLitLights());
    }
}

TEST(Aoc2015Day05LightGridTest, testWhenTheLightsAreTurnedOffTheCountTellsTheCorrenctNumber)
{
    OnOffLightGrid lightGrid;
    turnOnAllLights(lightGrid, 100, 100);

    lightGrid.turnOff(50, 50);
    EXPECT_EQ(9999, lightGrid.countLitLights());

    lightGrid.turnOff(50, 50);
    EXPECT_EQ(9999, lightGrid.countLitLights());

    lightGrid.turnOff(50, 50);
    EXPECT_EQ(9999, lightGrid.countLitLights());

    lightGrid.turnOff(10, 50);
    EXPECT_EQ(9998, lightGrid.countLitLights());

    lightGrid.turnOff(10, 50);
    EXPECT_EQ(9998, lightGrid.countLitLights());

    lightGrid.turnOff(10, 10);
    EXPECT_EQ(9997, lightGrid.countLitLights());
}

TEST(Aoc2015Day05LightGridTest, testWhenOneLightIsToggledTheCountChangesBetweenOneAndZero)
{
    OnOffLightGrid lightGrid;
    EXPECT_EQ(0, lightGrid.countLitLights());
    lightGrid.toggle(6, 28);
    EXPECT_EQ(1, lightGrid.countLitLights());
    lightGrid.toggle(6, 28);
    EXPECT_EQ(0, lightGrid.countLitLights());
}

TEST(Aoc2015Day05LightGridTest, testWhenDifferentLightsAreToggledTheCountIsEqualToTheNumberOfCalls)
{
    OnOffLightGrid lightGrid;
    for (int i = 0; i < 500; ++i)
    {
        lightGrid.toggle(i, i);
        EXPECT_EQ(i + 1, lightGrid.countLitLights());
    }
}

TEST(Aoc2015Day05LightGridTest, testWhenTheSameLightsAreToggledTheCountIsChangingBackAndForth)
{
    const int TEST_GRID_SIZE = 50;
    OnOffLightGrid lightGrid;
    turnOnAllLights(lightGrid, TEST_GRID_SIZE, TEST_GRID_SIZE);
    int count = TEST_GRID_SIZE * TEST_GRID_SIZE;
    EXPECT_EQ(count, lightGrid.countLitLights());

    lightGrid.toggle(25, 25);
    EXPECT_EQ(count - 1, lightGrid.countLitLights());

    lightGrid.toggle(25, 25);
    EXPECT_EQ(count, lightGrid.countLitLights());

    lightGrid.toggle(25, 25);
    EXPECT_EQ(count - 1, lightGrid.countLitLights());

    lightGrid.toggle(25, 25);
    EXPECT_EQ(count, lightGrid.countLitLights());

    lightGrid.toggle(TEST_GRID_SIZE + 1, 25);
    EXPECT_EQ(count + 1, lightGrid.countLitLights());

    lightGrid.toggle(TEST_GRID_SIZE + 1, 25);
    EXPECT_EQ(count, lightGrid.countLitLights());
}

TEST(Aoc2015Day05BrightnessLightGridTest, testWhenCreatedItsTotalBrightnessIsZero)
{
    BrightnessLightGrid lightGrid;
    EXPECT_EQ(0, lightGrid.totalBrightness());
}

TEST(Aoc2015Day05BrightnessLightGridTest, testWhenTurnOnItsTotalBrightnessIsIncreasing)
{
    BrightnessLightGrid lightGrid;
    EXPECT_EQ(0, lightGrid.totalBrightness());

    lightGrid.turnOn(0, 0);
    EXPECT_EQ(1, lightGrid.totalBrightness());

    lightGrid.turnOn(0, 0);
    EXPECT_EQ(2, lightGrid.totalBrightness());

    lightGrid.turnOn(55, 123);
    EXPECT_EQ(3, lightGrid.totalBrightness());

    lightGrid.turnOn(111, 6);
    EXPECT_EQ(4, lightGrid.totalBrightness());
}

TEST(Aoc2015Day05BrightnessLightGridTest, testWhenTurnOffItsTotalBrightnessIsDecreasing)
{
    BrightnessLightGrid lightGrid;
    const int TEST_GRID_SIZE = 100;
    turnOnAllLights(lightGrid, TEST_GRID_SIZE, TEST_GRID_SIZE);
    long long totalBrightness = TEST_GRID_SIZE * TEST_GRID_SIZE;

    EXPECT_EQ(totalBrightness, lightGrid.totalBrightness());

    lightGrid.turnOff(0, 0);
    EXPECT_EQ(totalBrightness - 1, lightGrid.totalBrightness());

    lightGrid.turnOff(0, 0);
    EXPECT_EQ(totalBrightness - 1, lightGrid.totalBrightness());

    lightGrid.turnOff(55, 83);
    EXPECT_EQ(totalBrightness - 2, lightGrid.totalBrightness());

    lightGrid.turnOff(11, 6);
    EXPECT_EQ(totalBrightness - 3, lightGrid.totalBrightness());
}

TEST(Aoc2015Day05BrightnessLightGridTest, testWhenToggleItsTotalBrightnessIsIncreasingByTwo)
{
    BrightnessLightGrid lightGrid;
    const int TEST_GRID_SIZE = 100;
    turnOnAllLights(lightGrid, TEST_GRID_SIZE, TEST_GRID_SIZE);
    long long totalBrightness = TEST_GRID_SIZE * TEST_GRID_SIZE;

    EXPECT_EQ(totalBrightness, lightGrid.totalBrightness());

    lightGrid.toggle(0, 0);
    EXPECT_EQ(totalBrightness + 2, lightGrid.totalBrightness());

    lightGrid.toggle(0, 0);
    EXPECT_EQ(totalBrightness + 4, lightGrid.totalBrightness());

    lightGrid.toggle(55, 123);
    EXPECT_EQ(totalBrightness + 6, lightGrid.totalBrightness());

    lightGrid.toggle(111, 6);
    EXPECT_EQ(totalBrightness + 8, lightGrid.totalBrightness());
}