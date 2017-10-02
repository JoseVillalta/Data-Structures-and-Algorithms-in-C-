#pragma once
#include "stdafx.h"
#include "Graph.h"
#define MAX_INT 100000


class DijkstrasAlgorithm
{
public:
    Graph * m_g;
    bool intree[MAXV + 1];
    int distance[MAXV + 1];
    int parent[MAXV + 1];
    
    DijkstrasAlgorithm();
    void shortest_path(int start);
    void insert_edge(int x, int y, int weight, bool directed);
    void print_path(int start, int end);
};