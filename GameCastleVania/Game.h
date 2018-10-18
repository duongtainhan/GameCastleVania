#pragma once
#include "GameTexture.h"
#include "List.h"
#include "GameTime.h"
#include "FrameAnimation.h"
#include "Animation.h"
#include "Sprite.h"

class Game
{
	static Game* instance;
	//Khung hình hiện tại
	int currentIndex;
	//Animation hiện tại
	int currentAnimation;
	//Sprite
	Sprite sprite;
	
	//Khởi tạo GameTime dùng để làm chậm lại animation
	GameTime timeDelay;
public:
	Game();
	~Game();

	static Game* getInstance();

	//Các hàm khởi tạo, cập nhật và vẽ game
	void GameInit();
	void GameUpdate();
	void GameRender();
};