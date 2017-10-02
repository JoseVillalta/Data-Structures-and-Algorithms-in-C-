#include "stdafx.h"
#define MAXCANDIDATES 1000
bool finished = false;

bool is_a_solution(int a[], int k, int * input)
{
    return false;
}

void process_solution(int a[], int k, int * input)
{
    
}

void construct_candidates(int a[], int k, int * input, int c[], int * ncandidates)
{
    
}

void make_move(int a[], int k, int * input)
{
    
}

void unmake_move(int a[], int k, int * input)
{
    
}

void backtrack(int a[], int k, int * input)
{
    int c[MAXCANDIDATES];
    int ncandidates;

    if (is_a_solution(a,k,input))
    {
        process_solution(a, k, input);
    }
    else
    {
        k++;
        construct_candidates(a, k, input, c, &ncandidates);
        for (int i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];
            make_move(a, k, input);
            backtrack(a, k, input);
            unmake_move(a, k, input);
            if (finished) return;
        }
    }
}