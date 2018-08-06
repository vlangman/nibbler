#include "sfmlLib.hpp"
#include "Drawable.hpp"
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
		delete window;
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

void sfmlLib::init(int width, int height)
{
	//getting the default bpp (bits per pixel) for the desktop
	// sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
	window = new sf::RenderWindow(sf::VideoMode(width, height, 32),"WHAT THE FUCK IS GOIN ON??");
}

sfmlLib *createLib(){
	return new sfmlLib();
}

void deleteLib(sfmlLib *lib){
	delete lib;
}

E_EVENT sfmlLib::handleEvents()
{
	sf::Event event;
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			return E_EVENT::EVENT_CLOSE_WINDOW;
		if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
				return E_EVENT::EVENT_CLOSE_WINDOW;
			else if (event.key.code == sf::Keyboard::Right)
				return E_EVENT::EVENT_KEYBOARD_RIGHT;
			else if (event.key.code == sf::Keyboard::Left)
				return E_EVENT::EVENT_KEYBOARD_LEFT;
			else if (event.key.code == sf::Keyboard::Right)
				return E_EVENT::EVENT_KEYBOARD_RIGHT;
			else if (event.key.code == sf::Keyboard::Up)
				return E_EVENT::EVENT_KEYBOARD_UP;
			else if (event.key.code == sf::Keyboard::Down)
				return E_EVENT::EVENT_KEYBOARD_DOWN;
			else if (event.key.code == sf::Keyboard::Num1)
				return E_EVENT::EVENT_KEYBOARD_1;
			else if (event.key.code == sf::Keyboard::Num2)
				return E_EVENT::EVENT_KEYBOARD_2;
			else if (event.key.code == sf::Keyboard::Num3)
				return E_EVENT::EVENT_KEYBOARD_3;
		}
	}
	return E_EVENT::EVENT_NONE;
}

void sfmlLib::draw(int x, int y, int width, int height, E_COLOR color)
{
	sf::RectangleShape rectangle(sf::Vector2f(width, height));
	rectangle.setPosition(x, y);

	switch (color)
	{
		case (E_COLOR::COLOR_YELLOW): rectangle.setFillColor(sf::Color::Yellow); break;
		case (E_COLOR::COLOR_RED): rectangle.setFillColor(sf::Color::Red); break;
	}
	window->draw(rectangle);
}

void sfmlLib::clearScreen()
{
	window->clear();
}
void sfmlLib::displayScreen()
{
	window->display();
}

void sfmlLib::cleanUp(){
	return;
}
