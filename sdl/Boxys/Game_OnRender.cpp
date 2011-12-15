

#include "Game.h"
#include "RenderEngine.h"


void Game::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	mRenderEngine.RenderWorld();

    mRenderEngine.RenderBeings();

    SDL_GL_SwapBuffers();
}