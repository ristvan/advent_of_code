#include "event.hpp"
#include "common/day.hpp"

#include <iostream>
#include <string>

using namespace std;

Event::Event(const string& name): name(name)
{
}

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
    cout << "Event: " << this->name << endl;
    for (auto& [day, solver]: this->days)
    {
        solver->solve();
        cout << "  * Day " << day << ":" << endl;
        cout << "      * Part 1: " << solver->get_result_of_part_one() << endl;
        cout << "      * Part 2: " << solver->get_result_of_part_two() << endl;
    }
}

void Event::solve_day(const int day)
{
    cout << "Event: " << this->name << endl;
    if (this->days.count(day) > 0)
    {
        Day *solver = this->days[day];
        solver->solve();
        cout << "  * Day " << day << ":" << endl;
        cout << "      * Part 1: " << solver->get_result_of_part_one() << endl;
        cout << "      * Part 2: " << solver->get_result_of_part_two() << endl;
    }
    else
    {
        cout << "  * Day " << day << ": Not Found" << endl;
    }
}

void Event::add_day(const int day, Day *solver)
{
    if (this->days.count(day) > 0)
    {
        Day *old_solver = this->days[day];
        delete old_solver;
        this->days[day] = nullptr;
    }
    this->days[day] = solver;
}