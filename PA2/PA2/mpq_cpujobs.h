#include<iostream>
#include<vector>
#include <fstream>
#include <string>

using namespace std;


struct CPU_Job {
	int ID; // process ID
	int length; // process length
	int prior; // process priority
	CPU_Job(int a = 0, int b = 0, int c = 0) : ID(a), length(b), prior(c) {};
	// compares jobs’ priorities and/or IDs
	bool operator<(const CPU_Job& job);
	bool operator>(const CPU_Job& job);
};


inline bool CPU_Job::operator<(const CPU_Job& job) {
	if (prior == job.prior) 
		return  (ID < job.ID);
	
	return (prior < job.prior);
	
}

inline bool CPU_Job::operator>(const CPU_Job& job) {
	if (prior == job.prior)
		return  (ID > job.ID);

	return (prior > job.prior);

}




