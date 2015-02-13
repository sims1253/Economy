#pragma once
#include "../Participants/Manufacture.h"
#include "../Participants/MovingTrader.h"
#include "Market.h"
#include <memory>

class World;

class Village
{
private:
	std::vector<std::shared_ptr<Manufacture>> manufacturers;
	std::vector<std::shared_ptr<MovingTrader>> traders;
	Market villageMarket;
	const World *homeWorld;
	// TODO Offers and needs
	// TODO Inhabitants
	// TODO Place for buildings
	// TODO Ressources available
public:
	Village(const World *homeWorld);
	~Village(void);
	void update();
	};
