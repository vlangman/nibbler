#pragma once
#include <iostream>
#include <vector>
#include "Drawable.hpp"
#include "Game.hpp"

class LibInterface {

public:
	virtual void init(int width, int height) = 0;
	virtual void drawGame(std::vector<Drawable*> &drawList) = 0;
	virtual void draw(int x, int y, int width, int height, E_COLOR color) = 0;
	virtual void clearScreen() = 0;
	virtual void displayScreen() = 0;

	virtual E_EVENT handleEvents() = 0;
	virtual ~LibInterface(){};
};