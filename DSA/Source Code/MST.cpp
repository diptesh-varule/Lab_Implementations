//============================================================================
// Title	   : Minimum Spanning Tree.
// Class	   : SE-10 (IT)
// Roll No	   : 23277
// Batch	   : H10
// Name        : MST.cpp
// Author      : Diptesh Varule
// Version     : Updating...
// Copyright   : Your copyright notice
// Description : Client Code in C++, Ansi-style
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
using namespace std;

int main() {

	Graph g;	//Creating Graph.
	int ch;
	do{
		cout<<"\n=============================================\n";
		cout<<"\n1.Input Graph \n2.Display Graph \n3.Prim's Algorithm";
		cout<<"\n4.Kruskal's Algorithm \n0.Exit \n";
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
				g.primAlgo();
				break;
			case 4:	//Displaying MST Using Kruskal's Algorithm.
				g.kruskalAlgo();
				break;
			case 0:	//Ending The Program.
				break;
			default://Handling Invalid Input.
				cout<<"\n\tINVALID OPTION !!!";
				break;
		}
	}while(ch != 0);

	cout << "\nProgram End" << endl; // prints MST
	return 0;
}

//Output
/*
=============================================

1.Input Graph
2.Display Graph
3.Prim's Algorithm
4.Kruskal's Algorithm
0.Exit

Enter Choice : 1

=============================================
Is The Building Graph Directed
1.True
2.False
Directed : 2

Enter The Number Of Building In the Graph : 5

Enter The Name Of The Building 1 : F-Wing
Enter The Name Of The Building 2 : H-Wing
Enter The Name Of The Building 3 : Hostels
Enter The Name Of The Building 4 : Canteen
Enter The Name Of The Building 5 : Ground

Enter The Distance Between F-Wing And H-Wing : 4
Enter The Distance Between F-Wing And Hostels : 10
Enter The Distance Between F-Wing And Canteen : 4
Enter The Distance Between F-Wing And Ground : 8

Enter The Distance Between H-Wing And Hostels : 7
Enter The Distance Between H-Wing And Canteen : 6
Enter The Distance Between H-Wing And Ground : 3

Enter The Distance Between Hostels And Canteen : 5
Enter The Distance Between Hostels And Ground : 10

Enter The Distance Between Canteen And Ground : 5



Adjacent Matrix Created Successfully
=============================================

1.Input Graph
2.Display Graph
3.Prim's Algorithm
4.Kruskal's Algorithm
0.Exit

Enter Choice : 2

=============================================

The Distance Between F-Wing And H-Wing Is : 4
The Distance Between F-Wing And Hostels Is : 10
The Distance Between F-Wing And Canteen Is : 4
The Distance Between F-Wing And Ground Is : 8

The Distance Between H-Wing And Hostels Is : 7
The Distance Between H-Wing And Canteen Is : 6
The Distance Between H-Wing And Ground Is : 3

The Distance Between Hostels And Canteen Is : 5
The Distance Between Hostels And Ground Is : 10

The Distance Between Canteen And Ground Is : 5


|F-Wing|-->|H-Wing|, Weight = 4
|H-Wing|-->|F-Wing|, Weight = 4
|F-Wing|-->|Hostels|, Weight = 10
|Hostels|-->|F-Wing|, Weight = 10
|F-Wing|-->|Canteen|, Weight = 4
|Canteen|-->|F-Wing|, Weight = 4
|F-Wing|-->|Ground|, Weight = 8
|Ground|-->|F-Wing|, Weight = 8
|H-Wing|-->|Hostels|, Weight = 7
|Hostels|-->|H-Wing|, Weight = 7
|H-Wing|-->|Canteen|, Weight = 6
|Canteen|-->|H-Wing|, Weight = 6
|H-Wing|-->|Ground|, Weight = 3
|Ground|-->|H-Wing|, Weight = 3
|Hostels|-->|Canteen|, Weight = 5
|Canteen|-->|Hostels|, Weight = 5
|Hostels|-->|Ground|, Weight = 10
|Ground|-->|Hostels|, Weight = 10
|Canteen|-->|Ground|, Weight = 5
|Ground|-->|Canteen|, Weight = 5


Displaying Adjacency List

|F-Wing|->|H-Wing, 4|->|Hostels, 10|->|Canteen, 4|->|Ground, 8|
|H-Wing|->|F-Wing, 4|->|Hostels, 7|->|Canteen, 6|->|Ground, 3|
|Hostels|->|F-Wing, 10|->|H-Wing, 7|->|Canteen, 5|->|Ground, 10|
|Canteen|->|F-Wing, 4|->|H-Wing, 6|->|Hostels, 5|->|Ground, 5|
|Ground|->|F-Wing, 8|->|H-Wing, 3|->|Hostels, 10|->|Canteen, 5|

=============================================

1.Input Graph
2.Display Graph
3.Prim's Algorithm
4.Kruskal's Algorithm
0.Exit

Enter Choice : 3

=============================================

Visited, Distance and path Status :

i = 0, Visited[0] = 1, p[0] = 0, d[0] = 0
i = 1, Visited[1] = 0, p[1] = 0, d[1] = 7777
i = 2, Visited[2] = 0, p[2] = 0, d[2] = 7777
i = 3, Visited[3] = 0, p[3] = 0, d[3] = 7777
i = 4, Visited[4] = 0, p[4] = 0, d[4] = 7777
Entering While Loop

Total visited = 1
Visited, Distance and path Status :

i = 0, Visited[0] = 1, p[0] = 0, d[0] = 0
i = 1, Visited[1] = 0, p[1] = 0, d[1] = 4
i = 2, Visited[2] = 0, p[2] = 0, d[2] = 10
i = 3, Visited[3] = 0, p[3] = 0, d[3] = 4
i = 4, Visited[4] = 0, p[4] = 0, d[4] = 8

Now, Finding The Minimum Cost


mincost = 4
current = 1

Current = 1
Total Visited = 2
Total visited = 2
Visited, Distance and path Status :

i = 0, Visited[0] = 1, p[0] = 0, d[0] = 0
i = 1, Visited[1] = 1, p[1] = 0, d[1] = 4
i = 2, Visited[2] = 0, p[2] = 1, d[2] = 7
i = 3, Visited[3] = 0, p[3] = 0, d[3] = 4
i = 4, Visited[4] = 0, p[4] = 1, d[4] = 3

Now, Finding The Minimum Cost


mincost = 3
current = 4

Current = 4
Total Visited = 3
Total visited = 3
Visited, Distance and path Status :

i = 0, Visited[0] = 1, p[0] = 0, d[0] = 0
i = 1, Visited[1] = 1, p[1] = 0, d[1] = 4
i = 2, Visited[2] = 0, p[2] = 1, d[2] = 7
i = 3, Visited[3] = 0, p[3] = 0, d[3] = 4
i = 4, Visited[4] = 1, p[4] = 1, d[4] = 3

Now, Finding The Minimum Cost


mincost = 4
current = 3

Current = 3
Total Visited = 4
Total visited = 4
Visited, Distance and path Status :

i = 0, Visited[0] = 1, p[0] = 0, d[0] = 0
i = 1, Visited[1] = 1, p[1] = 0, d[1] = 4
i = 2, Visited[2] = 0, p[2] = 3, d[2] = 5
i = 3, Visited[3] = 1, p[3] = 0, d[3] = 4
i = 4, Visited[4] = 1, p[4] = 1, d[4] = 3

Now, Finding The Minimum Cost


mincost = 5
current = 2

Current = 2
Total Visited = 5
Minimum cost = 16

Visited, Distance and path Status :

i = 0, Visited[0] = 1, p[0] = 0, d[0] = 0
i = 1, Visited[1] = 1, p[1] = 0, d[1] = 4
i = 2, Visited[2] = 1, p[2] = 3, d[2] = 5
i = 3, Visited[3] = 1, p[3] = 0, d[3] = 4
i = 4, Visited[4] = 1, p[4] = 1, d[4] = 3

|F-Wing|-->|H-Wing|, Weight = 4
|Canteen|-->|Hostels|, Weight = 5
|F-Wing|-->|Canteen|, Weight = 4
|H-Wing|-->|Ground|, Weight = 3

Total Cost of MST is 16

=============================================

1.Input Graph
2.Display Graph
3.Prim's Algorithm
4.Kruskal's Algorithm
0.Exit

Enter Choice : 4

=============================================

Edge array Entered By The User is :
|0->1|, Weight : 4
|1->0|, Weight : 4
|0->2|, Weight : 10
|2->0|, Weight : 10
|0->3|, Weight : 4
|3->0|, Weight : 4
|0->4|, Weight : 8
|4->0|, Weight : 8
|1->2|, Weight : 7
|2->1|, Weight : 7
|1->3|, Weight : 6
|3->1|, Weight : 6
|1->4|, Weight : 3
|4->1|, Weight : 3
|2->3|, Weight : 5
|3->2|, Weight : 5
|2->4|, Weight : 10
|4->2|, Weight : 10
|3->4|, Weight : 5
|4->3|, Weight : 5

Sorted List of edges
|1->4|, Weight : 3
|4->1|, Weight : 3
|0->1|, Weight : 4
|1->0|, Weight : 4
|0->3|, Weight : 4
|3->0|, Weight : 4
|2->3|, Weight : 5
|3->2|, Weight : 5
|3->4|, Weight : 5
|4->3|, Weight : 5
|1->3|, Weight : 6
|3->1|, Weight : 6
|1->2|, Weight : 7
|2->1|, Weight : 7
|0->4|, Weight : 8
|4->0|, Weight : 8
|0->2|, Weight : 10
|2->0|, Weight : 10
|2->4|, Weight : 10
|4->2|, Weight : 10


Edge selected|1->4|, Weight : 3, Both The Vertices Are Not Visited
Edge Rejected |4->1|, Weight : 3, Both The Vertices Have Same Connected Value
Edge selected|0->1|, Weight : 4, Both The Vertices Have Different Connected Value
Edge Rejected |1->0|, Weight : 4, Both The Vertices Have Same Connected Value
Edge selected|0->3|, Weight : 4, Both The Vertices Have Different Connected Value
Edge Rejected |3->0|, Weight : 4, Both The Vertices Have Same Connected Value
Edge selected|2->3|, Weight : 5, Both The Vertices Have Different Connected Value
Edge Rejected |3->2|, Weight : 5, Both The Vertices Have Same Connected Value
Edge Rejected |3->4|, Weight : 5, Both The Vertices Have Same Connected Value
Edge Rejected |4->3|, Weight : 5, Both The Vertices Have Same Connected Value
Edge Rejected |1->3|, Weight : 6, Both The Vertices Have Same Connected Value
Edge Rejected |3->1|, Weight : 6, Both The Vertices Have Same Connected Value
Edge Rejected |1->2|, Weight : 7, Both The Vertices Have Same Connected Value
Edge Rejected |2->1|, Weight : 7, Both The Vertices Have Same Connected Value
Edge Rejected |0->4|, Weight : 8, Both The Vertices Have Same Connected Value
Edge Rejected |4->0|, Weight : 8, Both The Vertices Have Same Connected Value
Edge Rejected |0->2|, Weight : 10, Both The Vertices Have Same Connected Value
Edge Rejected |2->0|, Weight : 10, Both The Vertices Have Same Connected Value
Edge Rejected |2->4|, Weight : 10, Both The Vertices Have Same Connected Value
Edge Rejected |4->2|, Weight : 10, Both The Vertices Have Same Connected Value


Kruskal's MST contains following edges::
|1->4|, Weight : 3
|0->1|, Weight : 4
|0->3|, Weight : 4
|2->3|, Weight : 5

Total Cost of MST is 16

=============================================

1.Input Graph
2.Display Graph
3.Prim's Algorithm
4.Kruskal's Algorithm
0.Exit

Enter Choice : 5

=============================================

	INVALID OPTION !!!
=============================================

1.Input Graph
2.Display Graph
3.Prim's Algorithm
4.Kruskal's Algorithm
0.Exit

Enter Choice : 0

=============================================

Program End
*/

