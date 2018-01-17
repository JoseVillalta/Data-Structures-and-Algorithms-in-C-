#pragma once
#include "Graph.h"
#define NMAX 100

class PathBuilder
{
public:
    int GetAllPaths(Graph * g, int s, int t);
    void ConstructCandidates(int a[], int k, int n, int c[], int * ncandidates);
    void Backtrack(int a[], int k, int n);
    bool IsSolution(int a[], int k, int t);
    void ProcessSolution();
    void MakeMove();
    void UnMakeMove();
    Graph * g;
    int pathCount;
};