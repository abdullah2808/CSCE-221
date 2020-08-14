#include<iostream>
#include<list>
using namespace std;


template <class T>
void insert(list<T>& MPQ, const T Data) {
	MPQ.push_front(Data); // simple O(1) runtime
}

template <class T>
T remove_min(list<T>& MPQ) { // O(n)
	T temp;
	temp = MPQ.front();
	typename list<T>::iterator it, it2;
	it2 = MPQ.begin();
	for (it = MPQ.begin(); it != MPQ.end(); it++) {
		if (*it < temp) {
			temp = *it;
			it2 = it;
		}
	}
	MPQ.erase(it2); 
	return temp;
}

template <class T>
bool is_emptyy(list<T> MPQ) { // O(1)
	if (MPQ.size() == 0) return true;
	else return false;

}

template <class T>
void show_list(list<T> MPQ) {
	typename list<T>::iterator it;
	for (it = MPQ.begin(); it != MPQ.end(); it++) {
		cout << *it << endl;
	}
}
// GIVEN BELOW IS A MAIN FUNCTION I USED FOR TESTING
/*int main() {
	list<int> MPQ;
	cout << "Constructing a new list of ints" << endl;
	cout << "Is the list empty: " << is_emptyy(MPQ) << endl; // after initial creation
	insert(MPQ, 4);
	insert(MPQ, 16);
	insert(MPQ, 2);
	insert(MPQ, 45);
	insert(MPQ, 1);
	cout << "Elements added." << endl;
	cout << "Is the list empty: " << is_emptyy(MPQ) << endl; // after adding some elements
	cout << "The smallest element is: " << remove_min(MPQ) << endl;
	show_list(MPQ);
	cout << "The smallest element is: " << remove_min(MPQ) << endl;
	show_list(MPQ);
	cout << "The smallest element is: " << remove_min(MPQ) << endl;
	show_list(MPQ);
	cout << "The smallest element is: " << remove_min(MPQ) << endl;
	show_list(MPQ);
	cout << "The smallest element is: " << remove_min(MPQ) << endl;
	show_list(MPQ);
	cout << "Is the list empty: " << is_emptyy(MPQ) << endl; // after removing all elements
	return 0;
}
*/