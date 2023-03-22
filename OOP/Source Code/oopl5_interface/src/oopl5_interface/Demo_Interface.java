package oopl5_interface;
import java.util.*;

interface printable{
	void print();
}

interface Vehicles{
	Scanner sc=new Scanner(System.in);
	double gear=1;
	double speed=10;
	void Gearchange();
	void Speedup();
	void applybreaks();
}
class bicycle implements Vehicles{
	public void Gearchange() {
		System.out.println("gear is not available to the bicycle");
	}
	public void Speedup() {
		System.out.println("enter the speed you want ");
		double s=sc.nextDouble();
		System.out.println("speed is changed from "+speed+" to "+s);
	}
	public void applybreaks() {
		System.out.println("breaks applied");
	}
}

class bike implements Vehicles{
    
	public void Gearchange() {
		System.out.println("enter the gear to be ");
		double g=sc.nextDouble();
		System.out.println("gear is changed from: "+gear+" to "+g);
		}
	
	public void Speedup() {
		System.out.println("enter the speed you want ");
		double s=sc.nextDouble();
		System.out.println("speed is changed from "+speed+" to "+s);
	}
	public void applybreaks() {
		System.out.println("breaks applied\n");
	}
}

class car implements Vehicles{
	public void Gearchange() {
		System.out.println("enter the gear to be ");
		double g=sc.nextDouble();
		System.out.println("gear is changed from: "+gear+" to "+g);
		}
	
	public void Speedup() {
		System.out.println("enter the speed you want ");
		double s=sc.nextDouble();
		System.out.println("speed is changed from "+speed+" to "+s);
	}
	public void applybreaks() {
		System.out.println("breaks applied\n");
	}
}

public class Demo_Interface {

	public static void main(String[] args) {
		bicycle bmx=new bicycle();
		car mustang=new car();
		bike thunder=new bike();
		
		int choice=0;
		Scanner s=new Scanner(System.in);
		while(choice!=4) {
			System.out.println("1)for bicycle");
			System.out.println("2)for bike");
			System.out.println("3)for car");
			System.out.println("to exit");
			choice=s.nextInt();
			switch(choice) {
			case 1:int ch=0;
			while(ch!=4) {
				System.out.println("1)to gear change");
				System.out.println("2)to speed up");
				System.out.println("3)to apply breaks");
				System.out.println("to exit");
				System.out.println("enter choice ");
				ch=s.nextInt();
				switch(ch) {
				case 1:bmx.Gearchange();
				break;
				case 2:bmx.Speedup();
				break;
				case 3:bmx.applybreaks();
				break;
				default:break;
				}
			}
			break;
			case 2:int c=0;
			while(c!=4) {
				System.out.println("1)to gear change");
				System.out.println("2)to spped up");
				System.out.println("3)to apply breaks");
				System.out.println("4)to exit");
				System.out.println("enter choice ");
				c=s.nextInt();
				switch(c) {
				case 1:thunder.Gearchange();
				break;
				case 2:thunder.Speedup();
				break;
				case 3:thunder.applybreaks();
				break;
				default:break;
				}
			}
			break;
			case 3:int cho=0;
			while(cho!=4) {
				System.out.println("1)to gear change");
				System.out.println("2)to spped up");
				System.out.println("3)to apply breaks");
				System.out.println("4)to exit");
				System.out.println("enter choice ");
				cho=s.nextInt();
				switch(cho) {
				case 1:thunder.Gearchange();
				break;
				case 2:thunder.Speedup();
				break;
				case 3:thunder.applybreaks();
				break;
				default:break;
				}
			}
			break;
			case 4:System.out.println("exit");
			break;
			default:break;
			}
					
		}
			
		
	}

}

