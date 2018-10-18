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
	tilemap = new Tilemap();
	//Thư mục chứa tilemap---demo
	tilemap->Init("Res/TileMap");
	Camera::getInstance()->set(
		0,
		400,
		// Kích thước của camera bằng với kích thước của backbuffer
		GLOBALS_D("backbuffer_width"),
		GLOBALS_D("backbuffer_height"));

	// Di chuyển camera theo phương phải 1 px
	Camera::getInstance()->setDx(1);
}
void Game::GameUpdate()
{
	// Di chuyển camera theo phương x
	Camera::getInstance()->goX();
}

void Game::GameRender()
{
	// Vẽ tile lên game
	tilemap->render(Camera::getInstance());
}