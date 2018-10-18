#include "Tilemap.h"
#include<fstream>
using namespace std;

Tilemap::Tilemap()
{
}
Tilemap::~Tilemap()
{
}
void Tilemap::Init(const char * tilesheetPath, const char * matrixPath)
{
	// Khởi tạo tilesheet
	tilesheet = new GameTexture();
	tilesheet->Init(tilesheetPath);

	// Khởi tạo matrix
	fstream fs(matrixPath);

	// Đọc các giá trị
	fs >> tileRows >> tileColumns >> tileWidth >> tileHeight >> tilesheetColumns;

	// Khởi tạo ma trận
	matrix = new int*[tileRows];

	for (size_t rowIndex = 0; rowIndex < tileRows; rowIndex++)
	{
		matrix[rowIndex] = new int[tileColumns];
		for (size_t columnIndex = 0; columnIndex < tileColumns; columnIndex++)
		{
			// Đọc thông số ma trận tile file
			fs >> matrix[rowIndex][columnIndex];
		}
	}

}

void Tilemap::Init(const char * folderPath)
{
	// Đường dẫn tilesheet và matrix
	string folderPathString = (string)folderPath;
	string tilesheetString = folderPathString;
	tilesheetString.append("/tilesheet.png");
	string matrixPathString = folderPathString;
	matrixPathString.append("/matrix.dat");

	// Khởi tạo bằng phương thức trên
	Init(tilesheetString.c_str(), matrixPathString.c_str());
}