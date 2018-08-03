#include <iostream>
#include <cstdlib>
#include "Game.hpp"
#include "Drawable.hpp"
#include <string>

int main(int argc, char **argv)
{

	if (argc < 3){
		std::cout << "Invalid arguments specified: Height & Width required" << std::endl;
	}
	else {
		Game game;

		// Use SFML by default
		game.setWindow(std::stoi(argv[1]), std::stoi(argv[2]));
		game.init(E_LIBRARY_CHOICE::NCURSES);
		game.runLoop();
		game.closeGame();
	}

	return 0;
}