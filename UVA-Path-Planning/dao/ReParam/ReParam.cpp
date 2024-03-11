#include "ReParam.h"
int const next_position[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };// 定义方向
priority_queue<Node> open; // 优先队列，就相当于open表
bool close[N][N]; // 访问情况记录，close列表
int valueF[N][N]; // 记录每个节点对应的F值
int pre[N][N][2]; // 存储每个节点的父节点
int map[N][N] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				 {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
				 {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
				 {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
				 {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
				 {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
				 {0, 0, 1, 0, 1, 0, 1, 0, 0, 0},
				 {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
				 {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
				 {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

void InitIfoma()
{
	fill(close[0], close[0] + N * N, false);    // 将visit数组赋初值false
	fill(valueF[0], valueF[0] + N * N, 0);      // 初始化F全为0
	fill(pre[0][0], pre[0][0] + N * N * 2, -1); // 路径同样赋初值-1
}

bool isValidNode(int x, int y, int xx, int yy)
{
	if (x < 0 || x >= N || y < 0 || y >= N)
		return false; // 判断边界
	if (map[x][y] == 1)
		return false; // 判断障碍物
	// 两节点成对角型且它们的公共相邻节点存在障碍物，在8方向时用
	if (x != xx && y != yy && (map[x][yy] == 1 || map[xx][y] == 1))
		return false;
	return true;
}

//void PrintPath(int x1, int y1)
//{
//	if (pre[x1][y1][0] == -1 || pre[x1][y1][1] == -1)
//	{
//		cout << "no path to get" << endl;
//		return;
//	}
//	int x = x1, y = y1;
//	int a, b;
//	while (x != -1 || y != -1)
//	{
//		map[x][y] = 2; // 将可行路径上的节点赋值为2
//		a = pre[x][y][0];
//		b = pre[x][y][1];
//		x = a;
//		y = b;
//	}
//	// ' '表示未经过的节点， '#'表示障碍物， '@'表示可行节点
//	string s[3] = { "  ", " #", " @" };
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < N; j++)
//			cout << s[map[i][j]];
//		cout << endl;
//	}
//}