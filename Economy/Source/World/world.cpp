#include <iostream>

/*
	This is The "Main" class that is handling all the stuff
*/

#include "world.h"


world::world(void)
{
	this->consumer = new consumers(NAHRUNG, 1, 3, 1, 100);
	this->producer = new producers(NAHRUNG, 2, 3, 100);
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
	std::cout << "Storage: \n" << productNames[NAHRUNG] << ": " << consumer->stock[NAHRUNG] << "/" << consumer->storage[NAHRUNG] << std::endl << std::endl;

	std::cout << "Producer 1:" << std::endl;
	std::cout << "Produces " << producer->productionAmount << " of " << productNames[producer->item] << ". Has " << producer->money << " moneys." << std::endl;
	std::cout << "Storage: \n" << productNames[NAHRUNG] << ": " << producer->stock[NAHRUNG] << "/" << producer->storage[NAHRUNG] << std::endl;
	}

void world::trade()
	{
	if(producer->stock[NAHRUNG] > (consumer->storage[NAHRUNG]-consumer->stock[NAHRUNG]))
		{
		int tmp = (consumer->storage[NAHRUNG]-consumer->stock[NAHRUNG]);
		producer->give(NAHRUNG, tmp, 25);
		consumer->receive(NAHRUNG, tmp, 5);
		}
	else
		{
		int tmp = producer->stock[NAHRUNG];
		producer->give(NAHRUNG, tmp, 25);
		consumer->receive(NAHRUNG, tmp, 5);
		}
	}
