#pragma once
#include "Primitive.h"
class Semaphore :
    public Primitive
{
public:
    Semaphore();
    void Enter() override;
    void Release() override;
    ~Semaphore();

private:
    HANDLE semaphore;
};

