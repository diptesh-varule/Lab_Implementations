//============================================================================
// Name        : heapsort.cpp
// Author      : Diptesh Varule
// Version     : Updating...
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include"heapsort.h"
#include <iostream>
using namespace std;

int main() {
	heap sort;
	sort.input();
	cout<<"Before sorting "<<endl;
	sort.display();
	cout<<"\nHeap list is"<<endl;
	sort.build_heap();
	sort.display();
	cout<<"\nHeap sort start"<<endl;
	sort.heapsort();
	cout<<"\nSorted output "<<endl;
	sort.display();
	return 0;
}
