#pragma once
#include "stdafx.h"
#include "Graph.h"

class PrimsAlgorithm
{
public:
    Graph * m_g;
    bool intree[MAXV + 1];
    int distance[MAXV + 1];
    int parent[MAXV + 1];
    void prim(int start);
    void InitGraph(bool directed);
    void InsertEdge(int x, int y, int weight, bool directed);

};