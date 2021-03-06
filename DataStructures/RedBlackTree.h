// Implementation copied from http://www.geeksforgeeks.org/c-program-red-black-tree-insertion/

#pragma once
#include "RBTreeNode.h"
using namespace std;

class RedBlackTree
{
public:
    RBTreeNode<int> *  Search(int val);
    void Min();
    void Max();
    void Predecessor();
    void Successor();
    void Insert(int val);
    void Delete();
    void InOrder();
    void LevelOrder();
private:
    RBTreeNode<int> * root;
    RBTreeNode<int> *  BSTInsert(RBTreeNode<int> * root, RBTreeNode<int> * pt);
	RBTreeNode<int> * BSTSearch(RBTreeNode<int> * root, int val);
    void InOrderHelper(RBTreeNode<int> * root);
    void LevelOrderHelper(RBTreeNode<int> * root);
    void FixViolations(RBTreeNode<int> * &root, RBTreeNode<int> * &pt);
    void RotateRight(RBTreeNode<int> * &root, RBTreeNode<int> * &pt);
    void RotateLeft(RBTreeNode<int> * &root, RBTreeNode<int> * &pt);
};