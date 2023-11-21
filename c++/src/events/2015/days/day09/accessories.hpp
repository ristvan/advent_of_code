#pragma once

#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>


std::list<std::list<std::string>> calculateAllPermutations(std::list<std::string>& inputItems);


class Distance
{
public:
    Distance(const std::string& firstPlace, const std::string & secondPlace, int distance)
        : firstPlace(firstPlace), secondPlace(secondPlace), distance(distance)
    {
    }

    std::string firstPlace;
    std::string secondPlace;
    int distance;
};

class LocationStorage
{
public:
    LocationStorage() {}
    ~LocationStorage();

    void addLocationDistance(Distance *distance);

    int getDistance(const std::string &firstPlace, const std::string &secondPlace) const;

    int getTotalDistances() const;

    int getNumberOfCities() const;

    std::set<std::string> getLocationNames() const;

private:
    std::vector<Distance*> locationDistances;
    std::set<std::string> locationNames;
};


class MinimalDistanceCalculator {
public:
    MinimalDistanceCalculator(LocationStorage &locationStorage);

    void calculateMinMaxDistances();
    int getMinimumDistance() const;
    int getMaximumDistance() const;
private:
    LocationStorage &locationStorage;
    const int INFINITE;
    int minimumDistance;
    int maximumDistance;
};
