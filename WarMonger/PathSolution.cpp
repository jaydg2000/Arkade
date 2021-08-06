#include "PathSolution.h"

PathSolution::PathSolution()
{
}

PathSolution::~PathSolution()
{
}

void PathSolution::add_point(uint32_t x, uint32_t y)
{
	_points.push_back(Point(x,y));
}

void PathSolution::clear()
{
	_points.clear();
}

bool PathSolution::empty()
{
	return _points.empty();
}

list<Point>* PathSolution::points()
{
	return &_points;
}

Point PathSolution::pop_point()
{
	Point point = _points.front();
	_points.pop_front();
	return point;
}
