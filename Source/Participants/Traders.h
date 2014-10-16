#pragma once
#include <vector>
#include <iostream>
#include "../Participants/EconomyParticipants.h"
class Traders :
	public EconomyParticipants
{
protected:
	std::vector<unsigned int> stock;
	std::vector<unsigned int> storageCapacity;
	product item;
	int money;

public:

};