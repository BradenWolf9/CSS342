//
// Created by Braden Wolf on 04/07/2021.
//
// Library class demonstrating partially filled arrays
// Can add/remove books from library
// findbooks in library
// remove books
// list all books

#include "library.h"
#include <iostream>

// constructor with default name
Library::Library(const string &Name) : name{Name}, numBooks{INITIAL} {}

// destructor
// nothing on heap
Library::~Library() {
  // destructor
}

// true if book found in library
bool Library::isInLibrary(const string &BookName) const {
  for (int i = 0; i < numBooks; i++) {
    if (BookName == bookList[i]) {
      return true;
    }
  }
  return false;
}

// add a new book
// return true if successful, false if
// book already in library
bool Library::addBook(const string &BookName) {
  if (isInLibrary(BookName)) {
    return false;
  } else {
    bookList[numBooks] = BookName;
    numBooks++;
    return true;
  }
}

// returns index of given book,
// -1 if book not found
int Library::findBook(const string &BookName) const {
  for (int i = 0; i < numBooks; i++) {
    if (BookName == this->bookList[i]) {
      return i;
    }
  }
  return -1;
}

// remove a book
// return true if successfully removed
// false if book not in library
bool Library::removeBook(const string &BookName) {
  if (!isInLibrary(BookName)) {
    return false;
  } else {
    int removeThisBook = findBook(BookName);
    int const firstBook = 0;
    int const lastBook = numBooks - 1;
    if (this->numBooks == 1) {
      this->bookList[firstBook] = "";
      numBooks--;
      return true;
    } else if (removeThisBook != lastBook) {
      this->bookList[removeThisBook] = this->bookList[lastBook];
      numBooks--;
      return true;
    } else {
      this->bookList[lastBook] = "";
      numBooks--;
      return true;
    }
  }
}

// add other list of library books to this list
Library &Library::operator+=(const Library &other) {
  for(int i = 0; i < other.numBooks; i++) {
    this->bookList[this->numBooks + i] = other.bookList[i];
    this->numBooks++;
  }
  return *this;
}

// list all books
void Library::listAllBooks() const { std::cout << *this; }

ostream &operator<<(ostream &Out, const Library &Lib) {
  int currBook = 0;
  for (int i = 0; i < Lib.numBooks; i++) {
    currBook = i + 1;
    Out << "Book " << currBook << ": " << Lib.bookList[i] << std::endl;
  }
  return Out;
}
