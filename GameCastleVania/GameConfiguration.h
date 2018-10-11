#pragma once
#include<map>
using namespace std;

#define GLOBALS_D(name) GameConfiguration::GetConfiguration(name)
#define GLOBALS_S(name) GameConfiguration::GetConfigurationString(name)

/*
Các khái niệm về con trỏ:
- const : đặt địa chỉ của biến là vùng nhớ hằng, giá trị bên trong vùng nhớ đó sẽ không bị thay đổi
- const: giúp đảm bảo an toàn dữ liệu cho biến
- Khi biến của const được khởi tạo giá trị, thì sẽ không được gán được giá trị khác, mọi tác động đến vùng nhớ
đều bị ngăn chặn
*/

class GameConfiguration
{
	static map<const char*, double>* globalsConfigurationDouble;
	static map<const char*, const char*>* globalsConfigurationString;
public:

	static double GetConfiguration(const char* key);
	static const char* GetConfigurationString(const char* key);
	GameConfiguration();
	~GameConfiguration();
};
