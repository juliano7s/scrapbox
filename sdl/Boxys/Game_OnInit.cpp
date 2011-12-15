#include "Game.h"


bool Game::OnInit()
{
    /* Set itself on the eventHandler */
	mEventHandler.SetGame(this);

    /* Initialize game graphics and window */
    if (!mRenderEngine.initGraphics())
        return false;	

	/* Initialize camera projection */
	mRenderEngine.initCamera();

	return true;

}
