#include "JsonIterator.hpp"
#include "JsonInterceptor.hpp"

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;
using namespace std;

JsonIterator::JsonIterator()
{
}

void JsonIterator::iterateJson(json& jsonItem)
{
    if (jsonItem.is_object()) iterateObject(jsonItem);
    else if (jsonItem.is_string()) iterateString(jsonItem);
    else if (jsonItem.is_boolean()) iterateBoolean(jsonItem);
    else if (jsonItem.is_number()) iterateNumber(jsonItem);
    else if (jsonItem.is_array()) iterateArray(jsonItem);
}

void JsonIterator::iterateObject(json& jsonObject)
{
    for (auto* interceptor: interceptors)
        interceptor->startObject();
    for (auto& [key, value] : jsonObject.items())
    {
        for (auto* interceptor: interceptors)
            interceptor->investigateObjectItem(key);
        iterateJson(value);
    }
    for (auto* interceptor: interceptors)
        interceptor->endObject();
}

void JsonIterator::iterateString(json& jsonString)
{
    for (auto* interceptor: interceptors)
        interceptor->investigateString(jsonString.template get<string>());
}

void JsonIterator::iterateBoolean(json& jsonBoolean)
{
    for (auto* interceptor: interceptors)
        interceptor->investigateBoolean(jsonBoolean.template get<bool>());
}

void JsonIterator::iterateNumber(json& jsonNumber)
{
    for (auto* interceptor: interceptors)
        interceptor->investigateNumber(jsonNumber.template get<int>());
}

void JsonIterator::iterateArray(json& jsonArray)
{
    for (auto* interceptor: interceptors)
        interceptor->startArray();
    for (auto& value : jsonArray)
    {
        iterateJson(value);
    }
    for (auto* interceptor: interceptors)
        interceptor->endArray();
}

void JsonIterator::addInterceptor(JsonInterceptor *interceptor)
{
    interceptors.push_back(interceptor);
}
