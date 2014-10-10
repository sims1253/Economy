#pragma once
#include "../Participants/Manufactur.h"
#include "../Participants/MovingTrader.h"
#include "world.h"
#include "catalogue.h"

class village
{
private:
	std::vector<Manufactur> manufacturers;
	std::vector<MovingTrader> traders;
	world *homeWorld;
public:
	village(void);
	~village(void);
	void update();
	};
