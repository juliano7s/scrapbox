

#include <iostream>

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

/* virtual */ void BoxysEventHandler::OnMouseMove(int x, int y, int relX, int relY,
            bool Left,bool Right,bool Middle)
{
    std::cout << "MMove (" << x << "," << y << ")" << std::endl;
    std::cout << "MMove rel (" << relX << "," << relY << ")" << std::endl;
    if (Left)
    {
        std::cout << "MMove Left Hold" << std::endl;
    }

    if (Middle)
    {
        std::cout << "MMove Middle Hold" << std::endl;
    }

    if (Right)
    {
        std::cout << "MMove Right Hold" << std::endl;
    }
}

/* virtual */ void BoxysEventHandler::OnLButtonDown(int x, int y)
{
    std::cout << "LBDown (" << x << "," << y << ")" << std::endl;    
}

/* virtual */ void BoxysEventHandler::OnLButtonUp(int x, int y)
{
    std::cout << "LBUp (" << x << "," << y << ")" << std::endl;
}

/* virtual */ void BoxysEventHandler::OnRButtonDown(int x, int y)
{
    std::cout << "RBDown (" << x << "," << y << ")" << std::endl;
}

/* virtual */ void BoxysEventHandler::OnRButtonUp(int x, int y)
{
    std::cout << "RBUp (" << x << "," << y << ")" << std::endl;
}

void BoxysEventHandler::WindowToGameCoordinates(int &x, int &y)
{
    int gameX, gameY;

    /* considering viewport at origin (0,0) */
    gameX = (x/Game::WINDOW_WIDTH) * Game::VIEWPORT_WIDTH;
    gameY = ((Game::WINDOW_HEIGHT - y)/Game::WINDOW_HEIGHT) * Game::VIEWPORT_HEIGHT;
	
    x = gameX;
    y = gameY;
}