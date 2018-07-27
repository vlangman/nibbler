#pragma once
#include <iostream>
#include "LibInterface.hpp"

/*
	- Game class in charge of methods for the main game loop 
*/

class LibInterface;

enum E_LIBRARY_CHOICE
{
	SFML, 
	SDL,
	NCURSES
};

class Game {

private:
	int window_x;
	int window_y;

	LibInterface *_library;
	E_LIBRARY_CHOICE curLib;
public:
	
	Game(void);
	~Game(void);
	Game & operator=(const Game & _Game);
	Game(const Game & _Game);

	Game(const int _X, const int _Y);

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
	void	useLibrary(E_LIBRARY_CHOICE libChoice);
	void	closeGame();

};