#pragma once

#ifndef __SHORTEST_PATHS__
#define __SHORTEST_PATHS__

#include "Graph.h"
#include <vector>
#include <queue>
#include <map>

using namespace std;

class ShortestPaths : public Graph
{
public:

    typedef struct
    {
        bool operator ()(const shared_ptr<Node>& l, const shared_ptr<Node>& r)
        {
            return l->distance > r->distance;
        }
    } spNode;
    
    ShortestPaths(int numEdges, int numNodes, bool isDirected, const string& file);
    void singleSourcePositiveWeight(const string& source);
    void traverse(const string& source);
    void resetTraversal();
    void printPaths();
    
private:
    vector<shared_ptr<spNode> > graph;
    void printPath(const shared_ptr<Node>& node);

};

#endif

