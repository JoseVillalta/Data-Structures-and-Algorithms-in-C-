#include "stdafx.h"
#include "DijkstrasAlgorithm.h"
#include <iostream>

DijkstrasAlgorithm::DijkstrasAlgorithm()
{
    m_g = new Graph();
    m_g->nvertices = 0;
    m_g->nedges = 0;

    for (int i = 1; i < MAXV; i++) m_g->degree[i] = 0;
    for (int i = 1; i < MAXV; i++) m_g->edges[i] = nullptr;
}

void DijkstrasAlgorithm::insert_edge(int x, int y, int weight, bool directed)
{
    auto edge = new edgenode();
    edge->weight = weight;
    edge->y = y;
    edge->next = m_g->edges[x];
    m_g->edges[x] = edge;
    m_g->degree[x]++;

    if (!directed)
    {
        insert_edge(y, x, weight, true);
    }
    else
    {
        m_g->nedges++;
    }
}

void DijkstrasAlgorithm::shortest_path(int start)
{
    int i;
    edgenode *p;
    int v;
    int w;
    int weight;
    int dist;

    for (i = 1; i <= m_g->nvertices;i++)
    {
        intree[i] = false;
        distance[i] = MAX_INT;
        parent[i] = -1;
    }

    distance[start] = 0;
    v = start;
    
    while (intree[v] == false)
    {
        intree[v] = true;
        p = m_g->edges[v];
        while (p != nullptr)
        {
            w = p->y;
            weight = p->weight;
            if (distance[w] > (distance[v] + weight))
            {
                distance[w] = distance[v] + weight;
                parent[w] = v;
            }
            p = p->next;
        }
        v = 1;
        dist = MAX_INT;
        for (i = 1; i <= m_g->nvertices; i++)
        {
            if ((intree[i] == false) && (dist > distance[i]))
            {
                dist = distance[i];
                v = i;
            }
        }
    }
}

void DijkstrasAlgorithm::print_path(int start, int end)
{
    if ((start == end)||end == -1)
    {
        std::cout << " " << start;
    }
    else
    {
        print_path(start, parent[end]);
        std::cout << " " << end;
    }
}



