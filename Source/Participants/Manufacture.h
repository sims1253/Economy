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
	void increaseProduction(char change);
	void decreaseProduction(char change);
	void increaseConsumption(char change);
	void decreaseConsumption(char change);

public:
	Manufacture(const int productionAmount, const int productionCapacity, const int consumeAmount, const int consumeMinimum, const int consumeCapacity, const int money, const product item);
	~Manufacture();
	bool update(char changeProduction, char changeConsumption);
	void dump(int id);
	
};