#include "PathSolution.h"

PathSolution::PathSolution()
{
}

PathSolution::~PathSolution()
{
}

void PathSolution::add_point(uint32_t x, uint32_t y)
{
	_points.push(Point(x,y));
}

void PathSolution::clear()
{
	while(!_points.empty())
		_points.pop();
}

bool PathSolution::empty()
{
	return _points.empty();
}

Point PathSolution::pop_point()
{
	Point point = _points.front();
	_points.pop();
	return point;
}
