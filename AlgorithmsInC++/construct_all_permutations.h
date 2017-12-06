#pragma once
#define NMAX 10

using namespace std;

class PermutationBuilder
{
public:
    void Backtrack(int a[], int k, int n);
    int ConstructCandidates(int a[], int k, int n, int c[]);
    bool IsSolution(int n, int k);
    void ProcessSolution(int a[], int k, int n);
    void GeneratePermutations(int n);
};