#pragma once
#include <vector>
#include <iostream>
#include <string>
#include "../World/catalogue.h"


class EconomyParticipants
{
private:

protected:
	bool alive;

public:
	virtual bool update(char changeProductivity, char changeConsumption) = 0;
};
