#pragma once

#include "common/day.hpp"
#include <string>

class Day03 : public Day
{
public:
    ~Day03();
    void solve();
    virtual std::string get_result_of_part_one() const;
    virtual std::string get_result_of_part_two() const;
private:
    long long numberOfHousesFirstYear;
    long long numberOfHousesSecondYear;
};
