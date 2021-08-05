#include "PathFinder.h"

PathFinder::PathFinder()
{
}

PathFinder::~PathFinder()
{
}

PathSolution* PathFinder::find_path(TiledMap* map, uint32_t start_x, uint32_t start_y, uint32_t end_x, uint32_t end_y, TerrainCosts* costs)
{
    _dest_x = end_x;
    _dest_y = end_y;
    _path_completed = false;
    _add_point(end_x, end_y);
    _mark_count_map(end_x, end_y, 0);
    _mark_count_map(start_x, start_y, 999);
    _map = map;
    _costs = costs;
    while (!_points.empty() || !_path_completed)
    {
        Point point = _points.front();
        _points.pop();
        uint32_t x = point.x;
        uint32_t y = point.y;
        int count = _count_map[x][y] + 1;
        _evaluate_neighbors(x, y, count);
    }

    return _create_solution(start_x, start_y);
}

void PathFinder::_add_point(uint32_t x, uint32_t y)
{
    _points.push(Point(x,y));
}

void PathFinder::_mark_count_map(uint32_t x, uint32_t y, int32_t count)
{
    _count_map[x][y] = count;
}

void PathFinder::_evaluate_neighbors(uint32_t x, uint32_t y, int count)
{
    // x - -
    // - . -
    // - - - 
    if (_is_valid_map_location(x-1, y-1))
    {
        _mark_and_add_point_to_evaluate(x-1, y-1, count);
    }

    // - x -
    // - . -
    // - - - 
    if (_is_valid_map_location(x, y - 1))
    {
        _mark_and_add_point_to_evaluate(x, y - 1, count);
    }

    // - - x
    // - . -
    // - - - 
    if (_is_valid_map_location(x + 1, y - 1))
    {
        _mark_and_add_point_to_evaluate(x + 1, y - 1, count);
    }

    // - - -
    // - . X
    // - - - 
    if (_is_valid_map_location(x + 1, y))
    {
        _mark_and_add_point_to_evaluate(x + 1, y, count);
    }

    // - - -
    // - . -
    // - - X 
    if (_is_valid_map_location(x + 1, y + 1))
    {
        _mark_and_add_point_to_evaluate(x + 1, y + 1, count);
    }

    // - - -
    // - . -
    // - X - 
    if (_is_valid_map_location(x, y + 1))
    {
        _mark_and_add_point_to_evaluate(x, y + 1, count);
    }

    // - - -
    // - . -
    // X - - 
    if (_is_valid_map_location(x - 1, y + 1))
    {
        _mark_and_add_point_to_evaluate(x - 1, y + 1, count);
    }

    // - - -
    // X . -
    // - - - 
    if (_is_valid_map_location(x - 1, y))
    {
        _mark_and_add_point_to_evaluate(x - 1, y, count);
    }

}

bool PathFinder::_is_valid_map_location(uint32_t x, uint32_t y)
{
    // location is not on the map.
    if (x < 0 || x >= MAP_WIDTH)
        return false;
    if (y < 0 || y >= MAP_HEIGHT)
        return false;

    uint16_t tile_type_id = _map->tile_at_xy(x,y);
    int32_t terrain_cost = _costs->cost(tile_type_id);

    // the tile cannot be occupied by this unit type.
    if (terrain_cost < 0)
        return false;

    // the tile has already been evaluated or it's the destination.
    if (_count_map[x][y] < 0)
        return false;

    return true;
}

void PathFinder::_mark_and_add_point_to_evaluate(uint32_t x, uint32_t y, int32_t count)
{
    if (_count_map[x][y] == 999)
    {
        _path_completed = true;
        while(!_points.empty())
            _points.pop();
        return;
    }
    _mark_count_map(x, y, count);
    _add_point(x,y);
}

PathSolution* PathFinder::_create_solution(uint32_t start_x, uint32_t start_y)
{
    PathSolution* solution = new PathSolution();
    Point last_point = _add_next_path_point(start_x, start_y, 999, solution);
    
    while(last_point.x != _dest_x && last_point.y != _dest_y)
    {
        uint32_t x = last_point.x;
        uint32_t y = last_point.y;
        last_point = _add_next_path_point(x, y, _count_map[x][y], solution);
    }

    return solution;
}

Point PathFinder::_add_next_path_point(uint32_t x, uint32_t y, int weight, PathSolution* solution)
{
    int32_t best_move_x = -1;
    int32_t best_move_y = -1;

    // x - -
    // - . -
    // - - - 
    if (_is_path_point_valid(x - 1, y - 1, weight))
    {
        best_move_x = x-1;
        best_move_y = y-1;
    }

    // - x -
    // - . -
    // - - - 
    if (_is_path_point_valid(x, y - 1, weight))
    {
        best_move_x = x;
        best_move_y = y-1;
    }

    // - - x
    // - . -
    // - - - 
    if (_is_path_point_valid(x + 1, y - 1, weight))
    {
        best_move_x = x+1;
        best_move_y = y-1;
    }

    // - - -
    // - . X
    // - - - 
    if (_is_path_point_valid(x + 1, y, weight))
    {
        best_move_x = x+1;
        best_move_y = y;
    }

    // - - -
    // - . -
    // - - X 
    if (_is_path_point_valid(x + 1, y + 1, weight))
    {
        best_move_x = x+1;
        best_move_y = y+1;
    }

    // - - -
    // - . -
    // - X - 
    if (_is_path_point_valid(x, y + 1, weight))
    {
        best_move_x = x;
        best_move_y = y+1;
    }

    // - - -
    // - . -
    // X - - 
    if (_is_path_point_valid(x - 1, y + 1, weight))
    {
        best_move_x = x-1;
        best_move_y = y+1;
    }

    // - - -
    // X . -
    // - - - 
    if (_is_path_point_valid(x - 1, y, weight))
    {
        best_move_x = x-1;
        best_move_y = y;
    }

    if (best_move_x >= 0 && best_move_y >= 0)
    {
        solution->add_point(best_move_x, best_move_y);        
    }

    return Point(best_move_x, best_move_y);
}

bool PathFinder::_is_path_point_valid(uint32_t x, uint32_t y, int weight)
{
    if (!_is_valid_map_location(x,y))
        return false;

    int path_point_weight = _count_map[x][y];
    return path_point_weight <= weight;
}


