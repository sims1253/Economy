#pragma once

#include "../World/catalogue.h"

#include <vector>


class consumers 
{
private:
	product item;
	int consumeAmount;
	int consumeMinimum;
	int consumeCapacity;
	int money;
	std::vector<int> stock;
	std::vector<int> storage;

public:
	consumers(const product inputProduct, const int inputAmount, const int inputCapacity, const int inputMinimum, const int inputMoney);
	~consumers(void);
	void update (char change);
	void upgrade (void);
	void downgrade (void);
	int receive (const product item, const int amount, const int prize);
	int give (const product item, const int amount, const int prize);
};
