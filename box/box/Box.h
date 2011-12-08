
#include <Windows.h>
#include <gl\GL.h>

#pragma once
class Box
{

public:
	Box(float x, float y, float side);
	void setXY(float x, float y);
	float getX();
	float getY();
	float getSide();
	float left() const;
	float right() const;
	float top() const;
	float bottom() const;
	int getDirection();
	void invertDirection();
	void stop();
	void setLoose();
	bool collided;
private:
	float x_position;
	float y_position;
	float side;
	int direction;	
};


