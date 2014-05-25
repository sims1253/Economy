#include "Manufactur.h"


/**
\brief Constructor for a Manufactur.
\param inputProduct product that is consumed and produced.
\param inputAmount amount that is consumed.
\param inputCapacity max amount that can be consumed.
\param inputMinimum min amount that must be consumed.
\param inputProductivity amount that is produced.
\param inputProductionCapacity max amount that can be produced.
\param inputMoney starting money.
*/
//TODO use vectors for items. Also make it possible to have different products in conumption and production
Manufactur::Manufactur(const int productionAmount, const int productionCapacity, const int consumeAmount, const int consumeMinimum, const int consumeCapacit, const int money, const product item)
	{
		this->item = item;
		this->consumeAmount = consumeAmount;
		this->consumeMinimum = consumeMinimum;
		this->consumeCapacity = consumeCapacit;
		this->money = money;;
		this->productionAmount = productionAmount;
		this->productionCapacity = productionCapacity;
		this->alive = 1;

		// TODO initialize vectors
		this->storageCapacity.push_back(4);
		this->storageCapacity.push_back(4);
		this->stock.push_back(1);
		this->stock.push_back(1);
	}

/*
\brief deconstructor
*/
Manufactur::~Manufactur(void)
{
}

/**
\brief Increases the productionAmount by 1 if productionCapacity is not already reached.
*/
void Manufactur::increaseProduction(const char change)
{
	if (productionAmount<productionCapacity)
		productionAmount++;
	return;
}

/**
\brief Reduces the productionAmount by 1. Can't be lower than 0.
*/
void Manufactur::decreaseProduction(const char change)
{
	if (productionAmount>0)
		productionAmount--;
	return;

}

/**
\brief Increases the consumeAmount by 1 if consumeCapacity is not already reached.
*/
void Manufactur::increaseConsumption(const char change)
{
	if (consumeAmount<consumeCapacity)
		consumeAmount++;
}

/**
\brief Reduces the consumeAmount by 1 if consumeMinimum is not already reached.
*/
void Manufactur::decreaseConsumption(const char change)
{
	if (consumeAmount>consumeMinimum)
		consumeAmount++;
}

/**
\brief Updates the state of the Manufactur.
\param changeProduction change in productivity.
\param changeConsumption change in Consumption.

Produces items until storage is full or productionAmount is reached.
Then calls producers::upgrade if >0, producers::downgrade if <0 or does nothing.

Then consumes(destroys) items until storage is empty or consumeAmount is reached.
Then calls consumers::upgrade if >0, consumers::downgrade if <0 or does nothing.
*/
//TODO nice doc pls
bool Manufactur::update(char changeProduction, char changeConsumption)
{
	eat();
	if (alive){
		//Produce part
		if (stock[item] < storageCapacity[item])
			stock[item] += productionAmount;
		if (changeProduction > 0)
			increaseProduction(1);
		else if (changeProduction < 0)
			decreaseProduction(1);

		//Consume part
		if (stock[item]>0)
			stock[item] -= consumeAmount;
		if (changeConsumption > 0)
			increaseConsumption(1);
		if (changeConsumption < 0)
			decreaseConsumption(1);
		return true;
	}
	else
	{
		std::cout << "This Manufactur is dead!\n";
		return false;
	}
}

//just a debug dump of data
	void Manufactur::dump(int id)
	{

		char *productNames[] =
		{
			"WATER",
			"FOOD",
			"TOOLS"
		};
		std::cout << "-------------------------------------------- \n";
		std::cout << "Manufactur: "<< id << std::endl;
		std::cout << "Produces " << this->productionAmount << " of " << productNames[this->item] << ". Has " << this->money << " moneys." << std::endl;
		std::cout << "Consumes " << this->consumeAmount << " of " << productNames[this->item] << ". Has " << this->money << " moneys." << std::endl;
		std::cout << "Storage: \n" << productNames[FOOD] << ": " << this->stock[FOOD] << "/" << this->storageCapacity[FOOD] << std::endl << std::endl;
	}

	//returns how much there is to trade
	//TODO doc pls
	int Manufactur::tradable(product item)
	{
		return stock[item];
	}