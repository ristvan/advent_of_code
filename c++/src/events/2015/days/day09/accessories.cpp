#include "accessories.hpp"
#include "common/permutations.hpp"

#include <format>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;


LocationStorage::~LocationStorage()
{
    for (auto& value: this->locationDistances)
    {
        delete value;
    }
    this->locationDistances.clear();
}

void LocationStorage::addLocationDistance(Distance *distance)
{
    locationDistances.push_back(distance);
    locationNames.insert(distance->firstPlace);
    locationNames.insert(distance->secondPlace);
}

int LocationStorage::getDistance(const std::string &firstPlace, const std::string &secondPlace) const
{
    for (auto& value: this->locationDistances)
    {
        if ((value->firstPlace.compare(firstPlace) == 0 && value->secondPlace.compare(secondPlace) == 0) ||
            (value->firstPlace.compare(secondPlace) == 0 && value->secondPlace.compare(firstPlace) == 0))
        {
            return value->distance;
        }
    }
    return getTotalDistances() + 1;
}

int LocationStorage::getTotalDistances() const {
    int sum_of_the_distances = 0;
    for (auto& value: this->locationDistances)
    {
        sum_of_the_distances += value->distance;
    }
    return sum_of_the_distances;
}

int LocationStorage::getNumberOfCities() const {
    return locationNames.size();
}

std::set<std::string> LocationStorage::getLocationNames() const {
    return locationNames;
}



MinimalDistanceCalculator::MinimalDistanceCalculator(LocationStorage &locationStorage):
        locationStorage(locationStorage), INFINITE(locationStorage.getTotalDistances() + 1)
{
}

void MinimalDistanceCalculator::calculateMinMaxDistances()
{
    minimumDistance = INFINITE;
    maximumDistance = 0;
    list<string> locationNames;
    for (auto& locationName : locationStorage.getLocationNames())
    {
        locationNames.push_back(locationName);
    }
    list<list<string>> locationPermutations = calculateAllPermutations(locationNames);
    for (auto& locations : locationPermutations)
    {
        string previousLocation = "";
        int actualDistance = -INFINITE;
        for (auto& location: locations)
        {
            actualDistance += locationStorage.getDistance(previousLocation, location);
            previousLocation = location;
        }
        if (minimumDistance > actualDistance)
            minimumDistance = actualDistance;
        if (maximumDistance < actualDistance)
            maximumDistance = actualDistance;
    }
}

int MinimalDistanceCalculator::getMinimumDistance() const
{
    return minimumDistance;
}

int MinimalDistanceCalculator::getMaximumDistance() const
{
    return maximumDistance;
}
