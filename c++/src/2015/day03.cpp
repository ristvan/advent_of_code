#include "day03.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <tuple>
#include <vector>


using namespace std;

class Coordinate
{
    public:
        Coordinate(const int x, const int y) : x(x), y(y) {}

        friend bool operator<(const Coordinate& l, const Coordinate& r)
        {
            return tie(l.x, l.y) < tie(r.x, r.y);
        }

        Coordinate goSouth() const
        {
            return Coordinate(x, y + 1);
        }

        Coordinate goNorth() const
        {
            return Coordinate(x, y - 1);
        }

        Coordinate goEast() const
        {
            return Coordinate(x + 1, y);
        }

        Coordinate goWest() const
        {
            return Coordinate(x - 1, y);
        }

    private:
        int x, y;
};


Day03::~Day03()
{
}

void Day03::solve()
{
    ifstream inputFile;
    inputFile.open("inputs/day_03.txt");
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

    Coordinate santasPosition = Coordinate(0, 0);
    Coordinate santasNextYearPosition = Coordinate(0, 0);
    Coordinate roboSantasPosition = Coordinate(0, 0);
    set<Coordinate> coordinates;
    coordinates.insert(santasPosition);
    set<Coordinate> coordinatesNextYear;
    coordinatesNextYear.insert(santasNextYearPosition);
    string line = lines[0];
    bool isSanta = true;
    for (char c : line)
    {
        if (c == '<')
        {
            santasPosition = santasPosition.goWest();
            if (isSanta)
            {
                santasNextYearPosition = santasNextYearPosition.goWest();
            }
            else
            {
                roboSantasPosition = roboSantasPosition.goWest();
            }
        }
        if (c == '>')
        {
            santasPosition = santasPosition.goEast();
            if (isSanta)
            {
                santasNextYearPosition = santasNextYearPosition.goEast();
            }
            else
            {
                roboSantasPosition = roboSantasPosition.goEast();
            }
        }
        if (c == '^')
        {
            santasPosition = santasPosition.goNorth();
            if (isSanta)
            {
                santasNextYearPosition = santasNextYearPosition.goNorth();
            }
            else
            {
                roboSantasPosition = roboSantasPosition.goNorth();
            }
        }
        if (c == 'v')
        {
            santasPosition = santasPosition.goSouth();
            if (isSanta)
            {
                santasNextYearPosition = santasNextYearPosition.goSouth();
            }
            else
            {
                roboSantasPosition = roboSantasPosition.goSouth();
            }
        }
        coordinates.insert(santasPosition);
        coordinatesNextYear.insert(santasNextYearPosition);
        coordinatesNextYear.insert(roboSantasPosition);
        isSanta = !isSanta;
    }

    cout << "Day 03" << endl;
    cout << "  * Part 1: " << coordinates.size() << endl;
    cout << "  * Part 2: " << coordinatesNextYear.size() << endl;
}
