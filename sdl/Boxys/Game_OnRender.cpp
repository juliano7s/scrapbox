

#include "Game.h"
#include "RenderEngine.h"


void Game::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

	mRenderEngine.renderWorld();

    mRenderEngine.renderBeings();

    SDL_GL_SwapBuffers();
}