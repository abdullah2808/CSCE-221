#pragma once

#ifndef RECORD_H
#define RECORD_H

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

#endif
