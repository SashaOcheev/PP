#include "stdafx.h"
#include "Bank.h"
#include "BankClient.h"

int main()
{
	CBank* bank = new CBank();
	auto client1 = bank->CreateClient();
	auto client2 = bank->CreateClient();

	// TODO: WaitForMultipleObjects
	while (true)
	{
	}

    delete bank;

    return 0;
}