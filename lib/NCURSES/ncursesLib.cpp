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
	move(y/10, x/10);
	refresh();
	addch('0');
}

void NcursesLib::init(int width, int height){

	initscr();
	int lines = height / 10;
	int colums = width / 10;

	if (lines > 55 || colums > 150 || lines < 0 || colums < 0)
	{
		while(1)
	  	{
	  		move(LINES/2, COLS/2 - 30);
	  		refresh();
	  		addstr("ERROR: Max res 1500 x 550 ... press any key to exit");
	  		refresh();
	  		getch();
	  		cleanUp();
	  		break;
	  	}
		exit(1);
	}

	
	cbreak();
	this->window = newwin(lines, colums, 0, 0);
	while(1){
		if (colums <= COLS && lines <= LINES){
			break;
		}
		else if (colums > COLS || lines > LINES){
			move(LINES/2, COLS/2 - 30);
	  		refresh();
	  		addstr("Error: Please resize screen then press any key");
			refresh();
			getch();
		}
		
	}
	
	
	keypad(this->window , TRUE);
	nodelay(this->window, TRUE);
	noecho();
	curs_set(TRUE);
	refresh();
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
			return E_EVENT::EVENT_KEYBOARD_UP;
			break;
		case KEY_DOWN:
			return E_EVENT::EVENT_KEYBOARD_DOWN;
			break;
		case KEY_LEFT:
			return E_EVENT::EVENT_KEYBOARD_LEFT;
			break;
		case KEY_RIGHT:
			return E_EVENT::EVENT_KEYBOARD_RIGHT;
			break;
		case KEY_CLOSE:
			return E_EVENT::EVENT_CLOSE_WINDOW;
			break;
		default:
			return E_EVENT::EVENT_NONE;
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






