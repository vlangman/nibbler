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
//conon start

    Drawable(void);
    ~Drawable(void);
    Drawable(const Drawable & _drawable);
    Drawable & operator=(const Drawable & _drawable);
    //canon end

    int getX();
    int getY();
    int getWidth();
    int getHeight();
    E_COLOR getColor();

    void setPosition(int x, int y);
    virtual void init(int x, int y, int width, int height, E_COLOR color);
    virtual void update();
    virtual void handleEvent(E_EVENT event);

    bool isUpdateable();
    void doNotUpdate();

};