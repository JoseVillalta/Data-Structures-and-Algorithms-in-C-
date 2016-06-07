#ifndef _BINARY_SEARCH_TREE_H__
#define _BINARY_SEARCH_TREE_H__
#include "TreeNode.h"
#include <vector>
using namespace std;
template<typename T>
class BST
{
public:
    BST();
    TreeNode<T> * Search(T Item);
    void Insert(T Item);
    int Level(T Item);
    int RecLevel(T Item);
    void Delete(T Item);
    bool DeleteRec(T Item);
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
    vector<T> * ToVectorInOrder();


private:
    TreeNode<T> * m_root;
    void InsertNode(TreeNode<T>* root, T val);
    TreeNode<T> * SearchNode(TreeNode<T> * root, T key);
    int RecLevelNode(TreeNode<T> * root, T key);
    int HeightNode(TreeNode<T> * root);
    int LeafCountNode(TreeNode<T> * root);
    void InOrderTrav(TreeNode<T> * root);
    void PreOrderTrav(TreeNode<T> * root);
    void PostOrderTrav(TreeNode<T> * root);
    void TraceInderOrder(TreeNode<T> * root);
    void DisplayPreOrder(TreeNode<T> * root);
    int NodeCountAux(TreeNode<T>* root);
    void DeleteAux(T item, TreeNode<T>* root);
    bool DeleteRecAux(T key, TreeNode<T>* root, TreeNode<T>* parent);
    void ToVectorAux(TreeNode<T>* root, vector<T>& v);
};




#endif