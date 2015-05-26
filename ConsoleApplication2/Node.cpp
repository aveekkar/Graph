//#include "stdafx.h"
#include "Node.h"
#include<iostream>


using namespace std;
typedef std::vector<shared_ptr<Node> >::const_iterator vecIter;

void Node::addEdge(const shared_ptr<Node>& next)
{
	mEdges.push_back(next);
}

bool Node::deleteEdge(const shared_ptr<Node>& next)
{
	int pos = findNode(next);
	if(pos != -1)
	{
		mEdges.erase(mEdges.begin() + pos);
		return true;
	}

	return false;
}

void Node::setEdges(const vector<shared_ptr<Node> >& adjucencyList)
{
	for(vecIter i = adjucencyList.begin(); i != adjucencyList.end(); ++i)
	{
		mEdges.push_back(*i);
	}
}

bool Node::setWeight(const shared_ptr<Node>& node, int weight)
{
	if(findNode(node) != -1)
	{
		this->mWeights.emplace(pair<string, int>(node->mName, weight));
		return true;
	}

	return false;
}

int Node::getWeight(const string& nodeName, bool& result)
{
	if(mWeights.find(nodeName) == mWeights.end())
	{
		result = false;
		return 0;
	}

	result = true;
	return mWeights.find(nodeName)->second;
}

const string& Node::getName()
{
	return mName;
}

const string& Node::getName() const
{
	return mName;
}

vector<shared_ptr<Node> >& Node::getList()
{
	return mEdges;
}


int Node::findNode(const shared_ptr<Node>& node)
{
	for(int i = 0; i < mEdges.size(); ++i)
	{
		if(mEdges[i]->mName == node->mName)
		{
			return i;
		}
	}

	return -1;
}

