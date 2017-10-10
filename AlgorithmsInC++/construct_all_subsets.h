#pragma once
#include "stdafx.h"
#include <string>
#define MAXCANDIDATES 100

using namespace std;
class SubsetBuilder
{
public:
    void backtrack(int a[], int k, string input);
    int * construct_candidates();
    void process_solution(int * a, int k, string input);
    bool is_a_solution(int * a, int k, string input);

};
