/**
 * @file main.cpp
 *
 * @brief ICA - Brown Fox, your job is to convert saying[] to a linked list,
 * print out the saying from the linked list, and clean up any memory you've
 * allocated on the heap.  Only use saying[] and lengthOfSaying when you
 * convert saying[] to a list. Don't use these variables to print the saying.
 *
 * @author Your Name
 */
 
#include "node.h"
#include <iostream>


int main() {

  std::string saying[] = {"The",  "quick", "brown", "fox", "jumps",
                          "over", "the",   "lazy",  "dog"};


  int lengthOfSaying = sizeof(saying) / sizeof(saying[0]);



  Node<std::string> *headerNode = nullptr;
  Node<std::string> *assistantNode = nullptr;


  // Converts saying[] to a linked list of nodes
  for (int i = (lengthOfSaying - 1); i >= 0; i--) {
    headerNode = new Node<std::string>(saying[i], assistantNode);
    assistantNode = headerNode;
  }


  // Prints the saying from the linked list of nodes
  while (assistantNode != nullptr) {
    std::cout << assistantNode->getItem() << " ";
    assistantNode = assistantNode->getNext();
  }


  // Releases allocated heap memory
  while (headerNode != nullptr) {
    assistantNode = headerNode->getNext();
    delete headerNode;
    headerNode = assistantNode;
  }


  // Makes sure pointers don't have access to the heap memory still
  headerNode = nullptr;
  assistantNode = nullptr;


  return 0;
}
