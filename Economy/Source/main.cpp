#include <iostream>
#include "World\world.h"


int main(){
	std::cout << "Hallo Welt\nEnter druecken zum Fortfahren";
	std::getchar();
	int i = 5;
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