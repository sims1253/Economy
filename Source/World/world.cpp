#include <iostream>

/*
	This is The "Main" class that is handling all the stuff
*/

#include "world.h"


world::world(void)
{
	this->consumer = new Manufactur(0, 3, 1, 1, 5, 200, FOOD);
	this->producer = new Manufactur(2, 3, 1, 1, 5, 200, FOOD);
}

world::~world(void)
{
}

void world::update()
	{
	consumer->update(0, 0);
	consumer->dump(1);
	producer->update(0, 0);
	producer->dump(2);
	}

//BUGGY AS HELL
//TODO debug pls
void world::trade()
	{
	if (producer->tradable(FOOD) > consumer->tradable(FOOD))
		{
		producer->give(FOOD, producer->tradable(FOOD), 25);
		consumer->receive(FOOD, producer->tradable(FOOD), 25);
		}
	else
	{
		producer->give(FOOD, consumer->tradable(FOOD), 25);
		consumer->receive(FOOD, consumer->tradable(FOOD), 25);
		}
	consumer->dump(1);
	producer->dump(2);
	}
