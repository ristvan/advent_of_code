#include "helpers.hpp"
#include "lightgrid.hpp"

#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

Rectangle::Rectangle() : topX(0), leftY(0), bottomX(0), rightY(0)
{

}

Rectangle::Rectangle(int topX, int leftY, int bottomX, int rightY)
  : topX(topX), leftY(leftY), bottomX(bottomX), rightY(rightY)
{

}

bool operator==(const Rectangle& l, const Rectangle& r)
{
    return l.topX == r.topX && l.leftY == r.leftY && l.bottomX == r.bottomX && l.rightY == r.rightY;
}

bool operator==(const Action& l, const Action& r)
{
    return l.type == r.type && r.rectangle == l.rectangle;
}

bool operator!=(const Action& l, const Action& r)
{
    return !(l == r);
}

Action::~Action()
{

}

TurnOn::~TurnOn()
{

}

void TurnOn::apply(LightGrid &lightGrid)
{
    for (int row = rectangle.leftY; row <= rectangle.rightY; ++row)
        for (int column = rectangle.topX; column <= rectangle.bottomX; ++column)
            lightGrid.turnOn(row, column);
}

TurnOff::~TurnOff()
{

}

void TurnOff::apply(LightGrid &lightGrid)
{
    for (int row = rectangle.leftY; row <= rectangle.rightY; ++row)
        for (int column = rectangle.topX; column <= rectangle.bottomX; ++column)
            lightGrid.turnOff(row, column);
}

Toggle::~Toggle()
{

}

void Toggle::apply(LightGrid &lightGrid)
{
    for (int row = rectangle.leftY; row <= rectangle.rightY; ++row)
        for (int column = rectangle.topX; column <= rectangle.bottomX; ++column)
            lightGrid.toggle(row, column);
}

Action* convert_line(const string& line)
{
    string coordinates;
    int type = 0;
    int length = 10;
    if (line.substr(0, 4).compare("turn") == 0)
    {
        if (line.substr(5, 2).compare("on") == 0)
        {
            length = 8;
        }
        else if (line.substr(5, 3).compare("off") == 0)
        {
            length = 9;
        }
    } else if (line.substr(0, 6).compare("toggle") == 0)
    {
        length = 7;
    }
    coordinates = line.substr(length);
    size_t position = coordinates.find(" through ");
    string topLeft = coordinates.substr(0, position);
    string bottomRight = coordinates.substr(position + 9);
    size_t topLeftComaPosition = topLeft.find(",");
    int topX, leftY;
    try
    {
        topX = stoi(topLeft.substr(0, topLeftComaPosition));
        leftY = stoi(topLeft.substr(topLeftComaPosition + 1));
    }
    catch (const invalid_argument& ia)
    {
        cerr << "Invalid argument: "  << ia.what() << endl;
        return nullptr;
    }

    size_t bottomRightComaPosition = bottomRight.find(",");
    int bottomX, rightY;
    try
    {
        bottomX = stoi(bottomRight.substr(0, bottomRightComaPosition));
        rightY = stoi(bottomRight.substr(bottomRightComaPosition + 1));
    }
    catch (const invalid_argument& ia)
    {
        cerr << "Invalid argument: "  << ia.what() << endl;
        return nullptr;
    }
    Rectangle rectangle(topX, leftY, bottomX, rightY);
    Action *action = nullptr;
    switch (length) {
        case 9: action = new TurnOff(rectangle); break;
        case 8: action = new TurnOn(rectangle); break;
        case 7: action = new Toggle(rectangle); break;
    }

    return action;
}
