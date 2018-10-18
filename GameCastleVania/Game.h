#pragma once
#include "GameTexture.h"
#include "List.h"
#include "GameTime.h"
#include "FrameAnimation.h"
#include "Animation.h"
#include "Sprite.h"
#include "Tilemap.h"
#include "World.h"

class Game
{
	static Game* instance;
	
	World* world;
public:
	Game();
	~Game();

	static Game* getInstance();

	//Các hàm khởi tạo, cập nhật và vẽ game
	void GameInit();
	void GameUpdate(float dt);
	void GameRender();
};