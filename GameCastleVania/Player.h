#pragma once
#include "PhysicsOject.h"
#include "SpriteManager.h"
#include "KEY.h"

class Player :
	public PhysicsObject
{
	static Player* instance;
public:
	static Player* getInstance();
	void onUpdate(float dt) override;
	Player();
	~Player();
};

