#pragma once
#include "../Participants/traders.h"
#include "village.h"
#include "catalogue.h"

class market
{
private:
	village *homeTown;
public:
	market(void);
	~market(void);
	void update();
	};
