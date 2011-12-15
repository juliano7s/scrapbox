#pragma once

#include <Windows.h>
#include <SDL.h>
#include <gl/GL.h>

#include "BoxysEventHandler.h"
#include "PhyEngine.h"
#include "RenderEngine.h"
#include "BoxysWorld.h"

class Game
{
    public:
        static const int WINDOW_WIDTH = 640;
        static const int WINDOW_HEIGHT = 480;
        static const int VIEWPORT_WIDTH = WINDOW_WIDTH;
        static const int VIEWPORT_HEIGHT = WINDOW_HEIGHT;
        
	public:
		Game(void);
		~Game(void);

		int		OnExecute();
		bool	OnInit();
		void	OnLoop();
		void	OnRender();
		void	OnCleanUp();

		void	Quit();
        void    CreateWorld();
        void    CreateWorld(const char* mapFile);


	private:
		bool				mIsRunning;
		BoxysEventHandler	mEventHandler;
		PhyEngine			mPhyEngine;
		RenderEngine		mRenderEngine;
        BoxysWorld          mWorld;
};

