#pragma once
#include "village.h"
#include "catalogue.h"

class world
{
private:
std::vector<village> villages;
public:
	world(void);
	~world(void);
	void update();
	};
