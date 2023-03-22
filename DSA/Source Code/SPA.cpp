//============================================================================
// Title	   : Shortest Path Algorithm.
// Class	   : SE-10 (IT)
// Roll No	   : 23277
// Batch	   : H10
// Name        : SPA.cpp
// Author      : Diptesh Varule
// Version     : Updating...
// Copyright   : Your copyright notice
// Description : Client Code in C++, Ansi-style
//============================================================================

//Problem Statement.
/*
Represent a graph of city using adjacency matrix /adjacency list. Nodes should represent the various
landmarks and links should represent the distance between them. Find the shortest path using
Dijkstra's algorithm from single source to all destination.
*/

#include <iostream>
#include "SPA_Header.h"
using namespace std;

int main() {

	Graph g;	//Creating Graph.
	int ch;		//Backend-Choice.
	do{
		//User Guide.
		cout<<"\n=============================================\n";
		cout<<"\n1.Input Graph \n2.Display Graph \n3.Dijkstras's Algorithm";
		cout<<"\n0.Exit \n";
		cout<<"\nEnter Choice : ";
		cin>>ch;
		cout<<"\n=============================================\n";
		switch(ch){
			case 1:	//Creating Graph.
				g.createGraphMat();
				break;
			case 2:	//Displaying Graph.
				g.displayGraphMat();
				break;
			case 3:	//Displaying MST Using Prim's Algorithm.
				g.dijktrasAlgo();
				break;
			case 0:	//Ending The Program.
				break;
			default://Handling Invalid Input.
				cout<<"\n\tINVALID OPTION !!!";
				break;
		}
	}while(ch != 0);

	cout << "\nProgram End" << endl; //Prints Program End
	return 0;
}

//Output
/*
=============================================

1.Input Graph
2.Display Graph
3.Dijkstras's Algorithm
0.Exit

Enter Choice : 1

=============================================
Is The Graph Directed
1.True
2.False
Directed : 1

Enter The Number Of Land Marks In the Graph : 5

Enter The Name Of The Land Mark 1 : Kothrud
Enter The Name Of The Land Mark 2 : Shivaji Nagar
Enter The Name Of The Land Mark 3 : Pimpri Chinchwad
Enter The Name Of The Land Mark 4 : Swar Gate
Enter The Name Of The Land Mark 5 : Katraj

Enter The Distance Between Kothrud --> Shivaji Nagar : 10
Enter The Distance Between Kothrud --> Pimpri Chinchwad : 5
Enter The Distance Between Kothrud --> Swar Gate : 0
Enter The Distance Between Kothrud --> Katraj : 0

Enter The Distance Between Shivaji Nagar --> Kothrud : 0
Enter The Distance Between Shivaji Nagar --> Pimpri Chinchwad : 2
Enter The Distance Between Shivaji Nagar --> Swar Gate : 1
Enter The Distance Between Shivaji Nagar --> Katraj : 0

Enter The Distance Between Pimpri Chinchwad --> Kothrud : 0
Enter The Distance Between Pimpri Chinchwad --> Shivaji Nagar : 3
Enter The Distance Between Pimpri Chinchwad --> Swar Gate : 9
Enter The Distance Between Pimpri Chinchwad --> Katraj : 2

Enter The Distance Between Swar Gate --> Kothrud : 0
Enter The Distance Between Swar Gate --> Shivaji Nagar : 0
Enter The Distance Between Swar Gate --> Pimpri Chinchwad : 0
Enter The Distance Between Swar Gate --> Katraj : 4

Enter The Distance Between Katraj --> Kothrud : 7
Enter The Distance Between Katraj --> Shivaji Nagar : 0
Enter The Distance Between Katraj --> Pimpri Chinchwad : 0
Enter The Distance Between Katraj --> Swar Gate : 6


Adjacent Matrix Created Successfully
=============================================

1.Input Graph
2.Display Graph
3.Dijkstras's Algorithm
0.Exit

Enter Choice : 2

=============================================

The Distance Between Kothrud And Shivaji Nagar Is : 10
The Distance Between Kothrud And Pimpri Chinchwad Is : 5

The Distance Between Shivaji Nagar And Pimpri Chinchwad Is : 2
The Distance Between Shivaji Nagar And Swar Gate Is : 1

The Distance Between Pimpri Chinchwad And Shivaji Nagar Is : 3
The Distance Between Pimpri Chinchwad And Swar Gate Is : 9
The Distance Between Pimpri Chinchwad And Katraj Is : 2

The Distance Between Swar Gate And Katraj Is : 4

The Distance Between Katraj And Kothrud Is : 7
The Distance Between Katraj And Swar Gate Is : 6

|Kothrud|-->|Shivaji Nagar|, Weight = 10
|Kothrud|-->|Pimpri Chinchwad|, Weight = 5
|Shivaji Nagar|-->|Pimpri Chinchwad|, Weight = 2
|Shivaji Nagar|-->|Swar Gate|, Weight = 1
|Pimpri Chinchwad|-->|Shivaji Nagar|, Weight = 3
|Pimpri Chinchwad|-->|Swar Gate|, Weight = 9
|Pimpri Chinchwad|-->|Katraj|, Weight = 2
|Swar Gate|-->|Katraj|, Weight = 4
|Katraj|-->|Kothrud|, Weight = 7
|Katraj|-->|Swar Gate|, Weight = 6


Displaying Adjacency List

|Kothrud|->|Shivaji Nagar, 10|->|Pimpri Chinchwad, 5|
|Shivaji Nagar|->|Pimpri Chinchwad, 2|->|Swar Gate, 1|
|Pimpri Chinchwad|->|Shivaji Nagar, 3|->|Swar Gate, 9|->|Katraj, 2|
|Swar Gate|->|Katraj, 4|
|Katraj|->|Kothrud, 7|->|Swar Gate, 6|

=============================================

1.Input Graph
2.Display Graph
3.Dijkstras's Algorithm
0.Exit

Enter Choice : 3

=============================================

0. Kothrud
1. Shivaji Nagar
2. Pimpri Chinchwad
3. Swar Gate
4. Katraj

Enter The source Serial Number : 0

Visited, Distance and path Status :

i = 0, Visited[0] = 1, p[0] = 0, d[0] = 0
i = 1, Visited[1] = 0, p[1] = 0, d[1] = 10
i = 2, Visited[2] = 0, p[2] = 0, d[2] = 5
i = 3, Visited[3] = 0, p[3] = 0, d[3] = 7777
i = 4, Visited[4] = 0, p[4] = 0, d[4] = 7777
Selected Vertex is : 2
Minimum is : 5

Visited, Distance and path Status :

i = 0, Visited[0] = 1, p[0] = 0, d[0] = 0
i = 1, Visited[1] = 0, p[1] = 2, d[1] = 8
i = 2, Visited[2] = 1, p[2] = 0, d[2] = 5
i = 3, Visited[3] = 0, p[3] = 2, d[3] = 14
i = 4, Visited[4] = 0, p[4] = 2, d[4] = 7
Selected Vertex is : 4
Minimum is : 7

Visited, Distance and path Status :

i = 0, Visited[0] = 1, p[0] = 0, d[0] = 0
i = 1, Visited[1] = 0, p[1] = 2, d[1] = 8
i = 2, Visited[2] = 1, p[2] = 0, d[2] = 5
i = 3, Visited[3] = 0, p[3] = 4, d[3] = 13
i = 4, Visited[4] = 1, p[4] = 2, d[4] = 7
Selected Vertex is : 1
Minimum is : 8

Visited, Distance and path Status :

i = 0, Visited[0] = 1, p[0] = 0, d[0] = 0
i = 1, Visited[1] = 1, p[1] = 2, d[1] = 8
i = 2, Visited[2] = 1, p[2] = 0, d[2] = 5
i = 3, Visited[3] = 0, p[3] = 1, d[3] = 9
i = 4, Visited[4] = 1, p[4] = 2, d[4] = 7
------------------------------------------------------

Shortest Path from Source to all Destinations
Source is -->Kothrud

Vertex = Shivaji Nagar, Distance = 8
Path = Shivaji Nagar <- Pimpri Chinchwad <- Kothrud

Vertex = Pimpri Chinchwad, Distance = 5
Path = Pimpri Chinchwad <- Kothrud

Vertex = Swar Gate, Distance = 9
Path = Swar Gate <- Shivaji Nagar <- Pimpri Chinchwad <- Kothrud

Vertex = Katraj, Distance = 7
Path = Katraj <- Pimpri Chinchwad <- Kothrud

------------------------------------------------------
=============================================

1.Input Graph
2.Display Graph
3.Dijkstras's Algorithm
0.Exit

Enter Choice : 00

=============================================

Program End
*/

