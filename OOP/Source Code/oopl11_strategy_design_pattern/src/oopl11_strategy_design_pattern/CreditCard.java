package oopl11_strategy_design_pattern;
import java.util.Scanner;

public class CreditCard implements PaymentProcessor {
	  Scanner sc =new Scanner (System.in);//creating object of scanner class
	  String name,ExpDate;//declaration of name,ExpDate
	  double CardNo;//declaration of CardNo
	  
	  //Constructor of CreditCard class
	  public CreditCard(){ 
		  super();//calling parent class constructor

		  System.out.println("----------------------------------------------------------");
		  System.out.print("\tCard holder Name :: ");//printing on console
		  this.name =sc.next();//taking Card holder Name as input from user
		  System.out.print("\tCard Number :: ");//printing on console
		  this.CardNo =sc.nextDouble();//taking Card Number as input from user
		  System.out.print("\tCard Expire Date :: ");//printing on console
		  this.ExpDate =sc.next();//taking Card Expire Date as input from user
		  System.out.println("----------------------------------------------------------");
	  }
	  
	  @Override 
	  public void pay(int amount) { 	//method for payment
		  System.out.println("----------------------------------------------------------");
	      System.out.println("Paying through CreditCard payment: Charging $" + amount);
	      System.out.println("----------------------------------------------------------");
	  }


}

