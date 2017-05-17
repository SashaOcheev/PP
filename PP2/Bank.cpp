#include "Bank.h"

CBank::CBank()
{
	m_clients = std::vector<std::shared_ptr<CBankClient>>();
	m_totalBalance = 0;
}


std::shared_ptr<CBankClient> CBank::CreateClient()
{
	unsigned clientId = unsigned(m_clients.size());
    std::shared_ptr<CBankClient> client(new CBankClient(this, clientId));
	m_clients.push_back(client);
    m_threads.push_back(client->handle);
	return client;
}


void CBank::UpdateClientBalance(CBankClient &client, int value)
{
    m_primitive->Enter();
	int totalBalance = GetTotalBalance();
	std::cout << "Client " << client.GetId() << " initiates reading total balance. Total = " << totalBalance << "." << std::endl;
	
	SomeLongOperations();
	totalBalance += value;

	std::cout
		<< "Client " << client.GetId() << " updates his balance with " << value
		<< " and initiates setting total balance to " << totalBalance
		<< ". Must be: " << GetTotalBalance() + value << "." << std::endl;

	// Check correctness of transaction through actual total balance
	if (totalBalance != GetTotalBalance() + value) {
		std::cout << "! ERROR !" << std::endl;
	}

	SetTotalBalance(totalBalance);
    m_primitive->Release();
}

void CBank::SetPrimitive(Primitive * primitive)
{
    m_primitive = primitive;
}

void CBank::Wait()
{
    WaitForMultipleObjects(m_threads.size(), m_threads.data(), TRUE, INFINITE);
}


int CBank::GetTotalBalance()
{
	return m_totalBalance;
}


void CBank::SetTotalBalance(int value)
{
	m_totalBalance = value;
}

void CBank::SomeLongOperations()
{
    Sleep(2000);
}