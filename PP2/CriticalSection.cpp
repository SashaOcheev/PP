#include "CriticalSection.h"



CriticalSection::CriticalSection()
{
    InitializeCriticalSection(&criticalSection);
}

void CriticalSection::Enter()
{
    EnterCriticalSection(&criticalSection);
}

void CriticalSection::Release()
{
    LeaveCriticalSection(&criticalSection);
}


CriticalSection::~CriticalSection()
{
    DeleteCriticalSection(&criticalSection);
}
