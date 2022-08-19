#include "factory.hpp"
#include "events/event.hpp"
#include "day01.hpp"
#include "day02.hpp"
#include "day03.hpp"
#include "day04.hpp"
#include "day05.hpp"
#include <iostream>

using namespace std;

Event* create_event()
{
    Event *event = new Event{"2015"};
    event->add_day(1, new Day01);
    event->add_day(2, new Day02);
    event->add_day(3, new Day03);
    event->add_day(4, new Day04);
    event->add_day(5, new Day05);
    return event;
}