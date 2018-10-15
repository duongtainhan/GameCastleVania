#pragma once
#include "GameTexture.h"
#include "List.h"

class Game
{
	//Danh sách các vị trí khung hình cần vẽ để tạo animation
	List<RECT*> rectAnimations;
	//Khung hình hiện tại
	int currentIndex;

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