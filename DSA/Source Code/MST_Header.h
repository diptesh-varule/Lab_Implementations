//============================================================================
// Title	   : Minimum Spanning Tree.
// Class	   : SE-10 (IT)
// Roll No	   : 23277
// Batch	   : H10
// Name        : MST_Header.h
// Author      : Diptesh Varule
// Version     : Updating...
// Copyright   : Your copyright notice
// Description : MST Header in C++, Ansi-style
//============================================================================

//Problem Statement.
/*
Represent a graph of your college campus using adjacency list /adjacency matrix. Nodes should
represent the various departments/institutes and links should represent the distance between them.
Find minimum spanning tree
a) Using Kruskal’s algorithm.
b) Using Prim’s algorithm.
*/

#ifndef MST_HEADER_H_
#define MST_HEADER_H_
#include <cstring>
using namespace std;

//Structure AL.
struct AL{
	int vertex;								//Vertex Number.
	int weight;								//Weight.
	AL* link;								//Link To Another Vertex.
};

//Structure of Edge.
struct Edge
{
	int U;									//Starting Vertex.
	int V;									//Ending Vertex.
	int wt;									//Weight Of The Edge.
};

//Class Graph.
class Graph{
private:
	int G[10][10] = {0};					//Adjacent Matrix.
	int vertices;							//Number of Vertices.
	string vname[10];						//Vertices Names.
	int edges;								//Number of Edges.
	AL *list[10];							//Adajent List.
	bool isDirected;						//To check for Directed Graph.
	Edge edge[50];							//Edge Array.
public:
	Graph();								//Constructor.
	~Graph();								//Destructor.

	void createGraphMat();					//create Graph(Matrix).
	void displayGraphMat();					//display Grapg(Matrix).

	void primAlgo();						//Prim's Algorithm.

	void kruskalAlgo();						//Kruskal's Algorithm.

	void sortg();							//Sort The Edge Array.

	void createGraphList();					//create Graph List.
	void displayGraphList();				//display Graph List.
};

AL* newNode(int i, int wt);

#endif /* MST_HEADER_H_ */
