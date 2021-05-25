/**
 * @file listdriver.cpp
 * @brief
 * @author Braden Wolf
 */
#include "nodedata.h"             // as a template, must add nodedata include
#include "employee.h"
#include "list.h"

// to compile under unix/linux:  g++ nodedata.cpp listdriver.cpp

int main() {
   NodeData* dataPtr;
   List<NodeData> mydatalist;

   // create file object and open the datafile
   ifstream dataInfile("listdata.txt");
   if (!dataInfile) {
      cout << "File could not be opened." << endl;
      return 1;
   }

   // build list from data file
   mydatalist.buildList(dataInfile);

   // now get node data from user and insert
   dataPtr = new NodeData;
   if (dataPtr == nullptr) return 1;
   dataPtr->setData();
   mydatalist.insert(dataPtr);

   // insert another node where data is pre-determined
   dataPtr = new NodeData(1000,'z');
   mydatalist.insert(dataPtr);

   // sort
   mydatalist.sort();

   // print, sorted list
   cout << endl << mydatalist << endl;



   Employee* employeePtr;
   List<Employee> myemployeelist;

   // create file object and open the datafile
   ifstream employeeInfile("listemployee.txt");
   if (!employeeInfile) {
      cout << "File could not be opened." << endl;
      return 1;
   }

   // build list from data file
   myemployeelist.buildList(employeeInfile);

   // insert another node where data is pre-determined
   employeePtr = new Employee("johnson", "ross", 5738, 200000);
   myemployeelist.insert(employeePtr);

   // sort
   myemployeelist.sort();

   // print, sorted list
   cout << endl << myemployeelist << endl;


   return 0;
}
