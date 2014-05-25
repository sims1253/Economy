#pragma once
#include "../Participants/Consumers.h"
#include "../Participants/Producers.h"
#include "catalogue.h"

class world
{
private:
	Producers *producer;
	Consumers *consumer;
public:
	world(void);
	~world(void);
	void update();
	void trade();
	void dump();

	};
