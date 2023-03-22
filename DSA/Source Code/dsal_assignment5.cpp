//============================================================================
// Name        : dsal_assignment5.cpp
// Author      : Diptesh Varule
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include"bstree.h"
using namespace std;

int main() {
	bstree t;
	bnode* temp=NULL;
	int ch;
	do{
		cout<<"**MENU***"<<endl;
		cout<<"1)Rec-Insert\n2)Insert\n3)Inorder traversal\n4)Search\n5)mirror\n6)copy\n7)Height\n8)Delete\n9)exit"<<endl;
		cin>>ch;
		switch(ch){
		case 1:int x1;
			   cout<<"Enter element to be inserted"<<endl;
			   cin>>x1;
			   temp=t.rec_insert(temp, x1);
			   break;
		case 2:int x2;
			   cout<<"Enter element to be inserted"<<endl;
			   cin>>x2;
			   temp=t.insert(temp, x2);
			   break;
		case 3:t.inorder(temp);
			   cout<<"\n";
			   break;
		case 4:int x3;
		       cout<<"Enter element to be searched"<<endl;
		       cin>>x3;
		       bnode* key;
		       key=t.search(temp, x3);
		       cout<<key->data<<endl;
		       break;
		case 5:bnode* mir;
			mir=t.mirror(temp);
			   t.inorder(mir);
			   break;
		case 6:bnode* cpy;
			   cpy=t.copy(temp);
			   cout<<"Copied tree:"<<endl;
			   t.inorder(cpy);
			   break;
		case 7:cout<<"Height of bst: "<<t.height(temp)<<endl;
				break;
		case 8:int x4;
	       	   cout<<"Enter element to be deleted"<<endl;
	       	   cin>>x4;
	       	   temp=t.deleteNode(temp, x4);
	       	   t.inorder(temp);
	       	   break;
		case 9:return 0;
		default:cout<<"invalid choice"<<endl;
				break;
		}
	}while(true);
	return 0;
}
