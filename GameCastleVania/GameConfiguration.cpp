#pragma once
#include "GameConfiguration.h"

#include "GameConfiguration.h"

//Khởi tạo giá trị
map<const char*, double>* GameConfiguration::globalsConfigurationDouble = 0;
map<const char*, const char*>* GameConfiguration::globalsConfigurationString = 0;

//Khởi tạo Contructor
GameConfiguration::GameConfiguration()
{
}

GameConfiguration::~GameConfiguration()
{
}

/*
WHAT IS BACKBUFFER?
- Backbuffer: Để ngăn chặn sự nhấp nháy trong hiệu ứng thì cách tốt nhất là vẽ ở off-screen texture
- Sau khi vẽ hoàn thành thì nó được đưa lên màn hình
*/

//Khởi tạo hàm
// :: kế thừa, giống như extends trong android
double GameConfiguration::GetConfiguration(const char * key)
{
	if (globalsConfigurationDouble == 0)
	{
		globalsConfigurationDouble = new map<const char*, double>();

		//Thiết lập kích thước cửa sổ cho game: window_width, window_height
		globalsConfigurationDouble->insert(pair<const char*, double>("window_width", 512));
		globalsConfigurationDouble->insert(pair<const char*, double>("window_height", 448));

		//Thiết lập kích thước cho BackBuffer: backbuffer_width, backbuffer_height
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_width", 256));
		globalsConfigurationDouble->insert(pair<const char*, double>("backbuffer_height", 224));

		//Thiết lập fps cho game
		globalsConfigurationDouble->insert(pair<const char*, double>("fps", 70));
	}
	//Xét các giá trị trên ở 1 key, tương tự như index trong mảng, nhằm xác định vị trí và phân biệt
	return globalsConfigurationDouble->at(key);
}

const char * GameConfiguration::GetConfigurationString(const char * key)
{
	if (globalsConfigurationString == 0)
	{
		globalsConfigurationString = new map<const char*, const char*>();

		//Thiết lập tiêu đề cửa sổ game và tên game
		globalsConfigurationString->insert(pair<const char*, const char*>("window_title", "Game Castle Vania"));
		globalsConfigurationString->insert(pair<const char*, const  char*>("window_class", "win_game"));
	}
	//Xét các giá trị trên ở 1 key
	return globalsConfigurationString->at(key);
}
