#pragma once

class Day
{
public:
    virtual ~Day(){};
    virtual void solve() = 0;
    virtual long long get_result_of_part_one() const = 0;
    virtual long long get_result_of_part_two() const = 0;
};
