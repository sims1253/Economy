#pragma once
#include "Producers.h"
#include "Consumers.h"

class Manufactur:
	public Producers, public Consumers
{
public:
	Manufactur();
	~Manufactur();
};

