#include "Traders.h"

/**
\brief Recieves items from a trader for money
\param item the item, the trader offers.
\param amount the amount, the trader offers.
\param prize the prize per unit.
\return The amount, that was actually taken. Or -1 if dead.

Increases the stored amount of given item until eighter the stock is full or the given amount is reached.
Returns how much was given.
*/
int Traders::receive(const product item, int amount, const int prize)
{
	if (alive)
	{
		int tmp = 0;
		while (amount && (stock[item]<storageCapacity[item]) && ((money - prize) >= 0))
		{
			stock[item]++;
			money -= prize;
			amount--;
		}
		return tmp;
	}
	else
	{
		std::cout << "This Trader is dead and can not receive items!\n";
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
// TODO change FOOD to live important ressource and limit of giving to what is needed for x updates
int Traders::give(const product item, int amount, const int prize)
{
	if (alive)
	{
		int tmp = 0;
		if (item == FOOD)
		{
			while ((stock[item] > 1) && (amount > 0))
			{
				stock[item]--;
				amount--;
				tmp++;
			}
		}
		else
		{
			while (stock[item] && (amount > 0))
			{
				stock[item]--;
				amount--;
				tmp++;
			}
		}
		return tmp;
	}
	else
	{
		std::cout << "This Trader is dead and can not give items!\n";
		return -1;
	}
}

/*
\brief Consumers eat 1 food per turn. If there is no food they die.
*/
void Traders::eat()
{
	if (stock[FOOD])
		stock[FOOD]--;
	else
		alive = 0;
}