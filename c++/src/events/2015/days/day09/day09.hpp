#pragma once

#include "common/day.hpp"

class Day09: public Day
{
public:
    Day09();
    virtual ~Day09();
    virtual void solve();
    virtual std::string get_result_of_part_one() const;
    virtual std::string get_result_of_part_two() const;
private:
    unsigned short valueOfA;
    unsigned short valueOfRevisedA;
};
