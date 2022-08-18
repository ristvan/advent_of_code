#include "factory.hpp"
#include "events/event.hpp"
#include "day01.hpp"
#include "day02.hpp"
#include <iostream>

using namespace std;

Event* create_event()
{
    Event *event = new Event{"2015"};
    event->add_day(1, new Day01);
    event->add_day(2, new Day02);
    return event;
}