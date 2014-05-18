#include <iostream>
#include <cstdio>
#include "World/world.h"


int main(){
	std::cout << "Hello world\npress enter to continue ";
	std::getchar();
	int i = 10;
	world welt;
	welt.dump();

	std::getchar();
	while(i){
		std::cout << "========================================================== \n";
		welt.update();
		std::cout << "\nUpdate \n";
		welt.dump();
		
		welt.trade();
		std::cout << "\nTrade \n";
		welt.dump();


		getchar();
		i--;
		}
	return 0;
	}
