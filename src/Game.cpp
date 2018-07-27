#include "Game.hpp"
#include <ctime>
#include <unistd.h>
#include <dlfcn.h>

/*
	- CANONICAL CONSTRUCTORS START
*/
	Game::Game(void){
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
	int 	Game::runLoop(void){

		void *handle;
		char *error;

		LibInterface *(*getSfml)(void);
		
		handle = dlopen("libsfmlLib.dylib",  RTLD_LOCAL | RTLD_LAZY);

		if (!handle) 
		{
			std::cout << dlerror() << std::endl;
			exit(1);
		}
		// *(void **) (&cosine)
		
		*(void **)(&getSfml) = dlsym(handle,"createSfmlLib");
		
		if ((error = dlerror()) != NULL) {
			std::cout << error << std::endl;
			exit(1);
		}
		std::cout << "calling getSfml" << std::endl;
		LibInterface *sfml =  getSfml();
		sfml->drawGame();
		dlclose(handle);
		return 0;
	}
/*
	MAIN GAME LOOP END
*/

void	Game::closeGame()
{

}

void	Game::useLibrary(void)
{
	
}