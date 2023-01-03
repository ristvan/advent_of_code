#include "matchsticker.hpp"

#include <string>

using namespace std;

long long memory_length(const string& text)
{
    long long length = 0;
    bool is_escape = false;
    int number_of_characters_to_escape = 0;
    for (auto const& ch : text)
    {
        if (number_of_characters_to_escape > 0)
        {
            if (ch == 'x')
            {
                number_of_characters_to_escape += 2;
            }
            --number_of_characters_to_escape;
        }
        else {
            if (ch == '\\')
            {
                number_of_characters_to_escape = 1;
            }
            ++length;
        }
    }
    return length - 2;
}

string encode_string(const string& text)
{
    string output = "\"";
    for (auto const& ch : text)
    {
        if (ch == '\\')
            output += '\\';
        else if (ch == '"')
            output += '\\';
        output += ch;
    }
    output += "\"";
    return output;
}