#include "Event.h"



Event::Event()
{
}

void Event::Enter()
{
    event = CreateEvent(NULL, false, true, NULL);
}

void Event::Release()
{
    WaitForSingleObject(event, INFINITE);
}


Event::~Event()
{
}
