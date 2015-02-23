/*
    This is The "Main" class that is handling all the stuff
    */

#include "World.h"


World::World(void)
{
	int villageCount = 5;
	int ressourceAmmount = 10;
	
	worldInitialization(villageCount, ressourceAmmount);
}

World::World(const int villageCount, const int ressourceAmmount)
{
	worldInitialization(villageCount, ressourceAmmount);
}

World::~World(void)
{

}

void World::worldInitialization(const int villageCount, const int ressourceAmmount)
{
	for (int i = villageCount; i > 0; i--)
	{
		//TODO c++14 gives you std::make_unique
		auto temp = std::unique_ptr<Village>(new Village(this));
		villages.push_back(std::move(temp));
	}

	srand((unsigned int)time(NULL));
	for (int i = ressourceAmmount; i > 0; i--)
	{
		auto type = rand() % NUMBER_OF_RESSOURCES;
		auto size = rand() % 101;
		auto x_pos = rand() % worldSize;
		auto y_pos = rand() % worldSize;
		auto finalPair = new pair<pair<int, int>, pair<int, int>>(type, size, x_pos, y_pos);
		ressources.push_back(finalPair);

	}

	return;
}

void World::update()
{
	for (size_t i = 0; i < villages.size(); i++)
	{
		villages[i]->update();
	}
}


