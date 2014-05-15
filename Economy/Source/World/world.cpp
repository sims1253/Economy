#include <iostream>

/*
	This is The "Main" class that is handling all the stuff
*/

#include "world.h"


world::world(void)
{
	this->consumer = new consumers(WASSER, 1, 3, 1, 100);
	this->producer = new producers(WASSER, 2, 3, 100);
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
	"Wasser",
	"Nahrung",
	"WERKZEUG"
	};
	std::cout << "-------------------------------------------- \n";
	std::cout << "Consumer 1:" << std::endl;
	std::cout << "Consumes " << consumer->consumeAmount << " of " << productNames[consumer->item] << ". Has " << consumer->money << " moneys." << std::endl;
	std::cout << "Storage: \n" << productNames[0] << ": " << consumer->stock[0] << "/" << consumer->storage[0] << std::endl << std::endl;

	std::cout << "Producer 1:" << std::endl;
	std::cout << "Produces " << producer->productionAmount << " of " << productNames[producer->item] << ". Has " << producer->money << " moneys." << std::endl;
	std::cout << "Storage: \n" << productNames[0] << ": " << producer->stock[0] << "/" << producer->storage[0] << std::endl;
	}

void world::trade()
	{
	if(producer->stock[0] > (consumer->storage[0]-consumer->stock[0]))
		{
		int tmp = (consumer->storage[0]-consumer->stock[0]);
		producer->give(WASSER, tmp, 5);
		consumer->receive(WASSER, tmp, 5);
		}
	else
		{
		int tmp = producer->stock[0];
		producer->give(WASSER, tmp, 5);
		consumer->receive(WASSER, tmp, 5);
		}
	}
