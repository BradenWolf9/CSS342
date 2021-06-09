/**
 * @file threadedBST.cpp
 * @brief implementation file for ThreadedBST class
 * @author Tristan Cortez and Braden Wolf
 */
#include "threadedBST.h"
#include <iostream>
#include <queue>

// prints tree from lowest node item to highest node item
template <typename Item>
std::ostream &operator<<(std::ostream &output,
                         const ThreadedBST<Item> &theTree) {
  TreeNode<Item> *currNode = theTree.getRoot();
  currNode = theTree.getLeftMost(currNode);

  while (currNode->getRightChildPtr() != nullptr) {
    output << currNode->getItem() << " ";
    if (currNode->getRightIsThread()) {
      currNode = currNode->getRightChildPtr();
    } else {
      currNode = currNode->getRightChildPtr();
      currNode = theTree.getLeftMost(currNode);
    }
  }
  // last node
  output << currNode->getItem();
  return output;
}

// returns a pointer to the left most node from the node passed in
template <typename ItemType>
TreeNode<ItemType> *
ThreadedBST<ItemType>::getLeftMost(TreeNode<ItemType> *currNode) const {
  while (currNode->getLeftChildPtr() != nullptr) {
    currNode = currNode->getLeftChildPtr();
  }
  return currNode;
}

// removes the root of the tree
template <typename ItemType>
bool ThreadedBST<ItemType>::removeRoot(TreeNode<ItemType> *remove) {
  TreeNode<ItemType> *current = remove;
  // if root has two children
  if (remove->getLeftChildPtr() != nullptr &&
      remove->getRightChildPtr() != nullptr) {
    current = current->getRightChildPtr();
    current = this->getLeftMost(current);
    // if current has no children
    if (current->isLeaf()) {
      TreeNode<ItemType> *parent = findParent(current->getItem());
      parent->setLeftChildPtr(nullptr);
      current->setLeftChildPtr(remove->getLeftChildPtr());
      current->setRightChildPtr(remove->getRightChildPtr());
      current->setRightIsThread(false);
      this->rootPtr = current;
      delete remove;
      return true;
    }
    // if current has one child
    else {
      TreeNode<ItemType> *parent = findParent(current->getItem());
      parent->setLeftChildPtr(current->getRightChildPtr());
      current->setLeftChildPtr(remove->getLeftChildPtr());
      current->setRightChildPtr(remove->getRightChildPtr());
      this->rootPtr = current;
      delete remove;
      return true;
    }
  }
  // if root has one child
  else if (remove->getLeftChildPtr() != nullptr ||
           remove->getRightChildPtr() != nullptr) {
    // if root has left child
    if (remove->getLeftChildPtr() != nullptr) {
      this->rootPtr = remove->getLeftChildPtr();
      if (this->rootPtr->getRightIsThread()) {
        this->rootPtr->setRightChildPtr(nullptr);
        this->rootPtr->setRightIsThread(false);
      }
      delete remove;
      return true;
    }
    // if root has right child
    else {
      this->rootPtr = remove->getRightChildPtr();
      if (this->rootPtr->getRightIsThread()) {
        this->rootPtr->setRightChildPtr(nullptr);
        this->rootPtr->setRightIsThread(false);
      }
      delete remove;
      return true;
    }
  }
  // if root has no child
  else {
    delete remove;
    this->rootPtr = nullptr;
    return true;
  }
}

// traverses tree in order and fills queue with pointers to nodes of the tree
template <typename ItemType>
void ThreadedBST<ItemType>::inOrderTraversal(
    TreeNode<ItemType> *currNode, std::queue<TreeNode<ItemType> *> &q) const {
  // base case
  if (currNode->isLeaf()) {
    q.push(currNode);
    return;
  }
  if (currNode->getLeftChildPtr() != nullptr) {
    inOrderTraversal(currNode->getLeftChildPtr(), q);
  }
  q.push(currNode);
  if (currNode->getRightChildPtr() != nullptr &&
      !currNode->getRightIsThread()) {
    inOrderTraversal(currNode->getRightChildPtr(), q);
  }
}

// threads the tree
template <typename ItemType> void ThreadedBST<ItemType>::threadTree() {
  std::queue<TreeNode<ItemType> *> q;
  inOrderTraversal(this->rootPtr, q);
  while (q.size() > 1) {
    TreeNode<ItemType> *leafThread;
    // if current item in queue is a leaf, set next item as its right child
    if (q.front()->isLeaf()) {
      leafThread = q.front();
      q.pop();
      leafThread->setRightChildPtr(q.front());
      leafThread->setRightIsThread(true);
    }
    q.pop();
  }
}

