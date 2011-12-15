



#include "BoxysBeing.h"


BoxysBeing::BoxysBeing(void)
{
}

BoxysBeing::BoxysBeing(float x, float y)
{
    mX = x;
    mY = y;
}

BoxysBeing::BoxysBeing(float x, float y, int width, int height)
{
    mX = x;
    mY = y;
    mWidth = width;
    mHeight = height;
}


BoxysBeing::~BoxysBeing(void)
{
}

void BoxysBeing::SetXY(float x, float y)
{
    mX = x;
    mY = y;
}

void BoxysBeing::SetDimensions(int width, int height)
{
    mWidth = width;
    mHeight = height;
}