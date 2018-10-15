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
	image.Init("file/viet_nam.png");
	x = 9;
	y = 9;
}

void Game::GameUpdate()
{
	x++;
}

void Game::GameRender()
{
	image.Render(x, y);
}