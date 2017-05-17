#pragma once
#include <Windows.h>
#include <memory>

enum class PrimitiveType
{
    CRITICAL_SECTION, MUTEX, SEMAPHORE, EVENT
};

class Primitive
{
public:
    static std::unique_ptr<Primitive> CreatePrimitive(PrimitiveType type);
    virtual void Enter() = 0;
    virtual void Release() = 0;
    virtual ~Primitive() = default;
};

