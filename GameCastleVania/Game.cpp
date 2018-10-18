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
	FrameAnimation* r1 = new FrameAnimation();
	SetRect(r1, 1, 6, 1+21, 6+28);
	r1->anchorX = 8;
	r1->anchorY = 0;
	animation.frames._Add(r1);
	//Thêm khung hình 2 vào list
	FrameAnimation* r2 = new FrameAnimation();
	SetRect(r2, 27, 6, 27+16, 6+28);
	r2->anchorX = 4;
	r2->anchorY = 0;
	animation.frames._Add(r2);
	FrameAnimation* r3 = new FrameAnimation();
	SetRect(r3, 46, 6, 46+23, 6+28);
	r3->anchorX = 4;
	r3->anchorY = 0;
	animation.frames._Add(r3);
	//Xét vị trí khung hình hiện tại là 0
	currentIndex = 0;
	//Xét vị trí đường dẫn của hình ảnh, và màu trong suốt
	mario.Init("file/mario.png", D3DCOLOR_XRGB(255, 255, 255));

	//Làm chậm animation
	timeDelay.init(1369);
}

void Game::GameUpdate()
{
	if (timeDelay.atTime())
	{
		currentIndex++;
		if (currentIndex > 2)
		{
			currentIndex = 0;
		}
	}
}

void Game::GameRender()
{
	auto frame = animation.frames.at(currentIndex);
	mario.Render(10,10,frame->anchorX,frame->anchorY,frame);
}