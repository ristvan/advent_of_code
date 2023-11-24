#pragma once

#include "common/day.hpp"
#include <string>

class Day07: public Day
{
public:
    Day07();
    virtual ~Day07();
    virtual void solve();
    virtual std::string get_result_of_part_one() const;
    virtual std::string get_result_of_part_two() const;
private:
    unsigned short valueOfA;
    unsigned short valueOfRevisedA;
};