/*
//Structure AL.
struct AL{
	int vertex;								//Vertex Number.
	int weight;								//Weight.
	AL* link;								//Link To Another Vertex.
};

//Create Graph Using Adjacent List.
void Graph::createGraphList(){

	cout<<"\nEnter The Number Of Vertices In the Graph : ";			//Asking For Vertices.
	cin>>vertices;

	for(int i = 0; i < vertices; i++){
		cout<<"\nEnter The Number Of Vertices Vertex "<<i<<" Is Connected : ";	//Asking For Total Number OF Vertices
		int itr;																//The Vertex Is Connected With.
		cin>>itr;

		AL* temp = newNode(i, 100);	//Adding The Vertex.
		list[i] = temp;

		AL* trav = list[i];		//Creating trav for Traversal.
		for(int j = 1; j <= itr; j++){

			while(trav->link != NULL){	//Traversing Till Null Link.
				trav = trav->link;
			}

			cout<<"Enter The Vertex Number : ";	//Asking For Vertex Number.
			int v;
			cin>>v;

			cout<<"Enter The Edge Weight  : ";	//Asking For Edge Weight.
			int w;
			cin>>w;

			AL* nev = newNode(v, w);	//Creating New Node.

			trav->link = nev;
			cout<<endl;
		}
		cout<<endl;
	}

}

//Display Graph Using Adjacent List.
void Graph::displayGraphList(){

	cout<<endl;
	for(int i = 0; i < vertices; i++){
		cout<<"|"<<list[i]->vertex<<"|";

		AL* trav = list[i];		//Creating trav for Traversal.
		while(trav != NULL){

			trav = trav->link;
			if(trav == NULL){	//If Trav is Null Then Break.
				break;
			}

			cout<<"->|"<<trav->vertex<<"|";	//Display vertex.

		}
		cout<<endl;		//Space.
	}
}
 */
