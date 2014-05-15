#include "producers.h"

/**
	\brief Constructor for a producer.
	\param inputProduct product that is produced.
	\param inputProductivity amount that is produced.
	\param inputProductionCapacity max amount that can be produced.
	\param inputMoney starting money.

*/
//TODO Ressource use for production
producers::producers(const product inputProduct, const int inputProductivity, const int inputProductionCapacity, const int inputMoney)
	{
	this->item					= inputProduct;
	this->productionAmount		= inputProductivity;
	this->productionCapacity	= inputProductionCapacity;
	this->money					= inputMoney;
	
	//TODO Vectoren Initialisieren
	this->storage.push_back(4);
	this->stock.push_back(0);
	}

/*
	\brief deconstructor
*/
producers::~producers(void)
	{
	}

/**
	\brief Updates the state of the producer.
	\param change change in productivity.

	Produces items until storage is full or productionAmount is reached. 
	Then calls producers::upgrade if >0, producers::downgrade if <0 or does nothing.
*/
void producers::update(char change)
	{
	if(stock[item]<storage[item])
		stock[item]+=productionAmount;
	if(change>0)
		upgrade();
	if(change<0)
		downgrade();
	return;

	}

/**
	\brief Increases the productionAmount by 1 if productionCapacity is not already reached.
*/
void producers::upgrade(void)
	{
	if(productionAmount<productionCapacity)
		productionAmount++;
	return;
	}

/**
	\brief Reduces the productionAmount by 1. Can't be lower than 0.
*/
void producers::downgrade(void)
	{
	if(productionAmount>0)
		productionAmount--;
	return;

	}

/**
	\brief Recieves items from a trader for money
	\param item the item, the trader offers.
	\param amount the amount, the trader offers.
	\param prize the prize per unit.
	\return The amount, that was actually taken.

	Increases the stored amount of given item until eighter the stock is full or the given amount is reached.
	Returns how much was given.
*/
int producers::receive (const product item, const int amount, const int prize)
	{
	for(int i = 0; i < amount; i++)
		{
		if((stock[item]<storage[item]) && ((money-prize)>=0))
			{
			stock[item]++;
			money-=prize;
			}
		}
	//TODO Return funktioniert nicht wie gewollt
	return amount;

	}
/**
	\brief Gives items to a trader for money
	\param item the item, the trader gets.
	\param amount the amount, the trader wants.
	\param prize the prize per unit.
	\return The amount, that was actually given.

	Reduces the stored amount of given item until eighter there is nothing left in stock or the given amount is reached.
	Returns how much was given.
*/
int producers::give (const product item, const int amount, const int prize)
	{
	for(int i = 0 ; i < amount; i++)
		{
		if(stock[item]>0)
			{
			stock[item]--;
			money+=prize;
			}
		}
	//TODO Return funktioniert nicht wie gewollt
	return amount;
	}