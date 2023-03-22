#include<fstream>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include <iomanip>
#include<string.h>


using namespace std;

//Class Database
class Database
{
private:
	 int rollno;// declaring Variable
	 char name[100];// declaring name variable
	 char address[100];// declaring address variable
	 float marks;// declaring marks variable

public:
	 void Input_data();//declaring Input_Data Method
	 void display();//declaring display method
	 int get_roll()// declarin get_roll number
	 {
	  return rollno;//returning roll number
	 }
};


//Method Definatiom
void Database::Input_data()
{
	 cout<<"Enter the roll number of the Student: ";
	 cin>>rollno;//entering roll number
	 cout<<"Enter the name: ";
	 cin.ignore();
	 gets(name);//entering nmae
	 cout<<"Enter the address:";
	 cin.ignore();
	 gets(address);//entering address
	 cout<<"Enter the marks (Out of 50): ";
	 cin>>marks;//entering marks
	 //Validation of Marks
	 if(marks>50){
	 	cout<<"Error!!\nPlease Enter marks appropriately!"<<endl;
	 	cout<<"Enter the marks (Out of 50): ";
	 	cin>>marks;
	 }
	 cout<<endl;
}
//Display Function
void Database::display()
{
	 cout << "---------------------------------------------" << endl;
        cout << setw(25) << "Name" << setw(15) << "Roll no." << setw(15) << "Marks" << setw(15) <<"Address"<<endl;
        cout << setw(25) << name << setw(15) << rollno << setw(15) << marks << setw(15)<<address<<endl;
}

class record{
public:
	fstream file1;
	Database fileobj;
    Database modified;//Creating Object
void Create();//Create Function Declaration
void Add();// Add Function Declaration
void Display();// Display Function Declaration
void Search();// Search Function Declaration
void Modify();// Modify Function Declaration
void Delete();// Delete Function Declaration
};

void record::Create()  //Function to Create DataBase File
	{
	 char ch='y';
	 file1.open("binary.dat",ios::out| ios::binary);

	 while(ch=='y' || ch =='Y')
	 {
		  fileobj.Input_data();
		  file1.write((char*)&fileobj, sizeof(fileobj));
		  cout<<"To Continue(y/n): ";
		  cin>>ch;
	 }
	 file1.close();
}

void record::Add()              //Function to Add New Record in DataBase File
{
	 char ch='y';
	 file1.open("binary.dat",ios::app| ios::binary);
	 while(ch=='y' || ch =='Y')
	 {
		  fileobj.Input_data();
		  file1.write((char*)&fileobj, sizeof(fileobj));
		  cout<<"To Continue(y/n): ";
		  cin>>ch;
	 }
	 file1.close();
}

void record::Display()  //Function to Display All Record from DataBase File
{
	 file1.open("binary.dat",ios::in| ios::binary);
	 if(!file1)
	 {
		  cout<<"File not Found!";
		  exit(0);
	 }
	 else
	 {
	  file1.read((char*)&fileobj, sizeof(fileobj));
	  while(!file1.eof())
	  {
	   fileobj.display();
	   file1.read((char*)&fileobj, sizeof(fileobj));
	  }
	 }
	 file1.close();
}

void record::Search()  //Function to Display particular Record from DataBase File
{
	 int rollnu;
	 cout<<"Enter Roll No that should be searched:";
	 cin>>rollnu;
	 file1.open("binary.dat",ios::in| ios::binary);
	 if(!file1)
	 {
		  cout<<"File not Found!";
		  exit(0);
	 }
	 else
	 {
		  file1.read((char*)&fileobj, sizeof(fileobj));
		  while(!file1.eof())
		  {
			   if(rollnu==fileobj.get_roll())
			   				fileobj.display();


			   file1.read((char*)&fileobj, sizeof(fileobj));
	       }
	 }
	 file1.close();
}
void record::Modify()  //Function to Modify Particular Record from DataBase File
{
	 int rollnu;
	 cout<<"Enter Roll No. that should be modified:";
	 cin>>rollnu;
	 ofstream m;
	 file1.open("binary.dat",ios::in| ios::out|ios::binary);
	 m.open("new.dat",ios::out|ios::binary);
	 if(!file1)
	 {
		  cout<<"File not Found";
		  exit(0);
	 }
	 else
	 {
		  file1.read((char*)&fileobj, sizeof(fileobj));
		  while(!file1.eof())
		  {
			   if(rollnu==fileobj.get_roll())
			   {
					cout<<"Enter New Record:-"<<endl;
					modified.Input_data();
					m.write((char*)&modified, sizeof(modified));
			   }
			   else
				   m.write((char*)&fileobj, sizeof(fileobj));

		   file1.read((char*)&fileobj, sizeof(fileobj));
		  }
	 }
	 m.close();
	 file1.close();
	 remove("binary.dat");
	 rename("new.dat", "binary.dat");
}

void record::Delete()  //Function to Delete Particular Record from DataBase File
{
	 int rollnu;
	 cout<<"Enter Roll No. that to be deleted:";
	 cin>>rollnu;
	 ofstream o;
	 o.open("new.dat",ios::out|ios::binary);
	 file1.open("binary.dat",ios::in| ios::binary);
	 if(!file1)
	 {
		  cout<<"File not Found!";
		  exit(0);
	 }
	 else
	 {
		  file1.read((char*)&fileobj, sizeof(fileobj));
		  while(!file1.eof())
		  {
			  if(rollnu!=fileobj.get_roll())
			   	   o.write((char*)&fileobj, sizeof(fileobj));

			  file1.read((char*)&fileobj, sizeof(fileobj));
		  }
	 }
	 o.close();
	 file1.close();
	 remove("binary.dat");
	 rename("new.dat", "binary.dat");
}
//Main Function
int main()
{
	cout<<"WELCOME!";
	 int ch;
	 record obj;//Object Creation
	 int pin=1;
	 while(pin == 1)
	 {
	 	 // Displaying Menu with Choices
          cout<<endl;
          cout<<endl<<".........Menu........."<<endl;
		  cout<<"1.Create Database File"<<endl;
		  cout<<"2.Add New Record"<<endl;
		  cout<<"3.Display all Records"<<endl;
		  cout<<"4.Search a Record"<<endl;
		  cout<<"5.Modify a Record"<<endl;
		  cout<<"6.Delete a Record"<<endl;
		  cout<<"7.Exit"<<endl;
		  cout<<"Enter the Choice : "<<endl;
		  cin>>ch;
		  switch(ch)
		  {
		   case 1:
		   {
			   obj.Create();//Calling Function
			   break;
		   }
		   case 2:
		   {
			   obj.Add();// Calling Function
			   break;
		   }
		   case 3:
		   {
			   obj.Display();// Calling Display
			   break;
		   }
		   case 4:
		   {
			   obj.Search();// Calling Search
			   break;
		   }
		   case 5:
		   {
			   obj.Modify();// Calling Function
			   break;
		   }
		   case 6:
		   {
			   obj.Delete();// Calling Function
			   break;
		   }
		   case 7:
		   	{
		   		pin=0;
		   		cout<<endl<<"Exiting...."<<endl;
		   		break;
		   	}
		   default:
		   {
			   cout<<"Please Enter the correct Option!";
			   break;

		   }
		  }
	 }
	 cout<<endl<<"Thankyou :)";// End Program
}

