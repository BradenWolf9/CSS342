#ifndef THREADEDBST_H
#define THREADEDBST_H

#include "treeNode.h"
#include <queue>

template <class ItemType> class ThreadedBST {
  //
  template <class Item>
  friend std::ostream &operator<<(std::ostream &output,
                                  const ThreadedBST<Item> &theTree);

private:
  TreeNode<ItemType> *rootPtr;

public:
  //
  TreeNode<ItemType> *getLeftMost(TreeNode<ItemType> *currNode) const;
  //
  bool removeRoot(TreeNode<ItemType> *remove);
  //
  void inOrderTraversal(TreeNode<ItemType> *currNode,
                        std::queue<TreeNode<ItemType> *> &q) const;

  //
  void threadTree();

  // use pre order
  void preOrderCopy(TreeNode<ItemType> *treeNode, TreeNode<ItemType> *prevNode);
  //
  ThreadedBST();
  //
  ThreadedBST(const ItemType &rootItem);
  //
  ThreadedBST(const ThreadedBST<ItemType> &tree);
  //
  ~ThreadedBST();
  //
  bool isEmpty() const;
  //
  int getHeight(TreeNode<ItemType> *currNode) const;
  //
  int getNumberOfNodes() const;

  // call thread function at end
  bool insert(ItemType item);
  //
  TreeNode<ItemType> *findNode(ItemType find);
  //
  TreeNode<ItemType> *findParent(ItemType find);
  //
  TreeNode<ItemType> *getRoot();

  // call thread function at end
  bool remove(ItemType toBeRemoved);

  // use post order
  void makeEmpty(TreeNode<ItemType> *currNode);

  //
  ThreadedBST<ItemType> &operator=(const ThreadedBST &right);
};

#include "threadedBST.cpp"

#endif
