#pragma once
#include "Village.h"
#include "ressources.h"
#include <time.h>
#include "IDGenerator.h"

struct worldData
{
	int type;
	int size;
	int villageID;
};

class World
{

private:
	const int villageCount= 5;
	const int ressourceAmmount = 10;
	const int worldSize = 10;
	//std::vector<std::unique_ptr<Village>> villages;
	std::map<const int, std::unique_ptr<Village>> villages;	
	std::vector<std::vector<worldData>> worldMap;
public:
	World(void);
	World(const int worldSize, const int villageCount, const int ressourceAmmount);
	~World(void);
	void worldInitialization();
	void update(void);
	void debug();
	IDGenerator worldIDGenerator;
};
