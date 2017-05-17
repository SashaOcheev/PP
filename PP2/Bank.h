#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Primitive.h"

#include "BankClient.h"

class CBank
{
public:
	CBank();
	std::shared_ptr<CBankClient> CreateClient();
	void UpdateClientBalance(CBankClient& client, int value);
    void SetPrimitive(Primitive *primitive);

private:
	std::vector<std::shared_ptr<CBankClient>> m_clients;
	int m_totalBalance;
    Primitive *m_primitive;

	int GetTotalBalance();
	void SetTotalBalance(int value);
	void SomeLongOperations(); 
};