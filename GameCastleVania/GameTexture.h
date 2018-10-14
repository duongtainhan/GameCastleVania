#pragma once
#include"GameDirectX.h"

enum TEXTURE_DIRECTION
{
	TEXTURE_DIRECTION_LEFT = -1,
	TEXTURE_DIRECTION_RIGHT = 1
};

/* Tạo texture
filepath: duong dan file hinh anh
transColor: mau can trong suot
*/
/* Vẽ texture
filepath: duong dan file hinh anh
transColor: mau can trong suot
*/

class GameTexture
{

private:
	LPDIRECT3DTEXTURE9 m_image;
public:

	int Width, Height;
	TEXTURE_DIRECTION direction;

	GameTexture(const char* filepath, D3DCOLOR transColor = 0);
	
	void Init(const char* filepath, D3DCOLOR transColor = 0);
	GameTexture() {}

	void Render(int x, int y, RECT *r = 0);
	~GameTexture();
};
