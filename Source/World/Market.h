#pragma once
#include "../Participants/Traders.h"
#include "../Participants/Manufacture.h"
#include "catalogue.h"

class Village;

class Market
{
private:
	std::weak_ptr<Village> homeTown;

public:
	Market(std::shared_ptr<Village> homeTown);
	~Market(void);
	bool update();
	void start(std::vector<std::shared_ptr<Manufacture>> manufacturers);
	};
