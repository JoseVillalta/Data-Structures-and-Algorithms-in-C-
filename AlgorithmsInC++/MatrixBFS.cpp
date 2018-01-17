#include "MatrixBFS.h"
#include <queue>

using namespace std;

void MatrixBFS::initGraph(bool directed)
{
	for (int i = 1; i < MAXV; i++)
	{
		for (int j = 1; j < MAXV; j++)
		{
			m[i][j] = 0;
		}
	}
}

void MatrixBFS::InsertEdge(int x, int y)
{
	m[x][y] = 1;
	if (!directed)
		m[y][x] = 1;
}

void MatrixBFS::BFS(int start)
{
	queue<int> q;
	q.push(start);
	discovered[start] = true;
	while (!q.empty())
	{
		int p = q.front();
		q.pop();
		for (int i = 1; i < MAXV; i++)
		{
			if (m[p][i] == 1)
			{
				if (!discovered[i])
				{
					discovered[i] = true;
					q.push(i);

				}
			}
		}
	}
}

void MatrixBFS::InitSearch()
{
	for (int i = 0; i < MAXV; i++)
	{
		discovered[i] = false;
		processed[i] = false;
	}
}

