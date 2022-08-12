#include "event.hpp"
#include "day.hpp"

#include <string>

using namespace std;

Event::Event(const string eventName) : eventName(eventName)
{
}

Event::~Event()
{
    for (Day *day : days)
    {
        delete day;
    }
}

std::string Event::getEventName() const
{
    return eventName;
}

void Event::add(Day *day)
{
    days.push_back(day);
}

void Event::solve()
{
    for (Day *day : days)
    {
        day->solve();
    }
}

