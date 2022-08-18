#pragma once

#include <map>

class Day;

class Event
{
public:
    virtual ~Event();

    void solve_all_days();
    void solve_day(const int id);
    void add_day(const int id, Day *day);
private:
    std::map<int, Day*> days;
};