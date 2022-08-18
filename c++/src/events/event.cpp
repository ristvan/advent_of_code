#include "event.hpp"
#include "common/day.hpp"

using namespace std;

Event::~Event()
{
    for (auto& [key, value]: this->days)
    {
        delete value;
    }
    this->days.clear();
}

void Event::solve_all_days()
{
    for (auto& [key, value]: this->days)
    {
        value->solve();
    }
}

void Event::solve_day(const int id)
{

}

void Event::add_day(const int id, Day *day)
{
    this->days[id] = day;
}