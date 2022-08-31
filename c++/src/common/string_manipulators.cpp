#include "string_manipulators.hpp"
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string str, const string delimiter)
{
    vector<string> tokens;
    auto start = 0U;
    auto end = str.find(delimiter);
    while (end != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
        end = str.find(delimiter, start);
    }
    tokens.push_back(str.substr(start, end - start));
    return tokens;
}
