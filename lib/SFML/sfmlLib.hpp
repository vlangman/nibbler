#pragma once
#include "LibInterface.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class sfmlLib : public LibInterface{
	private:
		int 		window_x;
		int 		window_y;
		bool		verbose;

		sf::RenderWindow *window;
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
		void init(int width, int height);
		void draw(int x, int y, int width, int height, E_COLOR color);
		void clearScreen();
		void displayScreen();	
		E_EVENT handleEvents();
		void cleanUp();

	/* 
		GETTER AND SETTERS
	*/
		int getWindowX(void) const;
		int getWindowY(void) const;

};

extern "C" {
	sfmlLib *createLib();
	void deleteLib(sfmlLib *lib);
}
