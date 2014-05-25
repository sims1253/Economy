#pragma once
#include "../Participants/Manufactur.h"
#include "catalogue.h"

class world
{
private:
	Manufactur *producer;
	Manufactur *consumer;
public:
	world(void);
	~world(void);
	void update();
	void trade();
	};
