#pragma once

#include "GEventHandler.h"

class Game;

class BoxysEventHandler : public GEventHandler
{
	public:
		BoxysEventHandler();
		BoxysEventHandler(Game *game);
		~BoxysEventHandler(void);

		void SetGame(Game *game);
		void OnExit();

	private:
		Game *mpGame;
};

