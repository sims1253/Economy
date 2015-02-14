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
	this->consumeAmount 		= inputAmount;
	this->consumeMinimum		= inputMinimum;
	this->consumeCapacity		= inputCapacity;
	this->money 				= inputMoney;
	this->alive 				= 1;

	// TODO initialize vectors
	this->storage.push_back(4);
	this->storage.push_back(4);
	this->stock.push_back(1);
	this->stock.push_back(1);
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
// TODO: eat und consume can be the same if item is food
void consumers::update (char change)
	{
	eat();
	if(alive)
		{
		if(stock[item]>0)
			stock[item]-=consumeAmount;
		if(change>0)
			upgrade();
		if(change<0)
			downgrade();
		return;
		}
	else
		std::cout << "XXXXXXXXXX  This consumer is dead!  XXXXXXXXXXXXXXXXXX\n";
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
\return The amount, that was actually taken. Or -1 if dead.

Increases the stored amount of given item until eighter the stock is full or the given amount is reached.
Returns how much was given.
*/
int consumers::receive (const product item, int amount, const int prize)
	{
	if(alive)
		{
		int tmp = 0;
		while(amount && (stock[item]<storage[item]) && ((money-prize)>=0))
			{
			stock[item]++;
			money-=prize;
			amount--;
			}
		return tmp;
		}
	else
		{
		std::cout << "This producer is dead and can not receive items!\n";
		return -1;
		}
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
int consumers::give (const product item, int amount, const int prize)
	{
	if(alive)
		{
		int tmp = 0;
		while((stock[item]>1) && (amount > 0))
			{
			stock[item]--;
			amount--;
			tmp++;
			}
		return tmp;
		}
	else
		{
		std::cout << "This producer is dead and can not give items!\n";
		return -1;
		}
	}

/*
\brief Consumers eat 1 food per turn. If there is no food they die.
*/
void consumers::eat()
	{
	if(stock[FOOD])
		stock[FOOD]--;
	else
		alive = 0;
	}
