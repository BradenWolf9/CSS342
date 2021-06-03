#ifndef THREADEDBST_H
#define	THREADEDBST_H

#include "TreeNode.h"

template<class ItemType>
class ThreadedBST
{

  friend ostream &operator<<(ostream &output, const ThreadedBST<ItemType> &theTree)

private:
TreeNode<ItemType>* rootPtr;

public:

ThreadedBST();
ThreadedBST(const ItemType& rootItem);
ThreadedBST(const ThreadedBST<ItemType> tree);
~ThreadedBST();

bool isEmpty() const;
int getHeight() const;
int getNumberOfNodes() const;

ItemType getRootItem() const;
void setRootItem(const ItemType& newItem);


bool insert(ItemType);
bool remove(ItemType& toBeRemoved);

void makeEmpty();

// do pre order
ThreadedBST& operator=(const ThreadedBST& right);

// create thread the tree function

}

#endif
