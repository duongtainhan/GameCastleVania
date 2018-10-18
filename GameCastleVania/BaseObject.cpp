#include "BaseObject.h"

void BaseObject::setSprite(Sprite * sprite)
{
	this->sprite = sprite;
}

Sprite * BaseObject::getSprite()
{
	return this->sprite;
}

bool BaseObject::getPauseAnimation()
{
	return pauseAnimation;
}

void BaseObject::setPauseAnimation(bool pauseAnimation)
{
	this->pauseAnimation = pauseAnimation;
}

bool BaseObject::getIsLastFrameAnimationDone()
{
	return isLastFrameAnimationDone;
}

void BaseObject::setIsLastFrameAnimationDone(bool isLastFrameAnimationDone)
{
	this->isLastFrameAnimationDone = isLastFrameAnimationDone;
}

void BaseObject::onInitFromFile(ifstream& fs, int mapHeight)
{
	int collisionType, x, y, width, height;
	// Đọc collision type x y width height từ file
	fs >> collisionType >> x >> y >> width >> height;
	// y của đối tượng trong file là tọa độ hướng từ trên xuống
	// y của game chúng ta làm thì gốc tọa độ bên dưới nên ta chuyển nó về cho đúng tọa độ logic
	y = mapHeight - y;
	// Khởi tạo x y width height cho đối tượng
	set(x, y, width, height);
}

void BaseObject::update(float dt)
{
	// Di chuyển đối tượng trước khi cập nhật
	goX();
	goY();

	setIsLastFrameAnimationDone(false);

	// nếu đối tượng này có hình và không bị pauseAnimation thì ta cập nhật animation cho nó
	if (!pauseAnimation && getSprite() != NULL)
	{
		if (animationGameTime.atTime())
		{
			// Cập nhật animation cho đối tượng
			sprite->update(animationIndex, frameIndex);
			if (frameIndex == 0)
			{
				// Nếu frame cuối đã chạy thì sau khi cập nhật frameIndex sẽ là 0
				setIsLastFrameAnimationDone(true);
			}
		}
	}

	onUpdate(dt);
}

void BaseObject::onUpdate(float dt)
{
	// Mặc định sẽ cho chạy animation
	setPauseAnimation(false);
}

void BaseObject::render(Camera* camera)
{
	float xView, yView;
	// Tính tọa độ view để vẽ đối tượng lên màn hình
	camera->convertWorldToView(getX(), getY(), xView, yView);
	// Vẽ đối tượng lên màn hình
	sprite->render(xView, yView, animationIndex, frameIndex);
}

BaseObject::BaseObject()
{
	setSprite(NULL);
	animationGameTime.init(GLOBALS_D("object_animation_time_default"));
}

BaseObject::~BaseObject()
{
}