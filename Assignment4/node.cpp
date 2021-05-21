/**
 * @file node.cpp
 * @brief Modified (incomplete & partially documented) from the Node class
 * created by Frank M. Carrano and Timothy M. Henry.
 * @author Braden Wolf
 */
#include "node.h"

template<class ItemType>
Node<ItemType>::Node() : next(nullptr)
{
} // end default constructor

template<class ItemType>
Node<ItemType>::Node(ItemType* anItemPtr) : itemPtr(anItemPtr), next(nullptr)
{
} // end constructor

template<class ItemType>
Node<ItemType>::Node(ItemType* anItemPtr, Node<ItemType>* nextNodePtr) :
                itemPtr(&anItemPtr), next(nextNodePtr)
{
} // end constructor

template<class ItemType>
void Node<ItemType>::setItem(ItemType* anItemPtr)
{
   itemPtr = anItemPtr;
} // end setItem

template<class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
   next = nextNodePtr;
} // end setNext

template<class ItemType>
ItemType* Node<ItemType>::getItem() const
{
   return itemPtr;
} // end getItem

template<class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
   return next;
} // end getNext

template<class ItemType>
Node<ItemType>::~Node()
{
  delete this->itemPtr;
  this->next = nullptr;
} // end destructor
