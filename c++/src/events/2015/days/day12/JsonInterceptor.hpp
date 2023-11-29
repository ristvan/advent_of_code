#pragma once

#include <string>

class JsonInterceptor
{
public:
    virtual ~JsonInterceptor() {}
    virtual void investigateNumber(const int number) = 0;
    virtual void investigateString(const std::string& string) = 0;
    virtual void investigateBoolean(const bool boolean) = 0;
    virtual void startObject() = 0;
    virtual void investigateObjectItem(const std::string& key) = 0;
    virtual void endObject() = 0;
    virtual void startArray() = 0;
    virtual void endArray() = 0;
};
