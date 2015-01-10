#pragma once
#include <vector>
#include "../World/catalogue.h"


class EconomyParticipants
{
private:

protected:
	bool alive;

public:
	virtual bool update() = 0;
};
