#pragma once
#include "GameTexture.h"
#include "List.h"
#include "GameTime.h"
#include "FrameAnimation.h"
#include "Animation.h"

class Game
{
	//Khung hình hiện tại
	int currentIndex;
	
	//Khởi tạo GameTime dùng để làm chậm lại animation
	GameTime timeDelay;

	static Game* instance;

	//danh sach cac vi tri khung
	List<FrameAnimation*> rectAnimations;
	//Buc hinh animation
	GameTexture mario;
	Animation animation;

public:
	Game();
	~Game();

	static Game* getInstance();

	//Các hàm khởi tạo, cập nhật và vẽ game
	void GameInit();
	void GameUpdate();
	void GameRender();
};