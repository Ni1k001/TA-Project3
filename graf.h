#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

class graf
{
private:
	int v;
	int** d;
	int** path;

public:
	graf(int v, vector<pair<pair<int, int>, int>> e);
	~graf();

	void FloydWarshall();
	void printPath(int s, int k);

	int getPathCost(int s, int k);
};

graf::graf(int v, vector<pair<pair<int, int>, int>> e)
{
	this->v = v;

	d = new int* [v];
	path = new int* [v];

	for (int i = 0; i < v; i++)
	{
		d[i] = new int[v];
		path[i] = new int[v];

		for (int j = 0; j < v; j++)
			d[i][j] = INT_MAX / 2;
	}

	for (int i = 0; i < e.size(); i++)
	{
		d[e[i].first.first][e[i].first.second] = e[i].second;
		path[e[i].first.first][e[i].first.second] = e[i].first.first;
	}
}

graf::~graf()
{
	for (int i = 0; i < v; i++)
	{
		delete[] d[i];
		delete[] path[i];
	}

	delete[] d;
	delete[] path;
}

void graf::FloydWarshall()
{
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			printf("d[%d][%d] = %d\n", i, j, d[i][j]);

	for (int p = 0; p < v; p++)
	{
		for (int s = 0; s < v; s++)
		{
			for (int k = 0; k < v; k++)
			{
				if (d[s][p] + d[p][k] < d[s][k])
				{
					d[s][k] = d[s][p] + d[p][k];
					path[s][k] = path[p][k];
				}
			}
		}
	}
	printf("\n");
	for (int i = 0; i < v; i++)
		for (int j = 0; j < v; j++)
			printf("d[%d][%d] = %d\n", i, j, d[i][j]);

}

void graf::printPath(int s, int k)
{
	if (path[s][k] == s)
	{
		printf("%d -> %d (%d)\t", s, k, d[s][k]);
		return;
	}

	printPath(s, path[s][k]);
	printf("%d -> %d (%d)\t", path[s][k], k, d[path[s][k]][k]);
}

int graf::getPathCost(int s, int k)
{
	return d[s][k];
}