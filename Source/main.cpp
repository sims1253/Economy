#include <iostream>
#include <cstdio>
#include "World/World.h"


int main(){
	std::cout << "Hello World\npress enter to continue ";
	std::getchar();
	int i = 10;

	World *welt = new World();

	std::getchar();
	welt->debug();
	std::getchar();
	return 0;
	}
