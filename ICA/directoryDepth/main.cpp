/*
 * @file: main.cpp
 *
 * @brief: Recursively finds what the directory depth of the current file is.
 *         Works on Linux machine with base directory being "home".
 *
 * @author: Braden Wolf
 */

#include "linux.cpp"
#include <cassert>
#include <iostream>
#include <string>

// Recursive function for getting the directory depth of a file from its path
int getDepth(std::string path) {
  std::string word;
  int last = path.size() - 1;
  // fill word that is the last directory in path and delete that word from path
  while (path[last] != '/') {
    word.push_back(path[last]);
    path.pop_back();
    last--;
  }
  // get rid of '/'
  assert(path[last] == '/');
  path.pop_back();
  // base case, words are backwords (home)
  if (word == "emoh") {
    return 0;
  } else {
    return getDepth(path) + 1;
  }
}

// Driver function for printing the file path and directory depth
int main() {
  std::cout << getExePath() << std::endl;
  std::cout << "File has a directory depth: " << getDepth(getExePath())
            << std::endl;
}
