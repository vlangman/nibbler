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

sfmlLib *createLib(){
	return new sfmlLib();
}

void deleteLib(sfmlLib *lib){
	delete lib;
}

void sfmlLib::drawGame(void){
	std::cout << "DRAW DA SNEK HERE" << std::endl;

	//getting the default bpp (bits per pixel) for the desktop
		// sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
		sf::RenderWindow window(
			sf::VideoMode(500, 500, 32),
			"WHAT THE FUCK IS GOIN ON??"
		);

		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Yellow);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(shape);
			window.display();
		}
}
