#include "stdafx.h"
#include "KruskalsAlgorithm.h"

void set_union_init(set_union * s, int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        s->p[i] = i;
        s->size[i] = 1;
    }
    s->n = n;
}

int find(set_union * s, int x)
{
    if (s->p[x] == x) return x;

    return(find(s, s->p[x]));

}

void union_sets(set_union * s, int s1, int s2)
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