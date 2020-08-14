#include<iostream>
#include<vector>

using namespace std;

template <class T> class BinaryHeap;
template <class T> class BinaryHeap{
private:
	vector<T> array;
public:
	BinaryHeap() {}// default constructor 

	int parent(int i) { return ((i-1) / 2); }
	// to get index of left child of node at index i 
	int left(int i) { return ((2 * i) +1 ); }
	// to get index of right child of node at index i 
	int right(int i) { return ((2 * i) + 2); }

	void insert(T data);
	T remove_min();
	bool is_empty();
	void show_heap();
};



template <class T>
void BinaryHeap<T>::insert(T data) {
	this->array.push_back(data);
	int i = this->array.size() - 1;
	while (i != 0 && this->array.at(parent(i)) > this->array.at(i)) // sorting the binary heap O(log n) since i = parent which means i / 2 
	{
		swap(this->array.at(i), this->array.at(parent(i)));
		i = parent(i);
	}
}


template <class T>
T BinaryHeap<T>::remove_min() {
	//cout << "The smallest element is : " << this->array.at(0) << endl;
	T temp;
	temp = this->array.at(0);
	this->array.erase(this->array.begin());
	for (int i = 0; i < this->array.size(); i++) { // sort the binary heap again O(n) complexity since it runs through every element from I to array size.
		if(this->array.at(parent(i)) > this->array.at(i))
			swap(this->array.at(i), this->array.at(parent(i)));
	}
	return temp;
}


template <class T>
void BinaryHeap<T>::show_heap() {
	cout << "The current binary heap is:" << endl;
	for (int i = 0; i < this->array.size(); i++) {
		cout << this->array.at(i) << endl;
	}
}
template <class T>
bool BinaryHeap<T>::is_empty() {
	if (this->array.size() == 0) return true;
	else return false;

}

// GIVEN BELOW IS A MAIN FUNCTION I USED FOR TESTING
/*
int main() {
	cout << "Constructing binary heap!" << endl;
	BinaryHeap<int> BH;
	cout << "Currently the binary heap is empty so the check if empty should return 1: " << BH.is_empty() << endl;
	cout << "Adding some elements to binary heap." << endl;
	BH.insert(5);
	BH.insert(3);
	BH.insert(9);
	BH.insert(12);
	BH.insert(16);
	BH.insert(1);
	BH.insert(6);
	BH.insert(8);
	BH.insert(43);
	cout << "Currently the binary heap has elements, so the check if empty should return 0: " << BH.is_empty() << endl;
	BH.show_heap();
	cout << "The current lowest element is:" << BH.remove_min() << endl;
	BH.show_heap();
	cout << "The current lowest element is:" << BH.remove_min() << endl;
	BH.show_heap();
	cout << "The current lowest element is:" << BH.remove_min() << endl;
	BH.show_heap();
	cout << "The current lowest element is:" << BH.remove_min() << endl;
	BH.show_heap();
	cout << "The current lowest element is:" << BH.remove_min() << endl;
	BH.show_heap();
	cout << "The current lowest element is:" << BH.remove_min() << endl;
	BH.show_heap();
	cout << "The current lowest element is:" << BH.remove_min() << endl;
	BH.show_heap();
	cout << "The current lowest element is:" << BH.remove_min() << endl;
	BH.show_heap();
	cout << "The current lowest element is:" << BH.remove_min() << endl;
	BH.show_heap();
	cout << "Currently the binary heap is empty so the check if empty should return 1: " << BH.is_empty() << endl;
	return 0;
}
*/