#include<vector>
#include<iostream>
#include <chrono> 
using namespace std;
using namespace std::chrono;


vector<double> scalar_mult(vector<double> a, vector<double> b) {
	vector<double> c;
	for (int i = 0; i < a.size(); i++) {
		c.push_back(a.at(i) * b.at(i));
	}

	return c;
}

bool odd_prod(vector<int> a) {
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] * a[j] % 2 == 1) {
				return true;
			}
		}
	}
	return false;
}


void Recur_fun(int n) {
	if (n > 0) {
		Recur_fun(n - 1);
		cout << n << endl;
		Recur_fun(n - 1);
	}
}
/*template <typename T>
 int binarysearch(vector<T>vec, int l, int r, T search) {
	if (r < l) {
		return -1; 	}
		int mid = (l + r) / 2;
	if (search < vec[mid]) {
		return binarysearch(vec, l, mid - 1, search); 	}
	else if (search > vec[mid]) {
		return binarysearch(vec, mid + 1, r, search); 	}
	return mid; }*/


int main() {

	Recur_fun(3);
	
	return 0;
}