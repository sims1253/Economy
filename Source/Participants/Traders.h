#pragma once
#include<map>
#include "../Participants/EconomyParticipants.h"
class Traders :
	public EconomyParticipants
{
protected:
	// first: item, second: stock
	std::map<product, int> stock;
	//first: item, second storageCapacity
	std::map<product, int> storageCapacity;
	int money;

public:

};