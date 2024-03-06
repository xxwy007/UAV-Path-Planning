#include "aStarAlgorithm/astar.h"
#include "blockallocator/blockallocator.h"
int main()
{
	char maps[10][10] =
	{
		{ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 1, 1, 1, 0, 1, 0, 1, 0, 1 },
		{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
		{ 0, 1, 0, 1, 1, 1, 1, 1, 0, 1 },
		{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 },
		{ 1, 1, 0, 0, 1, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 },
	};

	// ËÑË÷²ÎÊý
	AStar::Params param;
	param.width = 10;
	param.height = 10;
	param.corner = false;
	param.start = AStar::Vec2(0, 0);
	param.end = AStar::Vec2(9, 9);
	param.can_pass = [&](const AStar::Vec2& pos)->bool
		{
			return maps[pos.y][pos.x] == 0;
		};

	// Ö´ÐÐËÑË÷
	BlockAllocator allocator;
	AStar algorithm(&allocator);
	auto path = algorithm.find(param);
}