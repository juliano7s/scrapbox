#pragma once

#include <vector>

#include "BoxysBeing.h"

class BoxysWorld
{
    public:
        BoxysWorld(void);
        BoxysWorld(float x, float y);
        ~BoxysWorld(void);

        void SetXY(float x, float y);
        void SetDimensions(int width, int height);    
        float X() const { return mX; }
        float Y() const { return mY; }
        int Width() const { return mWidth; }
        int Height() const { return mHeight; }
        void AddBeing(BoxysBeing &being);
        void AddBeing(BoxysBeing *being);
        std::vector<BoxysBeing*>& BeingsList() { return beingsList; }

    private:
        std::vector<BoxysBeing*> beingsList;
        float mX, mY;
        int mWidth, mHeight;

};

