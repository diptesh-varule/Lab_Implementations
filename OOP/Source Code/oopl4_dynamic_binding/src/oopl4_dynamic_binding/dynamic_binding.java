package oopl4_dynamic_binding;

import java.util.*;

abstract class shape{
	double dim1,dim2;
	abstract void input();
	abstract double compute_area();
	
	//default constructor
	shape(){
	}
	
	//parameterised constructor
	shape(double dimension1,double dimension2){
		dim1=dimension1;
		dim2=dimension2;
	}

}

class triangle extends shape{
	//default constructor
	triangle(){
		
	}
	
	//parameterised constructor for using super constructor 
	triangle(double base,double height){
		super(base,height);
	}
	
	//input method to read the base and height of triangle
	void input() {
		Scanner s=new Scanner(System.in);
		System.out.println("Enter base : ");
		dim1=s.nextDouble();
		System.out.println("Enter height : ");
		dim2=s.nextDouble();
	}
	
	//method to compute area of triangle
	double compute_area() {
		return 0.5*dim1*dim2;
	}
}

class rectangle extends shape{
	//default constructor
	rectangle(){
		
	}
	
	//parameterised constructor for using super constructor 	
	rectangle(double length,double breadth){
		super(length,breadth);//calling super constructor
	}
	
	//input method to read the length and breadth of rectangle
	void input() {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter length : ");
		dim1=sc.nextDouble();
		System.out.println("Enter breadth : ");
		dim2=sc.nextDouble();
	}
	
	//method to compute area of rectangle
	double compute_area() {
	return dim1*dim2;
	}
}

public class dynamic_binding {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		double parameter1,parameter2;
		int option,ch=1;	

		Scanner s=new Scanner(System.in);

		while(ch==1) {
			
			System.out.println("Select \n1.Triangle\n2.Rectangle\n3.Exit");
			option=s.nextInt();
			
			switch(option) {
			case 1:
				shape t=new triangle();
				t.input();
				System.out.println("The area of triangle is : "+t.compute_area()+"\n");
				break;
			case 2:
				System.out.println("Enter length : ");
				parameter1=s.nextDouble();
				System.out.println("Enter breadth : ");
				parameter2=s.nextDouble();
				shape r=new rectangle(parameter1,parameter2);
				System.out.println("The area of rectangle is : "+r.compute_area()+"\n");
				break;
			case 3:
				System.exit(0);
			default:
				System.out.println("Enter valid input.........");
				
			}
			
		}
	}

}
