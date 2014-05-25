#pragma once
#include <vector>
#include "../Participants/EconomyParticipants.h"
class Traders :
	public EconomyParticipants
{
public:
	std::vector<unsigned int> stock;
	std::vector<unsigned int> storageCapacity;


};

