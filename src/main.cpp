#include <iostream>
#include <cstdlib>
#include "Game.hpp"
#include "Drawable.hpp"
#include <string>

int main(int argc, char **argv)
{

	if (argc < 3){
		std::cout << "Invalid arguments specified: width & height required" << std::endl;
	}
	else {

		int height = std::stoi(argv[1]);
		int width = std::stoi(argv[2]);
		Game game;


		if (height % 100 != 0){
			std::cout << "Bad aspect ratio" << std::endl;
			return 0;
		}
		else if (width % 100 != 0){
			std::cout << "Bad aspect ratio" << std::endl;
			return 0;
		}

		// Use SFML by default
		game.setWindow(height, width);
		game.init(E_LIBRARY_CHOICE::NCURSES);
		game.runLoop();
	}

	return 0;
}