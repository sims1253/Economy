#pragma once
#include "economy_participants.h"
class producers :
	public economy_participants
{
public:
	producers(const std::string inputProduct, const int inputAmount, const int inputCapacity);
	~producers(void);
};

