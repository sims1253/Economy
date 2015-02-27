#include <iostream>
#include <cstdio>
#include "World/world.h"


int main(){
	std::cout << "Hello world\npress enter to continue ";
	std::getchar();
	int i = 10;
	world welt;

	std::getchar();
	while(i){
		std::cout << "========================================================== \n";
		welt.update();
		std::cout << "\nUpdate \n";

		
		welt.trade();
		std::cout << "\nTrade \n";



		getchar();
		i--;
		}
	return 0;
	}
