#pragma once
#include "Village.h"
#include "ressources.h"
#include <time.h>

struct worldData
{
	int type;
	int size;
};

class World
{

private:
	const int villageCount= 5;
	const int ressourceAmmount = 10;
	const int worldSize = 10;
	std::vector<std::unique_ptr<Village>> villages;
	std::vector<std::vector<worldData>> worldMap;
public:
	World(void);
	World(const int worldSize, const int villageCount, const int ressourceAmmount);
	~World(void);
	void worldInitialization(const int villageCount, const int ressourceAmmount);
	void update(void);
	void debug();
};
