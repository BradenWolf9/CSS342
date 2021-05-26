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
 * copy constructor
 */
template <typename T>
List<T>::List(const List<T>& copyThis) {
  *this = copyThis;
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



// bubble sorts nodes in the list from lowest to highest
// returns true if ends sorted
template <typename T>
bool List<T>::sort() {

  if (this->isEmpty()) {return false;}

  Node<T> *current = head->getNext();     // to walk list
  Node<T> *previous = head;               // to walk list, lags behind

  // only one node in list, dont need to sort, return true
  if (current == nullptr) {return true;}

  else {
    bool swap = true;
    // continue until no nodes swap, which means list is sorted
    while (swap) {

      // will be changed back to true if any nodes are swapped
      swap = false;

      // check if first node is bigger than second, and adjust if needed
      if (*previous->getItem() > *current->getItem()) {
        previous->setNext(current->getNext());
        current->setNext(previous);
        this->head = current;
        current = this->head->getNext();
        previous = head;
        swap = true;
      }
      // check rest of list until end
      while (current->getNext() != nullptr) {
        if (*current->getItem() > *current->getNext()->getItem()) {

          previous->setNext(current->getNext());
          current->setNext(current->getNext()->getNext());
          previous->getNext()->setNext(current);
          previous = previous->getNext();
          swap = true;
        }
        else {
          current = current->getNext();
          previous = previous->getNext();
        }
      }
      current = this->head->getNext();
      previous = this->head;
    }
  }
  return true;
}



/**
 * insert
 * insert an item into list; operator< of the T class
 * has the responsibility for the sorting criteria
 */
template <typename T>
bool List<T>::insert(T* data) {

   Node<T> *ptr = new Node<T>();
   if (ptr == nullptr) return false; // out of memory, bail
   ptr->setItem(data);               // link the node to data

   // if the list is empty or if the node should be inserted before
   // the first node of the list
   if (isEmpty() || *ptr->getItem() < *head->getItem()) {
      ptr->setNext(head);
      head = ptr;
   }

   // then check the rest of the list until we find where it belongs
   else {
      Node<T> *current = head->getNext();     // to walk list
      Node<T> *previous = head;               // to walk list, lags behind

      // walk until end of the list or found position to insert
      while (current != nullptr && *current->getItem() < *ptr->getItem()) {
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
bool List<T>::remove(const Node<T> &target, Node<T>* &targetPtr) {
  targetPtr = nullptr;

  if (this->isEmpty()) {
    return false;
  }

  else {
    Node<T> *current = head->getNext();     // to walk list
    Node<T> *previous = head;               // to walk list, lags behind

    // if first node is target, remove
    if (*previous->getItem == target) {
      targetPtr = previous->getItem();
      this->head = previous->getNext();
      previous->setNext(nullptr);
      previous->setItem(nullptr);
      delete previous;
      return true;
    }

    // check rest of list
    else {
      // traverse list
      while (current != nullptr) {

        // if target found, remove
        if (*current->getItem == target) {
          targetPtr = current->getItem();
          previous->setNext(current->getNext());
          current->setNext(nullptr);
          current->setItem(nullptr);
          delete previous;
          return true;
        }

        // continue to next node
        current = current->getNext();
        previous = previous->getNext();
      }
    }
  }
  return false;
}



// similar to remove, but not removed from list.  If there are duplicates
// in the list, the first one encountered is retrieved. Second parameter is
// null if the return value is false
template <typename T>
bool List<T>::retrieve(const Node<T> &target, Node<T>* &targetPtr) const {
  targetPtr = nullptr;

  if (this->isEmpty()) {
    return false;
  }

  else {
    Node<T> *current = head->getNext();     // to walk list
    Node<T> *previous = head;               // to walk list, lags behind

    // check first node
    if (*previous->getItem == target) {
      targetPtr = previous;
      return true;
    }

    // check rest of list
    else {
      // traverse list
      while (current != nullptr) {

        // if target found
        if (*current->getItem == target) {
          targetPtr = current;
          return true;
        }

        // continue to next node
        current = current->getNext();
        previous = previous->getNext();
      }
    }
  }
  return false;
}



// takes 2 sorted lists and merge into one long sorted list (No new memory
// is allocated. At termination of function, the two parameter lists are
// empty unless one is also the current object. Duplicates are allowed in a
// merged list.)  (O(n) time, so insert must not be used or time would be
// O(n2))
template <typename T>
void List<T>::merge(List<T> one, List<T> two) {
  // if both one and two are empty, cannot merge
  if (one.isEmpty() && two.isEmpty()) {
    this->head = nullptr;
    return;
  }

  Node<T> *thisPrevious = this->head;
  Node<T> *thisCurrent = this->head;
  Node<T> *oneCurrent = one.head;
  Node<T> *twoCurrent = two.head;

  // set first node of new list
  // both one and two cannot be empty because of check at beginning of function
  // if two is empty or one is current node is lower
  if (twoCurrent == nullptr || *oneCurrent.getItem() < *twoCurrent.getItem()) {
    thisPrevious = oneCurrent;
    this->head = thisPrevious;
    oneCurrent = oneCurrent->getNext();
  // if two current node is lower
  } else {
    thisPrevious = twoCurrent;
    this->head = thisPrevious;
    twoCurrent = twoCurrent->getNext();
  }

  // set rest of list, walking through one and two
  while (oneCurrent != nullptr && twoCurrent != nullptr) {
    // both one and two cannot be empty because of check in while statement
    // if two is empty or one current node is lower
    if (twoCurrent == nullptr ||
        *oneCurrent.getItem() < *twoCurrent.getItem()) {
      thisCurrent = oneCurrent;
      oneCurrent = oneCurrent->getNext();
      thisPrevious->setNext(thisCurrent);
      thisPrevious = thisCurrent;
    } else {
      thisCurrent = twoCurrent;
      twoCurrent = twoCurrent->getNext();
      thisPrevious->setNext(thisCurrent);
      thisPrevious = thisCurrent;
    }
  } // end while, thisCurrent, oneCurrent, and twoCurrent should end on nullptr
  //make sure last node next points to nullptr
  thisPrevious->setNext(thisCurrent);
  thisPrevious = nullptr;
  return;
}



// takes 2 sorted lists and finds the items in common in both lists (New
// memory is allocated; at termination of the function, the two parameter
// lists are unchanged unless one is also the current object.)
template <typename T>
void List<T>::intersect(const List<T> &one, const List<T> &two) {
  Node<T> *thisPrevious = this->head;
  Node<T> *thisCurrent = this->head;
  Node<T> *oneCurrent = one.head;
  Node<T> *twoCurrent = two.head;

  // walk through both lists
  while (oneCurrent != nullptr && twoCurrent != nullptr) {
    if (*oneCurrent == *twoCurrent) {
      this->insert(*oneCurrent->getItem());
    }
    oneCurrent = oneCurrent->getNext();
    twoCurrent = twoCurrent->getNext();
  }
  return;
}



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
void List<T>::operator=(const List<T>& copyThis) {
  this->head = copyThis.head;

  Node<T> *copyCurrent = copyThis.head;
  Node<T> *thisCurrent;
  Node<T> *thisPrevious;

  // set first
  thisPrevious = new Node<T>();
  thisPrevious->setItem(copyCurrent->getItem());
  this->head = thisPrevious;

  // travers copyThis list
  while (copyCurrent != nullptr) {
    copyCurrent = copyCurrent->getNext();
    thisCurrent = new Node<T>();
    thisCurrent->setItem(copyCurrent->getItem());
    thisPrevious->setNext(thisCurrent);

    // continue to next node
    thisCurrent = thisCurrent->getNext();
    thisPrevious = thisPrevious->getNext();
  }
}



template <typename T>
bool List<T>::operator==(const List<T>& right) const {
  Node<T> *thisCurrent = this->head;
  Node<T> *rightCurrent = right.head;
  // traverse through list
  while (thisCurrent != nullptr) {
    // if nodes in same order are not equal, then lists are not equal
    if (thisCurrent->getItem() != rightCurrent.getItem()) {
      return false;
    }
    // move on to next nodes in both lists
    thisCurrent = thisCurrent->getNext();
    rightCurrent = rightCurrent->getNext();
  }
  // make sure both ended on nullptr, signifying end of list
  if (thisCurrent->getItem() != rightCurrent.getItem()) {
    return false;
  }

  return true;
}



template <typename T>
bool List<T>::operator!=(const List<T>& right) const {
  return !(*this == right);
}



/**
 * destructor
 */
template <typename T>
List<T>::~List() {
  this->makeEmpty();
}
