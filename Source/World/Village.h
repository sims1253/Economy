#pragma once
#include "../Participants/Manufactur.h"
#include "../Participants/MovingTrader.h"
#include "World.h"
#include "catalogue.h"

class Village
{
private:
	std::vector<Manufactur> manufacturers;
	std::vector<MovingTrader> traders;
	world *homeWorld;
public:
	Village(void);
	~Village(void);
	void update();
	};
