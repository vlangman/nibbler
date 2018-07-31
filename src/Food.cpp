#include "Food.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Food::Food()
{
    m_type = E_ENTITY_TYPE::ENTITY_FOOD;
    srand (time(NULL));
}

void Food::die()
{
    int x;
    int y;
    bool open = false;

    while (!open)
    {
        open = true;
        x = rand() % (m_world->getWindowX() / 10) * 10;
        y = rand() % (m_world->getWindowY() / 10) * 10;

        for (auto i : m_world->m_entityList){
            if (x == i->getX() && y == i->getY()){
                open = false;
                break;
            }
        }
    }

    Food *food = new Food();
    food->init(x,y,m_width, m_height, m_color, m_world);
    m_world->addEntity(food);

    GameEntity::die();
}