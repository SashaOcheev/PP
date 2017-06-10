#include "Semaphore.h"



Semaphore::Semaphore()
{
    semaphore = CreateSemaphore(NULL, 1, 1, NULL);
}

void Semaphore::Enter()
{
    
    WaitForSingleObject(semaphore, INFINITE);
}

void Semaphore::Release()
{
    ReleaseSemaphore(semaphore, 1, NULL);
}


Semaphore::~Semaphore()
{
    CloseHandle(semaphore);
}
