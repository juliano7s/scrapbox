
#include "World.h"
#include "Box.h"

#pragma once
class PhysicSystem
{
public:
	PhysicSystem(World &w);
	void calcBoxPositions();
	bool checkCollision(Box &b1, Box &b2);
	Box* checkBoxOnPosition(float x, float y);
	void dropDraggedBox();
	void dragBox(Box *box);
	Box* getDraggedBox();
	void moveDraggedBox(Box *box, float x, float y);
private:
	float gravity;
	World& world;
	Box *draggedBox;
};

