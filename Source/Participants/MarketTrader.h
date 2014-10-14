#pragma once
#include "Traders.h"


class MarketTrader :
	public Traders
{
protected:
	void decreaseConsumption(const char change);
	void increaseConsumption(const char change);
	void decreaseProduction(const char change);
	void increaseProduction(const char change);
	int productionAmount;
	int productionCapacity;
	int consumeAmount;
	int consumeMinimum;
	int consumeCapacity;
public:
	MarketTrader(const int productionAmount, const int productionCapacity, const int consumeAmount, const int consumeMinimum, const int consumeCapacity, const int money, const product item);
	~MarketTrader();
	bool update(char changeProduction, char changeConsumption);
	void dump(int id);
	int tradable(product item);
};