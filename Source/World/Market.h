#pragma once
#include "../Participants/Traders.h"
#include "../Participants/Manufacture.h"
#include "catalogue.h"

class Village;

class Market
{
private:
	const Village *homeTown;

public:
	Market(const Village *homeTown);
	~Market(void);
	bool update();
	void start(std::vector<std::shared_ptr<Manufacture>> manufacturers);
	};
