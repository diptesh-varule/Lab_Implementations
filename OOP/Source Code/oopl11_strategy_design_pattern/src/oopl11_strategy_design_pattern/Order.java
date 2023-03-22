package oopl11_strategy_design_pattern;

public class Order {

	private final PaymentProcessor paymentProcessor;//declaration of paymentProcessor object
	private final int amount;//declaration of amount
	   
	//Order Method
	public Order(int amount, PaymentProcessor paymentProcessor) {
	     this.amount = amount;//storing value
	     this.paymentProcessor = paymentProcessor;//storing value
	   }
	   
	//process Method
	public void process() {
	     paymentProcessor.pay(amount);//calling pay method
	   }
}
