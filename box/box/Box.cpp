#include "Box.h"


Box::Box(float x, float y, float side)
{
	this->x_position = x;
	this->y_position = y;
	this->side = side;
	this->direction = -1;
}

void Box::setXY(float x, float y)
{
	this->x_position = x;
	this->y_position = y;
}

float Box::getX()
{
	return this->x_position;
}

float Box::getY()
{
	return this->y_position;
}

float Box::getSide()
{
	return this->side;
}

float Box::left() const {
	return x_position;
}

float Box::right() const {
	return x_position + side;
}

float Box::top() const {
	return y_position + side;
}

float Box::bottom() const {
	return y_position;
}

int Box::getDirection()
{
	return this->direction;
}

void Box::invertDirection()
{
	this->direction = -this->direction;
}

void Box::stop()
{
	direction = 0;
}

void Box::setLoose()
{
	direction = -1;
}