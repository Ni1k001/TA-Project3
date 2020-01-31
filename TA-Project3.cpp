#include <iostream>
#include <stdio.h>

#include "graf.h"

int main()
{
	
	int v = 5;
	vector<pair<pair<int, int>, int>> e = { pair<pair<int, int>, int>(make_pair(0, 1), 5),
											pair<pair<int, int>, int>(make_pair(0, 2), 4),
											pair<pair<int, int>, int>(make_pair(0, 3), 8),
											pair<pair<int, int>, int>(make_pair(1, 0), -4),
											pair<pair<int, int>, int>(make_pair(1, 2), -2),
											pair<pair<int, int>, int>(make_pair(1, 4), 5),
											pair<pair<int, int>, int>(make_pair(2, 3), 5),
											pair<pair<int, int>, int>(make_pair(2, 4), 2),
											pair<pair<int, int>, int>(make_pair(3, 0), -1),
											pair<pair<int, int>, int>(make_pair(3, 1), 2),
											pair<pair<int, int>, int>(make_pair(3, 4), -1),
											pair<pair<int, int>, int>(make_pair(4, 2), 4),
											pair<pair<int, int>, int>(make_pair(4, 3), 2)
											};

	graf g(v, e);
	g.FloydWarshall();
	printf("\n\n\n");
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
		{
			printf("%d->%d   (%d)\t\t", i, j, g.getPathCost(i, j));
			g.printPath(i, j);
			printf("\n");
		}
}