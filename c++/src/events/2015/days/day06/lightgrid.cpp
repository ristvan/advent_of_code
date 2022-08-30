#include "lightgrid.hpp"
#include <iostream>
#include <map>

using namespace std;

LightGrid::~LightGrid() {}

OnOffLightGrid::OnOffLightGrid()
{
    for (int row = 0; row < 1000; ++row)
        for (int column = 0; column < 1000; ++column)
            lights[row][column] = false;
}

void OnOffLightGrid::turnOn(int row, int column)
{
    lights[row][column] = true;
}

void OnOffLightGrid::turnOff(int row, int column)
{
    lights[row][column] = false;
}

void OnOffLightGrid::toggle(int row, int column)
{
    lights[row][column] = !lights[row][column];
}

int OnOffLightGrid::countLitLights() const
{
    int numberOfLitLights = 0;
    for (int row = 0; row < 1000; ++row)
        for (int column = 0; column < 1000; ++column)
            if (lights[row][column])
                ++numberOfLitLights;
    return numberOfLitLights;
}

BrightnessLightGrid::BrightnessLightGrid()
{
    lights = new int *[1000];
    for (int row = 0; row < 1000; ++row)
    {
        lights[row] = new int[1000];
        for (int column = 0; column < 1000; ++column)
            lights[row][column] = 0;
    }
}

BrightnessLightGrid::~BrightnessLightGrid()
{
    for (int row = 0; row < 1000; ++row)
        delete[] lights[row];
    delete[] lights;
}

void BrightnessLightGrid::turnOn(int row, int column)
{
    lights[row][column] += 1ll;
}

void BrightnessLightGrid::turnOff(int row, int column)
{
    if (lights[row][column] > 0ll)
        lights[row][column] -= 1ll;
}

void BrightnessLightGrid::toggle(int row, int column)
{
    lights[row][column] += 2ll;
}

long long BrightnessLightGrid::totalBrightness() const
{
    long long totalBrightness = 0ll;
    // for (auto& [row, columns]: lights)
    //     for (auto& [columns, brightness]: columns)
    //         totalBrightness += brightness;
    for (int row = 0; row < 1000; ++row)
        for (int column = 0; column < 1000; ++column)
            totalBrightness += lights[row][column];
    return totalBrightness;
}
