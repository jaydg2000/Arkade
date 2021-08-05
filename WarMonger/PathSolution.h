#pragma once
#include <queue>
#include <Point.h>

using namespace std;
using namespace arkade;

class PathSolution
{
public:
	PathSolution();
	~PathSolution();

	Point							pop_point();
	void							add_point(uint32_t x, uint32_t y);
	void							clear();
	bool							empty();

private:
	queue<Point>					_points;
};

