#include "sdlLib.hpp"
#include "Drawable.hpp"
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
		std::cout << "SDL destructor called" << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
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

E_EVENT SdlLib::handleEvents()
{
	SDL_Event event;	 // used to store any events from the OS
	while(SDL_PollEvent(&event))
	{
		// determine if the user still wants to have the window open
		// (this basically checks if the user has pressed 'X')
		if (event.type == SDL_QUIT)
			return E_EVENT::EVENT_CLOSE_WINDOW;
		else if( event.type == SDL_KEYDOWN )
		{
			switch( event.key.keysym.sym )
			{
				case SDLK_UP: return E_EVENT::EVENT_KEYBOARD_UP;
				case SDLK_DOWN:return E_EVENT::EVENT_KEYBAORD_DOWN;
				case SDLK_LEFT:return E_EVENT::EVENT_KEYBOARD_LEFT;
				case SDLK_RIGHT:return E_EVENT::EVENT_KEYBOARD_RIGHT;
				case SDLK_1: return E_EVENT::EVENT_KEYBOARD_1;
				case SDLK_2: return E_EVENT::EVENT_KEYBOARD_2;
				case SDLK_3: return E_EVENT::EVENT_KEYBOARD_3;
				default: return E_EVENT::EVENT_NONE;
			}
		}
	}
	return E_EVENT::EVENT_NONE;

}

void SdlLib::draw(int x, int y, int width, int height, E_COLOR color)
{
	//Render red filled quad
	SDL_Rect fillRect = { x, y, width, height };

	if (color == E_COLOR::COLOR_RED){
		SDL_SetRenderDrawColor( renderer, 0xFF, 0x00, 0x00, 0xFF );
	}        
	else if (color == E_COLOR::COLOR_YELLOW){
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	}
	SDL_RenderFillRect( renderer, &fillRect );
}

void SdlLib::clearScreen()
{
	SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF );
	SDL_RenderClear( renderer );
}
void SdlLib::displayScreen()
{
	SDL_RenderPresent(renderer);
}

void SdlLib::init(int width, int height)
{
	std::cout << width << ":" << height << std::endl;
	SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "FUCKEN AYYYY CUNT!",                  // window title
        SDL_WINDOWPOS_CENTERED,           // initial x position
        SDL_WINDOWPOS_CENTERED,           // initial y position
        width,                               // width, in pixels
        height,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

	if (window == NULL) {
        // In the case that the window could not be made...
        std::cout << "Could not create window:" << SDL_GetError() << std::endl;
        exit(1);
    }

	renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
}

void SdlLib::drawGame(std::vector<Drawable *> &drawList){
	
    // SDL_Window *window;                    // Declare a pointer

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
}
