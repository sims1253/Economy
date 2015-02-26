/*
    This is The "Main" class that is handling all the stuff
    */

#include "World.h"



World::World(void)
{
	worldInitialization(villageCount, ressourceAmmount);
}

World::World(const int _villageCount, const int _ressourceAmmount, const int _worldSize)
	: villageCount(_villageCount), ressourceAmmount(_ressourceAmmount), worldSize(_worldSize)
{
	worldInitialization(villageCount, ressourceAmmount);
}

World::~World(void)
{

}

void World::worldInitialization(const int _villageCount, const int _ressourceAmmount)
{
	std::vector<std::vector<std::unique_ptr<worldData>>> 
		temp(worldSize, std::vector<std::unique_ptr<worldData>>(worldSize));
	worldMap = temp;

	for (int i = villageCount; i > 0; i--)
	{
		//TODO c++14 gives you std::make_unique
		auto temp = std::unique_ptr<Village>(new Village(this));
		villages.push_back(std::move(temp));
	}

	srand((unsigned int)time(NULL));
	for (int i = 0; i < worldSize; i++)
	{
		for (int j = 0; j < worldSize; j++)
		{
			
			if ((rand() % 100) < ressourceAmmount)
			{
				worldMap[i][j]->type = rand() % NUMBER_OF_RESSOURCES;
				worldMap[i][j]->size = (rand() % 100)+1 ;
			}
		}

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

void World::debug()
{


	using namespace std;
	cout << "------------------------------------------------------------------------------" << endl;
	for (int j = 0; j < worldSize; j++)
	{
		cout << "\t";
		for (int i = 0; i < worldSize; i++)
		{
			cout << worldMap[i][j]->type << "\t";
		}
		cout << endl;
	}


	return;
}

