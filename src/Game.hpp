#pragma once
#include <iostream>
#include <vector>

/*
	- Game class in charge of methods for the main game loop 
*/

class Drawable;

class LibInterface;

enum E_LIBRARY_CHOICE
{
	SFML, 
	SDL,
	NCURSES,
	NONE
};

enum E_EVENT 
{
	EVENT_NONE,
	EVENT_CLOSE_WINDOW,
	EVENT_KEYBOARD_RIGHT,
	EVENT_KEYBOARD_LEFT,
	EVENT_KEYBOARD_UP,
	EVENT_KEYBAORD_DOWN
};


class Game {

private:
	int window_x;
	int window_y;

	std::vector<Drawable*> m_drawlist; 

	LibInterface *_library;
	E_LIBRARY_CHOICE m_curLib;

	void	useLibrary(E_LIBRARY_CHOICE libChoice);
	void	handleEvents();

	bool 	m_shouldRun;
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
	void 	init(E_LIBRARY_CHOICE libChoice);
	void	closeGame();

	void	addEntity(Drawable *drawable);
};