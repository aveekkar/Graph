//#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include<vector>
#include "DFSGraph.h"


using namespace std;

typedef map<string, vector<string> >::const_iterator iter;
typedef map<string, DFSGraph::Time>::const_iterator timeIter;


void DFSGraph::traverse(const string& source)
{
	resetTraversal();
	int nodeIndex;
	if((nodeIndex = findNode(source)) == -1)
	{
		cout<<"No such node"<<endl;
		return;
	}

	shared_ptr<Node> sourceNode = mNodes[nodeIndex];

	for(vector<shared_ptr<Node> >::iterator i = mNodes.begin(); i != mNodes.end(); ++i)
	{
		vector<string> parentList;
		path.insert(pair<string, vector<string> >((*i)->getName(),parentList));
	}

	clock = -1;
	dfs(sourceNode);
}

void DFSGraph::printTraversal()
{
	cout<<"PRINTING GRAPH TRAVERSAL..."<<endl;
	
	for(vector<string>::const_iterator i = traversal.cbegin(); i != traversal.cend(); ++i)
	{
		cout<<(*i) + "-->";
	}

	cout<<"END"<<endl;
}

void DFSGraph::pathsFromSource()
{
	cout<<"PRINTING PATHS"<<endl;
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

void DFSGraph::dfs(shared_ptr<Node> source)
{
	source->status = Node::Status::grey;
	Time timeStruct;
	timeStruct.entry = ++clock;
	for(vector<shared_ptr<Node> >::iterator i = source->getList().begin(); i != source->getList().end(); ++i)
	{
		if((*i)->status == Node::Status::white)
		{
			vector<string> parentList = path[source->getName()];
			parentList.push_back(source->getName());
			path[(*i)->getName()] = parentList;
			dfs((*i));
		}
	}

	timeStruct.exit = ++clock;
	timeMap.insert(pair<string, Time>(source->getName(), timeStruct));
	source->status = Node::Status::black;
	traversal.push_back(source->getName());
}

void DFSGraph::resetTraversal()
{
	for(vector<shared_ptr<Node> >::iterator i = mNodes.begin(); i != mNodes.end(); ++i)
	{
		(*i)->status = Node::Status::white;
	}

	traversal.clear();
	path.clear();
	timeMap.clear();
}


void DFSGraph::printTimes()
{
	cout<<"PRINTING TIMES..."<<endl;

	for(timeIter i = timeMap.cbegin(); i != timeMap.cend(); ++i)
	{
		cout<<"Times for " + i->first + ":";
		cout<<i->second.entry;
		cout<<"|";
		cout<<i->second.exit<<endl;
	}
}

