#include <iostream>
#include <cstdio>
#include "World/World.h"


int main(){
	std::cout << "Hello World\npress enter to continue ";
	std::getchar();
	int i = 10;
	World welt;

	std::getchar();
	while(i){
		std::cout << "========================================================== \n";
		welt.update();
		std::cout << "\nUpdate \n";



		getchar();
		i--;
		}
	return 0;
	}
