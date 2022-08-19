#pragma once

#include "common/day.hpp"
#include <string>

bool hasAtLeastThreeVowels(const std::string& text);
bool hasLetterThatAppearsTwiceInARow(const std::string& text);
bool containsNotAllowedParts(const std::string& text);
bool hasPairAtLeastTwice(const std::string& text);
bool hasOneCharacterBetweenRepeatedCharacter(const std::string& text);

class Day05 : public Day
{
public:
    ~Day05();
    void solve();
    virtual long long get_result_of_part_one() const;
    virtual long long get_result_of_part_two() const;
private:
    long long numberOfNiceStrings;
    long long numberOfNiceStringsChangedCondition;
};
