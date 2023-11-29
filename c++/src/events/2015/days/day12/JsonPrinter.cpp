#include "JsonPrinter.hpp"

#include <iostream>
#include <string>

using namespace std;

JsonPrinter::JsonPrinter() : level(0), isPaddingNeeded(true)
{
}

JsonPrinter::~JsonPrinter() {}

void JsonPrinter::printPadding()
{
    if (isPaddingNeeded)
    {
        for (int i = 0; i < level; ++i)
            cout << "    ";
    }
    else isPaddingNeeded = true;
}

void JsonPrinter::investigateNumber(const int number)
{
    printPadding();
    cout << number << endl;
}

void JsonPrinter::investigateString(const string& text)
{
    printPadding();
    cout << "\"" << text << "\"" << endl;
}

void JsonPrinter::investigateBoolean(const bool boolean)
{
    printPadding();
    cout << boolean << endl;
}

void JsonPrinter::startObject()
{
    printPadding();
    cout << "{" << endl;
    ++level;
}

void JsonPrinter::investigateObjectItem(const string& key)
{
    printPadding();
    cout << "\"" << key << "\": ";
    isPaddingNeeded = false;
}

void JsonPrinter::endObject()
{
    --level;
    printPadding();
    cout << "}" << endl;
}

void JsonPrinter::startArray()
{
    printPadding();
    cout << "[" << endl;
    ++level;
}

void JsonPrinter::endArray()
{
    --level;
    printPadding();
    cout << "]" << endl;
}
