#include "ConstructAllPaths.h"

void PathBuilder::Backtrack(int a[], int k, int n)
{
    if (IsSolution(a, k, n))
    {
        ProcessSolution();
    }
    else
    {
        int  ncandidates;
        int c[NMAX];
        k++;
        ConstructCandidates(a, k, n, c, &ncandidates);
        for (int i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];
            Backtrack(a, k, n);
        }
    }
}

void PathBuilder::ConstructCandidates(int a[], int k, int n, int c[], int * ncandidates)
{
    int i;
    bool in_sol[NMAX];
    edgenode * p;

    for (i = 1; i < NMAX; i++) in_sol[i] = false;
    for (i = 1; i < k; i++) in_sol[a[i]] = true;

    if (k==1)
    {
        c[0] = 1;
        *ncandidates = 1;
    }
    else
    {
        *ncandidates = 0;
        int last = a[k - 1];
        p = g->edges[last];
        while (p != nullptr)
        {
            if (!in_sol[p->y])
            {
                c[*ncandidates] = p->y;
                *ncandidates++;
            }
            p = p->next;
        }
    }
}

bool PathBuilder::IsSolution(int a[], int k, int t)
{
    return (a[k] == t);
}

void PathBuilder::ProcessSolution()
{
    pathCount++;
}

void PathBuilder::MakeMove()
{
    
}

void PathBuilder::UnMakeMove()
{
    
}

int PathBuilder::GetAllPaths(Graph* input_g, int s, int t)
{
    g = input_g;
    pathCount = 0;
    int a[NMAX];
    Backtrack(a, 0, 3);

    return pathCount;

}





