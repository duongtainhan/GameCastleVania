#include "Tilemap.h"
#include<fstream>
using namespace std;

Tilemap::Tilemap()
{
}
Tilemap::~Tilemap()
{
}
int Tilemap::getWorldHeight()
{
	return tileRows * tileHeight;
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
void Tilemap::render(Camera * camera)
{
	// Chiều cao của world
	int mapHeight = tileRows * tileHeight;

	// Tính các tile đang cắt camera
	int tileLeft, tileRight, tileTop, tileBottom;

	// tileLeft là vị trí cột camera cắt bên trái
	tileLeft = camera->getleft() / tileWidth;

	// tileRight là vị trí cột camera cắt bên phải
	tileRight = camera->getRight() / tileWidth;

	// tileTop là vị trí dòng camera cắt bên trên
	tileTop = (mapHeight - camera->getTop()) / tileHeight;

	// tileBottom là vị trí dòng camera cắt bên dưới
	tileBottom = (mapHeight - camera->getBottom()) / tileHeight;

	// Điều kiện ràng buộc chống lỗi vượt quá index
	if (tileLeft < 0)
	{
		tileLeft = 0;
	}

	if (tileTop < 0)
	{
		tileTop = 0;
	}

	if (tileRight >= tileColumns)
	{
		tileRight = tileColumns - 1;
	}

	if (tileBottom >= tileRows)
	{
		tileBottom = tileRows - 1;
	}

	// Duyệt các tile cắt camera và vẽ chúng lên màn hình
	for (size_t rowIndex = tileTop; rowIndex <= tileBottom; rowIndex++)
	{
		for (size_t columnIndex = tileLeft; columnIndex <= tileRight; columnIndex++)
		{
			// Tính vị trí world của tile
			int xWorldOfTile = columnIndex * tileWidth;
			int yWorldOfTile = mapHeight - rowIndex * tileHeight;

			// Tính vị trí view của tile
			float xViewOfTile = 0;
			float yViewOfTile = 0;

			camera->convertWorldToView(xWorldOfTile, yWorldOfTile, xViewOfTile, yViewOfTile);

			/* tìm hình chữ nhật là vị trí của tile trong tilesheet */
			int tileValue = matrix[rowIndex][columnIndex];

			int xTileInTileSheet = tileWidth * (tileValue % tilesheetColumns);
			int yTileInTileSheet = tileHeight * (tileValue / tilesheetColumns);
			int widthTileInTilesheet = tileWidth;
			int heightTileInTilesheet = tileHeight;

			RECT rectCrop;
			SetRect(&rectCrop,
				xTileInTileSheet, // left
				yTileInTileSheet, // top
				xTileInTileSheet + widthTileInTilesheet, // right
				yTileInTileSheet + heightTileInTilesheet); // bottom
														   // Vẽ tile lên màn hình tại vị trí view
			tilesheet->Render(xViewOfTile, yViewOfTile, 0, 0, &rectCrop);
		}
	}
}
