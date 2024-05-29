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
#include <QtXml>
#include <QFile>
#include<QString>
#include <QDebug>
#include <vector>
#include "../../service/aStarAlgorithm/Node.h"
using namespace std;
#define N 10 // 地图的阶数
extern vector<QString> mapNames;//地图名
extern QDomDocument doc;//存地图信息
extern int const next_position[4][2];// 定义方向
extern priority_queue<Node> open; // 优先队列，就相当于open表
extern bool close[N][N]; // 访问情况记录，close列表
extern int valueF[N][N]; // 记录每个节点对应的F值
extern int pre[N][N][2]; // 存储每个节点的父节点
extern int startMap[N][N];
extern int endMap[N][N];
extern int finishSelect;
void InitIfoma();//初始化信息
//void PrintPath(int x1, int y1);
void resetMap();
bool isValidNode(int x, int y, int xx, int yy);//判断结点是否为空
void readXML();

#endif //_REPARAM_H_

