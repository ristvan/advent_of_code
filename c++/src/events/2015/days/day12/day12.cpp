#include "day12.hpp"

#include "JsonIterator.hpp"
#include "JsonInterceptor.hpp"
#include "NumberCounter.hpp"
#include "NotRedNumberCounter.hpp"
#include "JsonPrinter.hpp"

#include <nlohmann/json.hpp>
#include <format>
#include <fstream>
#include <string>

using json = nlohmann::json;
using namespace std;

Day12::Day12(): firstAnswer("-"), secondAnswer("-")
{
}

Day12::~Day12()
{
}

void Day12::solve()
{
    ifstream inputFile("inputs/day_12.txt");
    json data = json::parse(inputFile);

    NotRedNumberCounter notRedNumberCounter;
    NumberCounter numberCounter;
    JsonIterator jsonIterator;
    JsonPrinter printer;
    jsonIterator.addInterceptor(&notRedNumberCounter);
    jsonIterator.addInterceptor(&numberCounter);
    jsonIterator.addInterceptor(&printer);
    jsonIterator.iterateJson(data);
    firstAnswer = format("{}", numberCounter.getSumOfNumbers());
    secondAnswer = format("{}", notRedNumberCounter.getSumOfNumbers());
}

string Day12::get_result_of_part_one() const
{
    return firstAnswer;
}

string Day12::get_result_of_part_two() const
{
    return secondAnswer;
}