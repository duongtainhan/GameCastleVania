#pragma once
#include "MovableRect.h"
#include"Sprite.h"
#include"GameTime.h"
#include"Camera.h"

// Đây là đối tượng của game. Kế thừa lại lớp đối tượng có thể chuyển động
class BaseObject :
	public MovableRect
{
	Sprite* sprite;
	// Animation hiện tại và frame index hiện tại
	int animationIndex, frameIndex;

	// Dùng để làm chậm animation
	GameTime animationGameTime;

	// Dừng animation
	bool pauseAnimation;
	// Kiểm tra xem frame cuối cùng đã hoàn thành hay chưa
	bool isLastFrameAnimationDone;

	//Hướng mặt của đối tượng
	TEXTURE_DIRECTION direction;
public:
	void setSprite(Sprite*sprite);
	Sprite* getSprite();

	bool getPauseAnimation();
	virtual void setPauseAnimation(bool pauseAnimation);

	bool getIsLastFrameAnimationDone();
	virtual void setIsLastFrameAnimationDone(bool isLastFrameAnimationDone);

	// Khởi tạo đối tượng đọc từ file
	virtual void onInitFromFile(ifstream& fs, int mapHeight);

	// Update đối tượng
	virtual void onUpdate(float dt);
	// Cập nhật của đối tượng sau mỗi lần vẽ lại
	void update(float dt);
	// Vẽ đối tượng
	virtual void render(Camera* camera);

	int getAnimation();
	void setAnimation(int animation);
	int getFrameAnimation();
	void setFrameAnimation(int frameAnimarion);

	TEXTURE_DIRECTION getDirection();
	void setDirection(TEXTURE_DIRECTION direction);

	BaseObject();
	~BaseObject();
};
