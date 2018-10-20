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
	/* kiểm tra key bên trái có được nhấn */
	keyLeftDown = KEY::getInstance()->isLeftDown;
	/* kiểm tra key bên phải có được nhấn */
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;

	float vx = GLOBALS_D("player_vx");

	/* nếu vật đứng trên sàn */
	if (getIsOnGround())
	{
		if (keyLeftDown)
		{
			setVx(-vx);
		}
		else if (keyRightDown)
		{
			setVx(vx);
		}
		else
		{
			setVx(0);
		}
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
