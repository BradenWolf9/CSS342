/**
 * @file list.h
 * @brief
 * @author Braden Wolf
 */
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include "node.h"

using namespace std;

//--------------------------  class List  ------------------------------------
// ADT List: finite, ordered collection of zero or more items.
//           The ordering is determined by operator< of T class.
//
// Assumptions:
//   -- Control of <, printing, etc. of T information is in the T class.
//   -- There is no dummy head node, head points to first node.
//      If the list is empty, head is NULL.
//   -- The insert allocates memory for a Node, ptr to the data is passed in.
//      Allocating memory and setting data is the responsibility of the caller.
//
// Note this definition is not a complete class and is not fully documented.
//----------------------------------------------------------------------------

template <typename T>
class List {

   // output operator for class List, print data,
   // responsibility for output is left to object stored in the list
   friend ostream& operator<<(ostream& output, const List<T>& thelist) {
      Node<T> *current = thelist.head;
      while (current != nullptr) {
         output << *current->getItem();
         current = current->getNext();
      }
      return output;
}

public:
   List();                               // default constructor
   List(const List<T>& copyThis);          // copy constructor
   void buildList(ifstream&);            // build a list from datafile
   bool sort();                          // sorts nodes in the list
   bool insert(T*);                      // insert one Node into list
   // remove first parameter, the object, from the list and set the second
   // parameter to the Object* from the list if it is found. The return value
   // is whether the removal was successful. Second parameter is unreliable
   // (although it's best to set it to nullptr) if return value is false.
   // Remove from list
   bool remove(const Node<T> &target, Node<T>* &targetPtr);
   // similar to remove, but not removed from list.  If there are duplicates
   // in the list, the first one encountered is retrieved. Second parameter is
   // null if the return value is false
   bool retrieve(const Node<T> &target, Node<T>* &targetPtr) const;
   // takes 2 sorted lists and merge into one long sorted list (No new memory
   // is allocated. At termination of function, the two parameter lists are
   // empty unless one is also the current object. Duplicates are allowed in a
   // merged list.)  (O(n) time, so insert must not be used or time would be
   // O(n2))
   void merge(List<T> one, List<T> two);
   // takes 2 sorted lists and finds the items in common in both lists (New
   // memory is allocated; at termination of the function, the two parameter
   // lists are unchanged unless one is also the current object.)
   void intersect(const List<T> &one, const List<T> &two);
   bool isEmpty() const;                 // is list empty?
   bool makeEmpty();                     // removes all nodes from list
   // to assign one list to another, deep copy (all new memory)  (Takes O(n)
   // time. No insert() call.)
   void operator=(const List<T>& copyThis);
   bool operator==(const List<T>& right) const;
   bool operator!=(const List<T>& right) const;
   ~List();                               // destructor


   // needs many more member functions to become a complete ADT

private:
   Node<T>* head;              // pointer to first node in list
};

#include "list.cpp"

#endif
