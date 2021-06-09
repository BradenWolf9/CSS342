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
#include "threadedBST.h"
#include "treeNode.h"
#include <cassert>
#include <iostream>

/**
 * @brief driver function that creates treeNodes 
 * and threadedBST and tests their member functions.
 * 
 */
int main() {

  // TreeNode obj
  TreeNode<int> node1();
  TreeNode<int> node2(5);
  TreeNode<int> node3(5);
  assert(node2 == node3);
  TreeNode<int> node5(4);
  assert(node5 < node3);
  assert(node3 > node5);

  // ThreadedBST obj
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
  ThreadedBST<int> copyCtorTree(ourTree);
  ThreadedBST<int> copyOpTree = ourTree;
  std::cout << "Copy constructor: " << copyCtorTree << std::endl;
  std::cout << "Copy operator:    " << copyOpTree << std::endl;

  // Test member functions
  std::cout << "Height of ourTree: " << ourTree.getHeight(ourTree.getRoot())
            << std::endl; // expecting 3
  std::cout << "Number of nodes in ourTree: " << ourTree.getNumberOfNodes()
            << std::endl;

  // Test destructor
  ThreadedBST<int> empty;
  std::cout << "Print true(1) or false(0) isEmpty: " << empty.isEmpty()
            << std::endl; // should print 1
  std::cout << ourTree << std::endl;

  // Test other c'tor
  ThreadedBST<int> ctorTree(6);
  ctorTree.insert(3);
  ctorTree.insert(9);
  std::cout << ctorTree << std::endl;
  ctorTree.remove(9);
  std::cout << ctorTree << std::endl;
  assert(ctorTree.remove(6));
  std::cout << ctorTree << std::endl;

  // Test removing root
  assert(ourTree.remove(10));

  std::cout << "Our tree after removing 10: " << ourTree << std::endl;

  // Test member funcs
  assert(ctorTree.getRoot()->isLeaf());

  TreeNode<int> *find = ourTree.findNode(18);
  TreeNode<int> *findParent = ourTree.findParent(18);

  assert(find->getItem() == 18);
  assert(findParent->getItem() == 15);

  std::cout << "We finished here!" << std::endl;
}
