
#include <vector>

#include "Box.h"

#pragma once
class World
{

public:
	World(float x, float y);
	World(std::vector<Box> boxList);
	~World(void);
	void addBox(Box b);
	float getX() const;
	float getY() const;
	float getHeight() const;
	float getWidth() const;
	std::vector<Box>& getBoxList();

private:
	float x_position, y_position, height, width;
	std::vector<Box> boxList;
};

