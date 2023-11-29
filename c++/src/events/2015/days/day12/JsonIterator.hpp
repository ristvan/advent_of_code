#pragma once

#include <nlohmann/json.hpp>
#include <vector>

class JsonInterceptor;

class JsonIterator
{
public:
    JsonIterator();
    void iterateJson(nlohmann::json& jsonItem);
    void addInterceptor(JsonInterceptor *interceptor);  // [interceptor is owned by the user]
private:
    void iterateObject(nlohmann::json& jsonObject);
    void iterateString(nlohmann::json& jsonString);
    void iterateBoolean(nlohmann::json& jsonBoolean);
    void iterateNumber(nlohmann::json& jsonNumber);
    void iterateArray(nlohmann::json& jsonArray);
    std::vector<JsonInterceptor*> interceptors;
};
