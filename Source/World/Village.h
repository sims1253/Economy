#pragma once
#include "../Participants/Manufacture.h"
#include "../Participants/MovingTrader.h"
#include "catalogue.h"
class World;

class Village
{
private:
	std::vector<Manufacture> manufacturers;
	std::vector<MovingTrader> traders;
	World *homeWorld;
public:
	Village(void);
	~Village(void);
	void update();
	};
