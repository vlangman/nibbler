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
	cleanUp();
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


void NcursesLib::drawBorder(){
	int x = getWindowX();
	int y = getWindowY();

	attron (COLOR_PAIR (1));
    // mvwprintw (testwin, 0, 0, "%s", "Hello");
   
	for(int i = 0; i < x; i++){
		move(0, i);
		addch('=');
	}
	for(int i = 0; i < y; i++){
		move(i, x);
		addch(']');
	}
	for(int i = 0; i < y; i++){
		move(i, 0);
		addch('[');
	}
	for(int i = 0; i < x; i++){
		move(y, i);
		addch('=');
	}
	attroff (COLOR_PAIR (1));
}

void NcursesLib::draw(int x, int y, int width, int height, E_COLOR color){

	drawBorder();
	move((y/10)+1, (x/10)+1);
	switch (color)
	{
		case (0): 
			attron(3);
			addch('#');
			attroff(3);
			break;
		case (1):
			attron (COLOR_PAIR (1));
			addch('0');
			attroff (COLOR_PAIR (1));
			break;
	}
	refresh();
}

void NcursesLib::init(int width, int height){

	initscr();
	int lines = (height/10) + 1;
	int columns = (width/10) + 1;
	if (width % 10 != 0 || height % 10 != 0){
		move(LINES/2, COLS/2 - 30);
  		addstr("ERROR: height and width must be multiples of 10");
  		refresh();
		getch();
		cleanUp();
		exit(1);
	}
	if (lines > 56 || columns > 151 || lines < 0 || columns < 0)
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
	this->window = newwin(lines, columns, 1, 1);
	while(1){
		if (columns <= COLS && lines <= LINES){
			break;
		}
		else if (columns > COLS || lines > LINES){
			move(LINES/2, COLS/2 - 30);
	  		refresh();
	  		addstr("Error: Please resize screen then press any key");
			refresh();
			getch();
		}
		
	}

	if(has_colors() == FALSE)
	{	cleanUp();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);

	wresize(this->window, lines, columns);
	this->window_x = columns;
	this->window_y = lines;
	

	keypad(this->window , TRUE);
	nodelay(this->window, TRUE);
	noecho();
	curs_set(FALSE);
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
		case 49:
			return E_EVENT::EVENT_KEYBOARD_1;
			break;
		case 50:
			return E_EVENT::EVENT_KEYBOARD_2;
			break;
		default:
			return E_EVENT::EVENT_NONE;
			break;
	}
};

void NcursesLib::cleanUp(){
	std::cout << "CLEANUP CALLED" << std::endl;
	delwin(this->window);
	endwin();
}


NcursesLib *createLib(){
	return new NcursesLib();
}

void deleteLib(NcursesLib *lib){
	delete lib;
}






