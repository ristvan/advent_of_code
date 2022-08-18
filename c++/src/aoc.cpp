#include "common/day.hpp"
#include "version.hpp"
#include "events/event.hpp"

#include <iostream>

using namespace std;

class TestDay: public Day
{
public:
    virtual ~TestDay();
    virtual void solve();
    virtual long long get_result_of_part_one() const;
    virtual long long get_result_of_part_two() const;
};

TestDay::~TestDay()
{
    cout << "TestDay::dtor()" << endl;
}

void TestDay::solve()
{
    cout << "TestDay::solve()" << endl;
}

long long TestDay::get_result_of_part_one() const
{
    return 6;
}

long long TestDay::get_result_of_part_two() const
{
    return 28;
}


int main()
{
    cout << "Version: " << aoc_VERSION_MAJOR << "." << aoc_VERSION_MINOR << "." << aoc_VERSION_PATCH << endl;
    Event event{"Test Event"};
    event.add_day(1, new TestDay());
    event.solve_all_days();
    event.solve_day(1);
    event.solve_day(28);
    return 0;
}
