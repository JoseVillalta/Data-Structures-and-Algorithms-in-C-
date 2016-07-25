#include "RadixSortTest.h"
#include <iostream>
#include <string>

using namespace std;
void RadixSortTest::DoTests()
{
    cout << "Starting Radix Sort Test " << endl;
    auto radixSort = new RadixSort();
    string arr[] = {    "4PGC938","2IYE230","3CIO720","1ICK750",
                        "1OHV845","4JZY524","1ICK750","3CIO720",
                        "1OHV845","1OHV845","2RLA629","3ATW723" };

    radixSort->Sort(arr, 7, 12);

    for (int i = 0; i < 12; i++)
    {
        cout << arr[i] << ", ";
    }

    cout << "Radix Sort passed" << endl;
}