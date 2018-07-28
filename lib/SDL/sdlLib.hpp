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
		void drawGame(void);

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
