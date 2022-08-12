#include "event.hpp"
#include "day01.hpp"
#include "day02.hpp"
#include "day03.hpp"
#include "day04.hpp"
#include "day05.hpp"
#include "day06.hpp"

int main(int argc, char* argv[])
{
    Event event{"2015"};
    event.add(new Day01());
    event.add(new Day02());
    event.add(new Day03());
    event.add(new Day04());
    event.add(new Day05());
    event.add(new Day06());
    event.solve();
}

