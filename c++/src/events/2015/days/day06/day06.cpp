#include "day06.hpp"
#include "helpers.hpp"
#include "lightgrid.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> read_file(string filename)
{
    ifstream inputFile;
    inputFile.open(filename);
    vector<string> lines;
    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            lines.push_back(line);
        }
        inputFile.close();
    }
    return lines;
}

Day06::Day06(): numberOfLightsAreLit(0), totalBrightness(0)
{
}

Day06::~Day06()
{
}

void Day06::solve()
{
    vector<string> lines = read_file("inputs/day_06.txt");
    vector<Action*> actions;
    for (string& line : lines)
        actions.push_back(convert_line(line));

    OnOffLightGrid lightGrid;
    BrightnessLightGrid brightnessLightGrid;
    for (Action* action : actions)
    {
        action->apply(lightGrid);
        action->apply(brightnessLightGrid);
        delete action;
    }
    numberOfLightsAreLit = lightGrid.countLitLights();
    totalBrightness = brightnessLightGrid.totalBrightness();
    // totalBrightness = brightnessLightGrid.countLitLights();

}

long long Day06::get_result_of_part_one() const
{
    return numberOfLightsAreLit;
}

long long Day06::get_result_of_part_two() const
{
    return totalBrightness;
}