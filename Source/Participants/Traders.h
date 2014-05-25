#pragma once
#include <vector>
#include <iostream>
#include "../Participants/EconomyParticipants.h"
class Traders :
	public EconomyParticipants
{
protected:
	std::vector<unsigned int> stock;
	std::vector<unsigned int> storageCapacity;
	product item;
	int money;
	virtual void eat(void);
public:
	virtual int receive(const product item, int amount, const int prize);
	virtual int give(const product item, int amount, const int prize);
};