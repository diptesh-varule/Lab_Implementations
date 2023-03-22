package oopl11_strategy_design_pattern;

public class PayPal implements PaymentProcessor {
	
	//Constructor of PayPal class
	public PayPal(){
		super();//calling parent class constructor
		System.out.println("\nChecking Internet Connection........");  
	   }
	   
	@Override
	 public void pay(int amount) { 	//method for payment
		System.out.println("----------------------------------------------------------");
		System.out.println("Paying through PayPal payment: Charging $" + amount);
		System.out.println("----------------------------------------------------------");
	  }
}
