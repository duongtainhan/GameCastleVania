#include "World.h"
#include"Camera.h"

#include "Zombie.h"

void World::Init(const char * tilesheetPath, const char * matrixPath, const char * objectsPath)
{
	// Khởi tạo tilemap 
	tilemap.Init(tilesheetPath, matrixPath);

	int worldHeight = tilemap.getWorldHeight();

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

	Init(tilesheetString.c_str(), matrixPathString.c_str(), objectPathString.c_str());
}

void World::update(float dt)
{
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		// Cập nhật đối tượng
		allObjects[i]->update(dt);
	}
	// Di chuyển camera để thấy toàn cảnh
	Camera::getInstance()->moveX(1);
}

void World::render()
{
	tilemap.render(Camera::getInstance());
	for (size_t i = 0; i < allObjects.Count; i++)
	{
		// Vẽ đối tượng
		allObjects[i]->render(Camera::getInstance());
	}
}

World::World()
{
}
World::~World()
{
}