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



// sort by nodes in the list
template <typename T>
bool List<T>::sort() {return true;}



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



// remove first parameter, the object, from the list and set the second
// parameter to the Object* from the list if it is found. The return value
// is whether the removal was successful. Second parameter is unreliable
// (although it's best to set it to nullptr) if return value is false.
// Remove from list
template <typename T>
bool List<T>::remove(const Node<T> &target, Node<T>* &targetPtr) {return true;}



// similar to remove, but not removed from list.  If there are duplicates
// in the list, the first one encountered is retrieved. Second parameter is
// null if the return value is false
template <typename T>
bool List<T>::retrieve(const Node<T> &target, Node<T>* &targetPtr) const {return true;}



// takes 2 sorted lists and merge into one long sorted list (No new memory
// is allocated. At termination of function, the two parameter lists are
// empty unless one is also the current object. Duplicates are allowed in a
// merged list.)  (O(n) time, so insert must not be used or time would be
// O(n2))
template <typename T>
void List<T>::merge(List<T> one, List<T> two) {}



// takes 2 sorted lists and finds the items in common in both lists (New
// memory is allocated; at termination of the function, the two parameter
// lists are unchanged unless one is also the current object.)
template <typename T>
void List<T>::intersect(const List<T> &one, const List<T> &two) {}



//----------------------------------------------------------------------------
// isEmpty
// check to see if List is empty as defined by a NULL head
template <typename T>
bool List<T>::isEmpty() const {
   return head == nullptr;
}



/**
 * clearList
 * removes all nodes from list
 *
 * @return true if list end up clear or false if it ends up not clear
 */
template <typename T>
bool List<T>::makeEmpty() {
  if (!this->isEmpty()) {
    Node<T>* next = nullptr;
    // traverse list and delete nodes
    while (head != nullptr) {
      next = this->head->getNext();
      delete this->head;
      this->head = next;
    } // both head and next finish as nullptr
  }
  return true;
}



// to assign one list to another, deep copy (all new memory)  (Takes O(n)
// time. No insert() call.)
template <typename T>
void List<T>::operator=(const List<T>& copyThis) {}


template <typename T>
bool List<T>::operator==(const List<T>& right) const {return true;}

template <typename T>
bool List<T>::operator!=(const List<T>& right) const {return true;}



/**
 * destructor
 */
template <typename T>
List<T>::~List() {
  this->makeEmpty();
}
