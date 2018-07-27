#pragma once
#include "graphicsInterface.hpp"
#include "../lib/include/SFML/Graphics.hpp"


class sfmlLib : public graphicsInterface{
	private:
		int 		window_x;
		int 		window_y;
		bool		verbose;

	public:
	/*
		default constructors and deconstructors for canonical form
	*/
		sfmlLib(void);
		~sfmlLib(void);
		sfmlLib(const sfmlLib & _sfml);
		sfmlLib & operator=(const sfmlLib & _sfml);

	/*
		custom constructors for Height an Width
	*/

		sfmlLib(const int _W, const int _H);

	/* 
		VIRTUAL INHERITED ABSTRACT FUCNTIONS
	*/
		void drawGame(void);

	/* 
		GETTER AND SETTERS
	*/
		int getWindowX(void) const;
		int getWindowY(void) const;

};

extern "C" void drawGame(void){
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
};