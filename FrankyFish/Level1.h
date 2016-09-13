#pragma once

#include <Level.h>

using namespace arkade;

class Level1 : public Level
{
public:
	Level1();
	~Level1();

protected:
	virtual void					on_setup();

private:
	Scene*							m_ptr_scene_franky_first_swim;
};

