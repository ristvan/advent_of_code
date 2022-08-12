#include "day02.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <regex>
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

class Box
{
    public:
        Box(int l, int w, int h) : length(l), width(w), height(h)
        {
        }

        int wrappingPaperSize() const
        {
            int side1 = length * width;
            int side2 = length * height;
            int side3 = width * height;
            int smallest = side1;
            if (side2 < smallest) smallest = side2;
            if (side3 < smallest) smallest = side3;

            return 2*(side1 + side2 + side3) + smallest;
        }

        int ribbonSize() const
        {
            int max = length;
            if (max < width) max = width;
            if (max < height) max = height;
            int ribbon = length + width + height - max;
            return 2 * ribbon + length * width * height;
        }
    private:
        int length, width, height;
};

Day02::~Day02()
{
}

void Day02::solve()
{
    ifstream inputFile;
    inputFile.open("inputs/day_02.txt");
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
    vector<Box*> presents;
    for (string& line : lines)
    {
        vector<string> boxSides = split(line, "x");
        int length =  stoi(boxSides[0]);
        int height =  stoi(boxSides[1]);
        int width =  stoi(boxSides[2]);
        presents.push_back(new Box(length, width, height));
    }
    int sumWrapping = 0;
    int sumRibbonLeght = 0;
    for (Box* box : presents)
    {
        sumWrapping += box->wrappingPaperSize();
        sumRibbonLeght += box->ribbonSize();
    }
    cout << "Day 02" << endl;
    cout << "  * Part 1: " << sumWrapping << endl;
    cout << "  * Part 2: " << sumRibbonLeght << endl;
    for (Box* box : presents)
    {
        delete box;
    }
}
