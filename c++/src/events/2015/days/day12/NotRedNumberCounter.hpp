#pragma once

#include "JsonInterceptor.hpp"
#include <string>
#include <vector>

class LevelInfo;

class NotRedNumberCounter: public JsonInterceptor
{
public:
    NotRedNumberCounter();
    virtual ~NotRedNumberCounter();
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
    std::vector<LevelInfo*> levels;
};
