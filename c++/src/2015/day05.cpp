#include "day05.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool hasAtLeastThreeVowels(const string& text)
{
    int numberOfVowels = 0;
    for (const char ch: text)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            ++ numberOfVowels;
            if (numberOfVowels >= 3)
                break;
        }
    }
    return numberOfVowels >= 3;
}

bool hasLetterThatAppearsTwiceInARow(const string& text)
{
    char previous_ch = '\0';
    for (const char ch: text) {
        if (previous_ch == ch)
            return true;
        previous_ch = ch;
    }

    return false;
}

bool containsNotAllowedParts(const std::string& text)
{
    char previous_ch = text.at(0);
    for (const char ch: text.substr(1)) {
        if (previous_ch == 'a' && ch == 'b')
            return true;
        if (previous_ch == 'c' && ch == 'd')
            return true;
        if (previous_ch == 'p' && ch == 'q')
            return true;
        if (previous_ch == 'x' && ch == 'y')
            return true;
        previous_ch = ch;
    }

    return false;
    return false;
}

bool isNiceStringPart1Rules(const string& text)
{
    return hasAtLeastThreeVowels(text) && hasLetterThatAppearsTwiceInARow(text)
           && !containsNotAllowedParts(text);
}

bool hasPairAtLeastTwice(const string& text)
{
    map<string, int> pairs;
    set<string> early_pairs;
    string previous_pair, pair;
    previous_pair = pair = text.substr(0, 2);
    pairs[pair] = 1;
    for (int i = 1; i < text.length() - 1; ++i)
    {
        pair = text.substr(i, 2);
        if (pair.compare(previous_pair) != 0)
        {
            if (pairs.count(pair) > 0)
                pairs[pair] = pairs[pair] + 1;
            else pairs[pair] = 1;
        }
        else if (early_pairs.count(pair))
        {
            pairs[pair] = pairs[pair] + 1;
        }
        early_pairs.insert(previous_pair);
        previous_pair = pair;
    }
    for (const auto& [key, value]: pairs)
    {
        if (value > 1)
            return true;
    }
    return false;
}

bool hasOneCharacterBetweenRepeatedCharacter(const string& text)
{
    const int lenght_of_text = text.length();
    for (int i = 0; i < lenght_of_text - 2; ++i)
    {
        string sub_text = text.substr(i, 3);
        if (sub_text[0] == sub_text[2])
          return true;
    }
    return false;
}

bool isNiceStringPart2Rules(const string& text)
{
    return hasPairAtLeastTwice(text) && hasOneCharacterBetweenRepeatedCharacter(text);
}

Day05::~Day05()
{
}

void Day05::solve()
{
    ifstream inputFile;
    inputFile.open("inputs/day_05.txt");
    vector<string> lines;
    if (inputFile.is_open())
    {
        string line;
        while (getline(inputFile, line))
        {
            lines.push_back(line);
        }
        inputFile.close();
    }
    int part1 = 0, part2 = 0;
    for (const string& text: lines)
    {
        if (isNiceStringPart1Rules(text))
          ++part1;
        if (isNiceStringPart2Rules(text))
          ++part2;
    }
    cout << "Day 05" << endl;
    cout << "  * Part 1: " << part1 << endl;
    cout << "  * Part 2: " << part2 << endl;
}