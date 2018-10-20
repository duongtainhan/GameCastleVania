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
	bool keyLeftDown, keyRightDown, keyUpDown, keyDownDown, keyJumpPress;
	// Kiểm tra key bên trái có được nhấn
	keyLeftDown = KEY::getInstance()->isLeftDown;
	// Kiểm tra key bên phải có được nhấn */
	keyRightDown = KEY::getInstance()->isRightDown;
	keyUpDown = KEY::getInstance()->isUpDown;
	keyDownDown = KEY::getInstance()->isDownDown;
	// Kiểm tra key jump có được nhấn
	keyJumpPress = KEY::getInstance()->isJumpPress;

	float vx = GLOBALS_D("player_vx");

	// Nếu vật đứng trên sàn
	if (getIsOnGround())
	{
		// Nếu nhấn key trái
		if (keyLeftDown)
		{
			setVx(-vx);
		}
		// Nếu nhấn key phải
		else if (keyRightDown)
		{
			setVx(vx);
		}
		else
		{
			setVx(0);
		}
		// Nếu đứng trên sàn và nhấn key (x) - jump thì nhân vật sẽ nhảy
		if (keyJumpPress)
			setVy(100);
	}
	PhysicsObject::onUpdate(dt);
}

void Player::onCollision(MovableRect * other, float collisionTime, int nx, int ny)
{
	// Ngăn chặn di chuyển
	preventMovementWhenCollision(collisionTime, nx, ny);
	PhysicsObject::onCollision(other, collisionTime, nx, ny);
}

Player::Player()
{
	setSprite(SPR(SPRITE_INFO_SIMON));
}

Player::~Player()
{
}
