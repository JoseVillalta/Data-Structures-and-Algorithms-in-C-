#include "MergeSort.h"
#include <iostream>

using namespace std;

class MergeSortTest
{
public:
    void DoTests();
private:
    void TestSort();
    void TestBiggerInputs();
    void CountingInversions();
};