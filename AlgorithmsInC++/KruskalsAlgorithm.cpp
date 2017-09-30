#include "stdafx.h"
#include "KruskalsAlgorithm.h"

void KruskalsAlgorithm::set_union_init(set_union * s, int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        s->p[i] = i;
        s->size[i] = 1;
    }
    s->n = n;
}

int KruskalsAlgorithm::find(set_union * s, int x)
{
    if (s->p[x] == x) return x;

    return(find(s, s->p[x]));

}

void KruskalsAlgorithm::union_sets(set_union * s, int s1, int s2)
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

bool KruskalsAlgorithm::weight_compare()
{
    return true;
}

bool KruskalsAlgorithm::same_component(set_union s, int x, int y)
{
    return (find(&s, x) == find(&s, y));
}
edge_pair * KruskalsAlgorithm::to_edge_array()
{
    int i;
    edge_pair * arr = new edge_pair[MAXV + 1];
    int arrCounter = 0;
    for (i = 1; i < m_g->nedges; i++)
    {
        auto p = m_g->edges[i];
        while (p != nullptr)
        {
            edge_pair ep;
            ep.x = i;
            ep.y = p->y;
            ep.weight = p->weight;
            arr[arrCounter] = ep;
            arrCounter++;
            p = p->next;            
        }
    }
    return arr;
}


void KruskalsAlgorithm::findMST()
{
    int i;
    set_union s;
    set_union_init(&s, m_g->nvertices);
    auto e = to_edge_array();
    //sort edge array
    for (i = 0; i < m_g->nedges;i++)
    {
       // union_sets(&s, i, )
    }

}
