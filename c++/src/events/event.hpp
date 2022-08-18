#pragma once

#include <map>

class Day;

class Event
{
public:
    virtual ~Event();

    void solve_all_days();
    void solve_day(const int day);
    void add_day(const int day, Day *solver);
private:
    std::map<int, Day*> days;
};