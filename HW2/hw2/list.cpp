#include<list>
#include <iostream>

using namespace std;

list<int> intersection(list<int> L1, list<int> L2) 
{
	// construct a new list to return
	list<int> L3;
	// iterators
	list<int>::iterator it1;
	list<int>::iterator it2;

	it1 = L1.begin();

	it2 = L2.begin();

	while (it1 != L1.end() && it2 != L2.end()) {
		if (*it1 < *it2)
			it1++;
		else if (*it2 < *it1)
			it2++;
		else {
			L3.push_back(*it1);
			it1++;
			it2++;
		}
	}
	return L3;
}

void print(list<int> L1) {
	for (auto it = L1.begin(); it != L1.end(); ++it)
		cout << ' ' << *it;
}

int main() {
	list<int> L1, L2, L3;
	for (int i = 0; i < 9; i++) {
		L1.push_back(i);
	}
	for (int i = 0; i < 15; i++) {
		L2.push_back(i);
	}

	L3 = intersection(L1, L2);

	print(L1);
	cout << endl;
	print(L2);
	cout << endl;
	print(L3);

	return 0;
}
