#include "snake.hpp"
#include <ctime>
#include <unistd.h>
#include <dlfcn.h>

/*
	- CANONICAL CONSTRUCTORS START
*/
	Snake::Snake(void){
		return;
	};

	Snake::~Snake(void){
		return;
	};

	Snake & Snake::operator=(const Snake & _snake){
		this->window_x = _snake.getWindowX();
		this->window_y = _snake.getWindowY();
		return *this;
	};

	Snake::Snake(const Snake & _snake){
		this->window_x = _snake.getWindowX();
		this->window_y = _snake.getWindowY();
	};
/*
	- CANONICAL CONSTRUCTORS END
*/


/*
	GETTERS START
*/
	int Snake::getWindowX(void) const{
		return this->window_x;
	};

	int Snake::getWindowY(void) const{
		return this->window_y;
	};

/*
	GETTERS END
*/


/*
	MAIN GAME LOOP START
*/
	int 	Snake::runLoop(void){

		void *handle;
		void (*drawGame)(void);
		char *error;
		
		handle = dlopen("libsfmlLib.dylib",  RTLD_LOCAL | RTLD_LAZY);

		if (!handle) 
		{
			std::cout << dlerror() << std::endl;
			exit(1);
		}
		// *(void **) (&cosine)
		
		*(void **)(&drawGame) = dlsym(handle,"drawGame");
		
		if ((error = dlerror()) != NULL) {
			std::cout << error << std::endl;
			exit(1);
		}
		std::cout << "calling drawGame" << std::endl;
		drawGame();
		dlclose(handle);
		return 0;
	}
/*
	MAIN GAME LOOP END
*/