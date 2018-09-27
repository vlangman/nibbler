#include "Game.hpp"
#include <ctime>
#include <unistd.h>
#include <dlfcn.h>
#include "Drawable.hpp"
#include "LibInterface.hpp"
#include "../lib/SFML/sfmlLib.hpp"
#include "SnakeHead.hpp"
#include "Food.hpp"
/*
	- CANONICAL CONSTRUCTORS START
*/
Game::Game(void){
	m_curLib = E_LIBRARY_CHOICE::NONE;
	_library = NULL;
	return;
};

Game::~Game(void){
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
		std::cout << "CLOSING GAME" << std::endl;
		closeGame();
		return;
	}
	else if (event == E_EVENT::EVENT_KEYBOARD_1){
		useLibrary(E_LIBRARY_CHOICE::SFML);
	}
	else if (event == E_EVENT::EVENT_KEYBOARD_2){
		useLibrary(E_LIBRARY_CHOICE::SDL);
	}
	else if (event == E_EVENT::EVENT_KEYBOARD_3){
		useLibrary(E_LIBRARY_CHOICE::NCURSES);
	}
	for (auto i : m_entityList)
	{
		i->handleEvent(event);
	}
	
}

int 	Game::runLoop(void) 
{
	_library->clearScreen();

	usleep(60000);

	for (auto i : m_entityList)
	{
		i->update();
		_library->draw(i->getX(),i->getY(),i->getWidth(),i->getHeight(), i->getColor());
	}
	_library->displayScreen();
		cleanup();
	sleep(3);

	while (m_shouldRun)
	{
		handleEvents();
		_library->clearScreen();

		usleep(60000);

		for (auto i : m_entityList)
		{
			i->update();
			_library->draw(i->getX(),i->getY(),i->getWidth(),i->getHeight(), i->getColor());
		}
		_library->displayScreen();
		cleanup();
	}
	return 0;
}

void Game::cleanup()
{
	for (std::vector<GameEntity*>::iterator it=m_entityList.begin(); 
								it!=m_entityList.end(); 
								/*it++*/) 
	{

	if(!((*it)->isAlive())) 
	{
		delete ((*it));
		it = m_entityList.erase(it);
	}
	else 
		++it;
	}

	
}

void Game::setWindow(int x, int y)
{
	window_x = x;
	window_y = y;
}

void Game::init(E_LIBRARY_CHOICE libChoice)
{
	m_shouldRun = true;
	useLibrary(libChoice);


	SnakeHead *snake = new SnakeHead();
	snake->init( window_x/2, window_y/2, 10, 10, E_COLOR::COLOR_YELLOW, E_DIRECTION::RIGHT, this);
	addEntity(snake);

	Food *food = new Food();
	food->init(window_x/2+10,window_y/2, 10,10, E_COLOR::COLOR_RED, this);
	addEntity(food);
}

void	Game::closeGame()
{
	m_shouldRun = false;
	this->_library->cleanUp();
	useLibrary(E_LIBRARY_CHOICE::NONE);
}

void	Game::addEntity(GameEntity *entity)
{
	m_entityList.push_back(entity);
}

void	Game::useLibrary(E_LIBRARY_CHOICE libChoice)
{
	char *error;
	std::string libString;
	LibInterface *(*getLibrary)(void);
	void (*deleteLibrary)(LibInterface*);

	// Do nothing if we already have the lib loaded
	if (libChoice != m_curLib)
	{
		if (_library != NULL) {
			deleteLibrary = (void(*)(LibInterface*)) dlsym(_libHandle ,"deleteLib");
			dlclose(_libHandle);
			std::cout << "DELETING" << std::endl;
			deleteLibrary(_library);
		}

		if (libChoice == E_LIBRARY_CHOICE::SDL)
			libString = "libsdlLib.dylib";
		else if (libChoice == E_LIBRARY_CHOICE::SFML)
			libString = "libsfmlLib.dylib";
		else if (libChoice == E_LIBRARY_CHOICE::NCURSES)
			libString = "libncursesLib.dylib";
		else if (libChoice == E_LIBRARY_CHOICE::NONE)
			return;


		// if (libChoice == E_LIBRARY_CHOICE::SDL)
		// 	libString = "libsdlLib.so";
		// else if (libChoice == E_LIBRARY_CHOICE::SFML)
		// 	libString = "libsfmlLib.so";
		// else if (libChoice == E_LIBRARY_CHOICE::NCURSES)
		// 	libString = "libncursesLib.so";
		// else if (libChoice == E_LIBRARY_CHOICE::NONE)
		// 	return;
		
		_libHandle = dlopen(libString.c_str(), RTLD_LOCAL | RTLD_LAZY);
		if (!_libHandle){
			std::cout << "Could not dlopen: " << libString.c_str() << std::endl;
			std::cout << dlerror() << std::endl;
			exit(1);
		}

		*(void **)(&getLibrary) = dlsym(_libHandle ,"createLib");

		if ((error = dlerror()) != NULL) {
			std::cout << error << std::endl;
			exit(1);
		}

		m_curLib = libChoice;
		_library = getLibrary();
		_library->init(window_x,window_y);
	}
}