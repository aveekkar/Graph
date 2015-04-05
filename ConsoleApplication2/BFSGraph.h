#pragma once
#ifndef __BFS__
#define __BFS__

#include "Graph.h"

class BFSGraph : public Graph
{
public:
	BFSGraph(int numEdges, int numNodes, bool isDirected, const string& file)
		: Graph(numEdges, numNodes, isDirected, file)
	{
	}

	void traverse(const string& source);
	void printTraversal();
	void shortestPathsFromSource();

private:
	vector<string> traversal;
	map<string, vector<string> > path;
};

#endif

