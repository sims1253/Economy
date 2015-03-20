#pragma once
#include "../Participants/Manufacture.h"
#include "../Participants/MovingTrader.h"
#include "Market.h"
#include <memory>
#include "WorldDataTypes.h"

class World;

class Village
{
private:
	std::vector<std::shared_ptr<Manufacture>> manufacturers;
	std::vector<std::shared_ptr<MovingTrader>> traders;
	Market villageMarket;
	const World *homeWorld;
	const std::pair<int, int> coordinates;
	const int ID;
	worldData myTile;
	// TODO Offers, demands and needs
	// TODO Inhabitants
	// TODO Place for buildings
	// TODO Ressources available
public:
	Village(const World *homeWorld, const int ID, const std::pair<int, int> coords,
		worldData tile);
	~Village(void);
	void update();
	int getID(void);
	std::pair<int, int> getCoordinates(void);
	};
