#pragma once


class BoxysBeing
{
    public:
        BoxysBeing(void);
        BoxysBeing(float x, float y);
        BoxysBeing(float x, float y, int width, int height);
        ~BoxysBeing(void);

        /* coordinates and shape functions */
        float X() const { return mX; }
        float Y() const { return mY; }
        int Width() const { return mWidth; }
        int Height() const { return mHeight; }
        void SetXY(float x, float y);
        void SetDimensions(int width, int height); 

        /* movement */

        /* game intelligence */
        void OnLoop();

    private:
        /* coordinates and dimensions */
        float   mX, mY;
        int     mWidth, mHeight;

        /* movement */
        float   mSpeedX, mSpeedY;

};

