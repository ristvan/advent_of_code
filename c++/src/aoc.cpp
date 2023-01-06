#include "common/day.hpp"
#include "version.hpp"
#include "events/event.hpp"
#include "events/2015/factory.hpp"

#include <iostream>

using namespace std;

int main()
{
    cout << "Version: " << aoc_VERSION_MAJOR << "." << aoc_VERSION_MINOR << "." << aoc_VERSION_PATCH << endl;
    Event *event = events::y2015::create_event();
    event->solve_all_days();
    delete event;
    return 0;
}
