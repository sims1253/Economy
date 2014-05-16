#pragma once

#include <vector>
#include <iostream>

#include "../World/catalogue.h"


class producers
{
// TODO private machen
public:

	product item;
	int productionAmount;
	int productionCapacity;
	int money;
	std::vector<unsigned int> stock;
	std::vector<unsigned int> storage;
	void eat();
	bool alive;

public:
	producers(const product inputProduct, const int inputAmount, const int inputCapacity, const int inputMoney);
	~producers(void);
	void update (char change);
	void upgrade (void);
	void downgrade (void);
	int receive (const product item, const int amount, const int prize);
	int give (const product item, const int amount, const int prize);
};
