#pragma once
#include "Game.hpp"

class Drawable 
{
protected:
    int m_x;
    int m_y;
    int m_width;
    int m_height;
    E_COLOR m_color;

    bool mShouldUpdate;
public:
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    E_COLOR getColor();

    void setPosition(int x, int y);

    Drawable();
    virtual void init(int x, int y, int width, int height, E_COLOR color);
    virtual void update();
    virtual void handleEvent(E_EVENT event);

    bool isUpdateable();
    void doNotUpdate();

};