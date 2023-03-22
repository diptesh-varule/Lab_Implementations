//============================================================================
// Title	   : Shortest Path Algorithm.
// Class	   : SE-10 (IT)
// Roll No	   : 23277
// Batch	   : H10
// Name        : SPA_Impl.cpp
// Author      : Diptesh Varule
// Version     : Updating..
// Copyright   : Your copyright notice
// Description : SPA Impl in C++, Ansi-style
//============================================================================

//Problem Statement.
/*
Represent a graph of city using adjacency matrix /adjacency list. Nodes should represent the various
landmarks and links should represent the distance between them. Find the shortest path using
Dijkstra's algorithm from single source to all destination.
*/

#include <iostream>
#include "SPA_Header.h"
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

	cout<<"Is The Graph Directed"<<endl;
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

	cout<<"\nEnter The Number Of Land Marks In the Graph : ";			//Asking For Vertices.
	cin>>vertices;
	cout<<endl;
	cin.ignore();
	for(int i = 0; i < vertices; i++){
		cout<<"Enter The Name Of The Land Mark "<<i+1<<" : ";
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

//Dijktras's Algorithm.
void Graph::dijktrasAlgo()
{
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

	int i, j, k, min, current;	//Traversing Variables.

	cout<<endl;
	for(int i = 0; i < vertices; i++){
		cout<<i<<". "<<vname[i]<<endl;
	}

	int s;
	cout<<endl<<"Enter The source Serial Number : ";	//Asking User For Source.
	cin>>s;

	for (i=0;i<v;i++)	//Initializing Visited, DIstance And Path Arrays.
	{
		visited[i] =0;
		if(weight[s][i]!=0)
			d[i] = weight[s][i];
		p[i]=s;
	}

	current = s;		//Setting Current to source.
	visited[current] = 1;	//Now current is visited.
	d[s] = 0;				//Distance to itself is 0.

	cout<<"\nVisited, Distance and path Status : "<<endl;	//Displaying Distance and Path Status.
	for(i = 0; i < v; i++){
		cout<<endl<<"i = "<<i<<", Visited["<<i<<"] = "<<visited[i]<<", p["<<i<<"] = "<<p[i]<<", d["<<i<<"] = "<<d[i];
	}

	for(i = 0; i < v-2; i++)	//Outer loop for Traversing Till v-2 times.
	{
		min = 7777;	//Assigning Minimum to 7777(Infinity).
		for(j = 0; j < v; j++)	//Inner Loop For Finding Minimum Non Visited Edge.
		{
			if (min > d[j] && visited[j] == 0)	//If Found then Assigning Current to j.
			{
				min = d[j];
				current = j;
			}
		}
		cout<<endl<<"Selected Vertex is : "<<current;	//Displaying Selected Vertex.
		cout<<endl<<"Minimum is : "<<min<<endl;			//Dispaying Minimum Edge.

		visited[current] = 1;	//Now Current Is Visited.

		for(k=0;k<v;k++)	//Loop For Finding minimum Path.
		{
			if(visited[k] == 0 && (d[current] + weight[current][k]) < d[k])	//Checking For New Unvisited Edge To create path.
			{
				if(weight[current][k] != 0)	//Checking If Edge Is Not Present.
				{
					d[k] = d[current] + weight[current][k];	//Updating The Total Distance.
					p[k] = current;	//Assigning The New Path.
				}
			}
		}

		cout<<"\nVisited, Distance and path Status : "<<endl;	//Displaying Distance and Path Status.
		for(int m = 0; m < v; m++){
			cout<<endl<<"i = "<<m<<", Visited["<<m<<"] = "<<visited[m]<<", p["<<m<<"] = "<<p[m]<<", d["<<m<<"] = "<<d[m];
		}
	}//End Of Outer Loop.

	cout<<endl<<"------------------------------------------------------";
	cout<<endl<<"\nShortest Path from Source to all Destinations";
	cout<<endl<<"Source is -->"<<vname[s];
	for(i=0;i<v;i++)	//Displaying All the Shortest Paths.
	{
		if(i != s) //If Not Source.
		{
			cout<<endl<<"Vertex = "<<vname[i]<<", Distance = "<<d[i];
			cout<<"\nPath = "<<vname[i];
			j = i;
			do	//Traversing Till Source is Reachead.
			{
				j = p[j];
				cout<<" <- "<<vname[j];
			}while(j != s); //If Not Source.
		}
		cout<<endl;
	}
	cout<<endl<<"------------------------------------------------------";

}

//Function to create new AL Node.
AL* newNode(int i, int wt){
	AL *temp = new AL;
	temp->vertex = i;
	temp->weight = wt;
	temp->link = NULL;
	return temp;
}
