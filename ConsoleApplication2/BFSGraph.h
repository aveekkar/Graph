#pragma once
#ifndef __BFS__
#define __BFS__

#include <string.h>
#include "Graph.h"
#include <set>

class BFSGraph : public Graph
{
public:
	typedef struct
	{
		bool operator() (const shared_ptr<Node>& l, const shared_ptr<Node>& r)
		{
			return strcmp(l->getName().c_str(), r->getName().c_str()) < 0 ? true : false;
		}
	} NodeCompare;

	BFSGraph(int numEdges, int numNodes, bool isDirected, const string& file)
		: Graph(numEdges, numNodes, isDirected, file)
	{
	}

	void traverse(const string& source, set<shared_ptr<Node>, NodeCompare>& set);
	void traverse(const string& source);
	void printTraversal();
	void shortestPathsFromSource();
	int populateConnectedComponents();
	void resetTraversal();

private:
	vector<string> traversal;
	map<string, vector<string> > path;
	vector<set<shared_ptr<Node>, NodeCompare> > connectedComponents;
};

#endif

