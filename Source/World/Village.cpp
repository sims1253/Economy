#include "Village.h"

Village::Village(const World *world, const int myID, const std::pair<int, int> coords, worldData tile)
	: villageMarket(this), ID(myID), homeWorld(world), coordinates(coords), myTile(tile)
{
	
	villageMarket.start(manufacturers);
}

Village::~Village(void)
{

}

void Village::update()
{
	villageMarket.update();
}

int Village::getID()
{
	return ID;
}

std::pair<int, int> Village::getCoordinates()
{
	return coordinates;
}