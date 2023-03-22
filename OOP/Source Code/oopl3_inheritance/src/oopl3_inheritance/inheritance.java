package oopl3_inheritance;
import java.util.Scanner;

//base class Employee having all the required data members and functions
class Employee {
	String Emp_Name,Emp_Designation;
	static int id=1000;
	int Emp_Id;
	String Address;
	String Mail_Id;
	String Mobile_No;
	double DA,HRA,PF,BP,Staff_Club_Fund,Gross_Salary,Net_Salary;
	

//Constructor to assign employee_id to every new employee recruited 
	Employee(){
		id=id+1;
		Emp_Id=id;
	}
	
	
//method to read the details of the employee
	public void read_details(){
		Scanner sc=new Scanner(System.in);
		System.out.println("\nEnter details of Employee...");
		System.out.print("Enter Employee Name :");
		Emp_Name=sc.nextLine();
		
		System.out.print("Enter Address :");
		Address=sc.nextLine();
		
		System.out.print("Enter Mail Id :");
		Mail_Id=sc.nextLine();
		
		System.out.print("Enter Mobile No :");
		Mobile_No=sc.nextLine();
	}
	
//method to display the basic details of the Employee 
	public void display_details() {
		System.out.println("\n               Employee Details");
		System.out.println("----------------------------------------------------------");
		System.out.println("Employee ID          : "+Emp_Id);
		System.out.println("Employee Name        : "+Emp_Name);
		System.out.println("Employee Designation : "+Emp_Designation);
		System.out.println("----------------------------------------------------------");
	
}
	
//method to calculate the net and gross salary based on the the basic pay of the employee 
	protected void calculate() {
		DA=0.97*BP;
		HRA=0.1*BP;
		PF=0.12*BP;
		Staff_Club_Fund=0.001*BP;
		Gross_Salary=BP+DA+HRA;
		Net_Salary=Gross_Salary-Staff_Club_Fund;
		
		
	}
	
//method to display the payslip of the employee
	public void display_payslip() {
		System.out.println("               Salary Slip         ");
		System.out.println("----------------------------------------------------------");
		System.out.println("Basic Pay       : "+BP);
		System.out.println("DA              : "+DA);
		System.out.println("HRA             : "+HRA);
		System.out.println("PF              : "+PF);
		System.out.println("Staff Club Fund : "+Staff_Club_Fund);
		System.out.println("----------------------------------------------------------");
		System.out.println("Gross Salary    : "+Gross_Salary);
		System.out.println("Net Salary      : "+Net_Salary);
		System.out.println("----------------------------------------------------------");
	}
	

//method to display all the details of the Employee	
	void display() {
		display_details();
		calculate();
		display_payslip();
		System.out.println();
	}
}

//child class 
class Programmer extends Employee{
	
	//Method to read details of the Programmer
	void read() {
		Scanner sp=new Scanner(System.in);
		read_details();
		Emp_Designation="Programmer";
		System.out.println("Enter basic pay : ");
		double x=sp.nextDouble();
		if(x>=40000.0 && x<50000.0 ) {
			BP=x;
		}
		else {
			System.out.println("The basic pay must be between 40000 and 50000\nEnter the basic pay : ");
			BP=sp.nextDouble();
		}
	}
	
	//static method to search an Programmer in the company
	static int searchP(Programmer p[],int noOfP,int id) {
		int index=-1;
		for(int i=0;i<noOfP;i++) {
			if(p[i].Emp_Id==id) {
				index=i;
			}
		}
		return index;
	}
	
}

//child class
class TeamLead extends Employee{
	
	//Method to read details of the Team Lead
	void read() {
		Scanner st=new Scanner(System.in);
		read_details();
		Emp_Designation="Team Lead";
		System.out.println("Enter basic pay : ");
		double x=st.nextDouble();
		if(x>=50000.0 && x<60000.0 ) {
			BP=x;
		}
		else {
			System.out.println("The basic pay must be between 50000 and 60000\nEnter the basic pay : ");
			BP=st.nextDouble();
			
		}
	}
	
	//static method to search an Team lead in the company
	static int searchTL(TeamLead t[],int noOfTLs,int id) {
		int index=-1;
		for(int i=0;i<noOfTLs;i++) {
			if(t[i].Emp_Id==id) {
				index=i;
			}
		}
		return index;
	}
	
}

class Assistant_Project_Manager extends Employee{
	
	//Method to read details of the Assistant Project Manager
	void read() {
		Scanner sa=new Scanner(System.in);
		read_details();
		Emp_Designation="Assistant Project manager";
		System.out.println("Enter basic pay : ");
		double x=sa.nextDouble();
		if(x<70000.0 && x>=60000.0) {
			BP=x;
		}
		else {
			System.out.println("The basic pay must be between 60000 and 70000\nEnter the basic pay : ");
			BP=sa.nextDouble();
		}
	}
	
