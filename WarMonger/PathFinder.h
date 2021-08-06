#pragma once
#include <ArkadeTypes.h>
#include <queue>
#include "PathSolution.h"
#include "TiledMap.h"
#include "TerrainCosts.h"

class PathFinder
{
public:
	PathFinder();
	~PathFinder();

	int32_t							count_at(uint32_t x, uint32_t y);
	PathSolution*					find_path(TiledMap* map, uint32_t start_x, uint32_t start_y, uint32_t end_x, uint32_t end_y, TerrainCosts* costs);
private:
	TiledMap*						_map;
	int32_t							_count_map[MAP_WIDTH][MAP_HEIGHT];
	queue<Point>					_points;
	TerrainCosts*					_costs;
	bool							_path_completed;
	uint32_t						_dest_x, _dest_y;

	void							_add_point(uint32_t x, uint32_t y);
	void							_mark_count_map(uint32_t x, uint32_t y, int32_t count);
	void							_evaluate_neighbors(uint32_t x, uint32_t y, int count);
	bool							_is_valid_map_location(uint32_t x, uint32_t y);
	void							_mark_and_add_point_to_evaluate(uint32_t x, uint32_t y, int32_t count);
	PathSolution*					_create_solution(uint32_t start_x, uint32_t start_y);
	Point							_find_next_path_point(uint32_t x, uint32_t y, int weight);
	bool							_is_path_point_valid(uint32_t x, uint32_t y, int weight);
	void							_clear_count_map();
};

