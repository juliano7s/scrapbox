

#include "Game.h"


Game::Game(void) :
	mEventHandler(),
	mPhyEngine(),
    mRenderEngine(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT),
    mWorld()
{
	mpSurfaceDisplay = NULL;
	mIsRunning = false;
}


Game::~Game(void)
{
}

int Game::OnExecute()
{
    /* Initialize game control objects and resources */
	if (OnInit() == false)
		return -1;
    
    /* Start the game */
	mIsRunning = true;

	SDL_Event event;

    /* Main game loop */
	while (mIsRunning)
	{
        /* Checks for events */
		while (SDL_PollEvent(&event))
		{
			/* Pass event to the handler */
			mEventHandler.OnEvent(&event);
		}

        /* Updates game data */
		OnLoop();
        /* Renders game objects */
		OnRender();
	}

    /* Cleans allocated resources */
	OnCleanUp();

	return 0;
}

void Game::Quit()
{
	mIsRunning = false;
}

void Game::CreateWorld()
{
    mWorld.SetXY(1.0f, 1.0f);
    mWorld.SetDimensions(200,400);
}

