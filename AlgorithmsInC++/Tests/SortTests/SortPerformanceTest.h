#pragma once
#include <iostream>
#include <vector>

using namespace std;

class SortPerformanceTest
{
public:
    void DoTests();
private:
    void GetRandomVector(vector<int> & v, unsigned int size);
};