#pragma once

#include "common/day.hpp"
#include <string>

class Day12: public Day
{
public:
    Day12();
    virtual ~Day12();
    virtual void solve();
    virtual std::string get_result_of_part_one() const;
    virtual std::string get_result_of_part_two() const;
private:
    std::string firstAnswer;
    std::string secondAnswer;
};