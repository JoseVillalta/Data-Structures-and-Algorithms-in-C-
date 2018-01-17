#include "construct_all_permutations.h"
#include <iostream>

using namespace std;
void PermutationBuilder::Backtrack(int a[], int k, int n)
{
    int c[NMAX];
    int ncandidates = 0;
    int i;
    
    if (IsSolution(k, n))
    {
        ProcessSolution(a, k, n);
    }
    else
    {
        k = k + 1;
        ncandidates = ConstructCandidates(a, k, n, c);
        for (i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];         
            Backtrack(a, k, n);     
        }
    }
}

int PermutationBuilder::ConstructCandidates(int a[], int k, int n, int c[])
{
    int i;
    bool in_perm[NMAX];

    for (i = 1; i < NMAX; i++) in_perm[i] = false;
    for (i = 1; i < k; i++) in_perm[a[i]] = true;
    int ncandidates = 0;
    for (i = 1; i <= n;i++)
    {
        if (in_perm[i] == false)
        {
            c[ncandidates] = i;
            ncandidates++;
        }
    }
    return ncandidates;
}

bool PermutationBuilder::IsSolution(int k, int n)
{
    return (k == n);
}

void PermutationBuilder::ProcessSolution(int a[], int k, int n)
{
    for (int i = 1; i <= k; i++) cout << a[i] << " ";
    cout << endl;
}

void PermutationBuilder::GeneratePermutations(int n)
{
    int a[NMAX] = { 0 };

    Backtrack(a, 0, n);
}




