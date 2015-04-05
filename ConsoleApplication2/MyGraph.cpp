// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Graph.h"
#include "BFSGraph.h"
#include "DFSGraph.h"
#include "Node.h"

using namespace std;


int main(int argc, char* argv[])
{
	cout<<"running..."<<endl;
	BFSGraph graph(7, 5, false, "graphInput.txt");
	graph.init();
	graph.printGraph();
	graph.traverse("3");
	graph.printTraversal();
	graph.shortestPathsFromSource();
	DFSGraph dfs(7, 5, false, "graphInput.txt");
	dfs.init();
	dfs.traverse("3");
	dfs.printTraversal();
	dfs.pathsFromSource();
	dfs.printTimes();
	getchar();
	return 0;
}

