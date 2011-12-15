#pragma once

#include <SDL.h>


class GEventHandler
{
public:
	GEventHandler(void);
	~GEventHandler(void);

	virtual void OnEvent(SDL_Event *event);
	virtual void OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) { }
	virtual void OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) { }
	virtual void OnMouseFocus() { }
	virtual void OnMouseBlur() { }
	virtual void OnMouseMove(int mX, int mY, int relX, int relY,
		bool Left,bool Right,bool Middle) { }
	virtual void OnMouseWheel(bool Up, bool Down) { }    //Not implemented
	virtual void OnInputFocus() { }
	virtual void OnInputBlur() { }
	virtual void OnResize(int w,int h) { }
	virtual void OnRestore() { }
	virtual void OnMinimize() { }
	virtual void OnExpose() { }
	virtual void OnExit() { }
	virtual void OnUser(Uint8 type, int code, void* data1, void* data2) { }
	virtual void OnLButtonDown(int mX, int mY) { }
	virtual void OnLButtonUp(int mX, int mY) { }
	virtual void OnRButtonDown(int mX, int mY) { }
	virtual void OnRButtonUp(int mX, int mY) { }
	virtual void OnMButtonDown(int mX, int mY) { }
	virtual void OnMButtonUp(int mX, int mY) { }

private:

};

