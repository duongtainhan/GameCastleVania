#pragma once
#include"List.h"
#include"Sprite.h"

#define SPR SpriteManager::getSprite

// Tạo 1 sprite info để lưu thông tin của các sprite
enum SPRITE_INFO
{
	// Đối tượng không có hình ảnh ta sẽ đặt số âm
	SPRITE_INFO_GROUND = -1,
	// Đối tượng có hình ảnh ta sẽ đặt số dương
	SPRITE_INFO_SIMON = 0,
	SPRITE_INFO_ZOMBIE = 1,

	SPRITE_COUNT
};

class SpriteManager
{
	// Lưu tất cả sprite vào 1 list
	List<Sprite*> sprites;

	static SpriteManager* instance;
public:
	static SpriteManager* getInstance();

	// dùng để lấy sprite từ spriteManager
	static Sprite* getSprite(int spriteInfo);

	SpriteManager();
	~SpriteManager();
};