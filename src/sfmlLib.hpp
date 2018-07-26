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
		void drawGame(const Snake & _snake);

	/* 
		GETTER AND SETTERS
	*/
		int getWindowX(void) const;
		int getWindowY(void) const;

};

extern "C" {
    extern void drawGame(const Snake & _snake);
}