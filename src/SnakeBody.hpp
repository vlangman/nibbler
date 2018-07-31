#pragma once
#include "Snake.hpp"

class SnakeBody : public Snake
{
private:
    Snake *m_parent;
public:
    void init(int x, int y, int width, int height, int color, E_DIRECTION startDirection, Game *world, Snake *parent);
    void update();
    void handleEvent(E_EVENT event);
};