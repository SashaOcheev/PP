#include "stdafx.h"
#include "Bank.h"

#include <memory>
#include <algorithm>

#include "BankClient.h"
#include "Mutex.h"
#include "Semaphore.h"

using namespace std;

int main()
{
	CBank* bank = new CBank();
    
    auto mutex = std::move(make_unique<Mutex>());
    auto semaphore = std::move(make_unique<Semaphore>());

    bank->SetPrimitive(semaphore.get());

	auto client1 = bank->CreateClient();
	auto client2 = bank->CreateClient();

	// TODO: WaitForMultipleObjects
	//while (true)
	//{
	//}
    while (true)
    {
        bank->Wait();
    }

    delete bank;

    return 0;
}