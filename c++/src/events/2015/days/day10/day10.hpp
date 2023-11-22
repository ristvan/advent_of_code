#pragma once

#include "common/day.hpp"

class Day10: public Day
{
public:
    Day10();
    virtual ~Day10();
    virtual void solve();
    virtual long long get_result_of_part_one() const;
    virtual long long get_result_of_part_two() const;
private:
    unsigned int valueOfA;
    unsigned int valueOfRevisedA;
};
