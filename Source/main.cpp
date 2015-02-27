#include <iostream>
#include <cstdio>
#include "World/World.h"


int main(){
	std::cout << "Hello World\npress enter to continue ";
	std::getchar();

	World *welt = new World();
	welt->debug();
	std::getchar();
	World *welt2 = new World(10, 5, 50);
	welt2-> debug();
	std::getchar();
	return 0;
	}
