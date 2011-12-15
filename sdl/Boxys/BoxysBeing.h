#pragma once


class BoxysBeing
{
    public:
        BoxysBeing(void);
        BoxysBeing(float x, float y);
        BoxysBeing(float x, float y, int width, int height);
        ~BoxysBeing(void);

    private:
        float   mX, mY;
        int     mWidth, mHeight;

};

