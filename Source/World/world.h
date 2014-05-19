#pragma once
#include "../Participants/consumers.h"
#include "../Participants/producers.h"
#include "catalogue.h"

class world
{
private:
	producers *producer;
	consumers *consumer;
public:
	world(void);
	~world(void);
	void update();
	void trade();
	void dump();

	};
