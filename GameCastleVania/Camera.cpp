#include "Camera.h"
#include "Player.h"
#include<d3dx9.h>

Camera * Camera::instance = 0;
Camera * Camera::getInstance()
{
	if (instance == 0)
	{
		instance = new Camera();
	}
	return instance;
}

void Camera::update()
{
	// Mặc định cho camera đứng yên, chỉ khi player chạy nó mới chạy theo
	setDx(0);

	Player* player = Player::getInstance();
	// Nếu player đang chạy sang trái (player->getDx()<0) và phần giữa camera nằm bên phải hoặc phần giữa player
	if (player->getDx() < 0 && getMidX() > player->getMidX())
	{
		// Thì cho camera chạy theo player (về bên trái)
		setDx(player->getDx());
	}
	// Nếu player đang chạy sang phải (player->getDx()>0) và phần giữa camera nằm bên trái hoặc phần giữa player
	if (player->getDx() > 0 && getMidX() < player->getMidX())
	{
		// Thì cho camera chạy theo player (về bên phải)
		setDx(player->getDx());
	}

	// Cập nhật vị trí camera
	goX();
	goY();
}

void Camera::convertWorldToView(float xWorld, float yWorld, float & xView, float & yView)
{
	// Ma trận biến đổi world to view
	D3DXMATRIX matrixWorldToView;
	D3DXMatrixIdentity(&matrixWorldToView);
	matrixWorldToView._22 = -1;
	matrixWorldToView._41 = -this->getX();
	matrixWorldToView._42 = this->getY();

	// Nhân ma trận đó với xWorld yWorld ta được xView yView
	D3DXVECTOR3 pos3(xWorld, yWorld, 1);
	D3DXVECTOR4 MatrixResult;
	D3DXVec3Transform(&MatrixResult, &pos3, &matrixWorldToView);

	xView = MatrixResult.x;
	yView = MatrixResult.y;
}

Camera::Camera()
{
}


Camera::~Camera()
{
}
