#pragma once
enum Color {RED, BLACK};

template<typename T>
class RBTreeNode
{
public:
    RBTreeNode * left;
    RBTreeNode * right;
    RBTreeNode * parent;
    T data;
    bool color;
    RBTreeNode(T val = 0)
    {
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        data = val;
    }
};
