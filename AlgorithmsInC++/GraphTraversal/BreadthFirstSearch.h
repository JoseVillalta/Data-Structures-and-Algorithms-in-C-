#pragma once
#include<iostream>
#include "Graph.h"
#include "EdgeNode.h"

using namespace std;
class BFS
{
public:
    Graph * m_g;
    bool discovered[MAXV + 1];
    bool processed[MAXV + 1];
    int parent[MAXV + 1];

    void InitGraph(bool directed);
    void InsertEdge(int x, int y, bool directed);
    void BreadthFirstSearch(int start);
    void PrintGraph();
    void ProcessVertex(int x);
    void ProcessEdge(int x, int y);
};