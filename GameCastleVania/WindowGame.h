#pragma once

/*
Các thuộc tính trong DirectX:
- HINSTANCE: là 1 biến để đại diện cho game khi được hệ điều hành chạy
- HWND: Mỗi game sẽ có thể chứa nhiều cửa sổ, mỗi cửa sổ cần có 1 định danh riêng để phân biệt
- LPDIRECT3D9: là một Direct3D Object. Biến này cần thiết cho việc khởi tạo Device để thao tác vẽ trong Game
- LPDIRECT3DDEVICE9: dùng để lưu thông tin của Device sử dụng thao tác vẽ trong chương trình
- Hàm callback: dùng để lắng nghe các sự kiện của cửa sổ Game khi người dùng tương tác
Xác định hướng đi:
Game trải qua 3 giai đoạn chính gồm: Khởi Tạo (init), Chạy (run) và thoát (exit)
1. Khởi tạo các thuộc tính cần thiết cho cửa sổ
2. Khởi tạo môi trường lập trìn DirectX
3. Khởi tạo thiết bị DirectX
4. Tạo nơi để đặt tất cả các hàm khởi tạo cần thiết trước lúc chương trình chạy
5. Tạo nơi update Game
6. Tạo nơi giải phóng các tài nguyên cần được giải phóng trước lúc chương trình thoát
*/

#include <Windows.h>
#include "GameConfiguration.h"

class WindowGame
{
	HWND hWnd;
	static WindowGame* instance;

public:
	WindowGame();
	~WindowGame();
	static WindowGame* getIntance();
	static LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);
	void initHandleWindows(HINSTANCE hInstance, int nCmdShow);
	HWND getHandleWindow();
};