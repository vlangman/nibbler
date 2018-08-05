#include "ncursesLib.hpp"
#include <unistd.h>

/* 
	GETTER AND SETTERS
*/

int NcursesLib::getWindowX(void) const{
	return this->window_x;
}

int NcursesLib::getWindowY(void) const{
	return this->window_y;
}



// 		CANONICAL CONSTRUCTORS 	

NcursesLib::NcursesLib(void){
	return;
}

NcursesLib::~NcursesLib(void){
	return;
}

NcursesLib::NcursesLib(const NcursesLib & _lib){
	this->window_x = _lib.getWindowX();
	this->window_y = _lib.getWindowY();
	return;
}

NcursesLib & NcursesLib::operator=(const NcursesLib & _lib){
	this->window_x = _lib.getWindowX();
	this->window_y = _lib.getWindowY();
	return *this;
}


/* 
	CUSTOM CONSTRUCTOR FOR W AND H
*/


 NcursesLib::NcursesLib(const int _W, const int _H){
	this->window_x = _W;
	this->window_y = _H;
	return;
 }


/* 
	VIRTUAL INHERITED ABSTRACT FUCNTIONS
*/


void NcursesLib::drawGame(std::vector<Drawable *> &drawList){
	return;
}

void NcursesLib::draw(int x, int y, int width, int height, E_COLOR color){
	border('|', '|', '-',  '-', '+', '+', '+', '+');
	move(y, x);
	wmove(this->window,  y,  x);

	getch();
	refresh();
	addch('0');
}

void NcursesLib::init(int width, int height){

	int starty = (LINES - height) / 2;	/* Calculating for a center placement */
	int startx = (COLS - width) / 2;	/* of the window		*/

	initscr();
	cbreak();
	this->window = newwin(width, height, starty, startx);
	keypad(this->window , TRUE);
	nodelay(this->window, TRUE);
	noecho();
	curs_set(TRUE);
  	wrefresh(this->window);
}

void NcursesLib::clearScreen(){
	clear();
}

void NcursesLib::displayScreen(){
	refresh();
}

E_EVENT NcursesLib::handleEvents(){

	int c = wgetch(this->window);
	switch(c)
	{	case KEY_UP:
			addch('^');
			break;
		case KEY_DOWN:
			addch('_');
			break;
		case 32:
			std::cout << "Space key pressed" << std::endl;
			endwin();
			exit(1);
			break;
		default:
			break;
	}
};

void NcursesLib::cleanUp(){
	delwin(this->window);
	endwin();
}


NcursesLib *createLib(){
	return new NcursesLib();
}

void deleteLib(NcursesLib *lib){
	lib->cleanUp();
	delete lib;
}






