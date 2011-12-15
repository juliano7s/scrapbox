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
        void OnMouseMove(int x, int y, int relX, int relY,
            bool Left,bool Right,bool Middle);
        void OnLButtonDown(int x, int y);
	    void OnLButtonUp(int x, int y);
	    void OnRButtonDown(int x, int y);
	    void OnRButtonUp(int x, int y);
        void OnMButtonDown(int x, int y) { }
        void OnMButtonUp(int x, int y) { }


	private:
		Game *mpGame;

        void WindowToGameCoordinates(int &x, int &y);
};

