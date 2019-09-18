import java.util.Scanner;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
public class LDatabase {
	static int numfiles=0;
	public static ArrayList<String> dbfile=new ArrayList<>();
	public static ArrayList<ArrayList<String>> files =new ArrayList<>();
	public static Scanner sc=new Scanner(System.in);
	
	public static void createTable() throws IOException {//Creates a new table
		int size=0;
		
		System.out.println("Enter table name");
		String name=sc.next();
		files.add(new ArrayList<String>());
		files.get(numfiles).add(name);
		PrintWriter file = new PrintWriter("C:\\\\Users\\Zack\\Desktop\\" + name+ ".dbf", "UTF-8");
		file.println(name);
		System.out.println("Enter Column name");
		String col=sc.next();
		
		int next=0;
		System.out.println("Enter Column Width");
		int length=sc.nextInt();
		
		while(true) {//if(str != null && !str.isEmpty())
			int space=length-col.length();
			files.get(numfiles).add(col);
			files.get(numfiles).add(String.valueOf(length));
			file.print(col+":");
			for(int i=0; i<(space-1); i++) {
				file.print(" ");
			}
			//files.get(numfiles).add();
			size=length+size;
			System.out.println("Enter another column? yes=1 no=2");
			next = sc.nextInt();
			if(next==2) {
				break;
			}
			System.out.println("Enter Column name");
			col=sc.next();
			//System.out.println(col.length());
			System.out.println("Enter Column width");
			length=sc.nextInt();
		}
		file.println();
		FileWriter fw = new FileWriter("C:\\\\Users\\Zack\\Desktop\\dbFiles.dbf",true);
		dbfile.add(name);
		dbfile.add(String.valueOf(size));
		fw.append(name + "  " + size);
		fw.append(System.lineSeparator());
		file.close();
		fw.close();
		numfiles++;
	}
	
	public static boolean isNumeric(String str)//Helper function for use in insert
	{  
	  try  
	  {  
	    double d = Double.parseDouble(str);  
	  }  
	  catch(NumberFormatException nfe)  
	  {  
	    return false;  
	  }  
	  return true;  
	}

	public static void insert() throws IOException{
		System.out.println("Enter file name to add to");
		String name=sc.next();
		int con=0;
		int file=-1;
		for(int i=0; i<files.size(); i++) {
			if(files.get(i).contains(name)) {
				if(files.get(i).indexOf(name)==0) {
					file=i;
					break;
				}
			}
		}
		
		if(file==-1) {
			System.out.println("Database not found");
			return;
		}
		
		FileWriter fw = new FileWriter("C:\\\\Users\\Zack\\Desktop\\" + name+ ".dbf",true);
		ArrayList<String> data=files.get(file);
		int spot=1;
		String tab = "";
		String entry="";
		while(true) {
			System.out.println(data.get(spot) + ":");
			entry=sc.next();
			spot=spot+1;
			if(entry.length()>Integer.valueOf(data.get(spot))) {
				entry=entry.substring(0,Integer.valueOf(data.get(spot)));
			}
			String e="";
			for(int i=0; i<Integer.valueOf(data.get(spot)); i++){
				if(i>=entry.length()) {
					data.add(" ");
					tab+=" ";
				}
				else {
					e=""+entry.charAt(i);
					tab+=entry.charAt(i);
					data.add(e);
				}
			}
			spot=spot+1;
			fw.append(tab);
			tab="";
			if(data.get(spot).length()==1 && !isNumeric(data.get(spot+1))) {
				fw.append(System.lineSeparator());
				System.out.println("More Entries (Yes=1/No=2)");
				con=sc.nextInt();
				if(con==1) {
					spot=1;
				}
				else {
					break;
				}
			}
		}
		fw.close();
	}
	
