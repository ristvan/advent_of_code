#include "event_collection.hpp"
#include "event.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

EventCollection::EventCollection() { }

EventCollection::~EventCollection()
{
    for (auto& value: this->events)
    {
        delete value;
    }
    this->events.clear();
}

void EventCollection::addEvent(Event* event)
{
    events.push_back(event);
}

void EventCollection::solveEvent(const string &name, int day)
{
    bool isFound = false;
    for (auto& event: this->events)
    {
        if (event->get_name() == name)
        {
            isFound = true;
            if (day == -1)
                event->solve_all_days();
            else
                event->solve_day(day);
            break;
        }
    }
    if (!isFound)
    {
        cout << "Event not found: " << name << endl;
    }

}

void EventCollection::solveAllEvents()
{
    for (auto& event: this->events)
    {
        event->solve_all_days();
        cout << endl;
    }
}
