#include "day02.hpp"
#include "common/file_handler.hpp"
#include "common/string_manipulators.hpp"

#include <iostream>
#include <string>
#include <regex>
#include <vector>


using namespace std;


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
    vector<string> lines = read_file("inputs/day_02.txt");
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
    int sumRibbonLenght = 0;
    for (Box* box : presents)
    {
        sumWrapping += box->wrappingPaperSize();
        sumRibbonLenght += box->ribbonSize();
    }
    this->sumWrapping = sumWrapping;
    this->sumRibbonLenght = sumRibbonLenght;
    for (Box* box : presents)
    {
        delete box;
    }
}

string Day02::get_result_of_part_one() const
{
    return to_string(this->sumWrapping);
}

string Day02::get_result_of_part_two() const
{
    return to_string(this->sumRibbonLenght);
}
