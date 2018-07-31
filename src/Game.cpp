#include "Game.hpp"
#include <ctime>
#include <unistd.h>
#include <dlfcn.h>
#include "Drawable.hpp"
#include "LibInterface.hpp"
#include "../lib/SFML/sfmlLib.hpp"
#include "Snake.hpp"
/*
	- CANONICAL CONSTRUCTORS START
*/
Game::Game(void){
	m_curLib = E_LIBRARY_CHOICE::NONE;
	_library = NULL;
	return;
};

Game::~Game(void){
	useLibrary(E_LIBRARY_CHOICE::NONE);
	return;
};

Game & Game::operator=(const Game & _game){
	this->window_x = _game.getWindowX();
	this->window_y = _game.getWindowY();
	return *this;
};

Game::Game(const Game & _game){
	this->window_x = _game.getWindowX();
	this->window_y = _game.getWindowY();
};
/*
	- CANONICAL CONSTRUCTORS END
*/


/*
	GETTERS START
*/
int Game::getWindowX(void) const{
	return this->window_x;
};

int Game::getWindowY(void) const{
	return this->window_y;
};

/*
	GETTERS END
*/


/*
	MAIN GAME LOOP START
*/
void Game::handleEvents()
{
	E_EVENT event = _library->handleEvents();

	if (event == E_EVENT::EVENT_CLOSE_WINDOW){
		m_shouldRun = false;
		return;
	}

	for (auto i : m_drawlist)
	{
		i->handleEvent(event);
	}
	


}

int 	Game::runLoop(void) 
{
	while (m_shouldRun)
	{
		handleEvents();
		_library->clearScreen();
		for (auto i : m_drawlist)
		{
			usleep(60000);
			if (i->isUpdateable())
				i->update();
			_library->draw(i->getX(),i->getY(),i->getWidth(),i->getHeight());
		}
		_library->displayScreen();
	}

}

void Game::init(E_LIBRARY_CHOICE libChoice)
{
	m_shouldRun = true;
	useLibrary(libChoice);

	//Drawable *drawable = new Drawable();
	//drawable->init(20,20,20,20,1);
	//m_drawlist.push_back(drawable);

	Snake *snake = new Snake();
	snake->init(20,20,10,10,1,E_DIRECTION::RIGHT, this);
	m_drawlist.push_back(snake);
}


void	Game::closeGame()
{
	useLibrary(E_LIBRARY_CHOICE::NONE);
}

void	Game::addEntity(Drawable *drawable)
{
	m_drawlist.push_back(drawable);
}

void	Game::useLibrary(E_LIBRARY_CHOICE libChoice)
{
	void *handle;
	char *error;

	LibInterface *(*getLibrary)(void);

	// Do nothing if we already have the lib loaded
	if (libChoice != m_curLib)
	{
		if (_library != NULL){
			dlclose(_library);
		}


		if (libChoice == E_LIBRARY_CHOICE::SFML)
		{
			handle = dlopen("libsfmlLib.so",  RTLD_LOCAL | RTLD_LAZY);\
			if (!handle) 
			{
				std::cout << dlerror() << std::endl;
				exit(1);
			}

			*(void **)(&getLibrary) = dlsym(handle,"createLib");

			if ((error = dlerror()) != NULL) {
				std::cout << error << std::endl;
				exit(1);
			}

			_library = getLibrary();
			_library->init(300,300);
		}
		else if(libChoice == E_LIBRARY_CHOICE::NONE)
		{

		}
	}
}