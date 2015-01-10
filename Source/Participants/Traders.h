#pragma once
#include<map>
#include "../Participants/EconomyParticipants.h"
class Traders :
	public EconomyParticipants
{
protected:
	// first: item, second: stock
	std::map<const product, int> stock;
	//first: item, second storageCapacity
	std::map<const product, int> storageCapacity;
	int money;

public:

};