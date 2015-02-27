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
	virtual int give(const product item, int amount, const int prize);
	virtual int receive(const product item, int amount, const int prize);
public:
	virtual int buy(Traders seller, const product item, const int price, const int amount);
	virtual int sell(Traders buyer, const product item, const int price, const int amount);
	virtual bool update(char changeProductivity, char changeConsumption);
	virtual int tradable(product item);
};