#include "sfmlLib.hpp"
/*
	default constructors and deconstructors for canonical form
*/
	 sfmlLib::sfmlLib(){
		if (this->verbose){
			std::cout << "sfmlLib VOID CONSTRUCTOR called." << std::endl;
		}
		return;
	}

	 sfmlLib::~sfmlLib(){
		if (this->verbose){
			std::cout << "sfmlLib VOID DECONSTRUCTOR called." << std::endl;
		}
		return;
	}

	sfmlLib::sfmlLib(const sfmlLib & _sfml){
		this->window_x = _sfml.getWindowX();
		this->window_y = _sfml.getWindowY();
		return;
	}

	sfmlLib & sfmlLib::operator=(const sfmlLib & _sfml){
		this->window_x = _sfml.getWindowX();
		this->window_y = _sfml.getWindowY();
		return *this;
	}

/*
	custom constructors for Height an Width
*/

	sfmlLib::sfmlLib( int _W, int _H){
		this->window_x = _W;
		this->window_y = _H;
	};

/* 
	VIRTUAL INHERITED FUCNTIONS
*/

	void sfmlLib::drawGame(const Snake & _snake){
		std::cout << _snake.getWindowX() << std::endl;
		std::cout << "DRAW DA SNEK HERE" << std::endl;
	};


/*
	GETTERS START
*/
	int sfmlLib::getWindowX(void) const{
		return this->window_x;
	};

	int sfmlLib::getWindowY(void) const{
		return this->window_y;
	};


/*
	GETTERS END
*/