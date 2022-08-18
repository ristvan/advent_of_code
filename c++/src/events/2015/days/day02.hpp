#pragma once

#include "common/day.hpp"

class Day02 : public Day
{
public:
    virtual ~Day02();
    virtual void solve();
    virtual long long get_result_of_part_one() const;
    virtual long long get_result_of_part_two() const;
private:
    long long sumWrapping;
    long long sumRibbonLenght;
};

