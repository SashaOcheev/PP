#include "Mutex.h"

Mutex::Mutex()
{
}

void Mutex::Enter()
{
    mutex = CreateMutex(NULL, false, NULL);
}

void Mutex::Release()
{
    WaitForSingleObject(mutex, INFINITE);
}


Mutex::~Mutex()
{
}
