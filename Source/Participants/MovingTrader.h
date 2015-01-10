#pragma once
#include "Traders.h"


class MovingTrader :
	public Traders
{
protected:
	

public:
	MovingTrader(const int productionAmount, const int productionCapacity, const int consumeAmount, const int consumeMinimum, const int consumeCapacity, const int money, const product item);
	~MovingTrader();
	bool update();

	int tradable(product item);
};