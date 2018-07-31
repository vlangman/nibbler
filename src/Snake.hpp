#pragma once
#include "Drawable.hpp"

enum E_DIRECTION
{
    LEFT, 
    RIGHT,
    UP,
    DOWN
};

class Game;

class Snake : public Drawable
{
protected:
    E_DIRECTION mDirection;
    int mSpeed;
    Game *m_world;
    Snake *m_child;
public:
    virtual void init(int x, int y, int width, int height, int color, E_DIRECTION startDirection, Game *world);
    void update();
    virtual void handleEvent(E_EVENT event);

    int getSpeed();
    void changeDirection(E_DIRECTION dir);
    void setChild(Snake *child);
    void moveToNext(int x, int y);
};