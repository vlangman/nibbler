#include <iostream>
#include <cstdlib>
#include "Game.hpp"
#include "Drawable.hpp"


int main(int argc, char **argv)
{

	if (argc < 3){
		std::cout << "Invalid arguments specified: Height & Width required" << std::endl;
	}
	else {
		Game game;

		int Height = atoi(argv[1]);
		int Width = atoi(argv[1]);
		std::cout << Height << " :: " << Width << std::endl;

		// Use SFML by default
		game.init(E_LIBRARY_CHOICE::SFML);
		game.runLoop();
		game.closeGame();

		
	}

	return 0;
}