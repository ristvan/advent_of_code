#include "factory.hpp"
#include "events/event.hpp"
#include "events/2015/days/day01/day01.hpp"
#include "events/2015/days/day02/day02.hpp"
#include "events/2015/days/day03/day03.hpp"
#include "events/2015/days/day04/day04.hpp"
#include "events/2015/days/day05/day05.hpp"
#include "events/2015/days/day06/day06.hpp"
#include "events/2015/days/day07/day07.hpp"
#include "events/2015/days/day08/day08.hpp"
#include "events/2015/days/day09/day09.hpp"
#include "events/2015/days/day10/day10.hpp"

using namespace std;

Event* events::y2015::create_event()
{
    Event *event = new Event{"2015"};
    event->add_day(1, new Day01);
    event->add_day(2, new Day02);
    event->add_day(3, new Day03);
    event->add_day(4, new Day04);
    event->add_day(5, new Day05);
    event->add_day(6, new Day06);
    event->add_day(7, new Day07);
    event->add_day(8, new Day08);
    event->add_day(9, new Day09);
    event->add_day(10, new Day10);
    return event;
}
