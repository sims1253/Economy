#include "consumers.h"


/**
	\brief Constructor for a consumer.
	\param inputProduct product that is consumed.
	\param inputAmount amount that is consumed.
	\param inputCapacity max amount that can be consumed.
	\param inputMinimum min amount that must be consumed.
	\parm inputMoney starting money.
*/
consumers::consumers(const product inputProduct, const int inputAmount, const int inputCapacity, const int inputMinimum, const int inputMoney)
	{
	this->item					= inputProduct;
	this->consumeAmount			= inputAmount;
	this->consumeMinimum		= inputMinimum;
	this->consumeCapacity		= inputCapacity;
	this->money					= inputMoney;

	//TODO Vectoren Initialisieren
	this->storage.push_back(4);
	this->stock.push_back(0);
	}

/*
	\brief deconstructor
*/
consumers::~consumers(void)
	{
	}

/**
	\brief Updates the state of the consumer.
	\param change change in consuming.

	Consumes(destroys) items until storage is empty or consumeAmount is reached. 
	Then calls consumers::upgrade if >0, consumers::downgrade if <0 or does nothing.
*/
void consumers::update (char change)
	{
	if(stock[item]>0)
	stock[item]-=consumeAmount;
	if(change>0)
		upgrade();
	if(change<0)
		downgrade();
	return;
	}

/**
	\brief Increases the consumeAmount by 1 if consumeCapacity is not already reached.
*/
void consumers::upgrade (void)
	{
	if(consumeAmount<consumeCapacity)
		consumeAmount++;
	}

/**
	\brief Reduces the consumeAmount by 1 if consumeMinimum is not already reached.
*/
void consumers::downgrade (void)
	{
	if(consumeAmount>consumeMinimum)
		consumeAmount++;
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
int consumers::receive (const product item, const int amount, const int prize)
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
int consumers::give (const product item, const int amount, const int prize)
	{
		for(int i = 0; i < amount; i++)
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