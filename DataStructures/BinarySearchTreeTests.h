#include "BinarySearchTree.h"

class BSTTests
{
public:
   void DoTests();
private:
   BST<int> * m_tree;
   void Init();
   void CleanUp();
   void SearchTests();
   void LevelTest();
   void RecLevelTest();
   void HeightTest();
   void InOrderTraverseTest();
   void PreOrderTraverseTest();
   void PostOrderTraverseTest();
   void LeafCountTest();
   void InOrderTest();
   void LelvelByLevelTest();
   void DeleteTest();
   void NodeCountTest();
   void RecDeleteTest();
   void SearchFloatTest();
   void InOrderTraversalStrings();
};