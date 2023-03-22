//============================================================================
// Name        : dsa_Assignment1.cpp
// Author      : Diptesh Varule
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

struct Student{
string name;
int rollNo;
double SGPA;

};

class SEIT{
    Student S[15];
    int n;


public:

    void input(int);//Method to input the student data
    void display(int);//Method to display the student data
    void rollCall(int);//Bubble Sorting for sorting students according to the roll numbers
    void listWithSortedName(int);//insertion sort sorting for alphabetical order
    int Partition(int,int);//For the quick sort
    void quickSort(int,int);//using quick sort for toppers list
    void samemarks(int);//to search the student with their marks
    void namesearch(int);////binary search for searching a name in given list
    bool validate(string);

};

bool SEIT::validate(string y)
{
    //name validation
    bool valid;
    for(int j=0;j<y.size();j++){
        char s=y[j];
        int k=s;
        if(k>=65 && k<=90)
        {
            valid=true;
        }
        else if(k>=97 && k<=122)
        {
            valid=true;
        }
        else if(k==32)
        {
             valid=true;
        }
        else {
            valid=false;
                break;
        }
    }
    return valid;
}


//taking input from the user
void SEIT::input(int n)
{

    for (int i=0;i<n;i++){
        //input name
        cout<<"Enter Full Name : ";
        cin.ignore();
        string x;
        getline(cin,x);
        bool check;
        check=validate(x);
        if(!check){
            cout<<"INVALID NAME"<<endl;
            cout<<"Re-enter Name : ";
            cin.ignore();
            getline(cin,x);
        }
        S[i].name=x;

        //input roll no
        cout<<"Enter Roll no. : ";
        cin>>S[i].rollNo;
        //Roll No. Validation
        if(S[i].rollNo==0 || S[i].rollNo<0){
        cout<<"Roll no. should be greater than zero........."<<endl;
        cout<<"Re-Enter Roll NO. : ";
        cin>>S[i].rollNo;
        }
        for(int j=0;j<i;j++){
            if(S[j].rollNo==S[i].rollNo) {
                cout<<"Roll Numbers should be different"<<endl;
                cout<<"Re-Enter Roll NO. : ";
                cin>>S[i].rollNo;
            }
        }
        //input SGPA
        cout<<"Enter SGPA : ";
        cin>>S[i].SGPA;
        //SGPA validation
        while(S[i].SGPA<0 || S[i].SGPA>10){
            cout<<"SGPA must lie between 0 to 10....... "<<endl;
            cout<<"Re-Enter the SGPA : ";
            cin>>S[i].SGPA;
        }
        cout<<endl;

    }
}

//displaying the info of student
void SEIT::display(int n)
{
    cout<<"\nThe Student details are as follows........"<<endl;
    cout<<"Sr No.\t STUDENT NAME \t\t ROLL NO. \t SGPA \n";
    for(int i=0;i<n;i++){
        cout<<(i+1)<<". \t "<<S[i].name<<"\t\t  "<<S[i].rollNo<<"\t\t"<<S[i].SGPA<<endl;
    }
    cout<<"\n";

}

//using bubble sort sorting the information according to roll number
void SEIT::rollCall(int n)
{

    int i,j;
    bool flag;
    Student temp;
    for (i = 0; i < n-1; i++)
       {flag = false;
         for (j = 0; j < n-i-1; j++)
			 {
            if (S[j].rollNo > S[j+1].rollNo)
                {
					   temp=S[j];
					   S[j]=S[j+1];
					   S[j+1]=temp;
					   flag = true;
                }
			 }
         if (flag == false)
            break;
       }
       cout<<endl;

}

//insertion sort sorting for alphabetical order
void SEIT::listWithSortedName(int n)
{
    int i,j;
    string key;
    Student temp;
    for (i = 1; i < n; i++)
        {
            temp=S[i];
            key = S[i].name;
            j = i - 1;
            while (j >= 0 && S[j].name > key)
            {
                S[j + 1] = S[j];
                j = j - 1;
            }
        S[j + 1] = temp;
        }

}

//For the quick sort
int SEIT::Partition(int low,int high)
{
    double pivot = S[high].SGPA;
    Student temp;
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
        {
            if (S[j].SGPA > pivot)
            {
                i++;
                temp=S[i];
                S[i]=S[j];
                S[j]=temp;
            }
        }
        temp=S[i+1];
        S[i+1]=S[high];
        S[high]=temp;
        return (i + 1);
}

//using quick sort for toppers list
void SEIT::quickSort(int left,int right){
     if(left<right){
        int middle=Partition(left,right);
        quickSort(left,middle-1);
        quickSort(middle+1,right);
    }


}


//to search the student with their marks
void SEIT::samemarks(int n)
{
    cout<<"Enter the SGPA to search : ";
    double y;
    cin>>y;
    cout<<"STUDENT NAME \t\t ROLL NO \t\t SGPA\n";
    for(int i=0;i<n;i++){
        if (S[i].SGPA==y){
            cout<<S[i].name<<"\t"<<S[i].rollNo<<"\t"<<S[i].SGPA<<endl;
        }
    }
}

//to search the student with their name;using binary search;
void SEIT::namesearch(int n){
 cout<<"Enter the name to search : ";
    string y;
    cin.ignore();
    getline(cin,y);
    int left=0,right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;

        if(y==S[mid].name){
            cout<<"Student Found ........"<<endl;
            cout<<S[mid].name<<"\t"<<S[mid].rollNo<<"\t"<<S[mid].SGPA<<endl;
            int j=mid+1;
            while(S[j].name==y){
                cout<<S[j].name<<"\t"<<S[j].rollNo<<"\t"<<S[j].SGPA<<endl;
                j++;
            }
            j=mid-1;
            while(S[j].name==y){
                cout<<S[j].name<<"\t"<<S[j].rollNo<<"\t"<<S[j].SGPA<<endl;
                j--;
            }
            break;
        }
        else if(y<S[mid].name){
            right=mid-1;
        }
        else{
            left=mid+1;
        }

    }
}



int main() {
    SEIT p;
    int n;
    cout<<"Enter the number of students : ";
    cin>>n;
    if(n<0 || n==0)
    {
      cout<<"No of students must be greater than 0....."<<endl;
      cout<<"Re-Enter no. of students :  ";
      cin>>n;
    }
    p.input(n);
    p.display(n);

    int z=1;
    while(z){

    cout<<"Select \n 1.Bubble Sort For Roll NO(Displaying Roll Call) \n 2.Insertion Sort For Name (Namewise list) \n 3.Quick Sort For SGPA(display first ten toppers)  \n 4.Linear Search For SGPA \n 5.Binary Search For Name \n 6.Clear the screen \n 7.Exit \n";
    int x;
    cin>>x;
    switch(x){
    case 1:p.rollCall(n);
    	   p.display(n);
    	   break;
    case 2:p.listWithSortedName(n);
            p.display(n);
            break;
    case 3:p.quickSort(0,n-1);
           p.display(n);
    		break;
    case 4: p.samemarks(n);
            break;
    case 5:p.listWithSortedName(n);
            p.namesearch(n);
           break;
    case 6:system("cls");
            break;
    case 7: exit(0);
    default:cout<<"Enter a valid input !!!";

    }
    cout<<"Enter 1 To Continue : ";
    cin>>z;
    }
	return 0;
}
