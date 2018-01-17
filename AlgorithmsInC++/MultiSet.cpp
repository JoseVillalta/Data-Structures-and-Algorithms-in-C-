#include "MultiSet.h"
#include <iostream>

using namespace std;

void MultiSetBuilder::Backtrack(int a[], int k, int input[], int n)
{
    if (IsSolution(k,n))
    {
        ProcessSolution(a, k, input, n);
    }
    else
    {
        k++;
        int c[NMAX];
        int nCandidates = ConstructCandidates(a, k, input, c,n);
        for (int i = 0; i < nCandidates; i++)
        {
            a[k] = c[i];
            Backtrack(a, k, input,n);
        }
    }
    
}

void MultiSetBuilder::ProcessSolution(int a[], int k, int input[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << input[a[i]-1] << " ";
    }
    cout << endl;
}

bool MultiSetBuilder::IsSolution(int n, int k)
{
    return (n == k);
}

int MultiSetBuilder::ConstructCandidates(int a[], int k, int input[], int c[], int n)
{
    bool in_perm[NMAX];
    int i;
    for (i = 1; i < NMAX; i++) in_perm[i] = false;
    for (i = 1; i < k; i++) in_perm[a[i]] = true;
    
    int ncandidates = 0;
    for (i = 1; i <= n; i++)
    {
        if (in_perm[i] == false)
        {
            c[ncandidates] = i;
            ncandidates++;
        }
    }
    return ncandidates;
}

void MultiSetBuilder::GenerateMultiset(int input[], int n)
{
    int a[NMAX] = { 0 };
    Backtrack(a, 0, input, n);
}



