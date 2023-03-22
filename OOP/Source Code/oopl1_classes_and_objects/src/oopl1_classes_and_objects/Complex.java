package oopl1_classes_and_objects;
import java.util.*;

//Created a default class Complex_Op
class Complex_Op {
	private int real,imag;
	
	//initialised real and imaginary value of a complex number by using default constructor 
	Complex_Op(){
		real=0;
		imag=0;
		}
		
	//parameterised constructor
	Complex_Op(int x,int y){
		real=x;
		imag=y;
		
	}
	//method to perform addition of two complex number 
	void add(Complex_Op a,Complex_Op b) {
		real=a.real+b.real;
		imag=a.imag+b.imag;
	}
	
	//method to perform subtraction of two complex number	
	void sub(Complex_Op a,Complex_Op b) {
		real=a.real-b.real;
		imag=a.imag-b.imag;	
	}
	
	//method to perform of two complex number	
	void product(Complex_Op a,Complex_Op b) {
		real=a.real*b.real-a.imag*b.imag;
		imag=a.real*b.imag+a.imag*b.real;
	}
	
	//method to perform division of two complex number	
	 void div(Complex_Op a,Complex_Op b) {
			Complex_Op  temp=new Complex_Op();
		int mod;
		mod=(b.real*b.real+b.imag*b.imag) ;
		 real=(a.real*b.real+a.imag*b.imag)/mod;
		 imag=(a.imag*b.real-a.real*b.imag)/mod;
		}
	
	void display() {
		System.out.println("Complex Number : "+real +" +"+ imag+"i");
		 }}


public class Complex{
	
	public static void main(String[] args) {
		int p,q;//p and q are real and imaginary part of complex number respectively
		
		System.out.println("Enter first number : ");
		Scanner sc=new Scanner(System.in);
		p=sc.nextInt();
		q=sc.nextInt();
		Complex_Op m=new Complex_Op(p,q);//passing values of p and q in the constructor for creating an object m
		
		System.out.println("Enter second number : ");
		p=sc.nextInt();
		q=sc.nextInt();
		Complex_Op n=new Complex_Op(p,q);//passing values of p and q in the constructor for creating an object m
		System.out.println("Select \n 1 to add \n 2 to subtract \n 3 to multiply \n 4 to divide  \n ");
		Complex_Op ans=new Complex_Op();//creating an object by using default constructor
		int x=sc.nextInt();
		
		
		switch (x) {
			case 1: ans.add(m,n);//method calling for adding two complex numbers
						ans.display();
						break;
			case 2: ans.sub(m,n);//method calling for subtracting two complex numbers
						ans.display();
						break;
			case 3: ans.product(m,n);//method calling for mutiplying two complex numbers
						ans.display();
						break;
			case 4 :ans.div(m,n);//method calling for dividing two complex numbers
						ans.display();
						break;
			default : System.out.println("Enter a valid input");
				}
		}

}

