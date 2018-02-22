#pragma once
#include "Graph.h"
#define NMAX 100

class PathBuilder
{
public:
    int GetAllPaths(Graph * g, int s, int t);
    int ConstructCandidates(int a[], int k, int n, int c[]);
	void Backtrack(int a[], int k, int start, int end);
    bool IsSolution(int a[], int k, int t);
    void ProcessSolution();
    void MakeMove();
    void UnMakeMove();
    Graph * g;
    int pathCount;
};