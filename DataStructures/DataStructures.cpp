// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinarySearchTreeTests.h"
#include "CharBSTTests.h"
#include "BSTATests.h"
#include "RadixTreeTests.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    BSTTests * treeTests = new BSTTests();
    CharBSTTests * charTreeTests = new CharBSTTests();
    BSTATests * arrayTreeTests = new BSTATests();
    RadixTreeTests * radixTreeTests = new RadixTreeTests();
    
    treeTests->DoTests();
    charTreeTests->DoTests();
    arrayTreeTests->DoTests();
    radixTreeTests->DoTests();

    return 0;
}

