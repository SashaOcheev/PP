#include "Semaphore.h"



Semaphore::Semaphore()
{
}

void Semaphore::Enter()
{
    semaphore = CreateSemaphore(NULL, 1, 1, NULL);
}

void Semaphore::Release()
{
    WaitForSingleObject(semaphore, INFINITE);
}


Semaphore::~Semaphore()
{
}
