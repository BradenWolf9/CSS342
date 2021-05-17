/**
 * @file list.cpp
 * @brief
 * @author Braden Wolf
 */
#include "node.h"

/**
 * Constructor
 */
template <typename T>
List<T>::List() {
   head = nullptr;
}

//----------------------------------------------------------------------------
// isEmpty
// check to see if List is empty as defined by a NULL head
template <typename T>
bool List<T>::isEmpty() const {
   return head == nullptr;
}

/**
 * insert
 * insert an item into list; operator< of the T class
 * has the responsibility for the sorting criteria
 */
template <typename T>
bool List<T>::insert(T* data) {

   Node<T> *ptr= new Node<T>();
   if (ptr == nullptr) return false; // out of memory, bail
   ptr->setItem(data);               // link the node to data

   // if the list is empty or if the node should be inserted before
   // the first node of the list
   if (isEmpty() || ptr->getItem() < head->getItem()) {
      ptr->setNext(head);
      head = ptr;
   }

   // then check the rest of the list until we find where it belongs
   else {
      Node<T> *current = head->getNext();     // to walk list
      Node<T> *previous = head;               // to walk list, lags behind

      // walk until end of the list or found position to insert
      while (current != nullptr && current->getItem() < ptr->getItem()) {
            previous = current;                  // walk to next node
            current = current->getNext();
      }

      // insert new node, link it in
      ptr->setNext(current);
      previous->setNext(ptr);
   }
   return true;
}

/**
 * buildList
 * continually insert new items into the list
 */
template <typename T>
void List<T>::buildList(ifstream& infile) {
   T* ptr;
   bool successfulRead;                            // read good data
   bool success;                                   // successfully insert
   for (;;) {
      ptr = new T;
      successfulRead = ptr->setData(infile);       // fill the T object
      if (infile.eof()) {
         delete ptr;
         ptr = nullptr;
         break;
      }

      // insert good data into the list, otherwise ignore it
      if (successfulRead) {
         success = insert(ptr);
      }
      else {
         delete ptr;
         ptr = nullptr;
      }

      // if item was not inserted, throw it away
      if (!success) {
         delete ptr;
         ptr = nullptr;
      }
   }
}
