

#include "Game.h"


bool Game::OnInit()
{
    /* Set itself on the eventHandler */
	mEventHandler.SetGame(this);

    /* Set game world on renderEngine */
    mRenderEngine.SetWorld(mWorld);

    /* Initialize game graphics and window */
    if (!mRenderEngine.InitGraphics())
        return false;	

	/* Initialize camera projection */
	mRenderEngine.InitCamera();

	return true;

}
