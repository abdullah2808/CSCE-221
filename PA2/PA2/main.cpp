#include<iostream>
#include<vector>
#include<list>
#include <ctime>
#include "mpq_binaryheap.h"
#include "mpq_cpujobs.h"
#include "mpq_linkedlist.h"
#include "mpq_vec.h"


using namespace std;

// vector mpq
/*
int main() {
	clock_t t1, t2;
	vector<CPU_Job> PQ;
	CPU_Job Job;
	string line;

	ofstream outfile("OutSize10.txt");
	ifstream myfile("SetSize100000.txt"); // enter file name here 
	t1 = clock(); // start
	while (myfile >> Job.ID >> Job.length >> Job.prior)
	{
		insert(PQ, Job);
	}
	myfile.close();

	while (is_emptyy(PQ) == 0) {
		Job = remove_min(PQ);
		for (int i = 0; i < Job.length; i++) {  
			outfile <<"Job " <<Job.ID << " with length " << Job.length - i << " and priority " << Job.prior << endl; // outputs to console currently just for testing.
		}
	}
	outfile << "No more jobs to run.";
	t2 = clock(); // stop
	double diff = (double)(t2 - t1) * 1000 / CLOCKS_PER_SEC;
	cout << "Timing: " << diff << " milisec" << endl;
	return 0;
}
*/
// linked list mpq

int main() {
	clock_t t1, t2;
	list<CPU_Job> PQ;
	CPU_Job Job;
	string line;
	ofstream outfile("OutSize.txt");
	ifstream myfile("SetSize10000.txt"); // enter file name here 
	t1 = clock(); // start
	while (myfile >> Job.ID >> Job.length >> Job.prior)
	{
		insert(PQ, Job);
	}
	myfile.close();

	while (is_emptyy(PQ) == 0) {
		Job = remove_min(PQ);
		for (int i = 0; i < Job.length; i++) {
			outfile << "Job " << Job.ID << " with length " << Job.length - i << " and priority " << Job.prior << endl; // outputs to console currently just for testing.
		}
	}
	outfile << "No more jobs to run.";
	t2 = clock(); // stop
	double diff = (double)(t2 - t1) * 1000 / CLOCKS_PER_SEC;
	cout << "Timing: " << diff << " milisec" << endl;
	return 0;
}


// binary heap implmentation
/*
int main() {
	clock_t t1, t2;
	BinaryHeap<CPU_Job> PQ;
	CPU_Job Job;
	string line;
	ofstream outfile("OutSize10.txt");
	ifstream myfile("SetSize1000.txt"); // enter file name here 
	t1 = clock(); // start
	while (myfile >> Job.ID >> Job.length >> Job.prior)
	{
		PQ.insert(Job);
	}
	myfile.close();
	while (PQ.is_empty() == 0) {
		Job = PQ.remove_min();
		for (int i = 0; i < Job.length; i++) {
			outfile << "Job " << Job.ID << " with length " << Job.length - i << " and priority " << Job.prior << endl; // outputs to console currently just for testing.
		}
	}
	outfile << "No more jobs to run.";
	t2 = clock(); // stop
	double diff = (double)(t2 - t1) * 1000 / CLOCKS_PER_SEC;
	cout << "Timing: " << diff << " milisec" << endl;
	return 0;
}
*/


