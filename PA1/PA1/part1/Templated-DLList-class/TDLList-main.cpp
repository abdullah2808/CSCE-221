// testing the templated class DLList

#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>

#include "TemplatedDLList.h"

using namespace std;

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList<string> dll;
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_last(ss.str());
  }
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i<=100; i+=10) {
    stringstream ss;
    ss << i;
    dll.insert_first(ss.str());
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList<string> dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  cout << "Assign to another new list" << endl;
  DLList<string> dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i<10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl;

  // more testing...
  // add tests for insert_after, insert_before
  // add tests for remove_after, remove_before
  DLListNode<string>* pvalue = dll2.first_node()->next;
  cout << "Testing insert after on list 2" << endl << "inserting after the value " << pvalue->obj << endl << "and inserting a string hello " << endl;
  dll2.insert_after(*pvalue, "hello");
  cout << dll2 << endl << endl;


  DLListNode<string>* pvalue2 = dll3.first_node()->next->next->next->next->next;
  cout << "Testing insert before on list 3" << endl << "inserting before the value " << pvalue2->obj << endl << "and inserting a string blue " << endl;
  dll3.insert_before(*pvalue2, "blue");
  cout << dll3 << endl << endl;


  DLListNode<string>* pvalue3 = dll2.first_node()->next->next->next->next->next->next->next;
  cout << "Testing remove after on list 2" << endl << "Removing after " << pvalue3->obj << endl;
  dll2.remove_after(*pvalue3);
  cout << dll2 << endl << endl;

  DLListNode<string>* pvalue4 = dll3.first_node()->next->next->next->next->next;
  cout << "Testing remove before on list 3" << endl << "Removing before " << pvalue4->obj << endl;
  dll3.remove_before(*pvalue4);
  cout << dll3 << endl << endl;

  cout << "testing move assignment by creating new list 4 by moving list 2 into it" << endl;
  DLList<string> dll4 = move(dll2);
  cout << "list 4: " << endl << dll4 << endl << endl;


  cout << "testing copy assignment by creating new list 5 by copying list 3" << endl;
  DLList<string> dll5 = move(dll3);
  cout << "list 5: " << endl << dll5 << endl << endl;
  return 0;
}
