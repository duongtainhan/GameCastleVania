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
	//Đọc sprite từ file
	sprite.InitFromFile("file/mario.png", "file/test_mario.info.dat");
	//Xét vị trí khung hình hiện tại là 0
	currentIndex = 0;
	currentAnimation = 0;
	//Làm chậm animation
	timeDelay.init(999);
}

void Game::GameUpdate()
{
	if (timeDelay.atTime())
	{
		sprite.update(currentAnimation, currentIndex);
	}
}

void Game::GameRender()
{
	sprite.render(10, 10, currentAnimation, currentIndex);
}