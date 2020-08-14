#include<vector>
#include<iostream>
using namespace std;

template <class T> class MPQ;

template <class T>
void insert(vector<T>& MPQ,const T Data) {
	MPQ.push_back(Data); // simple push back O(1)
}

template <class T>
T remove_min(vector<T>& MPQ) {
	T temp = MPQ.at(0);
	int n = 0;
	for (int i = 0;i < MPQ.size() ;i++) // this finds the minimum element in this list O(n) complexity
	{
		if (MPQ.at(i) < temp) {
			temp = MPQ.at(i);
			n = i;
		}
	}
	MPQ.erase(MPQ.begin() + n); // removes the minimum element 
	return temp;
}

template <class T>
bool is_emptyy(vector<T> MPQ) { // O(1)
	if (MPQ.size() == 0) return true;
	else return false;

}
// GIVEN BELOW IS A MAIN FUNCTION I USED FOR TESTING
/*
int main() {
	vector<int> MPQ;
	cout << "Constructing a new vector of ints" << endl;
	cout << "Is the vector empty: " << is_emptyy(MPQ) << endl; // after initial creation
	insert(MPQ, 4);
	insert(MPQ, 16);
	insert(MPQ, 2);
	insert(MPQ, 45);
	insert(MPQ, 1);
	cout << "Elements added." << endl;
	cout << "Is the vector empty: " << is_emptyy(MPQ) << endl; // after adding some elements
	cout << "The minimum element is: " << remove_min(MPQ) << endl;
	cout << "The minimum element is: " << remove_min(MPQ) << endl;
	cout << "The minimum element is: " << remove_min(MPQ) << endl;
	cout << "The minimum element is: " << remove_min(MPQ) << endl;
	cout << "The minimum element is: " << remove_min(MPQ) << endl;
	cout << "Is the vector empty: " <<is_emptyy(MPQ) << endl; // after removing all elements
	cout << "Constructing a new vector of doubles" << endl;
	vector<double> MPQ1;
	insert(MPQ1, 4.2);
	insert(MPQ1, 4.2);
	insert(MPQ1, 4.1);
	insert(MPQ1, 6.2);
	insert(MPQ1, 1002.3);
	insert(MPQ1, 421.32);
	cout << "Elements added." << endl;
	cout << "Is the vector empty: " << is_emptyy(MPQ1) << endl; // after adding some elements
	cout << "The minimum element is: " << remove_min(MPQ1) << endl;
	cout << "The minimum element is: " << remove_min(MPQ1) << endl;
	cout << "The minimum element is: " << remove_min(MPQ1) << endl;
	cout << "The minimum element is: " << remove_min(MPQ1) << endl;
	cout << "The minimum element is: " << remove_min(MPQ1) << endl;
	cout << "The minimum element is: " << remove_min(MPQ1) << endl;
	cout << "Is the vector empty: " << is_emptyy(MPQ1) << endl; // after removing all elements
	return 0;
}
}
*/
