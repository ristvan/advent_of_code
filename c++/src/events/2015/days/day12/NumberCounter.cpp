#include "NumberCounter.hpp"
#include <string>

using namespace std;

NumberCounter::NumberCounter() : sumOfNumbers(0)
{
}

NumberCounter::~NumberCounter() {}

void NumberCounter::investigateNumber(const int number)
{
    sumOfNumbers += number;
}
void NumberCounter::investigateString(const string& text)
{
}

void NumberCounter::investigateBoolean(const bool boolean)
{
}

void NumberCounter::startObject()
{
}

void NumberCounter::investigateObjectItem(const string& key)
{
}

void NumberCounter::endObject()
{
}

void NumberCounter::startArray()
{
}

void NumberCounter::endArray()
{
}

long long NumberCounter::getSumOfNumbers() const
{
    return sumOfNumbers;
}
