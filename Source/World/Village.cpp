#include "Village.h"

Village::Village(std::shared_ptr<World> world)
{
	this->homeWorld = world;
	villageMarket->start(manufacturers);
}

Village::~Village(void)
{

}

void Village::update()
{
	villageMarket->update();
}

