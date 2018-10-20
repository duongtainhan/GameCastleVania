#pragma once
#include <Windows.h>

class KEY
{
public:
	bool
		isLeftDown,
		isRightDown,
		isUpDown,
		isDownDown,
		isJumpDown,
		isPreviousJumpDown,
		isJumpPress;

	static KEY* instance;
	static KEY* getInstance();

	void update();

	KEY();
	~KEY();
};
