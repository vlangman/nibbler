#pragma once
#include "GameEntity.hpp"

enum E_DIRECTION
{
    LEFT, 
    RIGHT,
    UP,
    DOWN
};

class Game;

class Snake : public GameEntity
{
protected:
    E_DIRECTION mDirection;
    int mSpeed;
    Snake *m_child;
public:
    virtual void init(int x, int y, int width, int height, E_COLOR color, E_DIRECTION startDirection, Game *world);
    virtual void update();
    virtual void handleEvent(E_EVENT event);

    Snake(void);
    ~Snake(void);
    Snake & operator=(const Snake & _rhs);
    Snake(const Snake & _snake);

    int getSpeed();
    void changeDirection(E_DIRECTION dir);
    void setChild(Snake *child);
    Snake *getChild();

    void moveToNext(int x, int y);
};