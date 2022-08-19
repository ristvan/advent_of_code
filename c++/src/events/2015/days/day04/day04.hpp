#pragma once

#include "common/day.hpp"

class Day04 : public Day
{
public:
    ~Day04();
    void solve();
    virtual long long get_result_of_part_one() const;
    virtual long long get_result_of_part_two() const;
private:
    long long numberProducingFiveZeros;
    long long numberProducingSixZeros;
};
