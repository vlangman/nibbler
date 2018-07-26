#pragma once
#include <iostream>
#include "graphicsInterface.hpp"

/*
	- SNAKE class in charge of methods for the main game loop 
*/

class graphicsInterface;

class Snake {

private:
	int window_x;
	int window_y;
	graphicsInterface *_library;


public:
	
	Snake(void);
	~Snake(void);
	Snake & operator=(const Snake & _snake);
	Snake(const Snake & _snake);

	Snake(const int _X, const int _Y);

	/*
		GETTERS 
	*/

	int getWindowX(void) const;
	int getWindowY(void) const;
	int getVerbose(void) const;

	/*
		MAIN GAME LOOP
	*/

	int 	runLoop(void);
	void	setLibrary(void);

};