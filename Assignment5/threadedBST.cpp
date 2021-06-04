#include <iostream>
#include "threadedBST.h"

template<typename ItemType>
TreeNode<ItemType>* getLeftMost(TreeNode<ItemType>* currNode) {
  while (currNode->leftChildPtr != nullptr) {
    currNode = currNode->getLeftChildPtr();
  }
  return currNode;
}

template<typename ItemType>
friend ostream &operator<<(ostream &output,
                           const ThreadedBST<ItemType> &theTree) {
   TreeNode<ItemType> *currNode = this->rootPtr;
   currNode = this->getLeftMost(currNode);

   while(currNode->getRightChildPtr() != nullptr) {
     output << currNode->getItem() << " ";
     if (currNode->getRightIsThread()) {
       currNode = currNode->getRightChildPtr();
     } else {
       currNode = currNode->getRightChildPtr();
       currNode = this->getLeftMost(currNode);
     }
   }
}

template<typename ItemType> ThreadedBST<ItemType>::ThreadedBST() {
  this->rootPtr = nullptr;
}

template<typename ItemType>
ThreadedBST<ItemType>::ThreadedBST(const ItemType& rootItem) {
  this->rootPtr = new TreeNode<ItemType>(rootItem);
}



  // recursive call
  preOrderCopy(treeNode->getLeftChildPtr(), prevNode->getLeftChildPtr());
  preOrderCopy(treeNode->getRightChildPtr(), prevNode->getRightChildPtr());
}

template<typename ItemType>
ThreadedBST<ItemType>::ThreadedBST(const ThreadedBST<ItemType> tree) {
  this->rootPtr = new TreeNode<ItemType>;
  this->rootPtr->setItem(tree.rootPtr->getItem());
  this->preOrderCopy(tree.rootPtr, this->rootPtr);
}

template<typename ItemType>
ThreadedBST<ItemType>::~ThreadedBST() {
  this->makeEmpty(this->rootPtr);
}

template<typename ItemType>
bool ThreadedBST<ItemType>::isEmpty() const {

}

template<typename ItemType>
void ThreadedBST<ItemType>::makeEmpty(TreeNode<ItemType> *currNode) {
  // base case
  if (this->isLeaf()) {
    delete currNode;
    return;
  }
  makeEmpty(currNode->getLeftChildPtr());
  makeEmpty(currNode->getRightChildPtr());
  delete currNode;
  return;
}

template<typename ItemType>
void ThreadedBST<ItemType>::preOrderCopy(TreeNode<ItemType> *treeNode,
                                         TreeNode<ItemType> *prevNode) {

  // base case
  if (treeNode->isLeaf()) {
    prevNode->setLeftChildPtr(nullptr);
    prevNode->setRightChildPtr(nullptr);
    if (tree->getRightIsThread()) {
      prevNode->setRightIsThread(true);
    }
    return;
  }

  // create left child and right child
  TreeNode<ItemType> *leftChild;
  leftChild = new TreeNode<ItemType>;
  TreeNode<ItemType> *rightChild;
  rightChild = new TreeNode<ItemType>;

  // set previous left and right child
  prevNode->setLeftChildPtr(leftChild);
  prevNode->setRightChildPtr(rightChild);

  // set items of children
  prevNode->getLeftChildPtr()->setItem(treeNode->getLeftChildPtr()->getItem());
  prevNode->getRightChildPtr()->setItem(
                      treeNode->getRightChildPtr()->getItem());

  // set bool for right thread
  if (tree->getRightIsThread()) {
    prevNode->setRightIsThread(true);
  }
