#pragma once
#include "Primitive.h"
class CriticalSection :
    public Primitive
{
public:
    CriticalSection();
    void Enter() override;
    void Release() override;
    ~CriticalSection();

private:
    CRITICAL_SECTION criticalSection;
};

