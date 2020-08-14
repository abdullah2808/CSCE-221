#include "graph.h"
#include<vector>
#include<iostream>
#include <queue>
using namespace std;
// to be implemented



Graph::~Graph()
{
	adj_list.clear();
	node_list.clear();
}



void Graph::buildGraph(ifstream& input)
{
	list<int> temp;
	int data, vertex;

	while (input >> vertex)
	{
		temp.clear();
		node_list.push_back(Vertex(vertex));
		while (input >> data)
		{
			if (data != -1) temp.push_back(data);
			else break;
		}
		adj_list.push_back(temp);
	}
	input.close();
}

void Graph::displayGraph()
{
	for (int i = 0; i < node_list.size(); i++)
	{

		list<int>::iterator it;
		cout << i + 1 << ": ";
		for (it = adj_list.at(i).begin(); it != adj_list.at(i).end(); it++)
			cout << *it << " ";
		cout << endl;
		
	}
}

void Graph::topological_sort()
{
	queue<Vertex> q;
	int counter = 0;
	list <int> temp;
	for (int i = 0; i < node_list.size(); i++) {
		if (node_list.at(i).indegree == 0) {
			q.push(node_list.at(i));
			top_sorted.push_back(node_list.at(i));

		}
	}

	while (!q.empty())
	{
		Vertex v = q.front();
		q.pop();
		v.top_num = ++counter; // Assign next number
		temp = adj_list.at(v.label-1);
		list<int>::iterator it;
		for (it = temp.begin(); it != temp.end(); it++) {
			if (--node_list.at(*it - 1).indegree == 0) {
				top_sorted.push_back(node_list.at(*it - 1));
				q.push(node_list.at(*it - 1));
			}
		}
		}
	if (counter != node_list.size()) {
		throw CycleFoundException();
	}
		
	
}

void Graph::compute_indegree()
{
	list<int> temp;
	for (int i = 0; i < node_list.size(); i++) {
		node_list.at(i).indegree = 0;
	}
	for (int i = 0; i < node_list.size(); i++) {
		list<int>::iterator it;
		for (it = adj_list.at(i).begin(); it != adj_list.at(i).end(); it++){
			node_list.at(*it - 1).indegree += 1;
		}
	}
}

void Graph::print_top_sort()
{
	cout <<  "After topological sort the order is : ";
	for (int i = 0; i < top_sorted.size(); i++) {
		cout << top_sorted.at(i).label << " " ;
	}
}


