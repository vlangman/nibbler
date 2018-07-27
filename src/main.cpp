
#include <iostream>
#include "Game.hpp"


int main(int argc, char **argv)
{

	if (argc < 3){
		std::cout << "Invalid arguments specified: Height & Width required" << std::endl;
	}
	else {

		Game game;

		int Height = std::atoi(argv[1]);
		int Width = std::atoi(argv[1]);
		std::cout << Height << " :: " << Width << std::endl;

		game.runLoop();

		
	}

	return 0;
}