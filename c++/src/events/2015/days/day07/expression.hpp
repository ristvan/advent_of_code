#pragma once

class Memory;

class Expression
{
public:
    virtual ~Expression() {}
    virtual unsigned short getValue(Memory& memory) const = 0;
};
