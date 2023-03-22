//============================================================================
// Title	   : Minimum Spanning Tree.
// Class	   : SE-10 (IT)
// Roll No	   : 23277
// Batch	   : H10
// Name        : MST_Impl.cpp
// Author      : Diptesh Varule
// Version     : Updating...
// Copyright   : Your copyright notice
// Description : MST Impl in C++, Ansi-style
//============================================================================

//Problem Statement.
/*
Represent a graph of your college campus using adjacency list /adjacency matrix. Nodes should
represent the various departments/institutes and links should represent the distance between them.
Find minimum spanning tree
a) Using Kruskal’s algorithm.
b) Using Prim’s algorithm.
*/

#include <iostream>
#include "MST_Header.h"
#include <bits/stdc++.h>
using namespace std;

//Constructor
Graph::Graph(){
	vertices = 0;
	edges = 0;
	G[10][10] = {0};
	isDirected = false;
}

//Destructor
Graph::~Graph(){}

//Create Graph Using Adjacent Matrix.
void Graph::createGraphMat(){

	vertices = 0;
	edges = 0;

	cout<<"Is The Building Graph Directed"<<endl;
	cout<<"1.True\n2.False"<<endl;
	int in = -1;
	while(in < 1 || in > 2){
		cout<<"Directed : ";
		cin>>in;
	}
	if(in == 1){
		isDirected = true;
	}
	else{
		isDirected = false;
	}

	cout<<"\nEnter The Number Of Building In the Graph : ";			//Asking For Vertices.
	cin>>vertices;
	cout<<endl;
	cin.ignore();
	for(int i = 0; i < vertices; i++){
		cout<<"Enter The Name Of The Building "<<i+1<<" : ";
		getline(cin, vname[i]);
	}
	cout<<endl;

	if(isDirected){
		int k = 0;
		for(int i = 0; i < vertices; i++){
			for(int j = 0; j < vertices; j++){						//Traversing Matrix.
				if(i == j){
					G[i][j] = 0;
					continue;
				}
				cout<<"Enter The Distance Between "<<vname[i]<<" --> "<<vname[j]<<" : ";	//Asking For Weight.
				int weight;
				cin>>weight;
				G[i][j] = weight;	//Assigning Weight.
				if(weight != 0){	//Entering The Edges in Edge Array.
					edge[k].U = i;
					edge[k].V = j;
					edge[k].wt = weight;
					k++;
					edges++;
				}
			}
			cout<<endl;
		}
		cout<<"\nAdjacent Matrix Created Successfully";
		return;
	}

	int k = 0;
	for(int i = 0; i < vertices; i++){
		for(int j = i+1; j < vertices; j++){						//Traversing For Upper Half Matrix.
			cout<<"Enter The Distance Between "<<vname[i]<<" And "<<vname[j]<<" : ";	//Asking For Weight.
			int weight;
			cin>>weight;
			G[i][j] = G[j][i] = weight;	//Assigning Weight.
			if(weight != 0){	//Entering The Edges in Edge Array.
				edge[k].U = i;
				edge[k].V = j;
				edge[k].wt = weight;
				k++;
				edges++;
				edge[k].U = j;
				edge[k].V = i;
				edge[k].wt = weight;
				k++;
				edges++;
			}
		}
		cout<<endl;
	}
	cout<<"\nAdjacent Matrix Created Successfully";
}

//Display Graph Using Adjacent Matrix.
void Graph::displayGraphMat(){


	if(isDirected){
		cout<<endl;
		for(int i = 0; i < vertices; i++){
			for(int j = 0; j < vertices; j++){//Traversing Matrix.
				//Displaying The Edges With it's Weight.
				if(G[i][j] != 0){
					cout<<"The Distance Between "<<vname[i]<<" And "<<vname[j]<<" Is : "<<G[i][j]<<endl;
				}
			}
			cout<<endl;
		}
	}
	else{
		cout<<endl;
		for(int i = 0; i < vertices; i++){
			for(int j = i+1; j < vertices; j++){//Traversing For Upper Half Matrix.
				//Displaying The Edges With it's Weight.
				if(G[i][j] != 0){
					cout<<"The Distance Between "<<vname[i]<<" And "<<vname[j]<<" Is : "<<G[i][j]<<endl;
				}
			}
			cout<<endl;
		}
	}

	for(int i = 0; i < edges; i++){
		cout<<"|"<<vname[edge[i].U]<<"|-->|"<<vname[edge[i].V];
		cout<<"|"<<", Weight = "<<edge[i].wt<<endl;
	}
	cout<<endl;

	cout<<"\nDisplaying Adjacency List"<<endl;
	createGraphList();
	displayGraphList();
}

