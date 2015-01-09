#pragma once
#include "Village.h"

class World
{
private:
std::vector<std::shared_ptr<Village>> villages;
public:
	World(void);
	World(const int villageCount);
	~World(void);
	void update(void);
};
