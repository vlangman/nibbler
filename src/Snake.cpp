#include "Snake.hpp"
#include "Game.hpp"
#include <iostream>

void Snake::init(int x, int y, int width, int height, E_COLOR color, E_DIRECTION startDirection, Game *world)
{
    m_child = NULL;
    GameEntity::init(x,y,width,height,color, world);
    mDirection = startDirection;
    mSpeed = width;
}

Snake *Snake::getChild()
{
    return m_child;
}

Snake::Snake()
{
    m_type = E_ENTITY_TYPE::ENTITY_SNAKE;
}

void Snake::setChild(Snake *child){
    m_child = child;
}

void Snake::handleEvent(E_EVENT event)
{

}

void Snake::update()
{

}

int Snake::getSpeed()
{
    return mSpeed;
}

void Snake::changeDirection(E_DIRECTION dir)
{
    mDirection = dir;
}

void Snake::moveToNext(int x, int y)
{
    if (m_child != NULL) {
        m_child->moveToNext(m_x, m_y);
    }

    m_x = x;
    m_y = y;
}