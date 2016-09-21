#include "stdafx.h"
#include "BackgroundImage.h"


BackgroundImage::BackgroundImage(const char* filename, Size texture_size, Size frame_size, float x, float y )
	:Image(filename, texture_size, x, y)
{
	m_camera_y = 400.0f;
	m_frame_width = frame_size.x;
	m_frame_height = frame_size.y;
}


BackgroundImage::~BackgroundImage()
{
}

float BackgroundImage::camera_x() {
	return m_camera_x;
}

void BackgroundImage::camera_x(float x) {
	this->m_camera_x = x;
}