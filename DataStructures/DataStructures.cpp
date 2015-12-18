// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinarySearchTreeTests.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    BSTTests * treeTests = new BSTTests();
    
    treeTests->DoTests();

    return 0;
}