	public static void remove() throws IOException {//Finds a given entry in a file to be deleted
		System.out.println("Enter file name to delete from");
		String name=sc.next();
		int file=-1;
		int size=0;
		for(int i=0; i<files.size(); i++) {
			if(files.get(i).contains(name)) {
				if(files.get(i).indexOf(name)==0) {
					file=i;
					break;
				}
			}
		}
		
		if(file==-1) {
			System.out.println("File doesn't exist");
			return;
		}
		
		ArrayList<String> data=files.get(file);
		int spot=1;
		
		int pos=dbfile.indexOf(name);
		size=Integer.valueOf(dbfile.get(pos+1));
		
		while(data.get(spot).length()!=1) {
			spot++;
		}
		System.out.println("How many columns will be used for deletion");
		int c=sc.nextInt();
		String delete[]=new String[c];
		boolean d[]=new boolean[c];
		for(int i=0; i<c; i++) {
			d[i]=false;
		}
		System.out.println("Input column entries to be deleted");
		for(int i=0; i<c; i++) {
			delete[i]=sc.next();
		}
		boolean deleted=false;
		boolean todelete=false;
		ArrayList<String> list=new ArrayList<>();
		BufferedReader reader=new BufferedReader(new FileReader("C:\\\\Users\\Zack\\Desktop\\" + name+ ".dbf"));
		String text="";
		int location=0;
		System.out.println("About to loop");
		text=reader.readLine();
		while ((text = reader.readLine()) != null) {
			if(!deleted && location>1) {
				for(int i=0; i<c; i++) {
					System.out.println("Inside for loop");
					if(text.contains(delete[i])) {
						d[i]=true;
						continue;
					}
					else {
						todelete=false;
						break;
					}
				}
			
				for(int i=0; i<c; i++) {
					if(d[i]==false) {
						break;
					}
					else {
						d[i]=false;
						if(i==(c-1)) {
							todelete=true;
						}
					}
				}
				
			}
			
			if(todelete) {
				StringBuilder line=new StringBuilder(text);
				line.setCharAt(0, '#');
				list.add(line + "\n");
				data.add(spot,"#");
				todelete=false;
				deleted=true;
			}
			else {
				list.add(text+ "\n");
				spot+=size;
			}
			location++;
		}
		reader.close();
		if(!deleted) {
			System.out.println("No such entry exists");
			list.clear();
			return;
		}
		PrintWriter writer = new PrintWriter("C:\\\\Users\\Zack\\Desktop\\" + name+ ".dbf");
		
		for(int i=0; i<list.size(); i++) {
			writer.println(list.get(i));
		}
		
		writer.close();
	}
	
	public static void listFiles() throws IOException {//TODO
		System.out.println("Enter file name to print out");
		String name=sc.next();
		int file=-1;
		for(int i=0; i<files.size(); i++) {
			if(files.get(i).contains(name)) {
				if(files.get(i).indexOf(name)==0) {
					file=i;
					break;
				}
			}
		}
		
		if(file==-1) {
			System.out.println("Data File not found");
			return;
		}
		String line="";
		
		BufferedReader reader=new BufferedReader(new FileReader("C:\\\\Users\\Zack\\Desktop\\" + name+ ".dbf"));
		line=reader.readLine();
		int i=0;
		while((line) != null) {
			System.out.println("i=" + i);
			if(!line.contains("#"))
				System.out.println(line);
			line=reader.readLine();
			i++;
        } 
		System.out.println("End of file");
		reader.close();
	}
	
	
	public static void purge() throws IOException {
		PrintWriter purge=null;
		//PrintWriter writer = new PrintWriter("C:\\\\Users\\Zack\\Desktop\\" + name+ ".dbf");
		System.out.println("Deleting");
		for(int i=0; i<files.size(); i++) {
			purge=new PrintWriter("C:\\\\Users\\Zack\\Desktop\\" + files.get(i).get(0) + ".dbf");
			//purge.write(" ");
		}
		purge=new PrintWriter("C:\\\\Users\\Zack\\Desktop\\dbfiles.dbf");
		//purge.write(" ");
		
		purge.close();
	}

	public static void main(String[] args)  throws IOException{
		// TODO Auto-generated method stub
		PrintWriter writer = new PrintWriter("C:\\\\Users\\Zack\\Desktop\\dbFiles.dbf", "UTF-8");
		writer.println("DBFile");
		writer.close();
		
		System.out.println("Welcome to database. What would you like to do?");
		int option=0;
		while(true) {//The main interface for the database
			System.out.println("1.Create a table, 2.Insert an entry to a table");
			System.out.println("3.List all elements of a table");
			System.out.println("4.Remove an entry from a table 5.Exit and purge all tables");
			option=sc.nextInt();
			
			if(option==1) {//Done
				createTable();
			}
			else if(option==2) {//Done
				insert();
			}
			else if(option==3) {
				listFiles();
			}
			else if(option==4) {
				remove();
			}
			else {//Done
				purge();
				break;
			}
		}
		
		
	}

}