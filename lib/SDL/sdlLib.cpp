#include "sdlLib.hpp"
/*
	default constructors and deconstructors for canonical form
*/
	 SdlLib::SdlLib(){
		if (this->verbose){
			std::cout << "sdlLib VOID CONSTRUCTOR called." << std::endl;
		}
		return;
	}

	 SdlLib::~SdlLib(){
		if (this->verbose){
			std::cout << "sdlLib VOID DECONSTRUCTOR called." << std::endl;
		}
		return;
	}

	SdlLib::SdlLib(const SdlLib & _sfml){
		this->window_x = _sfml.getWindowX();
		this->window_y = _sfml.getWindowY();
		return;
	}

	SdlLib & SdlLib::operator=(const SdlLib & _sfml){
		this->window_x = _sfml.getWindowX();
		this->window_y = _sfml.getWindowY();
		return *this;
	}

/*
	custom constructors for Height an Width
*/

	SdlLib::SdlLib( int _W, int _H){
		this->window_x = _W;
		this->window_y = _H;
	};

/* 
	VIRTUAL INHERITED FUCNTIONS
*/


/*
	GETTERS START
*/
	int SdlLib::getWindowX(void) const{
		return this->window_x;
	};

	int SdlLib::getWindowY(void) const{
		return this->window_y;
	};


/*
	GETTERS END
*/

SdlLib *createLib(){
	return new SdlLib();
}

void deleteLib(SdlLib *lib){
	delete lib;
}

void SdlLib::drawGame(void){
	
    SDL_Window *window;                    // Declare a pointer

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "FUCKEN AYYYY CUNT!",                  // window title
        SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        640,                               // width, in pixels
        480,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        std::cout << "Could not create window:" << SDL_GetError() << std::endl;
        exit(1);
    }

    // The window is open: could enter program loop here (see SDL_PollEvent())

    SDL_Delay(3000);  // Pause execution for 3000 milliseconds, for example

    // Close and destroy the window
    SDL_DestroyWindow(window);

    // Clean up
    SDL_Quit();


}
