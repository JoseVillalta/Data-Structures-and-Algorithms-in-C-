// DataStructures.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinarySearchTreeTests.h"
#include "CharBSTTests.h"
#include "BSTATests.h"
#include "RadixTreeTests.h"
#include "MaxPQTests.h"
#include "YoungTableauTests.h"
#include "StackTests.h"
#include "LinkedListTests.h"
#include <iostream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    BSTTests * treeTests = new BSTTests();
    CharBSTTests * charTreeTests = new CharBSTTests();
    BSTATests * arrayTreeTests = new BSTATests();
    RadixTreeTests * radixTreeTests = new RadixTreeTests();
    auto maxPQTests = new PQTest();
    auto YoungTableauuTests = new YoungTableauTests();
    auto stackTests = new StackTests();
    auto LinkedListTest = new LinkedListTests();
    
    treeTests->DoTests();
    charTreeTests->DoTests();
    arrayTreeTests->DoTests();
    radixTreeTests->DoTests();
    maxPQTests->DoTests();
    YoungTableauuTests->DoTests();
    stackTests->DoTests();
    LinkedListTest->DoTests();

    return 0;
}

