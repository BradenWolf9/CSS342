
/**
 * @file treeNode.cpp
 * @author Tristan, Braden
 * @brief The TreeNode cpp file implements TreeNode and its
 * member functions similar to the Node of a BinaryTree.
 * @version 0.1
 * @date 2021-06-07
 *
 * @copyright Copyright (c) 2021
 *
 */
#include "treeNode.h"

// Default constructor
template <typename ItemType> TreeNode<ItemType>::TreeNode() {
  this->leftChildPtr = nullptr;
  this->rightChildPtr = nullptr;
  this->rightIsThread = false;
}

// TreeNode destructor
template <typename ItemType> TreeNode<ItemType>::~TreeNode() {}

// TreeNode constructor with ItemType param
template <typename ItemType>
TreeNode<ItemType>::TreeNode(const ItemType &anItem) {
  this->item = anItem;
  this->leftChildPtr = nullptr;
  this->rightChildPtr = nullptr;
  this->rightIsThread = false;
}

// TreeNode constructor with ItemType, two TreeNode parameters
template <typename ItemType>
TreeNode<ItemType>::TreeNode(const ItemType &anItem, TreeNode<ItemType> leftPtr,
                             TreeNode<ItemType> rightPtr) {
  this->item = anItem;
  this->leftChildPtr = leftPtr;
  this->rightChildPtr = rightPtr;
  this->rightIsThread = false;
}

// Setter for ItemType item
template <typename ItemType>
void TreeNode<ItemType>::setItem(const ItemType &anItem) {
  this->item = anItem;
}

// Getter for ItemType item
template <typename ItemType> ItemType TreeNode<ItemType>::getItem() const {
  return this->item;
}

// Checks if TreeNode is a leaf of the Binary Search Tree
template <typename ItemType> bool TreeNode<ItemType>::isLeaf() const {
  if (this->leftChildPtr == nullptr) {
    return true;
  }
  return false;
}

// Returns left child ptr of TreeNode obj
template <typename ItemType> TreeNode<ItemType>*
TreeNode<ItemType>::getLeftChildPtr() const {
  return this->leftChildPtr;
}

// Returns right child ptr of TreeNode obj
template <typename ItemType> TreeNode<ItemType>*
TreeNode<ItemType>::getRightChildPtr() const {
  return this->rightChildPtr;
}

// Sets left child ptr of tree node obj
template <typename ItemType>
void TreeNode<ItemType>::setLeftChildPtr(TreeNode<ItemType> *leftPtr) {
  this->leftChildPtr = leftPtr;
}

// Sets right child ptr of tree node obj
template <typename ItemType>
void TreeNode<ItemType>::setRightChildPtr(TreeNode<ItemType> *rightPtr) {
  this->rightChildPtr = rightPtr;
}

// Sets bool thread depending on use-case
template <typename ItemType>
void TreeNode<ItemType>::setRightIsThread(bool thread) {
  this->rightIsThread = thread;
}

// Returns bool if there is a thread on TreeNode obj
template <typename ItemType>
bool TreeNode<ItemType>::getRightIsThread() {
  return this->rightIsThread;
}

// Copy operator
template <typename ItemType>
void TreeNode<ItemType>::operator=(const TreeNode<ItemType> &right) {
  this->item = right.getItem();
  this->leftChildPtr = right.getLeftChildPtr();
  this->rightChildPtr = right.getRightChildPtr();
  //this->rightIsThread = right.getRightIsThread();
}

// Equality operator
template <typename ItemType>
bool TreeNode<ItemType>::operator==(const TreeNode &right) const {
  if (this->item == right.item) {
        return true;
      }
  return false;
}

// Less than operator
template <typename ItemType>
bool TreeNode<ItemType>::operator<(const TreeNode &right) const {
  if (this->item < right.item) {
    return true;
  }
  return false;
}


// Greater than operator
template <typename ItemType>
bool TreeNode<ItemType>::operator>(const TreeNode &right) const {
  if (this->item > right.item) {
    return true;
  }
  return false;
}
