#pragma once

#include <string>
#include <vector>

class Event;

class EventCollection
{
public:
    EventCollection();
    ~EventCollection();

    void addEvent(Event* event);
    void solveEvent(const std::string &name, int day);
    void solveAllEvents();

private:
    std::vector<Event*> events;
};
