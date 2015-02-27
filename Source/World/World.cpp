/*
    This is The "Main" class that is handling all the stuff
    */

#include "World.h"



World::World(void)
{
	worldInitialization(villageCount, ressourceAmmount);
}

World::World(const int _worldSize, const int _villageCount, const int _ressourceAmmount)
	: villageCount(_villageCount), ressourceAmmount(_ressourceAmmount), worldSize(_worldSize)
{
	worldInitialization(villageCount, ressourceAmmount);
}

World::~World(void)
{

}

void World::worldInitialization(const int _villageCount, const int _ressourceAmmount)
{
	/*
	std::vector<std::vector<std::unique_ptr<worldData>>> 
		temp(worldSize, std::vector<std::unique_ptr<worldData>>(worldSize));
	worldMap = std::move(temp);
	*/

	for (int i = villageCount; i > 0; i--)
	{
		//TODO c++14 gives you std::make_unique
		auto temp = std::unique_ptr<Village>(new Village(this));
		villages.push_back(std::move(temp));
	}

	srand((unsigned int)time(NULL));
	for (int i = 0; i < worldSize; i++)
	{
		std::vector<worldData> worlVector;
		for (int j = 0; j < worldSize; j++)
		{
			worldData tempWorldData = { 0, 0 };
			if ((rand() % 100) < ressourceAmmount)
			{	
				tempWorldData.type = rand() % NUMBER_OF_RESSOURCES;
				tempWorldData.size = (rand() % 100)+1 ;
			}
			worlVector.push_back(tempWorldData);
		}
		worldMap.push_back(worlVector);
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
	std::vector<int> typeAmount(NUMBER_OF_RESSOURCES);

	using namespace std;
	cout << "-----------------------------------------------------------------------------------" << endl;
	for (int j = 0; j < worldSize; j++)
	{
		cout << "\t";
		for (int i = 0; i < worldSize; i++)
		{
			typeAmount[worldMap[i][j].type]+=1;
			cout << worldMap[i][j].type << "," << worldMap[i][j].size << "\t";
		}
		cout << endl;		
	}
	cout << "\t";
	for( std::vector<int>::const_iterator k = typeAmount.begin(); k != typeAmount.end(); ++k)
    		cout << *k << ' ';


	return;
}

