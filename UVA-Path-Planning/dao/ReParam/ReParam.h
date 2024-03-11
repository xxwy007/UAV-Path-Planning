/**
* @Anthor: xxwy007
* @Date: 2024/03/08 19:09:19
*/
#ifndef _REPARAM_H_
#define _REPARAM_H_
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <vector>
#include "../service/aStarAlgorithm/Node.h"
using namespace std;
#define N 10 // 地图的阶数
extern int const next_position[4][2];// 定义方向
extern priority_queue<Node> open; // 优先队列，就相当于open表
extern bool close[N][N]; // 访问情况记录，close列表
extern int valueF[N][N]; // 记录每个节点对应的F值
extern int pre[N][N][2]; // 存储每个节点的父节点
extern int map[N][N];

void InitIfoma();
//void PrintPath(int x1, int y1);
bool isValidNode(int x, int y, int xx, int yy);


#endif //_REPARAM_H_

