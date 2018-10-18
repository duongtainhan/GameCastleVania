#pragma once
#include "GameTexture.h"
#include "Camera.h"

class Tilemap
{
	// Chiều rộng tile
	int tileWidth;
	// Chiều dài tile
	int tileHeight;
	// Số lượng dòng trong matrix
	int tileRows;
	// Số lượng cột trong matrix
	int tileColumns;
	// Số lượng cột trong tilesheet
	int tilesheetColumns;

	// Tilesheet
	GameTexture* tilesheet;

	// Ma trận tile
	int** matrix;
public:
	//Vẽ tilemap bằng camera
	void render(Camera* camera);

	// tilesheetPath: đường dẫn tilesheet
	// matrixPath : đường dẫn file ma trận
	
	void Init(const char* tilesheetPath, const char* matrixPath);
	// folderPath : đường dẫn thư mục chứa ma trận và tilesheet
	void Init(const char* folderPath);
	Tilemap();
	~Tilemap();
};
