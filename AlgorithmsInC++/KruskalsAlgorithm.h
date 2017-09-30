#pragma once
#include "stdafx.h"
#include "Graph.h"
#define SET_SIZE 1000

typedef struct
{
    int p[SET_SIZE + 1];
    int size[SET_SIZE + 1];
    int n;
}set_union;

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

    KruskalsAlgorithm();
    void findMST();
private:
    bool same_component(set_union s, int x, int y);
    bool weight_compare();
    void union_sets(set_union * s, int s1, int s2);
    int find(set_union * s, int x);
    void set_union_init(set_union * s, int n);
    edge_pair * to_edge_array();




};