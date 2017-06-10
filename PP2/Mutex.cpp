#include "Mutex.h"

Mutex::Mutex()
{
    mutex = CreateMutex(NULL, false, NULL);
}

void Mutex::Enter()
{
    WaitForSingleObject(mutex, INFINITE);
}

void Mutex::Release()
{
    ReleaseMutex(mutex);
}


Mutex::~Mutex()
{
    CloseHandle(mutex);
}
