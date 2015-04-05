#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include<queue>
#include<vector>
#include "BFSGraph.h"

using namespace std;

typedef map<string, vector<string> >::const_iterator iter;

void BFSGraph::traverse(const string& source)
{
	int nodeIndex;
	if((nodeIndex = findNode(source)) == -1)
	{
		cout<<"No such node"<<endl;
		return;
	}

	shared_ptr<Node> sourceNode = mNodes[nodeIndex];
	sourceNode->status = Node::Status::grey;
	queue<shared_ptr<Node> > processQueue;
	for(vector<shared_ptr<Node> >::iterator i = mNodes.begin(); i != mNodes.end(); ++i)
	{
		vector<string> parentList;
		path.insert(pair<string, vector<string> >((*i)->getName(),parentList));
	}

	processQueue.push(sourceNode);

	while(!processQueue.empty())
	{
		shared_ptr<Node> current = processQueue.front();
		processQueue.pop();
		for(vector<shared_ptr<Node> >::iterator j = current->getList().begin(); j != current->getList().end(); ++j)
		{
			if((*j)->status == Node::Status::white)
			{
				(*j)->status = Node::Status::grey;
				vector<string> parentpath = path[current->getName()];
				parentpath.push_back(current->getName());
				path[(*j)->getName()] = parentpath;
				processQueue.push((*j));
			}
		}

		current->status = Node::Status::black;
		traversal.push_back(current->getName());
	}
}

void BFSGraph::printTraversal()
{
	cout<<"PRINTING GRAPH TRAVERSAL..."<<endl;
	
	for(vector<string>::const_iterator i = traversal.cbegin(); i != traversal.cend(); ++i)
	{
		cout<<(*i) + "-->";
	}

	cout<<"END"<<endl;
}

void BFSGraph::shortestPathsFromSource()
{
	cout<<"PRINTING SHORTEST PATHS"<<endl;
	for(iter i = path.cbegin(); i != path.cend(); ++i)
	{
		cout<<"SP to: " + i->first + "==>";
		for(vector<string>::const_iterator j = i->second.begin(); j != i->second.end(); ++j)
		{
			cout<<(*j) + "-->";
		}

		cout<<i->first<<endl;
	}
}