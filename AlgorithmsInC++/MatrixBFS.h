#pragma once
#define MAXV 100


class MatrixBFS
{
public:
	int m[MAXV + 1][MAXV + 1];
	void initGraph(bool);
	void InsertEdge(int, int);
	void BFS(int);
	void InitSearch();
	bool discovered[MAXV];
	bool processed[MAXV];
	int nvertices;
	int nedges;
	bool directed;
};
