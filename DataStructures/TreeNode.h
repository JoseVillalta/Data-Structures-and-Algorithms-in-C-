#ifndef __TREE_NODE_H__
#define __TREE_NODE_H__

class TreeNode
{
public:
    TreeNode * left;
    TreeNode * right;
    int data;
    TreeNode(int val = 0xFFFF)
    {
        left = nullptr;
        right = nullptr;
        data = val;
    }
};


#endif