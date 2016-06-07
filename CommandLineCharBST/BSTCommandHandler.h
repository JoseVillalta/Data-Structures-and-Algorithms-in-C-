#pragma once
#include "stdafx.h"
#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

class BSTCommandHandler
{
public:
    void Run();
    void InsertChar(char c);
    bool SearchChar(char c);
    void InOrderTraversal();
    void PreOrderTraversal();
    void PostOrderTraversal();

    BSTCommandHandler();
    ~BSTCommandHandler();
private:
    BST<char> * m_tree;
};

