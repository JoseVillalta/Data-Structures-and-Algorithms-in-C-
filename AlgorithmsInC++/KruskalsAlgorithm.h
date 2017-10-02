#pragma once
#include "stdafx.h"
#include "Graph.h"
#include <vector>
#define SET_SIZE 1000

using namespace std;

typedef struct
{
    int p[SET_SIZE + 1];
    int size[SET_SIZE + 1];
    int n;
}m_set_union;

typedef struct
{
    int x;
    int y;
    int weight;
}edge_pair;

class KruskalsAlgorithm
{
public:
    Graph * m_g;
    m_set_union s;

    KruskalsAlgorithm();
    void findMST();
    void insert_edge(int x, int y, int weight, bool directed);
private:
    bool same_component(m_set_union s, int x, int y);
    void union_sets(m_set_union * s, int s1, int s2);
    int find(m_set_union * s, int x);
    void set_union_init(m_set_union * s, int n);
    vector<edge_pair> * to_edge_array();
    
    
};