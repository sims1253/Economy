#include "Village.h"

Village::Village(const World *world, const int myID) : villageMarket(this), ID(myID), homeWorld(world)
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