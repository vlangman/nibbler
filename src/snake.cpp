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

		void *handle = dlopen("libsfmlLib.dylib",  RTLD_LOCAL | RTLD_LAZY);

		graphicsInterface *(*drawGame)();
		drawGame = (graphicsInterface *(*)(void))dlsym(handle, "drawGame");
		
		// float delta_time = 0.0;
		// float current_frame = 0.0;
		// float last_frame = time(0);


		while (1)
		{
			usleep(600);
			std::cout << "right here tjom" << std::endl;
			drawGame();
		}
		return 0;
		
	}
/*
	MAIN GAME LOOP END
*/