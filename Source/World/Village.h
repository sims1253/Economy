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
	std::shared_ptr<Market> villageMarket = std::make_shared<Market>(std::make_shared<Village>(this));
	std::weak_ptr<World> homeWorld;
	// TODO Offers and needs
	// TODO Inhabitants
	// TODO Place for buildings
	// TODO Ressources available
public:
	Village(std::shared_ptr<World> world);
	~Village(void);
	void update();
	};
