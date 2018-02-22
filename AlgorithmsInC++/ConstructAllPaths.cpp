#include "ConstructAllPaths.h"

void PathBuilder::Backtrack(int a[], int k, int start, int end)
{
	if (IsSolution(a, k, end))
    {
        ProcessSolution();
    }
    else
    {
        int c[NMAX];
        k++;
		int  ncandidates = ConstructCandidates(a, k, start, c);
        for (int i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];
			Backtrack(a, k, start, end);
        }
    }
}

int PathBuilder::ConstructCandidates(int a[], int k, int start, int c[])
{
    int i;
    bool in_sol[NMAX];
    edgenode * p;
	int ncandidates;

    for (i = 1; i < NMAX; i++) in_sol[i] = false;
    for (i = 1; i < k; i++) in_sol[a[i]] = true;

    if (k==1)
    {
		c[0] = start;
        ncandidates = 1;
    }
    else
    {
        ncandidates = 0;
        int last = a[k - 1];
        p = g->edges[last];
        while (p != nullptr)
        {
            if (!in_sol[p->y])
            {
                c[ncandidates] = p->y;
                ncandidates++;
            }
            p = p->next;
        }
    }
	return ncandidates;
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
	Backtrack(a, 0, 1, 3);

    return pathCount;

}





