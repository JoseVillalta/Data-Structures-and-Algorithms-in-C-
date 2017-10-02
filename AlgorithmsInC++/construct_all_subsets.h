#pragma once
#include "stdafx.h"

class SubsetBuilder
{
public:
    void backtrack(int a[], int k, int * input);
    void make_move(int a[], int k, int * input);
    void unmake_move(int a[], int k, int * input);
    void construct_candidates(int a[], int k, int * input, int c[], int * ncandidates);
    void process_solution(int a[], int k, int * input);
    bool is_solution(int a[], int k, int * input);
private:
    bool is_finished;
};
