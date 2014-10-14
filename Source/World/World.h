#pragma once
#include "Village.h"
#include "catalogue.h"

class World
{
private:
std::vector<Village> villages;
public:
	World(void);
	~World(void);
	void update();
};
