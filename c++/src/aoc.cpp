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
};

TestDay::~TestDay()
{
    cout << "TestDay::dtor()" << endl;
}

void TestDay::solve()
{
    cout << "TestDay::solve()" << endl;
}

int main()
{
    cout << "Version: " << aoc_VERSION_MAJOR << "." << aoc_VERSION_MINOR << "." << aoc_VERSION_PATCH << endl;
    Event event;
    event.add_day(1, new TestDay());
    event.solve_all_days();
    return 0;
}
