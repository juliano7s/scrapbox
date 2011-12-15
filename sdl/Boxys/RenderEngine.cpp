
#include <windows.h>
#include <GL/gl.h>
#include <SDL.h>
#include <vector>
#include <iostream>

#include "RenderEngine.h"
#include "GControlException.h"

RenderEngine::RenderEngine(void)
{
    mWindowWidth = 640;
    mWindowHeight = 480;
}

RenderEngine::RenderEngine(int windowWidth, int windowHeight,
    int viewportWidth, int viewportHeight)
{
    mWindowWidth = windowWidth;
    mWindowHeight = windowHeight;
    mViewportWidth = viewportWidth;
    mViewportHeight = viewportHeight;
}

RenderEngine::~RenderEngine(void)
{
}

void RenderEngine::SetWorld(BoxysWorld &world)
{
    mpWorld = &world;
}

bool RenderEngine::InitGraphics()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

    if (SDL_SetVideoMode(mWindowWidth, mWindowHeight, 32,
        SDL_HWSURFACE | SDL_OPENGL) == 0)
		return false;

    /* OpenGL options */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    return true;
}

void RenderEngine::InitCamera()
{
	glClearColor(0, 0, 0, 0); 
    glViewport(0, 0, mWindowWidth, mWindowHeight);
 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    /* If left or bottom changes from 0, BoxysEventHandler::WindowToGameCoordinates needs
       to change -> viewport at origin (0,0) */
    glOrtho(0, mViewportWidth, mViewportHeight, 0, 1, -1);
    
 	glMatrixMode(GL_MODELVIEW); 
	glEnable(GL_TEXTURE_2D); 
	glLoadIdentity();
}

void RenderEngine::RenderWorld()
{
    if (mpWorld == 0)
        throw GControlException("World not set on RenderEngine!");

    glColor3f(1, 1, 1);
    
    glBegin(GL_LINE_LOOP);
        glVertex2f(mpWorld->X(), mpWorld->Y());
        glVertex2f(mpWorld->X() + mpWorld->Width(), mpWorld->Y());
        glVertex2f(mpWorld->X() + mpWorld->Width(), mpWorld->Y() + mpWorld->Height());
        glVertex2f(mpWorld->X(), mpWorld->Y() + mpWorld->Height());
    glEnd();
 
}

void RenderEngine::RenderBeings()
{
    if (mpWorld == 0)
        throw GControlException("World not set on RenderEngine!");

    std::vector<BoxysBeing*>::iterator it;

    for (it = mpWorld->BeingsList().begin(); it != mpWorld->BeingsList().end(); it++)
    {
        BoxysBeing *_pBeing = *it;
        RenderEachBeing(*_pBeing);
    }
}

void RenderEngine::RenderEachBeing(BoxysBeing &being)
{
    glColor3f(1, 1, 1);

    glBegin(GL_LINE_LOOP);
        glVertex2f(being.X(), being.Y());
        glVertex2f(being.X() + being.Width(), being.Y());
        glVertex2f(being.X() + being.Width(), being.Y() + being.Height());
        glVertex2f(being.X(), being.Y() + being.Height());
    glEnd();
}
