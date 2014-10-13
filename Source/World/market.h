#pragma once
#include "../Participants/traders.h"
#include "Village.h"
#include "catalogue.h"

class Market
{
private:
	Village *homeTown;
public:
	Market(void);
	~Market(void);
	void update();
	};
