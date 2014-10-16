#pragma once
#include "Traders.h"


class Manufacture:
	public Traders
{
protected:
	int productionAmount;
	int productionCapacity;
	int consumeAmount;
	int consumeMinimum;
	int consumeCapacity;
	void increaseProduction(unsigned short int change);
	void decreaseProduction(unsigned short int change);
	void increaseConsumption(unsigned short int change);
	void decreaseConsumption(unsigned short int change);

public:
	Manufacture(const int productionAmount, const int productionCapacity, const int consumeAmount, const int consumeMinimum, const int consumeCapacity, const int money, const product item);
	~Manufacture();
	bool update(char changeProduction, char changeConsumption);
	void dump(int id);
	
};