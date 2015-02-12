#include "Market.h"

Market::Market(std::shared_ptr<Village> village)
{
	this->homeTown = village;
}

Market::~Market(void)
{

}

bool Market::update(void)
{
	return 1;
}

void Market::start(std::vector<std::shared_ptr<Manufacture>> manufacturers)
{
	for (size_t i = 0; i > manufacturers.size(); i++)
	{
		//TODO manufacturers[i]-> get all the stuff
	}
}

