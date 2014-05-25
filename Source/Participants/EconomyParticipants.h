#pragma once

#include "../World/catalogue.h"


class EconomyParticipants
{
private:

protected:
	bool alive;

public:
	virtual bool update(char changeProductivity, char changeConsumption) = 0;
};
