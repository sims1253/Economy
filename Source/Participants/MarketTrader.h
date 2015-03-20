#pragma once
#include "Traders.h"


class MarketTrader :
	public Traders
{
protected:

public:
	MarketTrader();
	~MarketTrader();
	bool update();
};