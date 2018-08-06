#pragma once
#include "LibInterface.hpp"
#include <ncurses.h>


class NcursesLib : public LibInterface{
	private:
		int window_x;
		int window_y;

		WINDOW *window;
	public:
	/*
		CANONICAL CONSTRUCTORS
	*/
		NcursesLib(void);
		~NcursesLib(void);
		NcursesLib(const NcursesLib & _sfml);
		NcursesLib & operator=(const NcursesLib & _sfml);


	/*
		CUSTOM CONSTRUCTOR FOR W AND H
	*/
		NcursesLib(const int _W, const int _H);

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

	/*
		ADDITIONAL FUNCTIONS
	*/
		void cleanUp(void);
};


extern "C" {
	NcursesLib *createLib();
	void deleteLib(NcursesLib *lib);
}


