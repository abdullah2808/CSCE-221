#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;


class Record {
public:

    friend istream& operator>>(istream& input, Record& R) { //input operator takes in books from file
        string line;
        getline(input, line);
        if (line.size() == 0)  getline(input, line); 
        R.Title = line;
        getline(input, line);
        R.Author = line;
        getline(input, line);
        R.ISBN = line;
        getline(input, line);
        R.Year = line;
        getline(input, line);
        R.Edition = line;
        return input;
    } // Since there is 13 operations in the function the running time is 13, and the Big-Notation is O(1).
      // So the total runtime in the scope of the program is 130.
    friend ostream& operator<<(ostream& output, const Record& R) { //output operator 
        output << "Title: " << R.Title << " Author: " << R.Author << " ISBN: " << R.ISBN << " Year: " << R.Year
            << " Edition: " << R.Edition;
        return output;
    } // Since there is 10 cout operations in the function the running time is 10, and the Big-O notation is O(1). It runs a total of 10 times cause there is 10 books.
      // So the total runtime in the scope of the program is 100.

    friend bool operator<(const Record& r1, const Record& r2) {
        return (r1.Title == r2.Title) && (r1.Author == r2.Author) && (r1.ISBN == r2.ISBN);
    }
    

    string ISBN, Title, Author, Edition, Year;
};


int main() {
    vector<Record> BookList;
    Record Book;


    ifstream FileRead("Book.txt");   // open file and read into BookList
    while (FileRead){
        FileRead >> Book;
        BookList.push_back(Book);
    }
    FileRead.close();

    for (int i = 0; i < (BookList.size() - 1); i++) cout << BookList.at(i) << endl; // print vector

    cout << (BookList.at(1) < BookList.at(2)); // checking for 2 books that should not match output should be 0
    BookList.at(2) = BookList.at(1); // setting 2 books in the vectors to the same to check the < operator output should be 1
    cout << (BookList.at(1) < BookList.at(2));

  
    return 0;
}
