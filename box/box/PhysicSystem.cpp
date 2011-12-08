	
#include <vector>
#include <iostream>

#include "PhysicSystem.h"

PhysicSystem::PhysicSystem(World &w) : world(w)
{
	this->world = w;
	this->gravity = 0.0015f;
}

void PhysicSystem::calcBoxPositions()
{
	std::vector<Box>::iterator it1;	
	std::vector<Box> &boxList = this->world.getBoxList();

	for (it1 = boxList.begin(); it1 != boxList.end(); it1++) {
		Box& b1 = *it1;
		float oldx = b1.getX();
		float oldy = b1.getY();

		if (&b1 != this->draggedBox)
			b1.setXY(oldx, b1.getY() + b1.getDirection()*this->gravity);

		bool collided = false;

		std::vector<Box>::iterator it2;

		for (it2 = boxList.begin(); it2 != boxList.end(); it2++) {
			Box& b2 = *it2;
			if (&b1 != &b2) {
				collided = checkCollision(b1,b2);
								
				if (collided) {
					//b1.invertDirection();
					b1.stop();
					collided = false;
				}	
			}				
		}

		if (b1.getY() <= this->world.getY())
			collided = true;

		if (b1.getY() + b1.getSide() >= this->world.getHeight())
			collided = true;
		
		if (collided) {
			//b1.setXY(oldx, oldy);
			//b1.invertDirection();
			b1.stop();
			collided = false;
		}	

		
	}
}

bool PhysicSystem::checkCollision(Box &b1, Box &b2)
{
	
	if (!(b1.top() < b2.bottom() || b1.bottom() > b2.top())) {
		if (b1.left() > b2.left() && b1.left() <= b2.right())
			return true;

		if (b1.right() < b2.right() && b1.right() >= b2.left())
			return true;
	}

	if (!(b1.right() < b2.left() || b1.left() > b2.right())) {
		if (b1.bottom() > b2.bottom() && b1.bottom() <= b2.top())
			return true;
		
		if (b1.top() < b2.top() && b1.top() >= b2.bottom())
			return true;
	}

	return false;
}

Box* PhysicSystem::checkBoxOnPosition(float x, float y) {
	
	std::vector<Box>::iterator it1;	
	std::vector<Box> &boxList = this->world.getBoxList();

	for (it1 = boxList.begin(); it1 != boxList.end(); it1++) {
		Box& b1 = *it1;
		
		if (x >= b1.left() && x <= b1.right()) {
			if (y >= b1.bottom() && y <= b1.top()) {
				return &b1;
			}
		}
	}

	return NULL;
}

void PhysicSystem::dropDraggedBox() {
	if (draggedBox != NULL) {
		draggedBox->setLoose();
		draggedBox = NULL;
	}
}

void PhysicSystem::dragBox(Box *box) {
	if (draggedBox == NULL) {
		draggedBox = box;
	}
}

Box* PhysicSystem::getDraggedBox() {
	return draggedBox;
}
