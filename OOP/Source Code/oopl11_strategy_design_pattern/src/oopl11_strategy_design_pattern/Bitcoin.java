package oopl11_strategy_design_pattern;
import java.util.*;

public class Bitcoin implements PaymentProcessor {
	Scanner sc =new Scanner (System.in);//creating object of scanner class
	String add;//declaration of add
	   
	//Constructor of BitCoin class
	public Bitcoin(){
		   super();//calling parent class constructor
		   System.out.print("\nEnter Transaction 'Input Address' :: ");//asking user of address
		   add= sc.next();//taking 'INPUT ADDRESS' as input from user
	   }
	
	@Override
	public void pay(int amount) { 	//method for payment
		  System.out.println("----------------------------------------------------------");
		    System.out.println("Paying through BitCoin payment: Charging $" + amount);
		    System.out.println("----------------------------------------------------------");
	  }
}
