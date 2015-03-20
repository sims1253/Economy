#pragma once
#include "Village.h"
#include "ressources.h"
#include <time.h>
#include "IDGenerator.h"
#include "WorldDataTypes.h"



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
	World(const int, const int, const int);
	~World(void);
	void worldInitialization();
	void update(void);
	void debug();
	IDGenerator worldIDGenerator;
	worldData getMyTileData(std::pair<int, int>);
};
