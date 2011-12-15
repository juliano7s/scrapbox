

#include "BoxysWorld.h"


BoxysWorld::BoxysWorld(void)
{
}

BoxysWorld::BoxysWorld(float x, float y)
{
    mX = x;
    mY = y;
}


BoxysWorld::~BoxysWorld(void)
{
}

void BoxysWorld::SetXY(float x, float y)
{
    mX = x;
    mY = y;
}

void BoxysWorld::SetDimensions(int width, int height)
{
    mWidth = width;
    mHeight = height;
}

void BoxysWorld::AddBeing(BoxysBeing &being)
{
    beingsList.push_back(&being);
}

void BoxysWorld::AddBeing(BoxysBeing *being)
{
    beingsList.push_back(being);
}