/**
 * @file listdriver.cpp
 * @brief
 * @author Braden Wolf
 */
#include "employee.h"
#include "list.h"
#include "node.h"
#include "nodedata.h" // as a template, must add nodedata include
#include <cassert>

// to compile under unix/linux:  g++ nodedata.cpp listdriver.cpp

void nodeDataTests() {
  NodeData *dataPtr;
  List<NodeData> mylist;
  NodeData *dataPtr2;
  List<NodeData> mylist2;

  // create file object and open the datafile
  ifstream dataInfile("listdata.txt");
  if (!dataInfile) {
    cout << "File could not be opened." << endl;
  }
  ifstream dataInfile2("listdata2.txt");
  if (!dataInfile) {
    cout << "File could not be opened." << endl;
  }

  // test lists equal each other when both empty
  assert(mylist == mylist2);

  // build list from data file
  mylist.buildList(dataInfile);
  mylist2.buildList(dataInfile2);

  // test sort
  mylist.sort();
  mylist2.sort();

  // test insert
  // now get node data from user and insert
  dataPtr = new NodeData;
  dataPtr->setData();
  mylist.insert(dataPtr);

  // insert another node where data is pre-determined
  dataPtr = new NodeData(1000, 'z');
  mylist.insert(dataPtr);
  dataPtr2 = new NodeData(1000, 'z');
  mylist2.insert(dataPtr2);

  // test remove
  Node<NodeData> removeTargetNode;
  removeTargetNode.setItem(dataPtr);
  Node<NodeData> *removeNode;
  assert(mylist.remove(removeTargetNode, removeNode));

  // test retrieve
  Node<NodeData> retrieveTargetNode;
  NodeData *retrieveDataPtr = new NodeData(1000, 'z');
  retrieveTargetNode.setItem(retrieveDataPtr);
  Node<NodeData> *retrieveNode;
  mylist2.retrieve(retrieveTargetNode, retrieveNode);
  assert(*retrieveTargetNode.getItem() == *retrieveNode->getItem());

  // test intersect
  // List<NodeData> intersectlist;
  // intersectlist.intersect(mylist, mylist2);
  // cout << endl << intersectlist << endl;

  // test operator=
  List<NodeData> mylist3;
  mylist3 = mylist2;
  assert(mylist2 == mylist3);

  // test operator!=, which uses operator==
  assert(mylist != mylist2);

  // test operator<<
  cout << endl << mylist << endl;
  cout << endl << mylist2 << endl;

  // test merge
  // List<NodeData> mergeList;
  // mergeList.merge(mylist, mylist2);
  // cout << endl << mergeList << endl;

  // test makeEmpty
  mylist.makeEmpty();
  assert(mylist.isEmpty());

  // delete dynnamically allocated memory
  //delete dataPtr;
  //delete dataPtr2;

  return;
}

void employeeTests() {
  Employee *employeePtr;
  List<Employee> mylist;

  Employee *employeePtr2;
  List<Employee> mylist2;

  // create file object and open the employee file
  ifstream employeeInfile("listemployee.txt");
  if (!employeeInfile) {
    cout << "File could not be opened." << endl;
  }

  ifstream employeeInfile2("listemployee2.txt");
  if (!employeeInfile2) {
    cout << "File could not be opened." << endl;
  }

  // build list from data file
  mylist.buildList(employeeInfile);
  mylist2.buildList(employeeInfile2);

  // insert another node where data is pre-determined
  employeePtr = new Employee("johnson", "ross", 5738, 200000);
  mylist.insert(employeePtr);
  employeePtr2 = new Employee("johnson", "ross", 5738, 200000);
  mylist2.insert(employeePtr2);

  // sort
  mylist.sort();
  mylist2.sort();

  // print, sorted list
  cout << endl << mylist << endl;
  cout << endl << mylist2 << endl;
}

int main() {
  nodeDataTests();
  employeeTests();
  return 0;
}
