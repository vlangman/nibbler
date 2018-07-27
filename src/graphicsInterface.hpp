#pragma once
#include <iostream>
#include "snake.hpp"

class Snake;

class graphicsInterface {

public:
	virtual void drawGame() = 0;
};