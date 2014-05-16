#pragma once

#include "../World/catalogue.h"

#include <vector>
#include <iostream>


class consumers 
{
// TODO pricate machen. Nur für den dump public
public:
	product item;
	int consumeAmount;
	int consumeMinimum;
	int consumeCapacity;
	int money;
	std::vector<unsigned int> stock;
	std::vector<unsigned int> storage;
	void eat();
	bool alive;

public:
	consumers(const product inputProduct, const int inputAmount, const int inputCapacity, const int inputMinimum, const int inputMoney);
	~consumers(void);
	void update (char change);
	void upgrade (void);
	void downgrade (void);
	int receive (const product item, const int amount, const int prize);
	int give (const product item, const int amount, const int prize);




};
