#pragma once

#include "common/day.hpp"
#include <string>

class Day11: public Day
{
public:
    Day11();
    virtual ~Day11();
    virtual void solve();
    virtual std::string get_result_of_part_one() const;
    virtual std::string get_result_of_part_two() const;
private:
    std::string firstPassword;
    std::string secondPassword;
};
