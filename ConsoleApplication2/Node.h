#pragma once
#ifndef __NODE__
#define __NODE__

using namespace std;

#include <string>
#include <vector>
#include <map>
#include "boost/shared_ptr.hpp";

class Node
{
public:
	typedef enum traversalStatus {white, grey, black} Status;
	 Status status;

	Node(const string& name, int outDegree) : mName(name), 
											mOutDegree(outDegree),
											status(traversalStatus::white)
	{
	}

	void addEdge(const shared_ptr<Node>& next);
	bool deleteEdge(const shared_ptr<Node>& next);
	void setEdges(const vector<shared_ptr<Node> >& adjucencyList);
	bool setWeight(const shared_ptr<Node>& node, int weight);
	int getWeight(const string& nodeName, bool& result);
	vector<shared_ptr<Node> >& getList();
	const string& getName();
	const string& getName() const;
	
private:
	string mName;
	int mOutDegree;
	vector<shared_ptr<Node> > mEdges;
	map<string, int> mWeights;

	int findNode(const shared_ptr<Node>& node);
};

#endif