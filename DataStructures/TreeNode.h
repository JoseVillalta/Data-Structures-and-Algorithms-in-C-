#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

template<typename T>
class TreeNode
{
public:
    TreeNode * left;
    TreeNode * right;
    T data;
    TreeNode(T val = 0)
    {
        left = nullptr;
        right = nullptr;
        data = val;
    }
};


#endif