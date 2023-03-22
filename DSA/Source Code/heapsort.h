#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

#include<iostream>
using namespace std;
class heap{
	int list[20];
	int size;
public:
	void input();
	void display();
	void max_heapify(int ,int);
	void heapsort();
	void build_heap();
};
void heap::build_heap(){
	int i;
	for(i=size/2;i>=0;i--){
		max_heapify(i,size);
	}
}
void heap::max_heapify(int i,int li){
	int j, temp;
	temp=list[i];
	j=2*i;
	while(j<li){
		if(j<=li && list[j+1] > list[j])
			j+=1;
		if(temp>=list[j])
			break;
		else if(temp<=list[j]){
			list[j/2]=list[j];
			j=2*j;
		}
	}
	list[j/2]=temp;
	return;
}
void heap::heapsort(){
	int i,temp;
	for(i=size-1;i>=0;i--){
		temp=list[i];
		list[i]=list[0];
		list[0]=temp;
		cout<<"\nHeap tree after root deletion"<<endl;
		display();
		max_heapify(0,i-1);
		cout<<"\nHeap after Reconstruction"<<endl;
		display();
	}
}
void heap::display(){
	for(int i=0;i<size;i++){
		cout<<" "<<list[i];
	}
}
void heap::input(){
	cout<<"Enter number of elements"<<endl;
	cin>>size;
	for(int i=0;i<size;i++){
		cout<<"Element "<<i+1<<endl;
		cin>>list[i];
	}
}



#endif // HEAPSORT_H_INCLUDED
