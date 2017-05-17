#include "Primitive.h"
#include "Mutex.h"
#include "CriticalSection.h"
#include "Semaphore.h"
#include "Event.h"

std::unique_ptr<Primitive> Primitive::CreatePrimitive(PrimitiveType type)
{
    switch (type)
    {
    case PrimitiveType::CRITICAL_SECTION:
        return std::make_unique<CriticalSection>();
    case PrimitiveType::MUTEX:
        return std::make_unique<Mutex>();
    case PrimitiveType::SEMAPHORE:
        return std::make_unique<Semaphore>();
    case PrimitiveType::EVENT:
        return std::make_unique<Event>();
    }
}
