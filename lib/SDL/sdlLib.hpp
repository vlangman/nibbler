#pragma once
#include "LibInterface.hpp"
#include <SDL.h>


class SdlLib : public LibInterface{
	private:
		int 		window_x;
		int 		window_y;
		bool		verbose;

	public:
	/*
		default constructors and deconstructors for canonical form
	*/
		SdlLib(void);
		~SdlLib(void);
		SdlLib(const SdlLib & _sfml);
		SdlLib & operator=(const SdlLib & _sfml);

	/*
		custom constructors for Height an Width
	*/

		SdlLib(const int _W, const int _H);

	/* 
		VIRTUAL INHERITED ABSTRACT FUCNTIONS
	*/
		void drawGame(std::vector<Drawable *> &drawList);
		void draw(int x, int y, int width, int height, E_COLOR color);
		void init(int width, int height);
		void clearScreen();
		void displayScreen();
		E_EVENT handleEvents();

	/* 
		GETTER AND SETTERS
	*/
		int getWindowX(void) const;
		int getWindowY(void) const;

};

extern "C" {
	SdlLib *createLib();
	void deleteLib(SdlLib *lib);
}
