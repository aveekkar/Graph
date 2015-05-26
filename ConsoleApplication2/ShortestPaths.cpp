#include "ShortestPaths.hpp"
#include <limits.h>

using namespace std;

ShortestPaths::ShortestPaths(int numEdges, int numNodes, bool isDirected, const string& file):
    Graph(numEdges, numNodes, isDirected, file)
{
}

void ShortestPaths::singleSourcePositiveWeight(const string& source)
{
    resetTraversal();
    traverse(source);
    
}


void ShortestPaths::traverse(const string& source)
{
    int nodeIndex;
    if((nodeIndex = findNode(source)) == -1)
    {
        cout<<"No such node"<<endl;
        return;
    }

	shared_ptr<Node> sourceNode = mNodes[nodeIndex];
    
    for(vector<shared_ptr<Node> >::iterator i = mNodes.begin(); i != mNodes.end(); ++i)
    {
        (*i)->distance = INT_MAX;
        (*i)->parent = NULL;
    }
    
    sourceNode->distance = 0;
    priority_queue<shared_ptr<Node> , vector<shared_ptr<Node> >, spNode> workerQueue;
    workerQueue.push(sourceNode);
    bool useLess;
    while(!workerQueue.empty())
    {
        shared_ptr<Node> vertex = workerQueue.top();
        workerQueue.pop();
        vertex->status = Node::Status::black;
        
        for(vector<shared_ptr<Node> >::iterator i = vertex->getList().begin(); i != vertex->getList().end(); ++i)
        {
            if((*i)->status == Node::Status::white)
            {
                if((vertex->distance + vertex->getWeight((*i)->getName(), useLess)) < (*i)->distance)
                {
                    //cout<<"weight "<<vertex->getName()<<"->"<<(*i)->getName()<<" : "<<vertex->getWeight((*i)->getName(), useLess)<<endl;
                    (*i)->distance = vertex->distance + vertex->getWeight((*i)->getName(), useLess);
                    (*i)->parent = vertex;
                    workerQueue.push((*i));
                }
            }
        }
    }
    
    
}

void ShortestPaths::resetTraversal()
{
    for(vector<shared_ptr<Node> >::iterator i = mNodes.begin(); i != mNodes.end(); ++i)
	{
        (*i)->status = Node::Status::white;
        (*i)->distance = INT_MAX;
        (*i)->parent = NULL;
	}
}


void ShortestPaths::printPaths()
{
    cout<<"-------SSSP-------"<<endl;
    for(vector<shared_ptr<Node> >::const_iterator i = mNodes.begin(); i != mNodes.end(); ++i)
    {
        printPath((*i));
    }
}

void ShortestPaths::printPath(const shared_ptr<Node>& node)
{
    shared_ptr<Node> next = node;
    while(next != NULL)
    {
        cout<<next->getName()<<"->";
        next = next->parent;
    }
    cout<<"dist("<<node->distance<<")"<<endl;
}
