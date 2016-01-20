#ifndef _BINARY_SEARCH_TREE_H__
#define _BINARY_SEARCH_TREE_H__
#include "TreeNode.h"

class BST
{
public:
    BST();
    TreeNode * Search(int Item);
    void Insert(int Item);
    int Level(int Item);
    int RecLevel(int Item);
    void Delete(int Item);
    bool DeleteRec(int Item);
    void TraverseInOrder();
    void TraversePreOrder();
    void TraversePostOrder();
    void InOrder();
    void LevelByLevel();
    void Trace();
    void Display();
    int Height();
    int LeafCount();
    int NodeCount();


private:
    TreeNode * m_root;
    void InsertNode(TreeNode* root, int val);
    TreeNode * SearchNode(TreeNode * root, int key);
    int RecLevelNode(TreeNode * root, int key);
    int HeightNode(TreeNode * root);
    int LeafCountNode(TreeNode * root);
    void InOrderTrav(TreeNode * root);
    void PreOrderTrav(TreeNode * root);
    void PostOrderTrav(TreeNode * root);
    void TraceInderOrder(TreeNode * root);
    void DisplayPreOrder(TreeNode * root);
    int NodeCountAux(TreeNode* root);
    void DeleteAux(int item, TreeNode* root);
    bool DeleteRecAux(int key, TreeNode* root, TreeNode* parent);
};




#endif