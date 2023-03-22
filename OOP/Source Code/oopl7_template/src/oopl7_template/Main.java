package oopl7_template;

import java.util.Scanner;
class Main{
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
        Scanner sc =new Scanner(System.in);
		
		int Choice;
		do {
			System.out.println("\n\t\t** Menu **\n");
			System.out.println("Press 1 : To perform Number Operation");
			System.out.println("Press 2 : To perform String Operation");
			System.out.println("Press 3 : TO EXIT");
			System.out.print("\nChoice : ");
			Choice=sc.nextInt();
			Template f =new Template();
			switch(Choice)
			{
			case 1:
				f.num_op();
				break;
			case 2:
				f.stringop();
				break;
			}
		}while(Choice!=3);
	}

}
