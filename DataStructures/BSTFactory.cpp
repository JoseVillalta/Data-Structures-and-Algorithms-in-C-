#include "BSTFactory.h"
#include <stdlib.h>

BST<char> * BSTFactory::GenerateBST(int n)
{
    auto tree = new BST<char>();
    int j;
    for (int i = 0; i < n; i++)
    {
        j = rand() % 26;
        tree->Insert('A' + j);
    }

    return tree;
}


