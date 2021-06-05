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
  if (rootPtr == nullptr) {
    return true;
  }
  return false;
}

template<typename ItemType>
bool ThreadedBST<ItemType>::insert(ItemType item) {
  if (this->isEmpty()) {
    this->rootPtr = new TreeNode<ItemType>(item);
    return true;
  }
  TreeNode<ItemType> *insert = new TreeNode<ItemType>(item);
  TreeNode<ItemType> *currNode = this->rootPtr;
  while (true) {
    // check left subtree
    if (item < currNode->getItem()) {
      if (currNode->getLeftChildPtr() == nullptr) {
        currNode->setLeftChildPtr(insert);
        return true;
      } else {
        currNode = currNode->getLeftChildPtr();
      }
    }
    // check right subtree
    else {
      if (currNode->getRightChildPtr() == nullptr) {
        currNode->setRightChildPtr(insert);
        return true;
      } else {
        currNode = currNode->getRightChildPtr();
      }
    }
  }
  return false;
}

template<typename ItemType>
TreeNode<ItemType>* ThreadedBST<ItemType>::findNode(ItemType& find) {
  TreeNode<ItemType> currNode = this->rootPtr;
  while(find != currNode->getItem() && currNode != nullptr) {
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

template<typename ItemType>
TreeNode<ItemType>* ThreadedBST<ItemType>::findParent(ItemType& find) {
  TreeNode<ItemType> currNode = this->rootPtr;
  TreeNode<ItemType> parent = nullptr;
  while(find != currNode->getItem() && currNode != nullptr) {
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

template<typename ItemType>
bool ThreadedBST<ItemType>::remove(ItemType& toBeRemoved) {
  TreeNode<ItemType>* remove = findNode(toBeRemoved);
  TreeNode<ItemType>* parent = findParent(toBeRemoved);
  // if could not find item to remove
  if (remove == nullptr) {
    std::cout << "Value can not be removed " << toBeRemoved << std:endl;
    return false;
  }
  // if wanting to remove root
  if (parent == nullptr) {
    
  }
  else if (remove->getItem() < parent->getItem()) {
    parent->setLeftChildPtr(nullptr);
  } else {
    parent->setRightChildPtr(nullptr);
  }

  // if remove has two children
  if (remove->getLeftChildPtr() !=nullptr &&
      remove->getRightChildPtr() != nullptr) {
    TreeNode<ItemType>* current = remove;
    current = current->getRightChildPtr();
    current = this->getLeftMost(current);
    // if current has no children
    if (current->getRightChildPtr() == nullptr) {
      current->setLeftChildPtr(remove->getLeftChildPtr());
      current->setRightChildPtr(remove->getRightChildPtr());
      delete remove;
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
