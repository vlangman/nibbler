#pragma once
#include "LibInterface.hpp"
#include "../lib/include/SFML/Graphics.hpp"


class sfmlLib : public LibInterface{
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

extern "C" {
	sfmlLib *createSfmlLib();
	void deleteSfmlLib(sfmlLib *lib);
}
