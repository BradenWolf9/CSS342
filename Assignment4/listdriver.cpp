/**
 * @file listdriver.cpp
 * @brief
 * @author Braden Wolf
 */
#include "nodedata.h"             // as a template, must add nodedata include
#include "list.h"

// to compile under unix/linux:  g++ nodedata.cpp listdriver.cpp

int main() {
   NodeData* ptr;
   List<NodeData> mylist;

   // create file object and open the datafile
   ifstream infile("listdata.txt");
   if (!infile) {
      cout << "File could not be opened." << endl;
      return 1;
   }

   // build list from data file
   mylist.buildList(infile);

   // now get node data from user and insert
   ptr = new NodeData;
   if (ptr == nullptr) return 1;
   ptr->setData();
   mylist.insert(ptr);
   delete ptr;

   // insert another node where data is pre-determined
   ptr = new NodeData(1000,'z');
   mylist.insert(ptr);
   delete ptr;

   // null out ptr
   ptr = nullptr;

   // print, sorted by number
   cout << endl << mylist << endl;

   return 0;
}
