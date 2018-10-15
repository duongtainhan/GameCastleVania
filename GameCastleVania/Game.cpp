#include "Game.h"

Game* Game::instance = 0;
Game* Game::getInstance()
{
	if (instance == 0)
		instance = new Game();
	return instance;
}

Game::Game()
{
}
Game::~Game()
{
}
void Game::GameInit()
{
	//Khởi tạo danh sách vị trí khung hình

	//Thêm khung hình 1 vào list
	RECT* r1 = new RECT();
	SetRect(r1, 16, 80, 48, 120);
	rectAnimations._Add(r1);
	//Thêm khung hình 2 vào list
	RECT* r2 = new RECT();
	SetRect(r2, 68, 80, 100, 120);
	rectAnimations._Add(r2);
	//Xét vị trí khung hình hiện tại là 0
	currentIndex = 0;
	//Xét vị trí đường dẫn của hình ảnh, và màu trong suốt
	image.Init("file/Animation.png", D3DCOLOR_XRGB(109, 167, 131));
}

void Game::GameUpdate()
{
	//Animation đang có 2 khung hình: 1 hoặc 0
	//Nếu vị trí là 0 thì vẽ khung hình 1
	//Ngược lại nếu là 1 thì vẽ khung hình 0

	currentIndex++;
	if (currentIndex > 1)
	{
		currentIndex = 0;
	}
}

void Game::GameRender()
{
	image.Render(9, 9, rectAnimations.at(currentIndex));
}