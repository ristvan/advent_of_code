#include "accessories.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;

TEST(Aoc2015Day09ListPermutatorTest, whenThreeItemsInTheList)
{
    list<string> input = {string("A"), string("B"), string("C")};
    list<list<string>> actualResult = calculateAllPermutations(input);

    // list<list<string>> expectedResult
    EXPECT_EQ(6, actualResult.size());
}

TEST(Aoc2015Day09LocationStorageTest, whenDirectConnectionExists)
{
    LocationStorage locationStorage;
    locationStorage.addLocationDistance(new Distance(string("A"), string("B"), 2));
    locationStorage.addLocationDistance(new Distance(string("A"), string("C"), 3));
    locationStorage.addLocationDistance(new Distance(string("C"), string("D"), 5));

    EXPECT_EQ(2, locationStorage.getDistance(string("A"), string("B")));
    EXPECT_EQ(3, locationStorage.getDistance(string("A"), string("C")));
    EXPECT_EQ(5, locationStorage.getDistance(string("C"), string("D")));
}

TEST(Aoc2015Day09LocationStorageTest, whenDirectConnectionDoesNotExists)
{
    LocationStorage locationStorage;
    locationStorage.addLocationDistance(new Distance(string("A"), string("B"), 2));
    locationStorage.addLocationDistance(new Distance(string("A"), string("C"), 3));
    locationStorage.addLocationDistance(new Distance(string("C"), string("D"), 5));

    const int INFINITE = locationStorage.getTotalDistances() + 1;
    EXPECT_EQ(INFINITE, locationStorage.getDistance(string("A"), string("D")));
    EXPECT_EQ(INFINITE, locationStorage.getDistance(string("B"), string("C")));
    EXPECT_EQ(INFINITE, locationStorage.getDistance(string("E"), string("D")));
    EXPECT_EQ(INFINITE, locationStorage.getDistance(string(""), string("D")));
}

TEST(Aoc2015Day09MinimalDistanceCalculatorTest, whenSmallNetworkIsGiven)
{
    LocationStorage locationStorage;
    locationStorage.addLocationDistance(new Distance(string("London"), string("Dublin"), 464));
    locationStorage.addLocationDistance(new Distance(string("London"), string("Belfast"), 518));
    locationStorage.addLocationDistance(new Distance(string("Dublin"), string("Belfast"), 141));

    MinimalDistanceCalculator distanceCalculator(locationStorage);
    distanceCalculator.calculateMinMaxDistances();
    EXPECT_EQ(605, distanceCalculator.getMinimumDistance());
}

// TEST(Aoc2015Day09MinimalDistanceCalculatorTest, whenAFourLocationsNetworkIsGiven)
// {
//     LocationStorage locationStorage;
//     locationStorage.addLocationDistance(new Distance(string("AlphaCentauri"), string("Snowdin"), 66));
//     locationStorage.addLocationDistance(new Distance(string("AlphaCentauri"), string("Tambi"), 28));
//     locationStorage.addLocationDistance(new Distance(string("AlphaCentauri"), string("Faerun"), 60));
//     locationStorage.addLocationDistance(new Distance(string("Snowdin"), string("Tambi"), 22));
//     locationStorage.addLocationDistance(new Distance(string("Snowdin"), string("Faerun"), 12));
//     locationStorage.addLocationDistance(new Distance(string("Tambi"), string("Faerun"), 39));

//     MinimalDistanceCalculator distanceCalculator(locationStorage);
//     EXPECT_EQ(62, distanceCalculator.minimalDistance());
// }

// TEST(Aoc2015Day09MinimalDistanceCalculatorTest, whenAFiveLocationsNetworkIsGiven)
// {
//     LocationStorage locationStorage;
//     locationStorage.addLocationDistance(new Distance(string("AlphaCentauri"), string("Snowdin"), 66));
//     locationStorage.addLocationDistance(new Distance(string("AlphaCentauri"), string("Tambi"), 28));
//     locationStorage.addLocationDistance(new Distance(string("AlphaCentauri"), string("Faerun"), 60));
//     locationStorage.addLocationDistance(new Distance(string("AlphaCentauri"), string("Norrath"), 34));
//     locationStorage.addLocationDistance(new Distance(string("Snowdin"), string("Tambi"), 22));
//     locationStorage.addLocationDistance(new Distance(string("Snowdin"), string("Faerun"), 12));
//     locationStorage.addLocationDistance(new Distance(string("Snowdin"), string("Norrath"), 91));
//     locationStorage.addLocationDistance(new Distance(string("Tambi"), string("Faerun"), 39));
//     locationStorage.addLocationDistance(new Distance(string("Tambi"), string("Norrath"), 113));
//     locationStorage.addLocationDistance(new Distance(string("Faerun"), string("Norrath"), 63));

//     MinimalDistanceCalculator distanceCalculator(locationStorage);
//     EXPECT_EQ(96, distanceCalculator.minimalDistance());
// }
