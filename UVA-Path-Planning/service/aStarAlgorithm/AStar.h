/**
* @Anthor: xxwy007
* @Date: 2024/03/08 15:17:43
*/
#ifndef _ASTAR_H_
#define _ASTAR_H_
#include "../../dao/ReParam.h"
/**
*@class:
* 
*/

class AStar
{
	Node node;
	int x0, y0,x1, y1;

public:
	AStar(int x0, int y0, int x1, int y1);

	void Astar();

	int Manhattan(int x, int y, int x1, int y1);

};


#endif //_ASTAR_H_