	//static method to search an Assistant Project Manager in the company
	static int searchAPM(Assistant_Project_Manager apm[],int noOfapms,int id ) {
		int index=-1;
		for(int i=0;i<noOfapms;i++) {
			if(apm[i].Emp_Id==id) {
				index=i;
			}
		}
		return index;
	}
	
}

class Project_Manager extends Employee{
	
	//Method to read details of the Project Manager
	void read() {
		Scanner spm=new Scanner(System.in);
		read_details();
		Emp_Designation="Project Manager";
		System.out.println("Enter basic pay : ");
		double x=spm.nextDouble();
		if(x<90000.0 && x>=70000.0) {
			BP=x;
		}
		else {
			System.out.println("The basic pay must be between 70000 and 90000\nEnter the basic pay : ");
			BP=spm.nextDouble();
		}
	}
	
	//static method to search an Project Manager in the company
	static int searchPM(Project_Manager pm[],int noOfpms,int id ) {
		int index=-1;
		for(int i=0;i<noOfpms;i++) {
			if(pm[i].Emp_Id==id) {
				index=i;
			}
		}
		return index;
	}
}




public class inheritance
{

	public static void main(String[] args) {
		//creating arrays of programmers,team leads,assitant project managers and managers
		Programmer p[]=new Programmer[10];
		TeamLead t[]=new TeamLead[10];
		Assistant_Project_Manager apm[]=new Assistant_Project_Manager[10];
		Project_Manager pm[]=new Project_Manager[10];
		
		Scanner s=new Scanner(System.in);
		
		int ch=1,option;
		int i=0,j=0,k=0,l=0,m=0;
		while(ch!=0) {
			
		System.out.println("Select \n1.to recruit programmer\n2.to recruit teamlead\n3.to recruit assistant project manager\n4.to recruit project manager\n5.to display Salary Slip of a Programmer\n6.to display Salary Slip of a Team Lead\n7.to display Salary Slip of a Assistant Project Manager\n8.to display Salary Slip of a Project Manager\n9.to display no of employees in company\n10.to display basic details of all employees in the company\n");
			option=s.nextInt();
			switch (option) {
			
			case 0:break;
			case 1:
				p[i]=new Programmer();
				p[i].read();
				i++;
				m++;
				break;
			case 2:
				t[j]=new TeamLead();
				t[j].read();
				m++;
				j++;
				break;
			case 3:
				apm[k]=new Assistant_Project_Manager();
				apm[k].read();
				m++;
				k++;
				break;
			case 4:
				pm[l]=new Project_Manager();
				pm[l].read();
				m++;
				l++;
				break;

			case 5:
				System.out.println("Enter Id of programmer you want to search : ");
				int pID=s.nextInt();
				int index=Programmer.searchP(p,i,pID);
				if(index==-1) {
					System.out.println("Programmer not found with "+pID);
				}
				else {
					System.out.println("Programmer found...");
					p[index].display();
				}
				break;
			case 6:
				System.out.println("Enter Id of Team Lead you want to search : ");
				int tID=s.nextInt();
				int c=TeamLead.searchTL(t,j,tID);
				if(c==-1) {
					System.out.println("Team Lead not found with "+tID);
				}
				else {
					System.out.println("Team Lead found...");
					t[c].display();
				}
				break;
			case 7:
				System.out.println("Enter Id of Assistant Project Manager you want to search:");
				int apmID=s.nextInt();
				int d=Assistant_Project_Manager.searchAPM(apm,k,apmID);
				if(d==-1) {
					System.out.println("Assistant Project Manager not found with "+apmID);
				}
				else {
					System.out.println("Assistant Project Manager found...");
					apm[d].display();
				}
				break;
				
			case 8:
				System.out.println("Enter Id of Project Manager you want to search:");
				int pmID=s.nextInt();
				int e=Project_Manager.searchPM(pm,l,pmID);
				if(e==-1) {
					System.out.println("Project Manager not found with "+pmID);
				}
				else {
					System.out.println("Project Manager found...");
					pm[e].display();
				}
				break;
				
			case 9:
				System.out.println("The total number of employees in the company :"+m+"\n");
				break;
			case 10:

				for(int n=0;n<i;n++) {
					p[n].display_details();
				}
				
				for(int n=0;n<j;n++) {
					t[n].display_details();
				}
				
				for(int n=0;n<k;n++) {
					apm[n].display_details();
				}
				

				for(int n=0;n<l;n++) {
					pm[n].display_details();
				}
				
				break;				
			
			
			
			
			default:
				System.out.println("Enter a valid option.........");
			}
			System.out.println("Enter 1 to continue : ");
			ch=s.nextInt();
			
		}

	}

}
