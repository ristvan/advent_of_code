#include "tools.hpp"

#include <set>
#include <string>

using namespace std;

bool hasSequenceInPassword(const string& passwordCandidate)
{
    char previousCharacter = 0, secondPreviousCharacter = 0;
    for (const char& ch :passwordCandidate)
    {
        if (previousCharacter == secondPreviousCharacter + 1 && previousCharacter + 1 == ch)
        {
            return true;
        }
        secondPreviousCharacter = previousCharacter;
        previousCharacter = ch;
    }
    return false;
}

bool areAllCharactersValid(const string& passwordCandidate)
{
    for (const char& ch :passwordCandidate)
    {
        if (ch == 'i' || ch =='o' || ch == 'l')
            return false;
    }
    return true;
}

bool hasTwoDifferentPairsOfLetters(const string& passwordCandidate)
{
    char previousCharacter = '\0';
    set<char> characterPairs;
    for (auto& ch : passwordCandidate)
    {
        if (ch == previousCharacter)
            characterPairs.insert(ch);
        previousCharacter = ch;
    }
    return characterPairs.size() > 1;
}

bool isValidPassword(const string& passwordCandidate)
{
    return hasSequenceInPassword(passwordCandidate) && areAllCharactersValid(passwordCandidate) &&
           hasTwoDifferentPairsOfLetters(passwordCandidate);
}

string nextPasswordCandidate(const string& passwordCandidate)
{
    string nextPassword(passwordCandidate);
    bool changeIsNeeded = true;
    for (int i = passwordCandidate.length() - 1; i >= 0 && changeIsNeeded; --i)
    {
        if (passwordCandidate[i] == 'z')
        {
            nextPassword[i] = 'a';
        }
        else
        {
            nextPassword[i] = passwordCandidate[i] + 1;
            changeIsNeeded = false;
        }
    }
    return nextPassword;
}

string findTheNextValidPassword(const string& startingPassword)
{
    string nextPassword(nextPasswordCandidate(startingPassword));
    while (!isValidPassword(nextPassword))
    {
        nextPassword = nextPasswordCandidate(nextPassword);
    }
    return nextPassword;
}
