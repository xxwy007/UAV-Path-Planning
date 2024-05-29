#include "aStar.h"
int AStar::Manhattan(int x, int y, int x1, int y1)
{
	return (abs(x - x1) + abs(y - y1)) * 10;
}


void AStar::setNum(int x0, int y0, int x1, int y1)
{
	this->x0 = x0;
	this->y0 = y0;
	this->x1 = x1;
	this->y1 = y1;
}

void AStar::Astar()
{
	// 起点加入open列表
	Node node(x0, y0);
	node.G = 0;
	node.H = Manhattan(x0, y0, x1, y1);
	node.F = node.G + node.H;
	valueF[x0][y0] = node.F;
	open.push(node);

	while (!open.empty())
	{
		Node node_current = open.top();                   //取优先队列头元素，即周围单元格中代价最小的点
		open.pop();                                       //从open列表中移除
		close[node_current.x][node_current.y] = true;     // 访问该点，加入close列表
		if (node_current.x == x1 && node_current.y == y1) // 到达终点
			break;

		// 遍历node_top周围的4个位置，如果是next_position有8，那么就需要遍历周围8个点
		for (int i = 0; i < 4; i++)
		{
			Node node_next(node_current.x + next_position[i][0], node_current.y + next_position[i][1]); // 创建一个node_top周围的点
			// 该节点坐标合法 且没有被访问
			if (isValidNode(node_next.x, node_next.y, node_current.x, node_current.y) && !close[node_next.x][node_next.y])
			{
				// 计算从起点并经过node_top节点到达该节点所花费的代价
				node_next.G = node_current.G + int(sqrt(pow(next_position[i][0], 2) + pow(next_position[i][1], 2)) * 10);
				// 计算该节点到终点的曼哈顿距离
				node_next.H = Manhattan(node_next.x, node_next.y, x1, y1);
				// 从起点经过node_top和该节点到达终点的估计代价
				node_next.F = node_next.G + node_next.H;

				// node_next.F < valueF[node_next.x][node_next.y] 说明找到了更优的路径，进行更新
				// valueF[node_next.x][node_next.y] == 0 说明该节点还未加入open表中，则加入
				if (node_next.F < valueF[node_next.x][node_next.y] || valueF[node_next.x][node_next.y] == 0)
				{
					// 保存该节点的父节点
					pre[node_next.x][node_next.y][0] = node_current.x;
					pre[node_next.x][node_next.y][1] = node_current.y;
					valueF[node_next.x][node_next.y] = node_next.F; // 修改该节点对应的valueF值
					open.push(node_next);
				}
			}
		}
	}
}

//void AStar::InitIfoma()
//{
//	fill(close[0], close[0] + N * N, false);    // 将visit数组赋初值false
//	fill(valueF[0], valueF[0] + N * N, 0);      // 初始化F全为0
//	fill(pre[0][0], pre[0][0] + N * N * 2, -1); // 路径同样赋初值-1
//}
