// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include "BFSGraph.h"
#include "DFSGraph.h"
#include "Node.h"
#include "ShortestPaths.hpp"

using namespace std;


int main(int argc, char* argv[])
{
    cout<<"running..."<<endl;
    BFSGraph graph(7, 5, false, "/home/rik/STUFF/workspace/Test/GraphStuff/ConsoleApplication2/GraphInput.txt");
    graph.init();
    graph.printGraph();
    graph.traverse("3");
    graph.printTraversal();
    graph.shortestPathsFromSource();
    DFSGraph dfs(7, 5, false, "/home/rik/STUFF/workspace/Test/GraphStuff/ConsoleApplication2/GraphInput.txt");
    dfs.init();
    dfs.traverse("3");
    dfs.printTraversal();
    dfs.pathsFromSource();
    dfs.printTimes();
    ShortestPaths sp(7, 5, false, "/home/rik/STUFF/workspace/Test/GraphStuff/ConsoleApplication2/GraphInput.txt");
    sp.init();
    sp.singleSourcePositiveWeight("3");
    sp.printPaths();
    DFSGraph ts1(8, 6, true, "/home/rik/STUFF/workspace/Test/GraphStuff/ConsoleApplication2/directed.txt");
    ts1.init();
    cout<<"Is Graph DAG? "<<ts1.isDAG()<<endl;
    getchar();
    return 0;
}

