#include <iostream>

/*
	This is The "Main" class that is handling all the stuff
*/

#include "world.h"


world::world(void)
{
	this->consumer = new Consumers(FOOD, 1, 3, 1, 100);
	this->producer = new Producers(FOOD, 2, 3, 100);
}


world::~world(void)
{
}

void world::update()
	{
	consumer->update(0);
	producer->update(0);
	}

void world::dump()
	{
	
	char *productNames[] =
	{
	"WATER",
	"FOOD",
	"TOOLS"
	};
	std::cout << "-------------------------------------------- \n";
	std::cout << "Consumer 1:" << std::endl;
	std::cout << "Consumes " << consumer->consumeAmount << " of " << productNames[consumer->item] << ". Has " << consumer->money << " moneys." << std::endl;
	std::cout << "Storage: \n" << productNames[FOOD] << ": " << consumer->stock[FOOD] << "/" << consumer->storageCapacity[FOOD] << std::endl << std::endl;

	std::cout << "Producer 1:" << std::endl;
	std::cout << "Produces " << producer->productionAmount << " of " << productNames[producer->item] << ". Has " << producer->money << " moneys." << std::endl;
	std::cout << "Storage: \n" << productNames[FOOD] << ": " << producer->stock[FOOD] << "/" << producer->storageCapacity[FOOD] << std::endl;
	}

void world::trade()
	{
	if (producer->stock[FOOD] > (consumer->storageCapacity[FOOD] - consumer->stock[FOOD]))
		{
		int tmp = (consumer->storageCapacity[FOOD] - consumer->stock[FOOD]);
		producer->give(FOOD, tmp, 25);
		consumer->receive(FOOD, tmp, 5);
		}
	else
		{
		int tmp = producer->stock[FOOD];
		producer->give(FOOD, tmp, 25);
		consumer->receive(FOOD, tmp, 5);
		}
	}
