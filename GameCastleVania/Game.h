#pragma once
#include "GameTexture.h"

class Game
{
	//Hình cần vẽ lên
	GameTexture image;
	//Vị trí của hình
	int x, y;

	static Game* instance;
public:
	Game();
	~Game();

	static Game* getInstance();

	//Các hàm khởi tạo, cập nhật và vẽ game
	void GameInit();
	void GameUpdate();
	void GameRender();
};