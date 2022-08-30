#pragma once

#include <string>

class LightGrid;

struct Rectangle
{
    Rectangle();
    Rectangle(int topX, int leftY, int bottomX, int rightY);
    int topX;
    int leftY;
    int bottomX;
    int rightY;

    friend bool operator==(const Rectangle& l, const Rectangle& r);
};

class Action
{
public:
    Action(Rectangle rectangle, int type): rectangle(rectangle), type(type) {}
    virtual ~Action() = 0;
    virtual void apply(LightGrid &lightGrid) = 0;
    friend bool operator==(const Action& l, const Action& r);
    friend bool operator!=(const Action& l, const Action& r);

protected:
    int type;
    Rectangle rectangle;
};

class TurnOn : public Action
{
public:
    TurnOn(Rectangle rectangle) : Action(rectangle, 1) {}
    virtual ~TurnOn();
    virtual void apply(LightGrid &lightGrid);
};

class TurnOff : public Action
{
public:
    TurnOff(Rectangle rectangle) : Action(rectangle, 2) {}
    virtual ~TurnOff();
    virtual void apply(LightGrid &lightGrid);
};

class Toggle : public Action
{
public:
    Toggle(Rectangle rectangle) : Action(rectangle, 3) {}
    virtual ~Toggle();
    virtual void apply(LightGrid &lightGrid);
};

Action* convert_line(const std::string& line);
