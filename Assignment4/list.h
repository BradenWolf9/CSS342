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
   // ~List();                           // destructor
   // List(const List&);                 // copy constructor
   bool insert(T*);                       // insert one Node into list
   bool isEmpty() const;                 // is list empty?
   void buildList(ifstream&);            // build a list from datafile

   // needs many more member functions to become a complete ADT

private:
   Node<T>* head;              // pointer to first node in list
};

#include "list.cpp"

#endif
