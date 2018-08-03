#pragma once
#include <iostream>
#include <vector>

/*
	- Game class in charge of methods for the main game loop 
*/

class Drawable;
class GameEntity;

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
	EVENT_KEYBAORD_DOWN,
	EVENT_KEYBOARD_1,
	EVENT_KEYBOARD_2,
	EVENT_KEYBOARD_3
};

enum E_COLOR 
{
	COLOR_YELLOW,
	COLOR_RED
};




class Game {

private:
	int window_x;
	int window_y;

	LibInterface *_library;
	E_LIBRARY_CHOICE m_curLib;
	void *_libHandle;

	void	useLibrary(E_LIBRARY_CHOICE libChoice);
	void	handleEvents();

	bool 	m_shouldRun;
public:
	std::vector<GameEntity*> m_entityList;
	
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

	void setWindow(int x, int y);

	/*
		MAIN GAME LOOP
	*/

	int 	runLoop(void);
	void 	init(E_LIBRARY_CHOICE libChoice);
	void	closeGame();

	void	addEntity(GameEntity *entity);

	void	cleanup();
};