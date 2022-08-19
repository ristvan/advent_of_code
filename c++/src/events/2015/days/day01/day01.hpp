#pragma once

#include "common/day.hpp"

class Day01 : public Day
{
public:
    virtual ~Day01();
    virtual void solve();
    virtual long long get_result_of_part_one() const;
    virtual long long get_result_of_part_two() const;
private:
    long long level;
    long long firstMinusOne;
};

