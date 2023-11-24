#include "day03.hpp"
#include "common/file_handler.hpp"

#include <iostream>
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
    vector<string> lines = read_file("inputs/day_03.txt");

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

    numberOfHousesFirstYear = static_cast<long long>(coordinates.size());
    numberOfHousesSecondYear = static_cast<long long>(coordinatesNextYear.size());
}

string Day03::get_result_of_part_one() const
{
    return to_string(numberOfHousesFirstYear);
}

string Day03::get_result_of_part_two() const
{
    return to_string(numberOfHousesSecondYear);
}
