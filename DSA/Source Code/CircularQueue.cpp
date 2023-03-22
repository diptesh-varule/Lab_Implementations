//============================================================================
// Name        : CircularQueue.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class CircularQueue{
private:
    int arr[5];
    int front,rear,itemCount;
public:
    CircularQueue(){
    	itemCount=0;
        front=-1;
        rear=-1;
    for(int i=0;i<5;i++){
        arr[i]=0;
    }
    }


    bool isEmpty(){
    if(front==-1 && rear==-1){
        return true;
    }
    else{
        return false;
    }
    }


    bool isFull(){
    if((rear+1)%5==front){
        return true;
    }
    else{
        return false;
    }
    }


    void enqueue(int val){
    if(isFull()){
        cout<<"Queue is full";
        return;
    }
    else if(isEmpty()){
        front=0;
        rear=0;
    }
    else{
        rear=(rear+1)%5;
    }
    arr[rear]=val;
    itemCount++;
    }


    int dequeue(){
    int x=0;
    if(isEmpty()){
        cout<<"Queue is empty";
        return 0;
    }
    else if(front==rear){
        x=arr[front];
        front=-1;
        rear=-1;
        arr[front]=0;
        itemCount--;
        return x;
    }

    else{
        x=arr[front];
        arr[front]=0;
        front=(front+1)%5;
        itemCount--;
        return x;
    }

    }

    int count(){
    	return itemCount;
    }

    void display(){
    cout<<"The Elements in the queue are as follows........."<<endl;
    for (int i=0;i<=4;i++){
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
    }

};

int main() {
CircularQueue obj;
	int option,value;

	do{
	        cout<<"Select the Operation you want to perform...."<<endl;
	        cout<<"1.Enqueue()"<<endl;
	        cout<<"2.Dequeue()"<<endl;
	        cout<<"3.isEmpty()"<<endl;
	        cout<<"4.isFull()"<<endl;
	        cout<<"5.count()"<<endl;
	        cout<<"6.display()"<<endl;
	        cout<<"7.clearscreen()"<<endl;

	        cin>>option;

	        switch(option){
	        case 0:
	            break;
	        case 1:
	            cout<<"Enter the element to enqueue : ";
	            cin>>value;
	            obj.enqueue(value);
	            break;
	        case 2:
	           cout<<"Dequeued value is "<<obj.dequeue()<<endl;
	            break;
	        case 3:
	            if(obj.isEmpty()){
	                cout<<"Queue is Empty"<<endl;
	            }
	            else{
	                cout<<"Queue is not Empty"<<endl;
	            }
	            break;
	        case 4:
	            if(obj.isFull()){
	                cout<<"Queue is full"<<endl;
	            }
	            else{
	                cout<<"Queue is not full"<<endl;
	            }
	            break;
	        case 5:
	            cout<<"The size of the queue is "<<obj.count()<<endl;
	            break;
	        case 6:
	            obj.display();
	            break;
	        case 7:
	            system("cls");
	            break;
	        default:
	            cout<<"Enter the correct option"<<endl;


	        }

	}while(option!=0);







	return 0;
}
