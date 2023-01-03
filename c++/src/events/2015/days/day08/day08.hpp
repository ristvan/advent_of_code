#pragma once

#include "common/day.hpp"

class Day08: public Day
{
public:
    Day08();
    virtual ~Day08();
    virtual void solve();
    virtual long long get_result_of_part_one() const;
    virtual long long get_result_of_part_two() const;
private:
    unsigned short valueOfA;
    unsigned short valueOfRevisedA;
};