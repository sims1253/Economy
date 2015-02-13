/*
    This is The "Main" class that is handling all the stuff
    */

#include "World.h"


World::World(void)
{
	
	for (int i = 5; i > 0; i--)
	{
		//TODO c++14 gives you std::make_unique
		auto temp = std::unique_ptr<Village>(new Village(this));
		villages.push_back(std::move(temp));
	}
}

World::World(const int villageCount)
{

	for (int i = villageCount; i > 0; i--)
	{
		//TODO c++14 gives you std::make_unique
		auto temp = std::unique_ptr<Village>(new Village(this));
		villages.push_back(std::move(temp));
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


