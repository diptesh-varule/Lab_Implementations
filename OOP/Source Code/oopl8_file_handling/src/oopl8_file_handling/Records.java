package oopl8_file_handling;
import java.io.*;
import java.util.*;
 
public class Records {
	static BufferedReader reader = new BufferedReader(new InputStreamReader(System.in)); 
	
	public void addNewRecord() throws IOException{
		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("record.txt",true)));
		String studentname, address;  
		int studentid, rollno, Class;  
		float marks;
		String s;
		boolean addMore = false;
		
		do  {  
		 System.out.print("\nEnter Student Name: ");
		studentname = reader.readLine();
		System.out.print("Student Id: ");
		studentid = Integer.parseInt(reader.readLine());
		System.out.print("Roll no: ");
		rollno = Integer.parseInt(reader.readLine());
		System.out.print("Address: ");
		address = reader.readLine();
		System.out.print("Class: ");
		Class = Integer.parseInt(reader.readLine());
		System.out.print("Marks : ");
		marks = Float.parseFloat(reader.readLine()); 
		
	

	
		writer.println(studentname+" "+studentid+" "+rollno+" "+address+" "+Class+" "+marks);    
		System.out.print("\nRecords added successfully !\n\nDo you want to add more records ? (y/n) : ");
		s = reader.readLine();
		if(s.equalsIgnoreCase("y"))   
		{    addMore = true;    
			System.out.println();
		}
		else   
		{ addMore = false;  
		} 
		}while(addMore);
		writer.close();
		DisplayMenu();
		
		
	}
	
	
	//method to read the data in records 
	public void readRecords() throws IOException  { 
		try  { 
			
			BufferedReader file = new BufferedReader(new   FileReader("record.txt"));
			String line;
			
			while((line = file.readLine()) != null) 
			{    System.out.println(line);  
				 System.out.println("");     
			} 
			file.close();
			DisplayMenu();
			}
		catch(FileNotFoundException e)  
		{   System.out.println("\nERROR : File not Found !!!");  
		}  
	}
	
	
	//method to delete the data in records
	public void deleteRecords() throws IOException  {
			try  { 
				 
				BufferedReader file1 = new BufferedReader(new FileReader("record.txt"));
				PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter("record1.txt",true))); 
				String line;
				int flag=0;
				Scanner sc=new Scanner(System.in);
				System.out.print("Enter the name of the student you want to delete: ");
				String searchname=sc.next();
				
				// Read records from the file
				while((line = file1.readLine()) != null)   
				{     String[] lines = line.split(" ");   
				//System.out.println(line[0]);    
				if(!searchname.equalsIgnoreCase(lines[0]))
				{                writer.println(line);
									flag=0;           
				} 
				else  
				{       System.out.println("Record found");
						flag=1;
				}       
			}   
			file1.close();
			writer.close();
			
			File delFileName =  new File("record.txt");
			File oldFileName =  new File("record1.txt");
			File newFileName =   new File("record.txt");
			
			if(delFileName.delete()) 
				System.out.println("deleted successfully");
			else
				System.out.println("Error");
			if (oldFileName.renameTo(newFileName))
				System.out.println("Renamed successfully");
			else
				System.out.println("Error"); 
			DisplayMenu();
			}
			catch(FileNotFoundException e)
			{   System.out.println("\nERROR : File not Found !!!");  
			}  
		}
	
	//method to search the data in records
	public void searchRecords() throws IOException  {
		try  { 
			// Open the file 
			BufferedReader file = new BufferedReader(new   FileReader("record.txt"));
			String name;
			int flag=0;
			Scanner sc=new Scanner(System.in);
			System.out.print("Enter an id of the student you want to search: "); 
			String searchname=sc.next(); 
			// Read records from the file
			while((name = file.readLine()) != null)   
			{     String[] line = name.split(" "); 
			//System.out.println(line[0]);
			if(searchname.equalsIgnoreCase(line[1]))
			{        System.out.println("Record found");        
					 System.out.println(name);
					 System.out.println("");
					 flag=1;
					 break;
					 }
			}
			
			if(flag==0)       System.out.println("Record not found");
			file.close();
			DisplayMenu();
			}
		catch(FileNotFoundException e)  
		{   System.out.println("\nERROR : File not Found !!!");  
		}
	}
	
	//method to update the data in records
	public void updateRecords() throws IOException  {
		try  {   // Open the file  
			BufferedReader file1 = new BufferedReader(new FileReader("record.txt"));   
			PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("record1.txt",true)));
			String name;  
			int flag=0;  
			Scanner sc=new Scanner(System.in);
			System.out.print("Enter the name of the student you want to update: ");
			String searchname=sc.next();
			// Read records from the file   
			while((name = file1.readLine()) != null)   
			{     String[] line = name.split(" ");   
			//System.out.println(line[0]);  
			if(!searchname.equalsIgnoreCase(line[0]))
			{                pw.println(name);
							flag=0; 
			}  
			else    {       
				System.out.println("Record found");       
				System.out.println("Enter updated marks:");  
				String up_mark=sc.next(); 
				pw.println(line[0]+" "+line[1]+" "+line[2]+" "+line[3]+" "+line[4]+" "+up_mark);  
				flag=1;   
				}       
			}  
			
			file1.close();   
			pw.close();    
			File delName =  new File("record.txt");    
			File oldName =  new File("record1.txt");        
			File newName =   new File("record.txt");          
			if(delName.delete())             System.out.println("record updated successfully"); 
			else             System.out.println("Error");    
			if (oldName.renameTo(newName))               System.out.println("Renamed successfully");
			else              System.out.println("Error");    
			DisplayMenu();  
			}  
		catch(FileNotFoundException e) 
		{   System.out.println("\nERROR : File not Found !!!");  
		}  
		} 
	
	
	//method to data the data in records
	public void clear(String filename) throws IOException  {
		// Create a blank file
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(filename))); 
		pw.close();
		System.out.println("\nAll Records cleared successfully !"); 
		for(int i=0;i<999999999;i++);
		// Wait for some time  DisplayMenu(); 
		} 
	
	//method to display the Main Menu
	public void DisplayMenu() throws IOException  {
		System.out.println("");
		System.out.print("**********Main Menu*********\n1. Add Records\n2. Display Records\n3. Clear All Records\n4. Search Records\n5. Delete Records\n6. Update Records \n7. Exit\n\nEnter your choice : ");
		int choice = Integer.parseInt(reader.readLine()); 
		System.out.println(""); 
		switch(choice)  { 
		case 1:    addNewRecord();
					break;
		case 2:    readRecords();
					break;
		case 3:    clear("record.txt");
					break; 
		case 4:     searchRecords();
					break;
		case 5:     deleteRecords();
					break;
		case 6:     updateRecords();
					break;   
		case 7:    System.exit(0);  
					break;
		default:    System.out.println("\nInvalid Choice !");
					break;  
					}  
		} 


	public static void main(String args[]) throws IOException  {
		Records operate = new Records();
		operate.DisplayMenu();
		} 
}

