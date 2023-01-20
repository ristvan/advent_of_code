#include "common/day.hpp"
#include "version.hpp"
#include "events/event.hpp"
#include "events/2015/factory.hpp"

#include <iostream>
#include <string>
#include <regex>

using namespace std;

static const int ALL_DAYS = -1;
static const regex INTEGER_PATTERN("[+-]?[0-9]+");

int main(int argc, char *argv[])
{
    string selectedEvent{"ALL"};
    int selectedDay = ALL_DAYS;
    string eventPrefix("--event=");
    string dayPrefix("--day=");
    for (int i = 1; i < argc; ++i)
    {
        string argument(argv[i]);
        if (!argument.compare(0, eventPrefix.length(), eventPrefix))
        {
            selectedEvent = argument.substr(eventPrefix.length());
        }
        else if (!argument.compare(0, dayPrefix.length(), dayPrefix))
        {
            string dayOption = argument.substr(dayPrefix.length());
            if (dayOption.compare("ALL") != 0) {
                selectedDay = atoi(dayOption.c_str());
            }
            if (selectedDay == 0) {
                cerr << "Invalid day! (" << dayOption << ")" << endl;
            }
        }
        // cout << i << ". " << argument << endl;
    }
    if (selectedDay == 0) {
        return 1;
    }

    cout << "Version: " << aoc_VERSION_MAJOR << "." << aoc_VERSION_MINOR << "." << aoc_VERSION_PATCH << endl << endl;
    cout << "Event: " << selectedEvent << endl;
    cout << "Day: " << (selectedDay == -1 ? "ALL" : to_string(selectedDay)) << endl << endl;
    Event *event = events::y2015::create_event();
    if (selectedDay > 0)
    {
        event->solve_day(selectedDay);
    }
    else
    {
        event->solve_all_days();
    }
    delete event;
    return 0;
}
