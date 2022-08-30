#pragma once
#include <map>

class LightGrid
{
public:
    virtual ~LightGrid();
    virtual void turnOn(int row, int column) = 0;
    virtual void turnOff(int row, int column) = 0;
    virtual void toggle(int row, int column) = 0;
};

class OnOffLightGrid : public LightGrid
{
public:
    OnOffLightGrid();
    virtual void turnOn(int row, int column);
    virtual void turnOff(int row, int column);
    virtual void toggle(int row, int column);
    int countLitLights() const;
private:
    bool lights[1000][1000];
};

class BrightnessLightGrid : public LightGrid
{
public:
    BrightnessLightGrid();
    ~BrightnessLightGrid();
    virtual void turnOn(int row, int column);
    virtual void turnOff(int row, int column);
    virtual void toggle(int row, int column);
    long long totalBrightness() const;
private:
    int **lights;
    // std::map<int, std::map<int, int> > lights;
};