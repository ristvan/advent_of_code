#pragma once

#include "common/day.hpp"

class Day06: public Day
{
public:
    Day06();
    virtual ~Day06();
    virtual void solve();
    virtual long long get_result_of_part_one() const;
    virtual long long get_result_of_part_two() const;
private:
    long long numberOfLightsAreLit;
    long long totalBrightness;
};