#pragma once
#ifndef __DFS__
#define __DFS__

#include "Graph.h"

class DFSGraph : public Graph
{
public:
	typedef struct
	{
		int entry;
		int exit;
	} Time;

	DFSGraph(int numEdges, int numNodes, bool isDirected, const string& file)
		: Graph(numEdges, numNodes, isDirected, file)
	{
	}

	void traverse(const string& source);
	void printTraversal();
	void pathsFromSource();
	void printTimes();
private:
	vector<string> traversal;
	map<string, vector<string> > path;
	map<string, Time> timeMap;
	int clock;

	void dfs(shared_ptr<Node> source);
};

#endif

