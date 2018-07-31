#pragma once
#include "Snake.hpp"

class SnakeHead : public Snake
{
private:
public:
    void handleEvent(E_EVENT event);
    void init(int x, int y, int width, int height, E_COLOR color, E_DIRECTION startDirection, Game *world);
    void update();

    void grow();
};