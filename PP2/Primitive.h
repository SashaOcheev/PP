#pragma once
#include <Windows.h>

class Primitive
{
public:
    virtual void Enter() = 0;
    virtual void Release() = 0;
    virtual ~Primitive() = default;
};

