#include "ncursesLib.hpp"

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

}



void NcursesLib::init(int width, int height){
	std::cout << "here2" << std::endl;

	// WINDOW *my_win;
	// int startx, starty, width, height;
	// int ch;

	// initscr();			/* Start curses mode 		*/
	// cbreak();			/* Line buffering disabled, Pass on
	// 				 * everty thing to me 		*/
	// keypad(stdscr, TRUE);		/* I need that nifty F1 	*/

	// height = 3;
	// width = 10;
	// starty = (LINES - height) / 2;	/* Calculating for a center placement */
	// startx = (COLS - width) / 2;	/* of the window		*/
	// printw("Press F1 to exit");
	// refresh();
	// my_win = create_newwin(height, width, starty, startx);

	// while((ch = getch()) != KEY_F(1))
	// {	switch(ch)
	// 	{	case KEY_LEFT:
	// 			destroy_win(my_win);
	// 			my_win = create_newwin(height, width, starty,--startx);
	// 			break;
	// 		case KEY_RIGHT:
	// 			destroy_win(my_win);
	// 			my_win = create_newwin(height, width, starty,++startx);
	// 			break;
	// 		case KEY_UP:
	// 			destroy_win(my_win);
	// 			my_win = create_newwin(height, width, --starty,startx);
	// 			break;
	// 		case KEY_DOWN:
	// 			destroy_win(my_win);
	// 			my_win = create_newwin(height, width, ++starty,startx);
	// 			break;	
	// 	}
	// }
		
	// endwin();			/* End curses mode		  */
	

	initscr();
	cbreak();
	keypad(stdscr, TRUE);

	this->window = newwin(height, width, 0, 0);
	box(this->window, 0 , 0);		/* 0, 0 gives default characters 
					 				* for the vertical and horizontal
					 				* lines			*/
	wrefresh(this->window);			/* Show that box 		*/


	// this->window = newwin(height, width, 0, 0);

	// box(this->window, 0 , 0);		 0, 0 gives default characters 
	// 							 * for the vertical and horizontal
	// 				 			* lines			
	// wrefresh(this->window);		/* Show that box 		*/

}

void NcursesLib::clearScreen(){

}

void NcursesLib::displayScreen(){

}

E_EVENT NcursesLib::handleEvents(){

};



NcursesLib *createLib(){
	return new NcursesLib();
}

void deleteLib(NcursesLib *lib){
	delete lib;
}






