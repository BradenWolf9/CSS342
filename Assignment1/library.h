//
// Created by Yusuf Pisan on 3/26/18.
// Adjusted by Braden Wolf on 4/7/19
//

#ifndef ASS1_LIBRARY_H
#define ASS1_LIBRARY_H

#include <string>

// Only for class code, OK to use namespace
using namespace std;

// Library holds books - can add, remove and list books
class Library {
  // display all books in library
  friend ostream &operator<<(ostream &Out, const Library &Lib);


public:
  // constructor with default name
  explicit Library(const string &Name);

  // destructor
  virtual ~Library();

  // true if book found in library
  bool isInLibrary(const string &BookName) const;

  // add a new book
  // return true if successful, false if
  // book already in library
  bool addBook(const string &BookName);

  // returns index of given book,
  // -1 if book not found
  int findBook(const string &BookName) const;

  // remove a book
  // return true if successfully removed
  // false if book not in library
  bool removeBook(const string &BookName);

  // add other list of library books to this list
  Library &operator+=(const Library &other);

  // list all books
  void listAllBooks() const;

private:
  std::string name;
  static const int MAX = 100;
  std::string bookList[MAX];
  static const int INITIAL = 0;
  int numBooks;
};

#endif // ASS1_LIBRARY_H
