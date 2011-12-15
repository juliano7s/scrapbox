

#include "Game.h"


Game::Game(void) :
	mEventHandler(),
	mPhyEngine(),
    mRenderEngine(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT,
        Game::VIEWPORT_WIDTH, Game::VIEWPORT_HEIGHT),
    mWorld()
{
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
    mWorld.SetXY(10.0f, 10.0f);
    mWorld.SetDimensions(600,400);

    /* Needs to be freed */
    BoxysBeing *b = new BoxysBeing(55.0f,70.0f);
    b->SetDimensions(20,20);

    mWorld.AddBeing(b);
}

