#include "Event.h"



Event::Event()
{
    event = CreateEvent(NULL, false, true, NULL);
}

void Event::Enter()
{
    WaitForSingleObject(event, INFINITE);
}

void Event::Release()
{
    SetEvent(event);
}


Event::~Event()
{
    CloseHandle(event);
}
