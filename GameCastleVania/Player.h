#pragma once
#include "PhysicsOject.h"
#include "SpriteManager.h"
#include "KEY.h"
#include "PhysicsOject.h"

class Player :
	public PhysicsObject
{
	static Player* instance;
public:
	static Player* getInstance();
	void onUpdate(float dt) override;
	void onCollision(MovableRect* other, float collisionTime, int nx, int ny) override;
	Player();
	~Player();
};

