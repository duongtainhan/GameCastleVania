#include "Player.h"

Player * Player::instance = 0;
Player * Player::getInstance()
{
	if (instance == 0)
	{
		instance = new Player();
	}
	return instance;
}

void Player::onUpdate(float dt)
{
	bool keyLeftDown, keyRightDown, keyUpDown, keyDownDown;
	keyLeftDown = KEY::getInstance()->isLeftDown;
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;

	int v = 2;
	if (keyLeftDown)
	{
		setDx(-v);
	}
	else if (keyRightDown)
	{
		setDx(v);
	}
	else
	{
		setDx(0);
	}
	if (keyUpDown)
	{
		setDy(v);
	}
	else if (keyDownDown)
	{
		setDy(-v);
	}
	else
	{
		setDy(0);
	}
	PhysicsObject::onUpdate(dt);
}

void Player::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	// Ngăn chặn di chuyển
	preventMovementWhenCollision(collisionTime, nx, ny);
}

Player::Player()
{
	setSprite(SPR(SPRITE_INFO_SIMON));
}

Player::~Player()
{
}
