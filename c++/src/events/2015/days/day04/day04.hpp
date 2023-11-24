#pragma once

#include "common/day.hpp"
#include <string>

class Day04 : public Day
{
public:
    ~Day04();
    void solve();
    virtual std::string get_result_of_part_one() const;
    virtual std::string get_result_of_part_two() const;
private:
    long long numberProducingFiveZeros;
    long long numberProducingSixZeros;
};
