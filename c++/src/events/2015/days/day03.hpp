#pragma once

#include "common/day.hpp"

class Day03 : public Day
{
public:
    ~Day03();
    void solve();
    virtual long long get_result_of_part_one() const;
    virtual long long get_result_of_part_two() const;
private:
    long long numberOfHousesFirstYear;
    long long numberOfHousesSecondYear;
};
