#include "TemplatedDLList.h"
#include "Record.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

void insert_record(vector<DLList<Record>>& v, Record r)
{
    char temp = '0';
    stringstream ss;
    ss << r.Title;
    ss >> temp; //get first letter
    int index = temp - 65;//shift index for ascill
    if (index < 0)
    {   
        index += 18;
        return;
    }
    v[index].insertOrdered(r); //insert into sorted list
}

void read(vector<DLList<Record>>& Library) {
    Record Book;
    char temp = '0';
    stringstream ss;
    ifstream FileRead("book.txt");   // open file and read
    while (FileRead) {
        FileRead >> Book;
        ss << Book.Title;
        ss >> temp; //get first letter
        int index = temp - 65;//shift index for ascill
        if (index != 0) insert_record(Library, Book);

    }
    FileRead.close();

}

void show(vector<DLList<Record> >& Library) {
	for (int i = 0; i < 26; i++)
		cout << Library[i] << endl;
}



Record* search(vector<DLList<Record>>& v, Record r)
{
    Record* result = new Record;
    char temp = '0';
    stringstream ss;
    ss << r.Title;
    ss >> temp; 

    int index = temp - 65;
    if (index < 0)
    {
        index += 18;
    }
    DLList<Record> temp_list1, temp_list2; 

    DLListNode<Record>* it = v[index].first_node();

    int counter = 0;

    while (it != v[index].after_last_node())
    {
        if (it->getElem().Title == r.Title)
        {
            *result = it->getElem();
            temp_list1.insertOrdered(*result);
            ++counter;

        }
        it = it->getNext();
    }
    if (counter == 0)
        return NULL;
    if (counter == 1)
        return result;
    cout << "There are " << counter << " books of the same title. " << endl
        << r.Title << "\nPlease input the edition of the book. "<< endl;
    getline(cin, r.Edition);
    counter = 0;
    it = temp_list1.first_node();
    while (it != temp_list1.after_last_node())
    {
        if (it->getElem().Edition == r.Edition)
        {
            *result = it->getElem();
            temp_list2.insertOrdered(*result);
            ++counter;
        }
        it = it->getNext();
    }
    if (counter == 0)
        return NULL;
    if (counter == 1)
        return result;

    return  result;
}

int main() {
    vector<DLList<Record>> Library(26);
    read(Library); // read book
    string author, bookIn;
    int i = 0;
    //show(Library);
    while (i == 0) {
        cout << "Please input the title of the book to begin search (remember to capitalize the first letter) or enter XEND to stop. " << endl;
        getline(cin, author);
        if (author == "XEND") break;
        Record input;
        input.Title = author;
        Record* result = search(Library, input);
        if (result == NULL) { //if the book is not found add it to the library 
            cout << "The the book was not found, you can enter it into the library now:" << endl;
            cout << "Enter Author: " << endl;
            getline(cin, bookIn);
            input.Author = bookIn;
            cout << "ISBN: " << endl;
            getline(cin, bookIn);
            input.ISBN = bookIn;
            cout << "Year: " << endl;
            getline(cin, bookIn);
            input.Year = bookIn;
            cout << "Edition: " << endl;
            getline(cin, bookIn);
            input.Edition = bookIn;
            insert_record(Library, input);
        }
        else
            cout << "The book was found: " << endl << *result << endl;

    }
    // show(Library);
	return 0;
}