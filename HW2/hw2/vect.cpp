#include <iostream>
#include<queue>
using namespace std;



int main() {
	int n = 100;
	int count = 0;
	for (int a = 0; a < n; a++) { // n is the input size
		for (int b = a; b <= a + 10; b++) {
			count++;
		}
	}
	cout << count;
	
	return 0;
}