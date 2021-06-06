//Take single line argument (int n)
//the program should create a TBST with Keytype being int
//insert the numbers in non incremental order
//that means the iterator should not use a stack (use thread links)
//then make a copy of the tree
//delete all even numbers from the copy
//Lastly use an iterator to perform an INORDER traversal of each tree, outputting to std::cout
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
  TreeNode<int> tnode1(5);
  TreeNode<int> tnode2(7);
  TreeNode<int> tnode3(8);
  TreeNode<int> tnode4(10);
  TreeNode<int> tnode5(11);
  TreeNode<int> tnode6(15);
  TreeNode<int> tnode7(18);



  ourTree.insert(10);
  ourTree.insert(7);
  ourTree.insert(15);
  ourTree.insert(5);
  ourTree.insert(8);
  ourTree.insert(11);
  ourTree.insert(18);

  std::cout << ourTree;

  TreeNode<int> node4 = node2;
}
