#include "BankClient.h"
#include "Bank.h"


CBankClient::CBankClient(CBank *bank, unsigned id)
	: m_bank(bank)
	, m_id(id)
{
	handle = CreateThread(NULL, 0, ThreadFunction, this, 0, NULL);
}


unsigned CBankClient::GetId()
{
	return m_id;
}


DWORD WINAPI CBankClient::ThreadFunction(LPVOID lpParam)
{
	CBankClient *client = (CBankClient*)lpParam;
	srand(client->m_id);

	client->m_bank->UpdateClientBalance(*client, GetBalanceChangeValue());
	
    return 0;
}


unsigned CBankClient::GetSleepDuration(CBankClient *client)
{
	// 1000 .. 3999
	return (1000 + rand() % 3000) * (client->m_id + 1);
}


int CBankClient::GetBalanceChangeValue()
{
	// -100 .. 100
	return rand() % 201 - 100;
}