#pragma once
#include <Windows.h>

class GameTime
{
	//Thời gian bắt đầu
	DWORD startTime;
	//Khoảng thời gian delay
	DWORD tickPerFrame;
	//Khoảng thời gian kể từ lúc bắt đầu đến hiện tại
	DWORD deltaTime;
public:
	GameTime(void);
	~GameTime(void);
	DWORD getStartTime();
	void setStartTime(DWORD startTime);
	DWORD getTickPerFrame();
	void setTickPerFrame(DWORD tickPerFrame);
	void init(DWORD tickPerFrame);
	DWORD getDeltaTime();
	void setDeltaTime(DWORD deltaTime);
	GameTime(DWORD tickPerFrame);
	//Đến thời điểm hiện tại
	virtual bool atTime();
};