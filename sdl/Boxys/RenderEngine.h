#pragma once

#include "BoxysWorld.h"

class RenderEngine
{
	public:
		RenderEngine(void);
        RenderEngine(int width, int height);
		~RenderEngine(void);

        bool initGraphics();
		void initCamera();
        void renderWorld();
        void renderBeings();

    private:
        BoxysWorld *mpWorld;
        int mWindowWidth, mWindowHeight;

};