//Prim's Algorithm.
void Graph::primAlgo()
{
	int current, totalvisited, mincost, i;
	int v = vertices;
	int d[30], visited[30], p[30], weight[10][10];

	for(int i = 0; i < 30; i++){	//Initializing distance, path and visited array.
		d[i] = 7777;
		p[i] = visited[i] = 0;
	}

	for(int m  = 0; m < vertices; m++){	//Creating weight Matrix;
		for(int n = 0; n < vertices; n++){
			weight[m][n] = G[m][n];
		}
	}

	current=0; d[current]=0;

	totalvisited =1;
	visited[current]=1;


	cout<<"\nVisited, Distance and path Status : "<<endl;	//Displaying Distance and Path Status.
	for(i = 0; i < v; i++){
		cout<<endl<<"i = "<<i<<", Visited["<<i<<"] = "<<visited[i]<<", p["<<i<<"] = "<<p[i]<<", d["<<i<<"] = "<<d[i];
	}
	cout<<endl<<"Entering While Loop"<<endl;
	while(totalvisited != v){
	//Displaying Total Visited.
	cout<<endl<<"Total visited = "<<totalvisited;


	for (i=0;i<v;i++)	//Assigning distance and path array to it's minimum avaialible.
		  {
			 if(weight[current][i]!=0)
				 if(visited[i]==0)
					 if(d[i]>weight[current][i])
					 {
						 d[i] = weight[current][i];
						 p[i] = current;
					 }
		  }
	//Displaying Distance and Path Status.
	cout<<"\nVisited, Distance and path Status : "<<endl;
	for(i = 0; i < v; i++){
		cout<<endl<<"i = "<<i<<", Visited["<<i<<"] = "<<visited[i]<<", p["<<i<<"] = "<<p[i]<<", d["<<i<<"] = "<<d[i];
	}

	 mincost= 7777;
	 cout<<endl<<"\nNow, Finding The Minimum Cost"<<endl;
	 for (i=0;i<v;i++)	//Finfing The Minimum cost among distance Array.
	 {
		if(visited[i] ==0)
			if (d[i] <mincost)
			{
				mincost = d[i];
				current = i;
			}

	 }
	 //Displaying Mincost and current.
	 cout<<"\n\nmincost = "<<mincost;
	 cout<<"\ncurrent = "<<current<<endl;


	 visited[current] = 1;
	 totalvisited++;

	 cout<<endl<<"Current = "<<current<<endl<<"Total Visited = "<<totalvisited;

	}   /*end of while loop */
	mincost =0;
	for (i=0;i<v;i++)	//Calculating The minimum Cost.
	     mincost += d[i];

	cout<<"\nMinimum cost = ";
	cout<<mincost<<endl;
	//Displaying Distance and Path Status.
	cout<<"\nVisited, Distance and path Status : "<<endl;
	for(i = 0; i < v; i++){
		cout<<endl<<"i = "<<i<<", Visited["<<i<<"] = "<<visited[i]<<", p["<<i<<"] = "<<p[i]<<", d["<<i<<"] = "<<d[i];
	}

	//Representation of Matrix.
	for(int m  = 0; m < vertices; m++){	//Assigning All Weight To zero in Weight Matrix.
		for(int n = 0; n < vertices; n++){
			weight[m][n] = 0;
		}
	}
	for(int m = 0; m < vertices; m++){	//Assigning Weights According To Distance Array and Path Array.
		weight[m][p[m]] = d[m];
		weight[p[m]][m] = d[m];
	}

	cout<<endl<<endl;
	for(int i = 1; i < v; i++){
		cout<<"|"<<vname[p[i]]<<"|-->|"<<vname[i];
		cout<<"|"<<", Weight = "<<d[i]<<endl;
	}
	cout<<endl<<"Total Cost of MST is "<<mincost<<endl;	//Displaying Cost.
}

//Method To Sort The Edges.
void Graph::sortg()
{
	int i,j;
    Edge temp;
    //using Bubble Sort.
	for(i=0;i<edges-1;i++)
			{	for(j=0;j<edges-1;j++)
				{	if(edge[j].wt>edge[j+1].wt)	//Swapping If Greater.
					{
					        temp=edge[j+1];
					        edge[j+1]=edge[j];
							edge[j]=temp;

					}
				}
			}
		cout<<"\nSorted List of edges"<<endl;
		for(int i=0;i<edges;i++)	//Displaying The Sorted List.
		{
			cout<<"|"<<edge[i].U<<"->"<<edge[i].V<<"|, Weight : "<<edge[i].wt<<endl;
		}
}

