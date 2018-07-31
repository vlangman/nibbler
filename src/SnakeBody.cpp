#include "SnakeBody.hpp"

void SnakeBody::update()
{
    Snake::update();
}
void SnakeBody::handleEvent(E_EVENT event)
{

}

void SnakeBody::init(int x, int y, int width, int height, int color, E_DIRECTION startDirection, Game *world, Snake *parent)
{
    Drawable::init(x,y,width,height,color);
    mDirection = startDirection;
    m_world = world;
    m_parent = parent;
    mSpeed = parent->getSpeed();
    m_child = NULL;
}