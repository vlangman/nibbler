#include "SnakeHead.hpp"

void SnakeHead::handleEvent(E_EVENT event)
{
    if (event == E_EVENT::EVENT_KEYBOARD_RIGHT){
        if (mDirection != E_DIRECTION::LEFT)
            mDirection = E_DIRECTION::RIGHT;
    }
    else if (event == E_EVENT::EVENT_KEYBOARD_LEFT){
        if (mDirection != E_DIRECTION::RIGHT)
            mDirection = E_DIRECTION::LEFT;
    }
    else if (event == E_EVENT::EVENT_KEYBOARD_UP){
        if (mDirection != E_DIRECTION::DOWN)
            mDirection = E_DIRECTION::UP;
    }
    else if (event == E_EVENT::EVENT_KEYBOARD_DOWN){
        if (mDirection != E_DIRECTION::UP)
            mDirection = E_DIRECTION::DOWN;
    }
}

void SnakeHead::grow()
{
    Snake *ptr = this;

    while (ptr->getChild() != NULL){
        ptr = ptr->getChild();
    }

    Snake *body = new Snake();
    body->init(ptr->getX(), ptr->getY(), m_width, m_height, m_color, mDirection, m_world);
    ptr->setChild(body);
    m_world->addEntity(body);
}

void SnakeHead::update()
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

    // Collision detection
    for (auto i : m_world->m_entityList){
        if (i->getX() == m_x && i->getY() == m_y ) {
            if (i->getType() == E_ENTITY_TYPE::ENTITY_FOOD)
            {
                grow();
                i->die();
            }
            else if (i != this && i->getType() == E_ENTITY_TYPE::ENTITY_SNAKE){
                m_world->closeGame();
            }
        }
    }

    // Boundary collision
    if (m_x < 0 || m_x >= m_world->getWindowX() || m_y < 0 || m_y >= m_world->getWindowY()){
        m_world->closeGame();
    }

    if (m_child != NULL){
        m_child->moveToNext(m_x, m_y);
    }
}

void SnakeHead::init(int x, int y, int width, int height, E_COLOR color, E_DIRECTION startDirection, Game *world)
{
    Snake::init(x,y,width,height,color,startDirection,world);

    grow();
    grow();
    grow();

    // Snake *body = new Snake;
    // body->init(x,y,width,height,color,startDirection,world);
    // world->addEntity(body);

    // Snake *body2 = new Snake;
    // body2->init(x,y,width,height,color,startDirection,world);
    // world->addEntity(body2);

    // Snake *body3 = new Snake;
    // body3->init(x,y,width,height,color,startDirection,world);
    // world->addEntity(body3);

    // m_child = body;
    // body->setChild(body2);
    // body2->setChild(body3);
}