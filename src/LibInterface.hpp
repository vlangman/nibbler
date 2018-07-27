#pragma once
#include <iostream>
#include "Game.hpp"

class LibInterface {

public:
	virtual void drawGame() = 0;
	virtual ~LibInterface(){};
};