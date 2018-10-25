#pragma once
#include "PhysicsOject.h"

class Zombie :
	public PhysicsObject
{
public:
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Zombie();
	~Zombie();
};
