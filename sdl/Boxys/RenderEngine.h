#pragma once

#include "BoxysWorld.h"
#include "BoxysBeing.h"

class RenderEngine
{
	public:
		RenderEngine(void);
        RenderEngine(int windowWidth, int windowHeight,
            int viewportWidth, int viewportHeight);
		~RenderEngine(void);
        
        void SetWorld(BoxysWorld &world);
        bool InitGraphics();
		void InitCamera();
        void RenderWorld();
        void RenderBeings();
        
    private:
        BoxysWorld *mpWorld;
        int mWindowWidth, mWindowHeight;
        int mViewportWidth, mViewportHeight;

        void RenderEachBeing(BoxysBeing &being);

};

