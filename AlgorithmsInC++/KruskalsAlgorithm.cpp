#include "stdafx.h"
#include "KruskalsAlgorithm.h"
#include <vector>
#include <algorithm>
#include <iostream>

bool weight_compare(const edge_pair &lhs, const edge_pair &rhs)
{
    return lhs.weight < rhs.weight;
}

KruskalsAlgorithm::KruskalsAlgorithm()
{
    m_g = new Graph();
    m_g->nvertices = 0;
    m_g->nedges = 0;

    for (int i = 1; i < MAXV; i++) m_g->degree[i] = 0;
    for (int i = 1; i < MAXV; i++) m_g->edges[i] = nullptr;
}

void KruskalsAlgorithm::set_union_init(m_set_union * s, int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        s->p[i] = i;
        s->size[i] = 1;
    }
    s->n = n;
}

int KruskalsAlgorithm::find(m_set_union * s, int x)
{
    if (s->p[x] == x) return x;

    return(find(s, s->p[x]));

}

void KruskalsAlgorithm::union_sets(m_set_union * s, int s1, int s2)
{
    int r1, r2;

    r1 = find(s, s1);
    r2 = find(s, s2);

    if (r1 == r2) return;

    if (s->size[r1] >= s->size[r2])
    {
        s->size[r1] = s->size[r1] + s->size[r2];
        s->p[r2] = r1;
    }
    else
    {
        s->size[r2] = s->size[r1] + s->size[r2];
        s->p[r1] = r2;
    }
}


bool KruskalsAlgorithm::same_component(m_set_union s, int x, int y)
{
    return (find(&s, x) == find(&s, y));
}

std::vector<edge_pair> * KruskalsAlgorithm::to_edge_array()
{
    int i;
    vector<edge_pair> * arr = new vector<edge_pair>();
    for (i = 1; i < m_g->nvertices; i++)
    {
        auto p = m_g->edges[i];
        while (p != nullptr)
        {
            edge_pair ep;
            ep.x = i;
            ep.y = p->y;
            ep.weight = p->weight;
            arr->push_back(ep);
            p = p->next;            
        }
    }
    return arr;
}


void KruskalsAlgorithm::findMST()
{
    int i;
    set_union_init(&s, m_g->nvertices);
    auto e = to_edge_array();
    sort(e->begin(), e->end(), weight_compare);
    for (i = 0; i < m_g->nedges;i++)
    {
        if (!same_component(s, e->at(i).x, e->at(i).y))
        {
            cout << "Edge " << e->at(i).x << " " << e->at(i).y << " weight " << e->at(i).weight << endl;
            union_sets(&s, e->at(i).x, e->at(i).y);          
        }       
    }
}

void KruskalsAlgorithm::insert_edge(int x, int y, int weight, bool directed)
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