#include <iostream>
#include "treeNode.h"


template <typename ItemType> TreeNode<ItemType>::TreeNode() {
  this->leftChildPtr = nullptr;
  this->rightChildPtr = nullptr;
  this->rightIsThread = false;
  this->leftIsThread = false;
}

template <typename ItemType> TreeNode<ItemType>::~TreeNode() {
  this->leftChildPtr = nullptr;
  this->rightChildPtr = nullptr;
}

template <typename ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& anItem) {
  this-> item = anItem;
  this->leftChildPtr = nullptr;
  this->rightChildPtr = nullptr;
  this->rightIsThread = false;
  this->leftIsThread = false;
}

template <typename ItemType>
TreeNode<ItemType>::TreeNode(const ItemType& anItem, TreeNode<ItemType> leftPtr,
                             TreeNode<ItemType> rightPtr) {
  this->item = anItem;
  this->leftChildPtr = leftPtr;
  this->rightChildPtr = rightPtr;
  this->rightIsThread = false;
  this->leftIsThread = false;
}

template <typename ItemType>
void TreeNode<ItemType>::setItem(const ItemType& anItem) {
  this->item = anItem;
}

template <typename ItemType> ItemType TreeNode<ItemType>::getItem() const {
  return this->item;
}

template <typename ItemType> bool TreeNode<ItemType>::isLeaf() const {
  if (this->leftChildPtr == nullptr) {
    return true;
  }
  return false;
}

template <typename ItemType> TreeNode<ItemType>*
TreeNode<ItemType>::getLeftChildPtr() const {
  return this->leftChildPtr;
}

template <typename ItemType> TreeNode<ItemType>*
TreeNode<ItemType>::getRightChildPtr() const {
  return this->rightChildPtr;
}

template <typename ItemType>
void TreeNode<ItemType>::setLeftChildPtr(TreeNode<ItemType>* leftPtr) {
  this->leftChildPtr = leftPtr;
}

template <typename ItemType>
void TreeNode<ItemType>::setRightChildPtr(TreeNode<ItemType>* rightPtr) {
  this->rightChildPtr = rightPtr;
}

template <typename ItemType>
void TreeNode<ItemType>::setRightIsThread(bool thread) {
  this->rightIsThread = thread;
}

template <typename ItemType>
void TreeNode<ItemType>::setLeftIsThread(bool thread) {
  this->leftIsThread = thread;
}

template <typename ItemType>
bool TreeNode<ItemType>::getRightIsThread() {
  return this->rightIsThread;
}

template <typename ItemType>
bool TreeNode<ItemType>::getLeftIsThread() {
  return this->leftIsThread;
}

template <typename ItemType>
void TreeNode<ItemType>::operator=(const TreeNode<ItemType> &right) {
  this->item = right.getItem();
  this->leftChildPtr = right.getLeftChildPtr();
  this->rightChildPtr = right.getRightChildPtr();
  this->rightIsThread = right.getRightIsThread();
  this->leftIsThread = right.getLeftChildPtr();
}

template <typename ItemType>
bool TreeNode<ItemType>::operator==(const TreeNode& right) const {
  if (this->item == right.item) {
      // this->leftChildPtr == right.leftChildPtr &&
      // this->rightChildPtr == right.rightChildPtr &&
      // this->leftIsThread == right.leftIsThread &&
      // this->rightIsThread == right.rightIsThread) {
        return true;
      }
  return false;
}

template <typename ItemType>
bool TreeNode<ItemType>::operator<(const TreeNode& right) const {
  if (this->item < right.item) {
    return true;
  }
  return false;
}

template <typename ItemType>
bool TreeNode<ItemType>::operator>(const TreeNode& right) const {
  if (this->item > right.item) {
    return true;
  }
  return false;
}
