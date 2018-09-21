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
    //canon start
    GameEntity(void);
    virtual ~GameEntity();
    GameEntity(const GameEntity & _entity);
    GameEntity & operator=(const GameEntity & _rhs);
     //cannon end

    void init(int x, int y, int width, int height, E_COLOR color, Game *world);
    bool isAlive();
    virtual void die();

    E_ENTITY_TYPE getType();
   
    
};