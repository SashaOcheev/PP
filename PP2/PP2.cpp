#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"
#include "Mutex.h"
#include <memory>
#include <algorithm>

using namespace std;

int main()
{
	CBank* bank = new CBank();
    
    auto mutex = std::move(make_unique<Mutex>());
    
    bank->SetPrimitive(mutex.get());

	auto client1 = bank->CreateClient();
	auto client2 = bank->CreateClient();

	// TODO: WaitForMultipleObjects
	while (true)
	{
	}

    delete bank;

    return 0;
}