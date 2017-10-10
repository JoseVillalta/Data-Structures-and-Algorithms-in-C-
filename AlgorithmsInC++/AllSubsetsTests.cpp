#include "stdafx.h"
#include "AllSubsetsTests.h"

#include <string>
#include <iostream>
using namespace std;

void AllSubSetsTests::DoTests()
{
    constructAllSubsetsTests();
}

void AllSubSetsTests::constructAllSubsetsTests()
{
    cout << "**** Backtracking *****" << endl;

    auto sb = new SubsetBuilder();
    string s1 = "ABCD";
    int arr[] = { 0, 0, 0, 0 };
    sb->backtrack(arr, 0, s1);
    cout << "**** Backtracking 2 *****" << endl;
    string s2 = "DCBA";
    //sb->backtrack(arr, 0, s2);
}

