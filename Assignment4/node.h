/**
 * @file node.h
 * @brief Modified (incomplete & partially documented) from the Node class by
 * Frank M. Carrano and Timothy M. Henry.
 * @author Braden Wolf
 */
#ifndef NODE_
#define NODE_

template<class ItemType>
class Node
{
private:
   ItemType       *itemPtr;   // Pointer to a data item
   Node<ItemType> *next;      // Pointer to next node

public:
   Node();
   Node(ItemType* anItemPtr);
   Node(ItemType* anItemPtr, Node<ItemType>* nextNodePtr);
   void setItem(ItemType* anItemPtr);
   void setNext(Node<ItemType>* nextNodePtr);
   ItemType* getItem() const ;
   Node<ItemType>* getNext() const ;
   ~Node();
}; // end Node

#include "node.cpp"
#endif
