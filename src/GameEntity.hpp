#pragma once
#include "Drawable.hpp"

enum E_ENTITY_TYPE
{
    ENTITY_SNAKE,
    ENTITY_FOOD,
    ENTITY_NONE
};

class GameEntity : public Drawable
{
protected:
    E_ENTITY_TYPE m_type;
    bool m_alive;
    Game *m_world;

public:
    void init(int x, int y, int width, int height, E_COLOR color, Game *world);
    bool isAlive();
    virtual void die();

    E_ENTITY_TYPE getType();
    GameEntity();
    virtual ~GameEntity();
};