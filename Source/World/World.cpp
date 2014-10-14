#include <iostream>

/*
	This is The "Main" class that is handling all the stuff
*/

#include "World.h"


World::World(void)
{
	this->consumer = new Manufactur(0, 3, 1, 1, 5, 200, FOOD);
	this->producer = new Manufactur(2, 3, 1, 1, 5, 200, FOOD);
}

World::~World(void)
{
}

void World::update()
	{
	consumer->update(0, 0);
	consumer->dump(1);
	producer->update(0, 0);
	producer->dump(2);
	}

