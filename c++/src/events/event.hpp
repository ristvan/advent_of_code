#pragma once

#include <map>
#include <string>

class Day;

class Event
{
public:
    Event(const std::string &name);
    virtual ~Event();

    void solve_all_days();
    void solve_day(const int day);
    void add_day(const int day, Day *solver);
    std::string get_name() const;
private:
    std::map<int, Day*> days;
    const std::string name;
};