#pragma once

#include "common/day.hpp"
#include <string>

class Day01 : public Day
{
public:
    virtual ~Day01();
    virtual void solve();
    virtual std::string get_result_of_part_one() const;
    virtual std::string get_result_of_part_two() const;
private:
    long long level;
    long long firstMinusOne;
};

