#include "Village.h"

Village::Village(const World *world) : villageMarket(this)
{
	this->homeWorld = world;
	villageMarket.start(manufacturers);
}

Village::~Village(void)


{

}

void Village::update()
{
	villageMarket.update();
}

