#include "MovableRect.h"


void MovableRect::onCollision(MovableRect* other, float collisionTime, int nx, int ny)
{
}
void MovableRect::preventMovementWhenCollision(float collisionTime, int nx, int ny)
{
	// Dời vật M về sát vật S
	if (nx != 0)
	{
		// Nếu vật va chạm theo phương x
		setDx(collisionTime*getDx());
	}
	if (ny != 0)
	{
		// Nếu vật va chạm theo phương y
		setDy(collisionTime*getDy());
	}
}

MovableRect::MovableRect()
{
	dx = 0;
	dy = 0;
}

void MovableRect::setCollisionType(COLLISION_TYPE collisionType)
{
	this->collisionType = collisionType;
}
COLLISION_TYPE MovableRect::getCollisionType()
{
	return collisionType;
}
void MovableRect::setDx(float dx)
{
	this->dx = dx;
}
void MovableRect::setDy(float dy)
{
	this->dy = dy;
}
float MovableRect::getDx()
{
	return dx;
}
float MovableRect::getDy()
{
	return dy;
}

void MovableRect::goX()
{
	Rect::moveX(dx);
}

void MovableRect::goY()
{
	Rect::moveY(dy);
}

MovableRect::~MovableRect()
{
}