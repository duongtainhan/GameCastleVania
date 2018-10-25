#pragma once
#include "Tilemap.h"
#include "SpriteManager.h"
#include "BaseObject.h"
#include "CollisionTypeCollide.h"

class World
{
	// Dùng tilemap để vẽ map
	Tilemap tilemap;

	// Lưu tất cả objects vào list
	List<BaseObject*> allObjects;
	// Danh sách collisionTypeCollide
	List<CollisionTypeCollide*> collisionTypeCollides;
	// Danh sách object được phân loại theo collision_type
	List<List<BaseObject*>*> objectCategories;

public:
	void Init(const char* tilesheetPath, 
		const char* matrixPath, 
		const char* objectsPath,
		const char* collisionTypeCollidePath);
	void Init(const char* folderPath);
	// Cập nhật các đối tượng trong game
	void update(float dt);
	// Vẽ các đối tượng trong game
	void render();
	World();
	~World();
};
