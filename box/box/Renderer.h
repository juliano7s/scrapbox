
#include "Box.h"
#include "World.h"
#include <vector>

#pragma once
class Renderer
{
public:
	Renderer(void);
	~Renderer(void);
	static void drawWorldBoxes(World *w);
	static void drawWorld(World const w);
};

