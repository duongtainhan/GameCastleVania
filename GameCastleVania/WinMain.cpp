#include<Windows.h>
#include"WindowGame.h"
#include"GameDirectX.h"
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

#include "GameTexture.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WindowGame::getInstance()->initHandleWindows(hInstance, nCmdShow);
	srand(time(NULL));

	// GetTickCount: lấy thời gian hiện tại của hệ thống
	// Tính thời gian bắt đầu
	DWORD startTime = GetTickCount();

	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	// Tính thời gian cho mỗi frame
	DWORD timePerFrame = 1000 / GLOBALS_D("fps");

	//Khởi tạo hình
	GameTexture gameTexture;
	gameTexture.Init("file/viet_nam.png", D3DCOLOR_ARGB(255,218,37,29));

	//Vòng lặp game
	while (msg.message != WM_QUIT)
	{
		// now là thời gian hiện tại
		DWORD now = GetTickCount();

		/* nếu khoảng thời gian kể từ lúc bắt đầu tới bây giờ lớn hơn thời gian cho mỗi frame thì khởi tạo lại thời gian bắt đầu
		là bây giờ*/
		DWORD deltaTime = now - startTime;
		if (deltaTime >= timePerFrame)
		{
			startTime = now;
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			float time = deltaTime / 1000.0f;

			//Bắt đầu vẽ lên backbuffer
			GameDirectX::getInstance()->BeginGraphics();

			RECT viewRect;
			SetRect(&viewRect, 66, 30, 182, 147);
			//Vẽ hình
			gameTexture.Render(9, 9,&viewRect);
			//Kết thúc vẽ lên backbuffer
			GameDirectX::getInstance()->EndGraphics();
			//Vẽ backbuffer lên màn hình
			GameDirectX::getInstance()->PresentBackBuffer();
		}
	}
	return nCmdShow;
}