//Kruskal's Algorithm.
void Graph::kruskalAlgo()
{
	int e = edges, i, j, conn[50], k, r, p, Val, cnt = 0, m = 0;	//Initializing Variables.

	cout<<"\nEdge array Entered By The User is :"<<endl;	//Displaying Edge Array.
	for (i=0;i<e;i++)
	{
		cout<<"|"<<edge[i].U<<"->"<<edge[i].V<<"|, Weight : "<<edge[i].wt<<endl;
	}

	sortg(); // Sort the list of edges
	cout<<endl<<endl;

	Edge t[50], h[50];	//creating Edge Array To Store Edges.

	for (i=0;i<e;i++)
			conn[i]=0;
	 Val=1;
	 cnt=0;
	 j=0;
	       while(cnt<e-1 && j<e)
	       {	//both vertices are not visited
	    	 if(conn[edge[j].U]==0 && conn[edge[j].V]==0)
			{
	    		 //Displaying Selected Edge.
	    		 cout<<"Edge selected"<<"|"<<edge[j].U<<"->"<<edge[j].V<<"|, Weight : "<<edge[j].wt<<", Both The Vertices Are Not Visited"<<endl;

	    		 //Adding Edge to t.
	    		 t[cnt]=edge[j];

	    		 //Assigning The Visited Vertices connected value.
			     conn[edge[j].U]=Val;
			     conn[edge[j].V]=Val;
			     Val++;
			     cnt++;

			     //Adding Edge to h.
			     h[m].U = edge[j].U;
			     h[m].V = edge[j].V;
			     h[m].wt = edge[j].wt;
			     m++;
			}
	    	else if(conn[edge[j].U]!=conn[edge[j].V])//if conn value of both vertices is not equal
			{
	    		//Displaying Selected Edge.
	    		cout<<"Edge selected"<<"|"<<edge[j].U<<"->"<<edge[j].V<<"|, Weight : "<<edge[j].wt<<", Both The Vertices Have Different Connected Value"<<endl;

			  //Adding Edge to h.
			  h[m].U = edge[j].U;
			  h[m].V = edge[j].V;
			  h[m].wt = edge[j].wt;
			  m++;

			  if(conn[edge[j].U]!=0 && conn[edge[j].V]!=0)//if both vertices are visited
			  {
			     t[cnt]=edge[j];	//Adding Edge to t.
			     if(conn[edge[j].U]<conn[edge[j].V])//if connected value of first vertex is less
			     {
			    	 r=conn[edge[j].U];	//Greater Connected Value.
				     p=conn[edge[j].V];	//Smaller Connected Value.
			     }
			     else //if connected value of second vertex is less
			     {   r=conn[edge[j].V];	//Greater Connected Value.
				     p=conn[edge[j].U];	//Smaller Connected Value.
			     }
			     for(k=0;k<e;k++)//replacing Greater connected value p with small value r
			     {
			    	 if(conn[k]==p)
				     conn[k]=r;
			     }
			     cnt++;
			   }
			   else if(conn[edge[j].U]==0 && conn[edge[j].V]!=0)//If first vertex is not visited & second is visited
			   {
			    	t[cnt]=edge[j];	//Adding Edge to t.
			        conn[edge[j].U]=conn[edge[j].V];	//Assigning same connected Value.
			        cnt++;
			   }
			   else //if first vertex is visited & second is not visited
			   {
			    	t[cnt]=edge[j];	//Adding Edge to t.
			        conn[edge[j].V]=conn[edge[j].U];	//Assigning same connected Value.
			        cnt++;
			    }

			}
			else //Both verticces has same connected value-reject edge--- forms cycle
				 //Displaying Rejected Edge.
				cout<<"Edge Rejected "<<"|"<<edge[j].U<<"->"<<edge[j].V<<"|, Weight : "<<edge[j].wt<<", Both The Vertices Have Same Connected Value"<<endl;
		       j++;
	       }
	       cout<<"\n\nKruskal's MST contains following edges::"<<endl;
	       int cost=0;
	       for(i=0;i<cnt;i++)
	       {
	    	   //Displaying Selected Edges.
	    	   cout<<"|"<<h[i].U<<"->"<<h[i].V<<"|, Weight : "<<h[i].wt<<endl;
	    	   cost = cost + h[i].wt;
	       }
	       cout<<endl<<"Total Cost of MST is "<<cost<<endl;	//Displaying Cost.
}

//Create Graph Using Adjacent List.
void Graph::createGraphList(){

	for(int i = 0; i < vertices; i++){
		AL* nev = newNode(i, 0);
		list[i] = nev;
	}
	for(int i = 0; i < edges; i++){

		AL* trav = list[edge[i].U];

		while(trav->link != NULL){
			trav = trav->link;
		}

		AL* nev = newNode(edge[i].V, edge[i].wt);
		trav->link = nev;
	}
}

//Display Graph Using Adjacent List.
void Graph::displayGraphList(){

	cout<<endl;
	for(int i = 0; i < vertices; i++){
		cout<<"|"<<vname[list[i]->vertex]<<"|";

		AL* trav = list[i];		//Creating trav for Traversal.
		while(trav != NULL){

			trav = trav->link;
			if(trav == NULL){	//If Trav is Null Then Break.
				break;
			}

			cout<<"->|"<<vname[trav->vertex]<<", "<<trav->weight<<"|";	//Display vertex.

		}
		cout<<endl;		//Space.
	}
}

//Function to create new AL Node.
AL* newNode(int i, int wt){
	AL *temp = new AL;
	temp->vertex = i;
	temp->weight = wt;
	temp->link = NULL;
	return temp;
}
