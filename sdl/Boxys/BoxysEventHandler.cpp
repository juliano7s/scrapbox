

#include "BoxysEventHandler.h"
#include "Game.h"


BoxysEventHandler::BoxysEventHandler()
{
}

BoxysEventHandler::BoxysEventHandler(Game *game)
{
	mpGame = game;
}

BoxysEventHandler::~BoxysEventHandler(void)
{
}

void BoxysEventHandler::SetGame(Game *game)
{
	if (game != 0)
		mpGame = game;
}

/* virtual */ void BoxysEventHandler::OnExit()
{
	this->mpGame->Quit();    
}

