#pragma once
#include "Rect.h"

// Đây là lớp Rect có thể di chuyển
class MovableRect :
	public Rect
{
	// Độ dời di chuyển của đối tượng
	float dx, dy;
public:
	virtual void setDx(float dx);
	virtual void setDy(float dy);
	float getDx();
	float getDy();
	// Phương thức di chuyển
	void goX();
	void goY();
	//Phương thức xử lý va chạm
	virtual void onCollision(MovableRect* other, float collisionTime, int nx, int ny);
	//Chặn di chuyển khi phát hiện va chạm
	void preventMovementWhenCollision(float collisionTime,int nx,int ny);
	MovableRect();
	~MovableRect();
};
