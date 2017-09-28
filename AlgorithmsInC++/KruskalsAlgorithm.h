#pragma once
#include "stdafx.h"
#define SET_SIZE 1000

typedef struct
{
    int p[SET_SIZE + 1];
    int size[SET_SIZE + 1];
    int n;
}set_union;

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