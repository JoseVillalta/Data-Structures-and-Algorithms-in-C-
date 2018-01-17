#pragma once

#define NMAX 10

using namespace std;

class MultiSetBuilder
{
public:
    void Backtrack(int a[], int k, int input[], int n);
    int ConstructCandidates(int a[], int k, int input[], int c[], int n);
    bool IsSolution(int n, int k);
    void ProcessSolution(int a[], int k, int input[], int n);
    void GenerateMultiset(int input[], int n);
};