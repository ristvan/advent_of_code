#include "day09.hpp"
#include "accessories.hpp"
#include "common/file_handler.hpp"
#include <map>
#include <format>
#include <set>
#include <string>
#include <vector>
#include <iostream>


using namespace std;

Distance* convert_line_to_distance(const string& line)
{
    size_t position = line.find(" = ");
    string path = line.substr(0, position);
    size_t p2 = path.find(" to ");
    string from = path.substr(0, p2);
    string to = path.substr(p2 + 4);
    int distance = stoi(line.substr(position + 3));
    return new Distance(from, to, distance);
}

Day09::Day09(): valueOfA(0), valueOfRevisedA(0)
{
}

Day09::~Day09()
{
}

void Day09::solve()
{
    vector<string> lines = read_file("inputs/day_09.txt");
    LocationStorage locationStorage;
    for (string& line : lines)
    {
        Distance *distance = convert_line_to_distance(line);
        locationStorage.addLocationDistance(distance);
    }
    MinimalDistanceCalculator minimalDistanceCalculator(locationStorage);
    minimalDistanceCalculator.calculateMinMaxDistances();
    valueOfA = minimalDistanceCalculator.getMinimumDistance();
    valueOfRevisedA = minimalDistanceCalculator.getMaximumDistance();
}

long long Day09::get_result_of_part_one() const
{
    return valueOfA;
}

long long Day09::get_result_of_part_two() const
{
    return valueOfRevisedA;
}