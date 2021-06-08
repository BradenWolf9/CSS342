/**
 * @file threadedBST.h
 * @brief header file for ThreadedBST class
 * @author Tristan Cortez and Braden Wolf
 */
#ifndef THREADEDBST_H
#define THREADEDBST_H

#include "treeNode.h"
#include <queue>

/**
 * ThreadedBST is a threaaded binary search tree that holds treeNodes
 *
 * variable *rootPtr points to root node of the tree
 */
template <class ItemType> class ThreadedBST {
  /**
   * prints tree from lowest node item to highest node item
   *
   * uses an in-order traversal by using the threads to print out the items
   * of the nodes in the tree from lowest value to highest value.
   *
   * @pre
   * @post
   * @param output
   * @param theTree
   * @return output
   */
  template <class Item>
  friend std::ostream &operator<<(std::ostream &output,
                                  const ThreadedBST<Item> &theTree);

private:
  TreeNode<ItemType> *rootPtr;
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  TreeNode<ItemType> *getLeftMost(TreeNode<ItemType> *currNode) const;
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  bool removeRoot(TreeNode<ItemType> *remove);
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  void inOrderTraversal(TreeNode<ItemType> *currNode,
                        std::queue<TreeNode<ItemType> *> &q) const;
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  void threadTree();
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  void preOrderCopy(TreeNode<ItemType> *treeNode, TreeNode<ItemType> *prevNode);

public:
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  ThreadedBST();
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  ThreadedBST(const ItemType &rootItem);
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  ThreadedBST(const ThreadedBST<ItemType> &tree);
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  ~ThreadedBST();
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  bool isEmpty() const;
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  int getHeight(TreeNode<ItemType> *currNode) const;
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  int getNumberOfNodes() const;
  // call thread function at end
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  bool insert(ItemType item);
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  TreeNode<ItemType> *findNode(ItemType find);
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  TreeNode<ItemType> *findParent(ItemType find);
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  TreeNode<ItemType> *getRoot();
  // call thread function at end
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  bool remove(ItemType toBeRemoved);
  // use post order
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  void makeEmpty(TreeNode<ItemType> *currNode);
  /**
   *
   *
   *
   *
   * @pre
   * @post
   * @param
   * @return
   */
  ThreadedBST<ItemType> &operator=(const ThreadedBST &right);
};

#include "threadedBST.cpp"

#endif
