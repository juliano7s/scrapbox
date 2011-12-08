#include "World.h"

World::World(float x, float y)
{
	this->x_position = x;
	this->y_position = y;
	height = 7;
	width = 6;
}

World::World(std::vector<Box> boxList)
{
	this->x_position = 0;
	this->y_position = 0;
	height = 7;
	width = 6;
	this->boxList = boxList;
}

World::~World(void)
{
	
}

void World::addBox(Box b)
{
	this->boxList.push_back(b);
}

std::vector<Box>& World::getBoxList()
{
	return this->boxList;
}

float World::getX() const
{
	return this->x_position;
}

float World::getY() const
{
	return this->y_position;
}

float World::getHeight() const
{
	return this->height;
}

float World::getWidth() const
{
	return this->width;
}