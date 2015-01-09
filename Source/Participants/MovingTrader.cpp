#include "MovingTrader.h"


/**
\brief Constructor for a MovingTrader.
\param inputProduct product that is consumed and produced.
\param inputAmount amount that is consumed.
\param inputCapacity max amount that can be consumed.
\param inputMinimum min amount that must be consumed.
\param inputProductivity amount that is produced.
\param inputProductionCapacity max amount that can be produced.
\param inputMoney starting money.
*/
//TODO use vectors for items. Also make it possible to have different products in conumption and production
MovingTrader::MovingTrader(const int productionAmount, const int productionCapacity, const int consumeAmount, 
	const int consumeMinimum, const int consumeCapacit, const int money, const product item)
{

	this->money = money;;

	this->alive = 1;

	// TODO initialize vectors
	storageCapacity[WATER] = 4;
	storageCapacity[FOOD] = 4;
	stock[WATER] = 1;
	stock[FOOD] = 1;
}

/*
\brief deconstructor
*/
MovingTrader::~MovingTrader(void)
{
}


/**
\brief Updates the state of the MovingTrader.
\param changeProduction change in productivity.
\param changeConsumption change in Consumption.

Produces items until storage is full or productionAmount is reached.
Then calls producers::upgrade if >0, producers::downgrade if <0 or does nothing.

Then consumes(destroys) items until storage is empty or consumeAmount is reached.
Then calls consumers::upgrade if >0, consumers::downgrade if <0 or does nothing.
*/
//TODO nice doc pls
bool MovingTrader::update(char changeProduction, char changeConsumption)
{
	return false;
	//TODO everything

}



//returns how much there is to trade
//TODO doc pls
int MovingTrader::tradable(product item)
{
	return stock[item];
}