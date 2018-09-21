#include "GameEntity.hpp"

   //canon start
	
GameEntity::GameEntity()
{
    m_type = ENTITY_NONE;
    m_alive = true;
}

GameEntity::GameEntity(const GameEntity & _entity){
	static_cast<void>(_entity);
	return;
};

GameEntity & GameEntity::operator=(const GameEntity & _rhs){
	static_cast<void>(_rhs);
	return *this;
}
//cannon end

E_ENTITY_TYPE GameEntity::getType()
{
    return m_type;
}


void GameEntity::init(int x, int y, int width, int height, E_COLOR color, Game *world)
{
    Drawable::init(x,y,width,height,color);
    m_world = world;
}

void GameEntity::die()
{
    m_alive = false;
}

bool GameEntity::isAlive()
{
    return m_alive;
}

GameEntity::~GameEntity()
{
    
}