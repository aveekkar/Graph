//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "Graph.h"
#include "boost/algorithm/string/predicate.hpp"
#include "boost/algorithm/string.hpp"

using namespace std;

typedef vector<shared_ptr<Node> >::iterator NodeIter;
typedef vector<string>::iterator vectorIter;
typedef map<string, shared_ptr<Node> >::iterator mapIter;

Graph::Graph(int numEdges, int numNodes, bool isDirected, const string& file) : mNumNodes(numNodes),
																				mNumEdges(numEdges),
																				mIsDirected(isDirected),
																				mFile(file)
{
}

bool Graph::deleteNode(shared_ptr<Node> node)
{
	return false;
}

bool Graph::deleteEdge(shared_ptr<Node> node_one, shared_ptr<Node> node_two)
{
	if(findNode(node_one->getName()) != -1 && findNode(node_two->getName()) != -1)
	{
		if(mIsDirected)
		{
			if(node_one->deleteEdge(node_two))
			{
				return true;
			}
		}
		else
		{
			if(node_one->deleteEdge(node_two) && node_two->deleteEdge(node_one))
			{
				return true;
			}
		}
	}
	
	return false;
}

bool Graph::init()
{
	ifstream graphInputFile;
	graphInputFile.open(mFile);
	if(graphInputFile.is_open())
	{
		map<string, shared_ptr<Node> > nodeCache;
		map<string, vector<string> > adjucencyList;
		string line;
		bool parseNext = false;
		string currentNode;
		while (getline(graphInputFile, line))
		{
			if(line == "")
			{
				continue;
			}
			if(!parseNext)
			{
				if(boost::starts_with(line, "Node"))
				{
					vector<string> forSplit;
					boost::split(forSplit, line, boost::is_any_of(":"));
					string val = forSplit[1];
					forSplit.clear();
					boost::split(forSplit, val, boost::is_any_of("-"));
					string name = forSplit[0];
					int outDegree = atoi(forSplit[1].c_str());
					shared_ptr<Node> makeNode(new Node(name, outDegree));
					nodeCache.insert(pair<string, shared_ptr<Node> >(makeNode->getName(), makeNode));
					currentNode = makeNode->getName();
					parseNext = true;
					continue;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if(boost::starts_with(line, "Edges"))
				{
					vector<string> forSplit;
					boost::split(forSplit, line, boost::is_any_of(":"));
					string val = forSplit[1];
					if(val == "")
					{
						parseNext = false;
						forSplit.clear();
						adjucencyList.insert(pair<string, vector<string> >(currentNode, forSplit));
						currentNode = "";
						continue;
					}

					forSplit.clear();
					boost::split(forSplit, val, boost::is_any_of(","));
					adjucencyList.insert(pair<string, vector<string> >(currentNode, forSplit));
					parseNext = false;
					currentNode = "";
				}
			}
		}

		for(mapIter i = nodeCache.begin(); i != nodeCache.end(); ++i)
		{
			shared_ptr<Node> node = i->second;
			string nodeName = i->first;
			vector<string> adjList = adjucencyList[nodeName];
			for(vectorIter i = adjList.begin(); i != adjList.end(); ++i)
			{
				vector<string> forSplit;
				boost::split(forSplit, *i, boost::is_any_of("-"));
				string connectingNodeName = forSplit[0];
				int weight;
				if(forSplit[1] == "")
				{
					weight = 1;
				}
				else
				{
					weight = atoi(forSplit[1].c_str());
				}

				shared_ptr<Node> connectingNode = (nodeCache[connectingNodeName]);
				node->addEdge(connectingNode);
				node->setWeight(connectingNode, weight);

			}

			this->mNodes.push_back(node);
		}

		graphInputFile.close();
		return true;
	}
	else
	{
		cout<<"unable to open graph file"<<endl;
		return false;
	}
}

void Graph::printGraph()
{
	for(NodeIter i = mNodes.begin(); i != mNodes.end(); ++i)
	{
		cout<<(*i)->getName();
		for(vector<shared_ptr<Node> >::const_iterator j = (*i)->getList().begin(); j != (*i)->getList().end(); ++j)
		{
			cout<<"--->" + (*j)->getName();
		}
		cout<<""<<endl;
	}
}

int Graph::findNode(const string& nodeName)
{
	for(int i = 0; i < mNodes.size(); ++i)
	{
		if(mNodes[i]->getName() == nodeName)
		{
			return i;
		}
	}

	return false;
}