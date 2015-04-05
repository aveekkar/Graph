#pragma once
#ifndef __GRAPH__
#define __GRAPH__

#include <string>
#include <vector>
#include "Node.h"
#include "boost/shared_ptr.hpp";

using namespace std;
typedef vector<shared_ptr<Node> > graph;


class Graph
{
public:
	Graph(int numEdges, int numNodes, bool isDirected, const string& file);
	bool deleteNode(shared_ptr<Node> node);
	bool deleteEdge(shared_ptr<Node> node_one, shared_ptr<Node> node_two);
	void addEdge(shared_ptr<Node> node_one, shared_ptr<Node> node_two);
	void addNode(shared_ptr<Node> node);
	bool init();
	void printGraph();
	virtual void resetTraversal() = 0;
	virtual void traverse(const string& source) = 0;
private:
	bool mIsDirected;
	int mNumEdges;
	int mNumNodes;
	string mFile;

protected:
	vector<shared_ptr<Node> > mNodes;
	int findNode(const string& name);
};

#endif