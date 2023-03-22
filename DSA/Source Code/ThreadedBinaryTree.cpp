//============================================================================
// Name        : ThreadedBinaryTree.cpp
// Author      : ccc
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Node
{
public :
	int data;
	Node *left,*right;
	bool lbit,rbit;

};

class TBT
{
	Node *root;
public :
	TBT()
    {
		root = getNode(0);
		root->left = root->right = root;
		root->lbit = 1;
		root->rbit = 1;
    }

	Node* getNode(int x)
	{
		//creating a node with given data
		Node* p = new Node();
		p->data = x;
		p->left = p->right = NULL;   //setting left and right as null
		p->lbit = 0;  //setting both as 0
		p->rbit = 0;
		return p;   //returning node
	}

	void create()
	{
		Node *temp1,*temp2;
		int x,choice;
		bool flag = 1;
		cout<<"ENTER VALUE : ";  //value for node
		cin>>x;

		if(root->left == root)
		{
			temp1 = getNode(x);
			temp1->left = root;
			temp1->lbit = 1;
			temp1->rbit = 1;
			temp1->right = root;
			root->left = temp1;
			root->lbit = 0;
		}
		else
		{
			//if root node is already present
			temp1 = root->left;
			do
			{
				//keep repeating unitl insertion takes place
				cout<<"CURRENT NODE : "<<temp1->data<<endl;
				cout<<"CURRENT NODE INSERTION \n1.LEFT  \n2.RIGHT "<<endl;
				cin>>choice;

				if(choice == 1)
				{
					if(temp1->lbit)
					{
						//check if left subtree is present
						//if not then it will be executed
						temp2 = getNode(x);
						temp2->left = temp1->left;
						temp2->right = temp1;
						temp2->rbit = temp2->lbit = 1;
						temp1->left = temp2;
						temp1->lbit = 0;
						flag = 0;

					}
					else
					{
						//if not null go ahead till u find insertion point
						temp1 = temp1->left;
					}
				}
				else
				{
					//for right link insertion
					if(temp1->rbit)
					{
						//check if right subtree is present
					    temp2=getNode(x);
					    temp2->right=temp1->right;    //points to succesor
					    temp2->left=temp1;            //points to predecessor
					    temp2->lbit=temp2->rbit=1;    //set both as 1
					    temp1->right=temp2;           //link parent to child
					    temp1->rbit=0;
					    flag=0;
					}
					else
					{
						temp1 = temp1->right;
						//if not null go ahead till u find insertion point
					}
				}
			}while(flag != 0);
		}
	}

	void display_Inorder()
	{
		Node *p = root->left;
		while(!(p->lbit))
		{
			//traverse till you get the last left node
			p = p->left;
		}
		while(p != root)
		{
			cout<<"  "<<p->data;   //print the data of node
			if(p->rbit)
			{
				//if no right child to succesor
				p = p->right;
			}
			else
			{
				//if right child present
				p = p->right;
				while(!(p->lbit) && (p != root))
				{
					//if right child has further subtree traverse it
					p = p->left;
				}
			}
		}

	}

	void preorder()
	{
		Node *temp=root->left;
		if(temp==root)
		{
			//if head is null print empty tree
			cout<<"Empty tree"<<endl;
			return;
		}
		while(temp!=root)
		{
			//if head is not null
			cout<<" "<<temp->data;     //print the data
			if(!(temp->lbit))
			{
				//if left child is present
				temp=temp->left;
				//point temp to left child and iterate loop
				continue;

			}
			else
			{
				//if no left child go to right subtree
				while(temp->rbit && temp!=root)
				{
					//if no subchild
					temp=temp->right;
					//point to successor
				}
			}
			if(!(temp->rbit)&&(temp!=root))
			{
				//if right child is present
				temp=temp->right;
				//point to the next node
			}
		}
	}

};
int main() {
	TBT obj;
	int choice;

	do
	{
		cout<<"\nEnter the choice : ";
		cout<<"\n1.Create : ";
		cout<<"\n2.Display Inorder : ";
		cout<<"\n3.Display Preorder : ";
		cout<<"\n4.Exit ";
		cin>>choice;

		switch(choice)
		{
		case 1 :
			obj.create();
			break;
		case 2 :
			obj.display_Inorder();
			break;
		case 3 :
			obj.preorder();
			break;
		case 4 :
			cout<<"Exited";
			break;
		default :
			cout<<"Enter valid choice ";
		}

	}while(choice != 4);
	return 0;
}
