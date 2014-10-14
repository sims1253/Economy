#pragma once
#include "Traders.h"


class MovingTrader :
	public Traders
{
protected:
	int consumeAmount;
	void MovingTrader::decreaseConsumption(const char change);
	void MovingTrader::increaseConsumption(const char change);
	void MovingTrader::decreaseProduction(const char change);
	void MovingTrader::increaseProduction(const char change);
	int productionAmount;
	int productionCapacity;
	int consumeAmount;
	int consumeMinimum;
	int consumeCapacity;
public:
	MovingTrader(const int productionAmount, const int productionCapacity, const int consumeAmount, const int consumeMinimum, const int consumeCapacity, const int money, const product item);
	~MovingTrader();
	bool update(char changeProduction, char changeConsumption);
	void dump(int id);
	int tradable(product item);
};