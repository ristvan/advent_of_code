#pragma once

#include "JsonInterceptor.hpp"

#include <string>

class NumberCounter: public JsonInterceptor
{
public:
    NumberCounter();
    virtual ~NumberCounter();
    virtual void investigateNumber(const int number);
    virtual void investigateString(const std::string& text);
    virtual void investigateBoolean(const bool boolean);
    virtual void startObject();
    virtual void investigateObjectItem(const std::string& key);
    virtual void endObject();
    virtual void startArray();
    virtual void endArray();
    long long getSumOfNumbers() const;
private:
    long long sumOfNumbers;
};
