#ifndef THREADEDBST_H
#define	THREADEDBST_H

#include "treeNode.h"
#include<queue>

template<class ItemType>
class ThreadedBST
{
  //
  template<class Item>
  friend std::ostream &operator<<(std::ostream &output,
                             const ThreadedBST<Item> &theTree);

private:
TreeNode<ItemType>* rootPtr;

public:
//
ThreadedBST();
//
ThreadedBST(const ItemType& rootItem);
//
ThreadedBST(const ThreadedBST<ItemType>& tree);
//
~ThreadedBST();
//
bool isEmpty() const;
//
int getHeight(TreeNode<ItemType>* currNode) const;
//
int getNumberOfNodes() const;

//
TreeNode<ItemType>* getLeftMost(TreeNode<ItemType>* currNode) const;

// call thread function at end
bool insert(ItemType item);
//
TreeNode<ItemType>* findNode(ItemType& find);
//
TreeNode<ItemType>* findParent(ItemType& find);
//
bool removeRoot(TreeNode<ItemType>* remove);

// call thread function at end
bool remove(ItemType& toBeRemoved);
//
void inOrderTraversal(TreeNode<ItemType>* currNode,
                      std::queue<TreeNode<ItemType>*>& q) const;
//
void threadTree();

// use post order
void makeEmpty(TreeNode<ItemType> *currNode);

// use pre order
void preOrderCopy(TreeNode<ItemType> *treeNode, TreeNode<ItemType> *prevNode);
//
ThreadedBST<ItemType>& operator=(const ThreadedBST& right);
};

#include "threadedBST.cpp"

#endif
