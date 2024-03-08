#include "aStarAlgorithm/AStar.h"
#include "aStarAlgorithm/Node.h"
#include "aStarAlgorithm/ReParam.h"

int main()
{
	InitIfoma();
	//  // Æðµã // ÖÕµã
	int x0 = 5, y0 = 4, x1 = 8, y1 = 6;
	if (!isValidNode(x0, y0, x0, y0))
	{
		printf("Invalid input.\n");
		return 0;
	}
	AStar* aStar = new AStar(x0, y0, x1, y1);
	aStar->Astar();
	PrintPath(x1, y1);
	return 0;
}