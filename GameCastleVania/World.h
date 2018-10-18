#pragma once
#include"Tilemap.h"
#include"SpriteManager.h"
#include"BaseObject.h"

class World
{
	// Dùng tilemap để vẽ map
	Tilemap tilemap;

	// Lưu tất cả objects vào list
	List<BaseObject*> allObjects;

public:
	void Init(const char* tilesheetPath, const char* matrixPath, const char* objectsPath);
	void Init(const char* folderPath);
	// Cập nhật các đối tượng trong game
	void update(float dt);
	// Vẽ các đối tượng trong game
	void render();
	World();
	~World();
};
