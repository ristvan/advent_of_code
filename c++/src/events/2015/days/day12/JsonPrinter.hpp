#pragma once

#include "JsonInterceptor.hpp"
#include <string>

class JsonPrinter: public JsonInterceptor
{
public:
    JsonPrinter();
    virtual ~JsonPrinter();
    virtual void investigateNumber(const int number);
    virtual void investigateString(const std::string& string);
    virtual void investigateBoolean(const bool boolean);
    virtual void startObject();
    virtual void investigateObjectItem(const std::string& key);
    virtual void endObject();
    virtual void startArray();
    virtual void endArray();
private:
    void printPadding();
    int level;
    bool isPaddingNeeded;
};
