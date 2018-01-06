#include "stdafx.h"
#include "construct_all_subsets.h"
#include <iostream>

using namespace std;

bool SubsetBuilder::is_a_solution(int a[], int k, string input)
{
    return (k == input.length());
}

int * SubsetBuilder::construct_candidates()
{
    int * arr = new int[2];
    arr[0] = 0;
    arr[1] = 1;
    return arr;
    
}

void SubsetBuilder::process_solution(int  *a, int k, string input)
{
    int i;
    cout << "{ ";
    for (i = 0; i <= k;i++)
    {
        if (a[i] == 1)
        {
            cout << input.at(i) << " ";
        }
    }
    cout << "} ";
    cout << endl;
}


void SubsetBuilder::backtrack(int  *a, int k, string input)
{
    
    int ncandidates = 2; // there are only 2 possibilities


    if (is_a_solution(a, k, input))
    {
        process_solution(a, k, input);
    }
    else
    {
        auto c = construct_candidates();
        for (int i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];
            backtrack(a, k + 1, input);
        }
    }
}



