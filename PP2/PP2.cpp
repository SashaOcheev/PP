#include "stdafx.h"
#include "Bank.h"

#include <memory>
#include <algorithm>
#include <string>
#include <stdexcept>

#include "BankClient.h"
#include "Primitive.h"

using namespace std;

unique_ptr<Primitive> GetPrimitive(string type)
{
    if (type == "mutex")
        return Primitive::CreatePrimitive(PrimitiveType::MUTEX);
    if (type == "critical_section")
        return Primitive::CreatePrimitive(PrimitiveType::CRITICAL_SECTION);
    if (type == "semaphore")
        return Primitive::CreatePrimitive(PrimitiveType::SEMAPHORE);
    if (type == "event")
        return Primitive::CreatePrimitive(PrimitiveType::EVENT);
    
    throw domain_error("enter mutex, critical_section, semaphore or event");
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    if (!strcmp(argv[1], "?"))
    {
        std::cout << "enter mutex, critical_section, semaphore or event" << std::endl;
    }
    
    auto primitive = GetPrimitive(argv[1]);

	CBank* bank = new CBank();
    
    bank->SetPrimitive(primitive.get());

	auto client1 = bank->CreateClient();
	auto client2 = bank->CreateClient();

    while (true)
    {
        bank->Wait();
    }

    delete bank;

    return 0;
}