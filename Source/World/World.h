#pragma once
#include "Village.h"
#include "ressources.h"
#include <time.h>

using namespace std;
class World
{
private:
vector<unique_ptr<Village>> villages;
vector<pair<pair<int, int>, pair<int, int>>> ressources;
public:
	World(void);
	World(const int villageCount, const int ressourceAmmount);
	~World(void);
	void worldInitialization(const int villageCount, const int ressourceAmmount);
	void update(void);
	int worldSize;
};
