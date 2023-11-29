#include "NotRedNumberCounter.hpp"

#include <string>
#include <vector>

using namespace std;

class LevelInfo
{
public:
    LevelInfo() : sum(0), foundRed(false) {}
    long long getSum() const { return sum; }
    void add(long long value) { sum+= value; }
    bool hasRed() const { return foundRed; }
    void setRed() { foundRed = true; }
private:
    long long sum;
    bool foundRed;
};


NotRedNumberCounter::NotRedNumberCounter()
{
}

NotRedNumberCounter::~NotRedNumberCounter()
{
    for (LevelInfo* levelInfo : levels)
        delete levelInfo;
}

void NotRedNumberCounter::investigateNumber(const int number)
{
    levels.back()->add(number);
}
void NotRedNumberCounter::investigateString(const string& text)
{
    if (string("red").compare(text) == 0)
    {
        levels.back()->setRed();
    }
}

void NotRedNumberCounter::investigateBoolean(const bool boolean) {}
void NotRedNumberCounter::startObject()
{
    levels.push_back(new LevelInfo());
}

void NotRedNumberCounter::investigateObjectItem(const string& key) {}
void NotRedNumberCounter::endObject()
{
    if (levels.size() > 1)
    {
        LevelInfo *actualLevel = levels.back();
        levels.pop_back();
        if (!actualLevel->hasRed())
        {
            levels.back()->add(actualLevel->getSum());
        }
        delete actualLevel;
    }
}
void NotRedNumberCounter::startArray()
{
    levels.push_back(new LevelInfo());
}

void NotRedNumberCounter::endArray()
{
    if (levels.size() > 1)
    {
        LevelInfo *actualLevel = levels.back();
        levels.pop_back();
        levels.back()->add(actualLevel->getSum());
        delete actualLevel;
    }
}

long long NotRedNumberCounter::getSumOfNumbers() const
{
    return levels.back()->getSum();
}
