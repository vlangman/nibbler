#include "Drawable.hpp"

void Drawable::init(int x, int y, int width, int height, int color)
{
    this->m_x = x;
    this->m_y = y;
    this->m_width = width;
    this->m_height = height;
    this->m_color = color;
    mShouldUpdate = true;
}

Drawable::Drawable()
{
}

void Drawable::setPosition(int x, int y)
{
    m_x = x;
    m_y = y;
}

int Drawable::getX()
{
    return this->m_x;
}
int Drawable::getY()
{
    return this->m_y;
}
int Drawable::getWidth()
{
    return this->m_width;
}

int Drawable::getHeight()
{
    return m_height;
}
int Drawable::getColor()
{

}

bool Drawable::isUpdateable(){
    return mShouldUpdate;
}

void Drawable::doNotUpdate()
{
    mShouldUpdate = false;
}

void Drawable::update()
{

}

void Drawable::handleEvent(E_EVENT event)
{

}