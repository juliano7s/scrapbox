
#include <windows.h>
#include <GL/gl.h>
#include <SDL.h>

#include "RenderEngine.h"
#include "GControlException.h"

RenderEngine::RenderEngine(void)
{
    mWindowWidth = 640;
    mWindowHeight = 480;
}

RenderEngine::RenderEngine(int width, int height)
{
    mWindowWidth = width;
    mWindowHeight = height;
}

RenderEngine::~RenderEngine(void)
{
}

bool RenderEngine::initGraphics()
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

void RenderEngine::initCamera()
{
	glClearColor(0, 0, 0, 0); 
    glViewport(0, 0, mWindowWidth, mWindowHeight);
 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); 
	glOrtho(0, mWindowWidth, mWindowHeight, 0, 1, -1);
 
	glMatrixMode(GL_MODELVIEW); 
	glEnable(GL_TEXTURE_2D); 
	glLoadIdentity();
}

void RenderEngine::renderWorld()
{
    if (mpWorld == 0)
        throw GControlException("World not set on RenderEngine!");

   glBegin(GL_QUADS);
        glColor3f(1, 1, 0); glVertex3f(0, 0, 0);
        glColor3f(1, 1, 0); glVertex3f(100, 0, 0);
        glColor3f(1, 0, 1); glVertex3f(100, 100, 0);
        glColor3f(1, 1, 1); glVertex3f(0, 100, 0);
    glEnd();
 
}

void RenderEngine::renderBeings()
{
    if (mpWorld == 0)
        throw GControlException("World not set on RenderEngine!");
}
