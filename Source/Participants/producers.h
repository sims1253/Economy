#pragma once

#include <vector>
#include <iostream>

#include "../World/catalogue.h"
#include "Traders.h"


class Producers:
	public Traders
{
// TODO private 
public:

	product item;
	int productionAmount;
	int productionCapacity;
	int money;
	void eat();
	bool alive;

public:
	Producers(const product inputProduct, const int inputAmount, const int inputCapacity, const int inputMoney);
	~Producers(void);
	void update (char change);
	void upgrade (void);
	void downgrade (void);
	int receive (const product item, const int amount, const int prize);
	int give (const product item, int amount, const int prize);
};
