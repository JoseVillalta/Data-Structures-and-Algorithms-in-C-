#pragma once
#include <vector>

using namespace std;

static void GetRandomVector(vector<int> & v, unsigned int size)
{
    for (int i = 0; i < size; i++)
    {
        int n = rand() % size;
        v.push_back(n);
    }
}


