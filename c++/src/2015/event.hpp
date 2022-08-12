#pragma once

#include <string>
#include <list>

class Day;

class Event
{
    public:
        Event(const std::string eventName);
	~Event();

        std::string getEventName() const;

        void add(Day *day);
        void solve();
    private:
        std::string eventName;
        std::list<Day*> days;
};
