#include "Manufacture.h"



/**
\brief Constructor for a Manufacture.
\param inputProduct product that is consumed and produced.
\param inputAmount amount that is consumed.
\param inputCapacity max amount that can be consumed.
\param inputMinimum min amount that must be consumed.
\param inputProductivity amount that is produced.
\param inputProductionCapacity max amount that can be produced.
\param inputMoney starting money.
*/
//TODO use vectors for items. Also make it possible to have different products in 
//conumption and production

Manufacture::Manufacture(std::map<const product, std::pair<int, int> > production, std::map<const product, std::pair<int, int> > consumtion, const int money)
	: production(production), consumtion(consumtion)
{
	this->money = money;;
	this->alive = 1;

	// TODO initialize vectors
	storageCapacity[TOOLS] = 4;
	storageCapacity[FOOD] = 4;
	stock[TOOLS] = 1;
	stock[FOOD] = 1;
}

/*
\brief deconstructor
*/
Manufacture::~Manufacture(void)
{
}

/**
\brief Increases the productionAmount by 1 if productionCapacity is not already reached.
*/
short int Manufacture::changeProduction(product item, short int change)
{
	//TODO use find_if()
	auto itemFound = production.find(item);
	if (itemFound == production.end())
		return 0;

	if (change < 0)
	{
		if (itemFound->second.first + change >= 0)
			itemFound->second.first += change;
		else
		{
			return -1; //-1 code if production would go negative
		}
	}
	else
	{
		if (itemFound->second.first + change> itemFound->second.second)
			itemFound->second.first += change;
		else
		{
			return -2; //-2 code if production would exceede capacity
		}
	}

	return 1;
}


/**
\brief Increases the consumeAmount by 1 if consumeCapacity is not already reached.
*/
short int Manufacture::changeConsumption(product item, short int change)
{
	//TODO use find_if()
	auto itemFound = consumtion.find(item);
	if (itemFound == consumtion.end())
		return 0;

	if (change < 0)
	{
		if (itemFound->second.first + change >= itemFound->second.second)
			itemFound->second.first += change;
		else
		{
			return -1; //-1 code if consumtion would go below minimum
		}
	}
	else
	{
		itemFound->second.first += change;
	}

	return 1;
}



/**
\brief Updates the state of the Manufacture.
\param changeProduction change in productivity.
\param changeConsumption change in Consumption.

Produces items until storage is full or productionAmount is reached.
Then calls producers::upgrade if >0, producers::downgrade if <0 or does nothing.

Then consumes(destroys) items until storage is empty or consumeAmount is reached.
Then calls consumers::upgrade if >0, consumers::downgrade if <0 or does nothing.
*/
//TODO nice doc pls
//TODO Rework pls
//TODO needs something to change production and consumption 
bool Manufacture::update()
{
	if (alive)
	{
		//Produce part
		for (std::map<const product, std::pair<int, int> >::iterator iter = production.begin(); iter != production.end(); iter++){
			if ((stock[iter->first] - iter->second.first) >= 0)
			{
				stock[iter->first] -= iter->second.first;
			}
			else
			{
				stock[iter->first] = 0;
			}
		}
		//TODO what to do if full / not enough capacity
		//TODO change production

		//Consume part
		for (std::map<const product, std::pair<int, int> >::iterator iter = production.begin(); iter != production.end(); iter++){
			if ((stock[iter->first] - iter->second.first) >= 0)
			{
				stock[iter->first] -= iter->second.first;
			}
			else
			{
				stock[iter->first] = 0;
			}
		}
		//TODO what to do if empty / not enough stock
		//TODO change consumtion

		return true;
	}
	else
	{
		std::cout << "This Manufacture is dead! Buhu!" << std::endl;
		return false;
	}
}