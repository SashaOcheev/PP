#include "CriticalSection.h"



CriticalSection::CriticalSection()
{  
}

void CriticalSection::Enter()
{
    InitializeCriticalSection(&criticalSection);
}

void CriticalSection::Release()
{
    LeaveCriticalSection(&criticalSection);
}


CriticalSection::~CriticalSection()
{
    DeleteCriticalSection(&criticalSection);
}
