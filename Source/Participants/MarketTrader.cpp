#include "MarketTrader.h"


/**
\brief Constructor for a MarketTrader.
\param inputProduct product that is consumed and produced.
\param inputAmount amount that is consumed.
\param inputCapacity max amount that can be consumed.
\param inputMinimum min amount that must be consumed.
\param inputProductivity amount that is produced.
\param inputProductionCapacity max amount that can be produced.
\param inputMoney starting money.
*/
//TODO use vectors for items. Also make it possible to have different products in conumption and production
MarketTrader::MarketTrader()
{

}

/*
\brief deconstructor
*/
MarketTrader::~MarketTrader(void)
{
}


/**
\brief Updates the state of the MarketTrader.
\param changeProduction change in productivity.
\param changeConsumption change in Consumption.

Produces items until storage is full or productionAmount is reached.
Then calls producers::upgrade if >0, producers::downgrade if <0 or does nothing.

Then consumes(destroys) items until storage is empty or consumeAmount is reached.
Then calls consumers::upgrade if >0, consumers::downgrade if <0 or does nothing.
*/
//TODO nice doc pls
bool MarketTrader::update()
{
	return false;
}