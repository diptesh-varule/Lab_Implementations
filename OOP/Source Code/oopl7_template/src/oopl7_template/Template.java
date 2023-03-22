package oopl7_template;
import java.util.*;

public class Template {
	static int count;
	void num_op()
	{
		int element, choice, n;
		Scanner sc=new Scanner(System.in); 
		ArrayList<Integer> numlst=new ArrayList<Integer>();
		System.out.print("Enter the Number of Elements To be Entered : ");
		n=sc.nextInt();
		System.out.println("Enter the elements : \n");
		for(int i=0;i<n;i++)
		{
			System.out.print("Enter "+(i+1)+" Element : ");
			element=sc.nextInt();
			numlst.add(element);
		}
		System.out.println("Enter the choice : ");
		System.out.println("1. To check EVEN OR ODD \n2.To check PRIME OR NOT");
		System.out.print("Choice : ");
		choice=sc.nextInt();
		Iterator<Integer> itr=numlst.iterator();
		count=0;
		
			if(choice==1)
			{
				while(itr.hasNext())
				{
					int ele=(int)itr.next();
					if (isEven(ele))
					{
						System.out.println(ele+" is Even..!!");
						count++;
					}
					else if (isOdd(ele))
					{
						System.out.println(ele+" is Odd..!!");
					}
				}
			}
			else if(choice==2)
			{
				while(itr.hasNext())
				{
					int ele=(int)itr.next();
					if (isPrime(ele))
					{
						System.out.println(ele+" is Prime..!!");
						count++;
					}
					else
					{
						System.out.println(ele+" is Not Prime..!!");
					}
				}
			}
			else {
				System.out.println("Wrong Input Given..!!");
				}
		display(choice,count,n);
		
	}
	static void display(int choice,int count,int n)
	{
		if(choice==1) {
			System.out.println("The Total Even number's are : "+count);
			System.out.println("The Total Odd number's are : "+(n-count));
		}
		if(choice==2)
		{
			System.out.println("The total Prime Number's are : "+count);
		}
	}
	void stringop()
	{
		int   n;
		String element;
		Scanner sc=new Scanner(System.in);
		LinkedList<String> strlst=new LinkedList<String>();
		System.out.print("Enter the Number of Strings To be Entered : ");
		n=sc.nextInt();
		System.out.println("Enter the Strings : \n");
		sc.nextLine();
		for(int i=0;i<n;i++)
		{
			System.out.print("Enter "+(i+1)+" String : ");
			element=sc.nextLine();
			strlst.add(element);
		}
		count=0;
		for(String w:strlst)
		{
			if(isPalindrome((String)w))
			{
				System.out.println(w+" is a Palindrome");
				count++;
			}
			else {
				System.out.println(w+" is not a Palindrome");
			}
		}
	}
	static boolean isEven(int A)// Checking Number is Even
	{
		if(A%2==0)
		{
			return true;
		}
		return false;
	}
	static boolean isOdd(int B)// Checking Number is Odd
	{
		if(B%2!=0)
		{
			return true;
		}
		return false;
	}
	
	
	static boolean isPrime(int C)// Checking Number is Prime
	{
		for(int i = 2; i <= C/2; ++i)
        {
            // condition for nonprime number
            if(C % i == 0)
            {
              return false;
            }
        }
		return true;
	}
	static boolean isPalindrome(String str) 
    { 
		 String rev = "";
		 str=str.toLowerCase();
		 int length = str.length();
		 
	      for ( int i = length - 1; i >= 0; i-- )
	         rev = rev + str.charAt(i);
	      if (str.equals(rev))
	         return true;
	      else
	         return false;
        
    }

}
