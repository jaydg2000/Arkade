#pragma once
#include <Image.h>
#include <ArkadeTypes.h>
#include <Size.h>

using namespace arkade;

class BackgroundImage : public Image
{
public:
	BackgroundImage(const char* filename, Size texture_size, Size frame_size, float x, float y);
	~BackgroundImage();

	float						camera_x();
	void						camera_x(float);

private:
	float						m_camera_x;
	float						m_camera_y;
	uint32_t					m_frame_width;
	uint32_t					m_frame_height;
};

