package oopl2_polymorphism;
import java.util.*;

//Class Publication
class Publication{
	private String title;
	int copies;
	double price;
	static double TotalSale=0;
	

//read() method to read the details of the Publication
	void read() {
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the details for the following Entities...................");
		System.out.println("Enter the title :");
		title=sc.nextLine();
		System.out.println("Price_per_copy :");
		price=sc.nextDouble();
		System.out.println("No._of_copies :");
		copies=sc.nextInt();
	}

//display() method to display the details of the Publication
	void display() {
			System.out.println("The Details for the entity are as follows...................");
			System.out.println("Title                    : "+title);
			System.out.println("Price_per_Copy           : "+price);
			System.out.println("No. of copies available  : "+copies);
			
	}

//sellcopy() method to sell an entity of the Publication
	void sell_Copy() {
		Scanner ss=new Scanner(System.in);
		System.out.println("Enter no. of Copies to be sold : ");
		int x=ss.nextInt();
		if(x<copies) {
			System.out.println("Available for sale...........");
			double total=price*x;
			TotalSale+=total;
			copies=copies-x;
			System.out.println("The total bill is : "+total+" Rs.");
			System.out.println("Sold...............");
			System.out.println("No. of copies availble in stock : "+copies);
		}
		else {
			System.out.println("Out of Stock.....Try with less no of copies.");
		}
	}
	
	
}

//Class Book
class Book extends Publication{
	private String author;
	
//read_Book() method to read the details of the Book
	void read_Book(){
		read();
		Scanner s=new Scanner(System.in);
		System.out.println("Enter the author :");
		author=s.nextLine();
	}
	
//display_Book() method to display the details of the Book
	void display_Book() {
		display();
		System.out.println("Author                   : "+author);
	}
	
//orderCopies() method to order an entity of the Book
	void orderCopies() {
		System.out.println("The no. of copies available : "+copies);
		Scanner sb=new Scanner(System.in);
		System.out.println("Enter no. of Copies to be ordered : ");
		int y=sb.nextInt();
		copies=copies+y;
		System.out.println("The updated stock is : "+copies);
	}
	
}

//Class Magazine
class Magazine extends Publication{
	private int orderQty;
	private String month;
	
//read_Magazine() method to read the details of the Magazine
	void read_Magazine() {
		read();
		Scanner s=new Scanner(System.in);
		System.out.println("Enter the month of issue :");
		month=s.nextLine();

	}

//display_Magazine() method to display the details of the Magazine
	void display_Magazine() {
		display();
		System.out.println("Month of issue           : "+month);
	}
	
//receiveNewIssue() method to receive the new Edition of the Magazine
	void receiveNewIssue(){
		Scanner sd=new Scanner(System.in);
		System.out.println("Enter the new month of issue : ");
		String newMonth=sd.nextLine();
		month=newMonth;
	
		System.out.println("Enter the quantity of new magazines received : ");
		orderQty=sd.nextInt();
		copies=orderQty;
		
		display(); 
	}
	
}







//Class Polymorphism
public class Polymorphism {

	public static void main(String[] args) {

		Book a=new Book();
		Magazine b=new Magazine();
	
		int y=1;
		while(y==1) {
			Scanner sp=new Scanner(System.in);
			System.out.println("...........................Welcome to MyPublications..........................");
			System.out.println("Select from below \n 1.To read data for Book \n 2.To display details of a book \n 3.To salecopy of a book \n 4.To ordercopy of a book \n 5.To read data for Magazine \n 6.To display details of a Magazine \n 7.To salecopy of  magazine \n 8.To receive New Isssue of a Magazine \n 9.Exit");
			int x=sp.nextInt();
		
		switch(x) {
		case 1:
			a.read_Book();
			break;
		case 2:
			a.display_Book();
			break;
		case 3:
			a.sell_Copy();
			break;
		case 4:
			a.orderCopies();
			break;
		case 5:
			b.read_Magazine();
			break;
		case 6:
			b.display_Magazine();
			break;
		case 7:
			b.sell_Copy();
			break;
		case 8:
			b.receiveNewIssue();
			break;
		case 9:
			System.exit(0);
			break;
		default:
			System.out.println("Enter a Valid input");
		
		}
		System.out.println("Enter 1 to continue.........");
		y=sp.nextInt();
		}
		Publication p=new Publication();
		System.out.println("\n");
		System.out.println("The total sale for the day is : "+p.TotalSale);
	}
}

