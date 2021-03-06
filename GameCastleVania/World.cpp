﻿#include "World.h"
#include"Camera.h"

#include "Zombie.h"
#include "KEY.h"
#include "Player.h"
#include "Collision.h"

void World::Init(const char * tilesheetPath, 
	const char * matrixPath, 
	const char * objectsPath,
	const char * collisionTypeCollidePath)
{
	//Khởi tạo player
	Player::getInstance()->set(52, 350, 16, 30);

	// Khởi tạo tilemap 
	tilemap.Init(tilesheetPath, matrixPath);

	int worldHeight = tilemap.getWorldHeight();
	// Khởi tạo phân loại đối tượng
	for (size_t i = 0; i < COLLISION_TYPE_COUNT; i++)
	{
		objectCategories._Add(new List<BaseObject*>());
	}
	// Khởi tạo đối tượng
	int objectCount;
	ifstream fs(objectsPath);
	fs >> objectCount;
	for (size_t i = 0; i < objectCount; i++)
	{
		BaseObject* obj;
		int id;
		// Đọc id đối tượng
		fs >> id;
		switch (id)
		{

		case SPRITE_INFO_ZOMBIE:
			obj = new Zombie();
			break;

		default:
			obj = new BaseObject();
			break;
		}
		// Đọc thông số của đối tượng
		obj->onInitFromFile(fs, worldHeight);
		if (id >= 0)
		{
			// Nếu id đối tượng không âm tức đối tượng có sprite ta gán sprite cho nó
			obj->setSprite(SPR(id));
		}
		// Thêm đối tượng vào danh sách
		allObjects._Add(obj);
		// Thêm object vào từng đối tượng
		objectCategories.at(obj->getCollisionType())->_Add(obj);
	}

	// Đọc collisionType collide
	int numberOfCollisionTypeCollides = 0;
	ifstream fsColli(collisionTypeCollidePath);
	fsColli >> numberOfCollisionTypeCollides;
	for (size_t i = 0; i < numberOfCollisionTypeCollides; i++)
	{
		int collisionType1, collisionType2;
		fsColli >> collisionType1 >> collisionType2;
		CollisionTypeCollide* collisionTypeCollide = new CollisionTypeCollide();
		collisionTypeCollide->COLLISION_TYPE_1 = (COLLISION_TYPE)collisionType1;
		collisionTypeCollide->COLLISION_TYPE_2 = (COLLISION_TYPE)collisionType2;
		collisionTypeCollides._Add(collisionTypeCollide);
	}
}

void World::Init(const char * folderPath)
{
	// Tìm đường dẫn tilesheet và matrix object
	string folderPathString = (string)folderPath;
	string tilesheetString = folderPathString;
	tilesheetString.append("/tilesheet.png");
	string matrixPathString = folderPathString;
	matrixPathString.append("/matrix.dat");
	string objectPathString = folderPathString;
	objectPathString.append("/objects.dat");
	string collisionTypeCollidePath = folderPathString;
	collisionTypeCollidePath.append("/collision_type_collides.dat");
	Init(tilesheetString.c_str(), 
		matrixPathString.c_str(), 
		objectPathString.c_str(),
		collisionTypeCollidePath.c_str());
}

void World::update(float dt)
{
	KEY::getInstance()->update();
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		// Cập nhật đối tượng
		allObjects[i]->update(dt);
		//Kiểm tra va chạm
		Collision::CheckCollision(Player::getInstance(), allObjects[i]);
	}
	// Xét va chạm cho các loại đối tượng với nhau
	for (size_t i = 0; i < collisionTypeCollides.size(); i++)
	{
		COLLISION_TYPE col1 = collisionTypeCollides.at(i)->COLLISION_TYPE_1;
		COLLISION_TYPE col2 = collisionTypeCollides.at(i)->COLLISION_TYPE_2;

		// Danh sách đối tượng thuộc collision type 1
		List<BaseObject*>* collection1 = objectCategories.at(col1);
		// Danh sách đối tượng thuộc collision type 2
		List<BaseObject*>* collection2 = objectCategories.at(col2);

		for (size_t i1 = 0; i1 < collection1->size(); i1++)
		{
			for (size_t i2 = 0; i2 < collection2->size(); i2++)
			{
				// Cho xét va chạm của đối tượng dựa vào 1 cặp collisionType trong CollisionTypeCollide
				Collision::CheckCollision(collection1->at(i1), collection2->at(i2));
			}
		}

	}

	Player::getInstance()->update(dt);
	Camera::getInstance()->update();
}

void World::render()
{
	tilemap.render(Camera::getInstance());
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		// Vẽ đối tượng
		allObjects[i]->render(Camera::getInstance());
	}
	Player::getInstance()->render(Camera::getInstance());
}

World::World()
{
}
World::~World()
{
}