/*
    This is The "Main" class that is handling all the stuff
    */

#include "World.h"


World::World(void)
{
	
	for (int i = 5; i > 0; i--)
	{
		auto temp = std::make_shared<Village>(std::make_shared<World>(this));
		villages.push_back(temp);
	}
}

World::World(const int villageCount)
{

	for (int i = villageCount; i > 0; i--)
	{
		auto temp = std::make_shared<Village>(std::make_shared<World>(this));
		villages.push_back(temp);
	}
}

World::~World(void)
{

}

void World::update()
{
	for (size_t i = 0; i < villages.size(); i++)
	{
		villages[i]->update();
	}
}


