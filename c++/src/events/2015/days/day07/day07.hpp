#pragma once

#include "common/day.hpp"

class Day07: public Day
{
public:
    Day07();
    virtual ~Day07();
    virtual void solve();
    virtual long long get_result_of_part_one() const;
    virtual long long get_result_of_part_two() const;
};