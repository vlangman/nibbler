#include "Snake.hpp"
#include "Game.hpp"
#include <iostream>
#include "SnakeBody.hpp"

void Snake::init(int x, int y, int width, int height, int color, E_DIRECTION startDirection, Game *world)
{
    m_world = world;
    Drawable::init(x,y,width,height,color);
    mDirection = startDirection;
    mSpeed = width;

    // First block
    SnakeBody *body = new SnakeBody();
    m_child = body;
    body->init(x, y, width, height, color, startDirection, m_world, this);
    body->doNotUpdate();
    m_world->addEntity(body);

    // Second block
    SnakeBody *body2 = new SnakeBody();
    body2->init(x - width, y, width, height, color, startDirection, m_world, m_child);
    body2->doNotUpdate();
    m_child->setChild(body2);
    m_world->addEntity(body2);
}

void Snake::setChild(Snake *child){
    m_child = child;
}

void Snake::handleEvent(E_EVENT event)
{
    if (event == E_EVENT::EVENT_KEYBOARD_RIGHT){
        m_child->changeDirection(E_DIRECTION::RIGHT);
        mDirection = E_DIRECTION::RIGHT;
    }
    else if (event == E_EVENT::EVENT_KEYBOARD_LEFT){
        m_child->changeDirection(E_DIRECTION::LEFT);
        mDirection = E_DIRECTION::LEFT;
    }
    else if (event == E_EVENT::EVENT_KEYBOARD_UP){
        m_child->changeDirection(E_DIRECTION::UP);
        mDirection = E_DIRECTION::UP;
    }
    else if (event == E_EVENT::EVENT_KEYBAORD_DOWN){
        m_child->changeDirection(E_DIRECTION::DOWN);
        mDirection = E_DIRECTION::DOWN;
    }
}

void Snake::update()
{
    if (mDirection == E_DIRECTION::UP){
        m_y -= mSpeed;
    }
    else if (mDirection == E_DIRECTION::DOWN){
        m_y += mSpeed;
    }
    else if (mDirection == E_DIRECTION::LEFT){
        m_x -= mSpeed;
    }
    else if (mDirection == E_DIRECTION::RIGHT){
        m_x += mSpeed;
    }

    if (m_child != NULL)
        m_child->update();
}

int Snake::getSpeed()
{
    return mSpeed;
}

void Snake::changeDirection(E_DIRECTION dir)
{
    mDirection = dir;
    if (m_child != NULL){
        m_child->changeDirection(dir);
    }
}

void Snake::moveToNext(int x, int y)
{
    m_x = x;
    m_y = y;
}