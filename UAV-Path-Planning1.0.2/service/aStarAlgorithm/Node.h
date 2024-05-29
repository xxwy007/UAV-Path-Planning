/**
* @Anthor: xxwy007
* @Date: 2024/03/08 15:19:25
*/
#ifndef _NODE_H_
#define _NODE_H_

/**
*@class:结点
*/
class Node
{
public:
	int x, y;    // 节点所在位置
	int F, G, H; // G:从起点开始，沿着产的路径，移动到网格上指定方格的移动耗费。
	// H:从网格上那个方格移动到终点B的预估移动耗费，使用曼哈顿距离。
	// F = G + H
	Node(){}
	Node(int a, int b) { x = a, y = b; }
	// 重载操作符，使优先队列以F值大小为标准维持堆
	bool operator<(const Node& a) const
	{
		return F == a.F ? G > a.G : F > a.F;
	}
};


#endif //_NODE_H_
