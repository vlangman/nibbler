
#include <iostream>
#include "snake.hpp"


int main(int argc, char **argv)
{

	if (argc < 3){
		std::cout << "Invalid arguments specified: Height & Width required" << std::endl;
	}
	else {

		Snake snake;

		int Height = std::atoi(argv[1]);
		int Width = std::atoi(argv[1]);
		std::cout << Height << " :: " << Width << std::endl;

		snake.runLoop();

		
	}

	return 0;
}