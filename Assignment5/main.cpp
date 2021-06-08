/**
 * @file main.cpp
 * @author Tristan, Braden
 * @brief Main is used to create TreeNodes and several ThreadBST 
 * Take single line argument (int n)
 * the program should create a both objects with Keytype being int
 * insert the numbers in non incremental order
 * that means the iterator should not use a stack (use thread links)
 * then make a copy of the tree
 * delete all even numbers from the copy
 * Lastly use an iterator to perform an INORDER traversal of each tree,
 * outputting to std::cout
 * @version 0.1
 * @date 2021-06-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <iostream>
#include "treeNode.h"
#include "threadedBST.h"
#include <cassert>
#include <iostream>

/**
 * @brief testNodes function that creates treeNodes and tests
 * its member functions.
 * 
 */
void testNodes() {
  TreeNode<int> node1();
  TreeNode<int> node2(5);
  TreeNode<int> node3(5);
  assert(node2 == node3);
  TreeNode<int> node5(4);
  assert(node5 < node3);
  assert(node3 > node5);
  node5 = node2;
  assert(node5 == node3);

  std::cout << "Successfully finished testNodes()" << std::endl;
}

/**
 * @brief testThreadedBST function that creates a threadedBST and
 * tests its member functions after insertion.
 * 
 */
void testThreadedBST() {
  ThreadedBST<int> ourTree;
  ourTree.insert(10); // inserting in non incremental order
  ourTree.insert(7);
  ourTree.insert(15);
  ourTree.insert(5);
  ourTree.insert(8);
  ourTree.insert(11);
  ourTree.insert(18);

  // Test output of ourTree
  std::cout << "ourTree: " << ourTree << std::endl;

  // Test copy c'tor and copy operator
  ThreadedBST<int> copyCtorTree(ourTree);
  ThreadedBST<int> copyOpTree = ourTree;
  std::cout << "Copy constructor: " << copyCtorTree << std::endl;
  std::cout << "Copy operator:    " << copyOpTree << std::endl;

  // Test member functions
  std::cout << "Height of ourTree: " << ourTree.getHeight(ourTree.getRoot())
            << std::endl; // expecting 3
  std::cout << "Number of nodes in ourTree: " << ourTree.getNumberOfNodes()
            << std::endl;
  ThreadedBST<int> empty;
  std::cout << "Print true(1) or false(0) isEmpty: " << empty.isEmpty()
            << std::endl; // should print 1

  // Test other constructor
  ThreadedBST<int> ctorTree(6);
  ctorTree.insert(3);
  ctorTree.insert(9);
  std::cout << "\nctorTree: " << ctorTree << std::endl;
  std::cout << "removing 9 from ctor tree, success: " << ctorTree.remove(9) << std::endl;
  std::cout << "ctorTree: " << ctorTree << std::endl;
  std::cout << "removing 6 from ctor tree, success: " << ctorTree.remove(6) << std::endl;
  std::cout << "ctorTree: " << ctorTree << std::endl;

  // Test removing root
  assert(ourTree.remove(10));
  
  // Check if one node (root) is leaf
  assert(ctorTree.getRoot()->isLeaf());
  
  // Test more member functions
  TreeNode<int>* find = ourTree.findNode(18);
  TreeNode<int>* findParent = ourTree.findParent(18);

  
  assert(find->getItem() == 18);
  assert(findParent->getItem() == 15);

  std::cout << "Successfully finished testThreadedBST()" << std::endl;
}

/**
 * @brief Main driver for threadedBST
 * 
 * @return int 
 */
int main() {
  testNodes();
  testThreadedBST();

  std::cout << "Completed all tests" << std::endl;
  return 0;
}
