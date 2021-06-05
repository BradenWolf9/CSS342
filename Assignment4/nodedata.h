/**
 * @file nodedata.h
 * @brief Simple object containing one integer and one character
 * @author Braden Wolf
 */

#ifndef NODEDATA_H
#define NODEDATA_H

#include <fstream>
#include <iostream>
using namespace std;

//---------------------------  class NodeData  ------------------------------
class NodeData { // incomplete class
  friend ostream &operator<<(ostream &, const NodeData &);

public:
  NodeData(int n = 0, char c = 'z'); // default constructor
  bool setData();                    // sets data by prompting user
  bool setData(ifstream &);          // reads data from file

  // <, > are defined by order of num; if nums are equal, ch is compared
  bool operator<(const NodeData &) const;
  bool operator>(const NodeData &) const;
  bool operator==(const NodeData &) const;
  bool operator!=(const NodeData &) const;
  bool operator<=(const NodeData &) const;
  bool operator>=(const NodeData &) const;

  ~NodeData(); // destructor

private:
  int num;
  char ch;
};

#endif
