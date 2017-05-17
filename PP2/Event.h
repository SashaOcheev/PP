#pragma once
#include "Primitive.h"
class Event :
    public Primitive
{
public:
    Event();
    void Enter() override;
    void Release() override;
    ~Event();

private:
    HANDLE event;
};


