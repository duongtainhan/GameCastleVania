#include "SpriteManager.h"

SpriteManager * SpriteManager::instance = 0;
SpriteManager * SpriteManager::getInstance()
{
	if (instance == 0)
	{
		instance = new SpriteManager();
	}
	return instance;
}
Sprite * SpriteManager::getSprite(int spriteInfo)
{
	return getInstance()->sprites[spriteInfo];
}
SpriteManager::SpriteManager()
{
	// Thêm SPRITE_COUNT phần tử cho list sprite
	for (size_t i = 0; i < SPRITE_COUNT; i++)
	{
		sprites._Add(new Sprite());
	}

	// Thêm sprite ở đây
	// Thiết lập sprite cho con zoombie
	sprites[SPRITE_INFO_ZOMBIE]->InitFromFile("Res/Objects/Zombie/zombie.png", "Res/Objects/Zombie/zombie.info.dat");
	sprites[SPRITE_INFO_SIMON]->InitFromFile("Res/Objects/Simon/image.png", "Res/Objects/Simon/simon.info.dat");
}
SpriteManager::~SpriteManager()
{
}