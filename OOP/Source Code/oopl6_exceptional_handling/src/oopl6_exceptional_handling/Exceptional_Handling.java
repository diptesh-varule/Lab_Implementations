package oopl6_exceptional_handling;

public class Exceptional_Handling {
	double t;//data member

	Exceptional_Handling()//default constructor
	{

	}

	void divide(int x,int y) throws ArithmeticException//use of throws in a method
	{
	if (y==0)
	{
	throw new ArithmeticException("Zero error");//throwing an exception
	}
	else {
	t=(double)x/(double)y;
	this.display(t);
	}
	}

	void display(double t)
	{
	System.out.println("The division is : "+t);
	}



	public static void main(String args[])
	{
	Exceptional_Handling obj=new Exceptional_Handling();
	int a = args.length;//using command line arguments
	int b=0,c=0;//initialising value 

	//try catch block
	try
	{
	b=Integer.parseInt(args[0]);
	c=Integer.parseInt(args[1]);
	}

	catch(NumberFormatException e)
	{
	System.out.println("Arguments given are not integer : "+e);
	}

	catch(ArrayIndexOutOfBoundsException e)
	{
	System.out.println("Array index out of bound : "+e);
	}


	//try catch finally block
	try
	{
	obj.divide(b,c);
	}

	catch(ArithmeticException e)
	{ 
	System.out.println("Divide by 0 :"+e);
	}

	finally
	{
	System.out.println("finally block executed");
	}
	System.out.println("Outside try-finally clause");
	}
}

