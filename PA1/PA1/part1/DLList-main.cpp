// test of the DLList class

#include <iostream>
#include <cstdlib>
#include "DLList.h"

using namespace std;

int main ()
{
  // Construct a linked list with header & trailer
  cout << "Create a new list" << endl;
  DLList dll;
  cout << "list: " << dll << endl << endl;
  
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_last(i);
  }
  cout << "list: " << dll << endl << endl;

  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10; i <= 100; i+=10) {
    dll.insert_first(i);
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Copy to a new list" << endl;
  DLList dll2(dll);
  cout << "list2: " << dll2 << endl << endl;
  
  cout << "Assign to another new list" << endl;
  DLList dll3;
  dll3 = dll;
  cout << "list3: " << dll3 << endl << endl;
  
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_last();
  }
  cout << "list: " << dll << endl << endl;
  
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0; i < 10; i++) {
    dll.remove_first();
  }
  cout << "list: " << dll << endl << endl;
  
  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl << endl;

  // more testing...
  // add tests for insert_after, insert_before
  // add tests for remove_after, remove_before
  DLListNode * pvalue = dll2.first_node()->next;
  cout << "Testing insert after on list 2" << endl << "inserting after the value " << pvalue->obj << endl << "and inserting a value of 26 " << endl;
  dll2.insert_after(*pvalue, 26);
  cout << dll2 << endl << endl;


  DLListNode* pvalue2 = dll3.first_node()->next->next->next->next->next;
  cout << "Testing insert before on list 3" << endl << "inserting before the value " << pvalue2->obj << endl << "and inserting a value of 41 " << endl;
  dll3.insert_before(*pvalue2, 41);
  cout << dll3 << endl << endl;


  DLListNode* pvalue3 = dll2.first_node()->next->next->next->next->next->next->next;
  cout << "Testing remove after on list 2" << endl << "Removing after " << pvalue3->obj << endl;
  dll2.remove_after(*pvalue3);
  cout << dll2 << endl << endl;

  DLListNode* pvalue4 = dll3.first_node()->next->next->next->next->next;
  cout << "Testing remove before on list 3" << endl << "Removing before " << pvalue4->obj << endl;
  dll3.remove_before(*pvalue4);
  cout << dll3 << endl << endl;

  cout << "testing move assignment by creating new list 4 by moving list 2 into it" << endl;
  DLList dll4 = move(dll2);
 cout << "list 4: " << endl << dll4 << endl << endl;


 cout << "testing copy assignment by creating new list 5 by copying list 3" << endl;
 DLList dll5 = move(dll3);
 cout << "list 5: " << endl << dll5 << endl << endl;

  return 0;
}

