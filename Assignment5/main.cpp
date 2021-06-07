//Take single line argument (int n)
//the program should create a TBST with Keytype being int
//insert the numbers in non incremental order
//that means the iterator should not use a stack (use thread links)
//then make a copy of the tree
//delete all even numbers from the copy
//Lastly use an iterator to perform an INORDER traversal of each tree,
//outputting to std::cout
#include <iostream>
#include "treeNode.h"
#include "threadedBST.h"
#include <cassert>

int main() {
  TreeNode<int> node1();
  TreeNode<int> node2(5);
  //std::cout << node2.getItem() << std::endl;
  TreeNode<int> node3(5);
  assert(node2 == node3);
  // node1 = node2;
  TreeNode<int> node5(4);
  assert(node5 < node3);
  assert(node3 > node5);



  ThreadedBST<int> ourTree;
  ourTree.insert(10);
  ourTree.insert(7);
  ourTree.insert(15);
  ourTree.insert(5);
  ourTree.insert(8);
  ourTree.insert(11);
  ourTree.insert(18);

  // Test output of ourTree
  std::cout << ourTree << std::endl;

  // Test copy c'tor and copy operator
 //ThreadedBST<int> copyTree(ourTree);
  ThreadedBST<int> copyCtorTree(ourTree);
  ThreadedBST<int> copyOpTree = ourTree;
  std::cout << "Copy constructor: " << copyCtorTree << std::endl;
  std::cout << "Copy operator: " << copyOpTree << std::endl;

  // Test member functions
  std::cout << "Height of ourTree: " << ourTree.getHeight(ourTree.getRoot())
            << std::endl; // expecting 3
  std::cout << "Number of nodes in ourTree: " << ourTree.getNumberOfNodes()
            << std::endl;

  // Test destructor
  //std::cout << tnode0->getItem() << std::endl;
  //ourTree.~ThreadedBST();
  std::cout << "Print true(1) or false(0) isEmpty: " << ourTree.isEmpty()
            << std::endl; // should print 1
  std::cout << ourTree << std::endl;

  ThreadedBST<int> ctorTree(6);
  ctorTree.insert(3);
  ctorTree.insert(9);
  std::cout << ctorTree << std::endl;
  ctorTree.remove(9);
  std::cout << ctorTree << std::endl;

  std::cerr << "got here" << std::endl;

}