// recursive function to help with deep copying
template <typename ItemType>
void ThreadedBST<ItemType>::preOrderCopy(TreeNode<ItemType> *treeNode,
                                         TreeNode<ItemType> *prevNode) {
  // base case
  if (treeNode->isLeaf()) {
    prevNode->setLeftChildPtr(nullptr);
    prevNode->setRightChildPtr(nullptr);
    if (treeNode->getRightIsThread()) {
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
  if (treeNode->getRightIsThread()) {
    prevNode->setRightIsThread(true);
  }
  // recursive call
  preOrderCopy(treeNode->getLeftChildPtr(), prevNode->getLeftChildPtr());
  preOrderCopy(treeNode->getRightChildPtr(), prevNode->getRightChildPtr());
}

// basic Constructor for ThreadedBST
template <typename ItemType> ThreadedBST<ItemType>::ThreadedBST() {
  this->rootPtr = nullptr;
}

// constructor for ThreadedBST but also creates the root
template <typename ItemType>
ThreadedBST<ItemType>::ThreadedBST(const ItemType &rootItem) {
  this->rootPtr = new TreeNode<ItemType>(rootItem);
}

// uses preOrderCopy to make a deep copy of tree
template <typename ItemType>
ThreadedBST<ItemType>::ThreadedBST(const ThreadedBST<ItemType> &tree) {
  this->rootPtr = new TreeNode<ItemType>;
  this->rootPtr->setItem(tree.rootPtr->getItem());
  this->preOrderCopy(tree.rootPtr, this->rootPtr);
  this->threadTree();
}

// calls makeEmpty to empty the tree and delete the nodes
template <typename ItemType> ThreadedBST<ItemType>::~ThreadedBST() {
  this->makeEmpty(this->rootPtr);
}

// if the rootPtr is nullptr then tree is empty
template <typename ItemType> bool ThreadedBST<ItemType>::isEmpty() const {
  if (this->rootPtr == nullptr) {
    return true;
  }
  return false;
}

// recursive function to get the height of the tree
template <typename ItemType>
int ThreadedBST<ItemType>::getHeight(TreeNode<ItemType> *currNode) const {
  if (this->isEmpty()) {
    return 0;
  }
  // base case
  if (currNode->isLeaf()) {
    return 1;
  } else {
    int left = 0;
    int right = 0;
    if (currNode->getLeftChildPtr() != nullptr) {
      left = getHeight(currNode->getLeftChildPtr()) + 1;
    }
    right = getHeight(currNode->getRightChildPtr()) + 1;
    if (left > right) {
      return left;
    } else {
      return right;
    }
  }
}

// returns the number of nodes in the tree
template <typename ItemType>
int ThreadedBST<ItemType>::getNumberOfNodes() const {
  if (this->isEmpty()) {
    return 0;
  }
  std::queue<TreeNode<ItemType> *> q;
  inOrderTraversal(this->rootPtr, q);
  return q.size();
}

// creates a new node with item in it and inserts that node into the tree
template <typename ItemType> bool ThreadedBST<ItemType>::insert(ItemType item) {
  if (this->isEmpty()) {
    this->rootPtr = new TreeNode<ItemType>(item);
    this->rootPtr->setLeftChildPtr(nullptr);
    this->rootPtr->setRightChildPtr(nullptr);
    return true;
  }
  TreeNode<ItemType> *insert = new TreeNode<ItemType>(item);
  TreeNode<ItemType> *currNode = this->rootPtr;
  while (true) {
    // check left subtree
    if (item < currNode->getItem()) {
      if (currNode->getLeftChildPtr() == nullptr) {
        currNode->setLeftChildPtr(insert);
        this->threadTree();
        return true;
      } else {
        currNode = currNode->getLeftChildPtr();
      }
    }
    // check right subtree
    else {
      if (currNode->getRightChildPtr() == nullptr ||
          currNode->getRightIsThread()) {
        currNode->setRightChildPtr(insert);
        currNode->setRightIsThread(false);
        this->threadTree();
        return true;
      } else {
        currNode = currNode->getRightChildPtr();
      }
    }
  }
}

// given an item will return a pointer to a node that has the same item
template <typename ItemType>
TreeNode<ItemType> *ThreadedBST<ItemType>::findNode(ItemType find) const {
  TreeNode<ItemType> *currNode = this->rootPtr;
  while (find != currNode->getItem() && currNode != nullptr) {
    if (find < currNode->getItem()) {
      currNode = currNode->getLeftChildPtr();
    } else if (find > currNode->getItem()) {
      currNode = currNode->getRightChildPtr();
    }
  }
  if (currNode == nullptr) {
    std::cout << "Couldn't find value " << find << std::endl;
  }
  return currNode;
}

// finds the parent of the node that has the same item as find
template <typename ItemType>
TreeNode<ItemType> *ThreadedBST<ItemType>::findParent(ItemType find) const {
  TreeNode<ItemType> *currNode = this->rootPtr;
  TreeNode<ItemType> *parent = nullptr;
  while (find != currNode->getItem() && currNode != nullptr) {
    parent = currNode;
    if (find < currNode->getItem()) {
      currNode = currNode->getLeftChildPtr();
    } else if (find > currNode->getItem()) {
      currNode = currNode->getRightChildPtr();
    }
  }
  if (currNode == nullptr) {
    std::cout << "Couldn't find value " << find << std::endl;
  }
  return parent;
}

// returns a pointer to the root of the tree
template <typename ItemType>
TreeNode<ItemType> *ThreadedBST<ItemType>::getRoot() const{
  return this->rootPtr;
}

// removes the node that holds the same item as passed in
template <typename ItemType>
bool ThreadedBST<ItemType>::remove(ItemType toBeRemoved) {
  TreeNode<ItemType> *remove = findNode(toBeRemoved);
  TreeNode<ItemType> *parent = findParent(toBeRemoved);
  // if could not find item to remove
  if (remove == nullptr) {
    std::cout << "Value can not be removed " << toBeRemoved << std::endl;
    return false;
  }
  // if wanting to remove root
  if (parent == nullptr) {
    return removeRoot(remove);
  }
  // if node too remove is on left side of parent
  else if (remove->getItem() < parent->getItem()) {
    parent->setLeftChildPtr(nullptr);
  }
  // if node too remove is on right side of parent
  else {
    parent->setRightChildPtr(nullptr);
  }
  // if remove has two children
  if (remove->getLeftChildPtr() != nullptr &&
      remove->getRightChildPtr() != nullptr) {
    TreeNode<ItemType> *current = remove;
    current = current->getRightChildPtr();
    current = this->getLeftMost(current);
    // if current has no children
    if (current->getRightChildPtr() == nullptr) {
      TreeNode<ItemType> *parent = findParent(current->getItem());
      parent->setLeftChildPtr(nullptr);
      current->setLeftChildPtr(remove->getLeftChildPtr());
      current->setRightChildPtr(remove->getRightChildPtr());
      delete remove;
      this->threadTree();
      return true;
    }
    // if current has one child
    else {
      TreeNode<ItemType> *parent = findParent(current->getItem());
      parent->setLeftChildPtr(current->getRightChildPtr());
      current->setLeftChildPtr(remove->getLeftChildPtr());
      current->setRightChildPtr(remove->getRightChildPtr());
      delete remove;
      this->threadTree();
      return true;
    }
  }
  // if remove has one child
  else if (remove->getLeftChildPtr() != nullptr ||
           remove->getRightChildPtr() != nullptr) {
    // remove has left child
    if (remove->getLeftChildPtr() != nullptr) {
      // if remove is left child of parent
      if (remove->getItem() < parent->getItem()) {
        parent->setLeftChildPtr(remove->getLeftChildPtr());
        delete remove;
        return true;
      }
      // if remove is right child of parent
      else {
        parent->setRightChildPtr(remove->getLeftChildPtr());
        delete remove;
        return true;
      }
    }
    // remove has right child
    else {
      // if remove is left child of parent
      if (remove->getItem() < parent->getItem()) {
        parent->setLeftChildPtr(remove->getRightChildPtr());
        delete remove;
        return true;
      }
      // if remove is right child of parent
      else {
        parent->setRightChildPtr(remove->getRightChildPtr());
        delete remove;
        return true;
      }
    }
  }
  // if remove has no children
  else {
    delete remove;
    return true;
  }
}

// makes the tree empty
template <typename ItemType>
void ThreadedBST<ItemType>::makeEmpty(TreeNode<ItemType> *currNode) {
  if (this->isEmpty()) {
    return;
  }
  // base case
  if (currNode->isLeaf()) {
    delete currNode;
    return;
  }
  if (currNode->getLeftChildPtr() != nullptr) {
    makeEmpty(currNode->getLeftChildPtr());
  }
  if (currNode->getRightChildPtr() != nullptr) {
    makeEmpty(currNode->getRightChildPtr());
  }
  delete currNode;
  rootPtr = nullptr;
  return;
}

// uses preOrderCopy to make a deep copy of right
template <typename ItemType>
ThreadedBST<ItemType> &
ThreadedBST<ItemType>::operator=(const ThreadedBST<ItemType> &right) {
  if (right.isEmpty()) {
    std::cout << "cannot copy empty tree" << std::endl;
    return *this;
  }
  this->rootPtr->setItem(right.rootPtr->getItem());
  this->preOrderCopy(right.rootPtr, this->rootPtr);
  this->threadTree();
}
