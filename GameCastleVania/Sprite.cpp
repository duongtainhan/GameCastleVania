#include "Sprite.h"
#include <fstream>
using namespace std;

Sprite::Sprite()
{
}

Sprite::~Sprite()
{
}
void Sprite::InitFromFile(const char * imagePath, const char * infoPath)
{
	image = new GameTexture();
	ifstream fs(infoPath);
	// Trước tiên đọc argb và khởi tạo bức hình trước
	// Bỏ 2 line và đọc a r g b
	ignoreLineIfstream(fs, 2);
	int a, r, g, b;
	fs >> a >> r >> g >> b;

	// Khởi tạo image
	image->Init(imagePath, D3DCOLOR_ARGB(a, r, g, b));

	// Từ cuối dòng đó ta enter xuống 2 lần để đọc số 2 của animation count
	ignoreLineIfstream(fs, 2);
	int animationCount;
	fs >> animationCount;

	// tiếp theo ta duyệt vòng lặp để khởi tạo animation
	for (size_t i = 0; i < animationCount; i++)
	{
		Animation* animation = new Animation();
		// Từ cuối số 2 ta enter 6 lần để đọc frameCount là số 3
		ignoreLineIfstream(fs, 6);
		// Đọc frame count
		int frameCount;
		fs >> frameCount;
		// Ta enter 3 dòng để bắt đầu đọc frame
		ignoreLineIfstream(fs, 3);
		for (size_t frameIndex = 0; frameIndex < frameCount; frameIndex++)
		{
			// Khởi tạo frame
			FrameAnimation* frame = new FrameAnimation();
			int x, y, width, height, anchorX, anchorY;
			fs >> x >> y >> width >> height >> anchorX >> anchorY;
			SetRect(frame, x, y, x + width, y + height);
			frame->anchorX = anchorX;
			frame->anchorY = anchorY;
			// Thêm frame vào animation
			animation->frames._Add(frame);
		}
		// Thêm animation vào sprite
		animations._Add(animation);
	}

}

void Sprite::update(int animationIndex, int& frameIndex)
{
	// Cập nhật bằng cách chuyển frame của animation
	frameIndex = animations.at(animationIndex)->NextFrame(frameIndex);
}

void Sprite::render(int x, int y, int animationIndex, int frameIndex)
{
	// Vẽ hình tại animation index và frame index
	auto animation = animations.at(animationIndex);
	auto frame = animation->frames.at(frameIndex);
	image->Render(x, y, frame->anchorX, frame->anchorY, frame);
}
