#include "KEY.h"

DWORD getKeyChar(char keyChar)
{
	return ((int)keyChar - 'a') + 0x41;
}

KEY * KEY::instance = 0;
KEY * KEY::getInstance()
{
	if (instance == 0)
		instance = new KEY();
	return instance;
}

void KEY::update()
{
	isUpDown = GetAsyncKeyState(VK_UP);
	isDownDown = GetAsyncKeyState(VK_DOWN);
	isLeftDown = GetAsyncKeyState(VK_LEFT);
	isRightDown = GetAsyncKeyState(VK_RIGHT);
	isPreviousJumpDown = isJumpDown;
	isJumpDown = GetAsyncKeyState(getKeyChar('x'));
	isJumpPress = (!isPreviousJumpDown && isJumpDown);
}

KEY::KEY()
{
}

KEY::~KEY()
{
}
