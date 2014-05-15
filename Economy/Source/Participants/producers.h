#pragma once

#include <vector>

#include "../World/catalogue.h"


class producers
{
private:
	product item;
	int productionAmount;
	int productionCapacity;
	int money;
	std::vector<int> stock;
	std::vector<int> storage;

public:
	producers(const product inputProduct, const int inputAmount, const int inputCapacity, const int inputMoney);
	~producers(void);
	void update (char change);
	void upgrade (void);
	void downgrade (void);
	int receive (const product item, const int amount, const int prize);
	int give (const product item, const int amount, const int prize);
};
