#pragma once
#include "Primitive.h"
class Mutex :
    public Primitive
{
public:
    Mutex();
    void Enter() override;
    void Release() override;
    ~Mutex();

private:
    HANDLE mutex;
};

