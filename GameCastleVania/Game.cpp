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
	// Khởi tạo tilemap
	world = new World();
	//Thư mục chứa tilemap---demo
	world->Init("Res/TileMap");
	Camera::getInstance()->set(
		0,
		400,
		// Kích thước của camera bằng với kích thước của backbuffer
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));
}
void Game::GameUpdate(float dt)
{
	world->update(dt);
}

void Game::GameRender()
{
	world->render();
}