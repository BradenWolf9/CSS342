#ifndef THREADEDBST_H
#define	THREADEDBST_H

#include "TreeNode.h"

template<class ItemType>
class ThreadedBST
{
  //
  friend ostream &operator<<(ostream &output,
                             const ThreadedBST<ItemType> &theTree);

private:
TreeNode<ItemType>* rootPtr;

public:
//
ThreadedBST();
//
ThreadedBST(const ItemType& rootItem);
//
ThreadedBST(const ThreadedBST<ItemType> tree);
//
~ThreadedBST();
//
bool isEmpty() const;

int getHeight(TreeNode<ItemType>* currNode) const;
int getNumberOfNodes() const;

ItemType getRootItem() const;
void setRootItem(const ItemType& newItem);
//
TreeNode<ItemType>* getLeftMost(TreeNode<ItemType>* currNode);

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
                      queue<TreeNode<ItemType>*>& q);
//
void threadTree();

// use post order
void makeEmpty();

// use pre order
void preOrderCopy(TreeNode<ItemType> *treeNode, TreeNode<ItemType> *prevNode);

ThreadedBST<ItemType>& operator=(const ThreadedBST& right);
};

#endif
