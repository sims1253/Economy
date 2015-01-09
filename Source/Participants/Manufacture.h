#pragma once
#include "Traders.h"
#include <algorithm>
#include <memory>
#include <iostream>


class Manufacture:
	public Traders
{
protected:
	//Find entries via product enum, first: productionAmount second: productionCapacity
	std::map<product, std::pair<int, int>> production;
	//first: item, second.first: amount, second.second: minimum
	//Find entries via product enum, first: consumtionAmount second : consumtionMinimum
	std::map<product, std::pair<int, int>> consumtion;	

public:
	Manufacture(std::map<product, std::pair<int, int>> production, std::map<product, std::pair<int, int>> consumtion, const int money);
	~Manufacture();
	bool update();
	short int changeProduction(product item, short int change);
	short int changeConsumption(product item, short int change);
	
};