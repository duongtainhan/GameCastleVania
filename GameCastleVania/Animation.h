#pragma once
#include"List.h"
#include"FrameAnimation.h"

class Animation
{
public:
	Animation();
	~Animation();

	/* Danh sách frame */
	List<FrameAnimation*> frames;
	/* Chuyển sang frame kế khi truyền vào current frame */
	int NextFrame(int currentFrame);
};
