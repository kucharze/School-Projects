import java.util.Scanner;
import java.util.Vector;
import java.util.ArrayList;
import java.sql.*;
import java.io.*;
//import sun.jdbc.odbc.* //may not need this
public class Accesdatabase {
	public static Scanner sc=new Scanner(System.in);
	public static ArrayList<ArrayList<String>> tables = new ArrayList<>();
	
	public static void create(Connection c) throws SQLException {
		System.out.println("Enter table name you would like to create");
		String t=sc.next();
		String column="";
		int size=0;
		Statement s=c.createStatement();
		int next=0;
		String create="Create Table "+ t + "(   ";
		//s.executeUpdate("Create Table"+ t + "(   )");
		//String create = "CREATE TABLE Books(Name VARCHAR(20), Price CURRENCY)";
		while(true) {
			System.out.println("Enter Column name");
			column=sc.next();
			System.out.println("Enter column size");
			size=sc.nextInt();
			create+=column + " ";
			create+="VARCHAR("+size+")";
			System.out.println("Add another column? 1.Yes 2.No");
			next=sc.nextInt();
			if(next==2) {
				create+=")";
				break;
			}
			else {
				create+=", ";
			}
		}
		try {
			s.executeUpdate(create);
		}catch(SQLException e) {
			System.out.println("Error: Table already exists");
		}
	}
	
	//Helper class for use in insert grabbed from handout with code
	public static Vector<String> getColumnNames(ResultSet results) throws SQLException{
		Vector<String> columnNames=new Vector<>();
		ResultSetMetaData metaData =results.getMetaData();
		int columnCount = metaData.getColumnCount();
		//System.out.println("ColumnCount = " + columnCount);
		for(int i=1; i<=columnCount; i++) {
			columnNames.add(metaData.getColumnName(i));
		}
		
		return columnNames;
	}
	
	public static void insert(Connection c) throws SQLException{
		System.out.println("Enter table to insert into?");
		String t=sc.next();
		//boolean exists=false;
		String grab="Select * From " +t;
		Statement s=c.createStatement();
		ResultSet r=null;
		try {
			r=s.executeQuery(grab);
		}catch(SQLException e) {
			System.out.println("Table does not exist");
			return;
		}

		//ResultSet test=s.executeQuery(grab);
		//System.out.println("column count" + test.getCo);
		Vector<String> filelist=getColumnNames(r);
		String entry="";
		String insert="INSERT INTO " + t + " VALUES (";
		
		//String sql = "INSERT INTO people (id, name) VALUES (?, ?)";
		for(int i=0; i<filelist.size(); i++) {
			if(i<filelist.size()-1) {
				insert+="?,";
			}
			else {
				insert+="?)";
			}
		}
		System.out.println(insert);
		PreparedStatement ps = c.prepareStatement(insert);
		//ps.setInt(1, id);
		//ps.setString(2, name);
		//ps.executeUpdate();
		///*
		for(int i=0; i<filelist.size(); i++) {
			//System.out.println("filelist.size= "+ filelist.size());
			System.out.println(filelist.get(i) + ":");
			entry=sc.next();
			if(isNumeric(entry) || entry.contains("-")) {
				entry="'"+entry + "'";
			}
			ps.setString((i+1),entry);
			
		}//*/
		try {
		ps.executeUpdate();
		}catch(SQLException e) {
			System.out.println("Error inputting data.");
			System.out.println("Either data for a row is too big or table does not exist");
		}
	}
	
	public static boolean isNumeric(String str)//Helper function for use in delete
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
	
	public static void delete(Connection c) throws SQLException {
		Vector<String> columnNames;
		System.out.println("Select a table to delete from?");
		String file=sc.next();
		String grab="Select * FROM "+file;
		String delete="Delete FROM "+file+" WHERE "; 
		//he='23';";
		Statement s=c.createStatement();
		
		ResultSet r=null;
		try {//check if the table actually exists
			r=s.executeQuery(grab);
		}catch(SQLException e) {
			System.out.println("Table does not exist");
			return;
		}
		
		columnNames=getColumnNames(r);
		
		PreparedStatement pd=null;
		
		String values[]=new String[columnNames.size()];
		int spot=0;
		///*
		while(true) {
			System.out.println("Select column names to be used for deletion from the following");
			for(int i=0; i<columnNames.size(); i++) {
				System.out.print((i+1)+"." + columnNames.get(i)+ "  ");
			}
			System.out.println();
			int option=sc.nextInt();
			delete+=columnNames.get(option-1)+" = ?";
			//columns[spot]=columnNames.get(option-1);
			System.out.println("Enter value of attribute to use for deletion");
			String value=sc.next();
			if(!isNumeric(value) && !value.contains("-") && !value.contains("_"))values[spot]=value;
			else { values[spot]="'"+ value+"'";}
			System.out.println("Use another value for deletion 1.Yes 2.No");
			int op=sc.nextInt();
			if(op==2) {
				delete+=";";
				spot++;
				break;
			}
			else {
				delete+=" AND ";
			}
		}//*/
		pd=c.prepareStatement(delete);
		//System.out.println(delete);
		//pd.executeUpdate(delete);
		//s.executeUpdate(delete);
		for(int i=0;i<columnNames.size(); i++) {
			if(values[i]!=null) {
				//System.out.println(values[i]);
				//System.out.println(columns[i]);
				pd.setString(i+1, values[i]);
			}
		}
		pd.executeUpdate();
	}
	
	//Helper file for use in listfile
	public static Vector getRows(ResultSet results) throws SQLException{
		Vector<Vector> rows=new Vector();
		ResultSetMetaData metaData= results.getMetaData();
		int columnCount=metaData.getColumnCount();
		
		while(results.next()) {
			Vector row=new Vector();
			for(int i=1; i<=columnCount; i++) {
				if(metaData.getColumnType(i) == Types.VARCHAR) {
					row.add(results.getString(i));
				}
				else if(metaData.getColumnType(i)==Types.INTEGER) {
					row.add(results.getInt(i));
				}
				else if(metaData.getColumnType(i)==2) {
					row.add(new Double(results.getDouble(i)));
				}
			}
			rows.add(row);
		}
		
		return rows;
	}
	
	public static void listfile(Connection c)throws SQLException {
		System.out.println("Enter file to pull from");
		String file=sc.next();
		String list="Select * FROM " + file;
		Statement s=c.createStatement();
		
		ResultSet r=null;
		try {
			r=s.executeQuery(list);
		}catch(SQLException e) {
			System.out.println("Table does not exist");
			return;
		}
		
		Vector columnnames=getColumnNames(r);
		Vector rows=getRows(r);
		System.out.println("Table " +file);
		for(int i=0; i<columnnames.size(); i++) {
			System.out.print(columnnames.get(i) + "   ");
		}
		System.out.println();
		
		
		for(int i=0; i<rows.size(); i++) {
			//for(int i=0; i<rows.get(i).s)
			System.out.println(rows.get(i));
		}
	}
	
	public static void addNewUser(Connection c) throws SQLException {
		String add="Insert INTO people Values(?,?)";
		PreparedStatement p = c.prepareStatement(add);
		System.out.println("SSN:");
		p.setString(1, sc.next());
		System.out.println("Name:");
		p.setString(2, sc.next());
		try {
			p.executeUpdate();}
		catch(SQLException e) {
			System.out.println("Error Inputing data");
		}
	}
	
	public static void addNewBook(Connection c) throws SQLException{
		String add="Insert into books Values(?,?,?);";
		PreparedStatement p = c.prepareStatement(add);
		System.out.println("Author:");
		p.setString(1, sc.next());
		System.out.println("Title:");
		p.setString(2, sc.next());
		System.out.println("callNo:");
		p.setString(3, sc.next());
		try {
		p.executeUpdate();}
		catch(SQLException e) {
			System.out.println("Error Inputing data");
		}
	}
	
	public static void findCheckedOutUsers(Connection c)throws SQLException {
		ArrayList<String> people=new ArrayList<>();
		ArrayList<String> book =new ArrayList<>();
		String pssn="Select SSN From people";
		String pname="Select name From people";
		String title="Select title From books";
		
		String np="Select name from people Where SSN=?";
		String co="Select callNo From checkedOutBooks Where SSN=?";
		String bo="Select title From books Where callNo=?";
		
		PreparedStatement p=c.prepareStatement(np);
		PreparedStatement check=c.prepareStatement(co);
		PreparedStatement books=c.prepareStatement(bo);
		
		Statement s=c.createStatement();
		ResultSet r=s.executeQuery(pssn);
		
		while(r.next()) {
			String sn=r.getString("SSN");
			String user="";
			p.setString(1, sn);
			check.setString(1,sn);
			ResultSet name=p.executeQuery();
			while(name.next()) {//Pull the user name
				user=name.getString("name");
			}
			ResultSet ch=check.executeQuery();
			if(ch.next()) {//Check if user SSN
				ch=check.executeQuery();
				System.out.println(user+ " Has checked out the following books:");
				while(ch.next()) {
					String ti=ch.getString("callNo");
					books.setString(1, ti);
					ResultSet b=books.executeQuery();
					while(b.next()) {
						System.out.println(b.getString("title"));
					}
					//System.out.println();
				}
			}else {
				
				System.out.println(user+" Has no books checked out");
			}
		}
		
	}
	
	public static void checkOut(Connection c) throws SQLException{
		ArrayList<String> list=new ArrayList<>();
		String checkout="Insert Into checkedOutBooks Values(?,?)";
		String findssn="Select SSN from people where SSN=?";
		String books="Select * From books";
		Statement b=c.createStatement();
		System.out.println("Enter SSN number of user");
		String ssn=sc.next();
		PreparedStatement people=c.prepareStatement(findssn);
		ssn="'"+ssn+"'";
		people.setString(1, ssn);
		ResultSet r=people.executeQuery();
		//StringBuilder i=null;
		if(r.next()) {//check to see if the user SSN exists
			//list.add(r.getString("SSN"));
			System.out.println(r.getString("SSN"));
			System.out.println("User ssn found");
			//}
		}
		else {
			System.out.println("Alert User SSN not found");
			return;
		}
		//System.out.println(list.get(0));
		//if(list.contains(ssn)) {
		//	System.out.println("User ssn found");
		//}
		//String findBook="Select callNo from books where callNo=?";
		
		Vector bookslist=getRows(b.executeQuery(books));
		while(true) {
			PreparedStatement ch=c.prepareStatement(checkout);
			ch.setString(1, ssn);
			String findBook="Select callNo from books where callNo=?";
			PreparedStatement book=c.prepareStatement(findBook);
			System.out.println("Select a callNo of a book to checkout");
			for(int i=0; i<bookslist.size(); i++) {
				System.out.println(bookslist.get(i));
			}
			String bookc=sc.next();
			book.setString(1, bookc);
			ResultSet booklist=book.executeQuery();
			if(booklist.next()) {//Book found
				ch.setString(2,bookc);
				ch.executeUpdate();
			}
			else {//No book with that callNo
				System.out.println("Book not found");
			}
			System.out.println("Checkout another book? 1.Yes 2.No");
			int option=sc.nextInt();
			if(option==2) {
				break;
			}
		}
	}
	
	public static void returnBook(Connection c) throws SQLException{
		String d="Delete From checkedOutBooks Where SSN = ? AND callNo = ?;";
		String cob="Select callNo From checkedOutBooks where SSN=?";
		String findssn="Select SSN from people where SSN=?";
		PreparedStatement find=c.prepareStatement(findssn);
		PreparedStatement books=c.prepareStatement(cob);
		PreparedStatement p=c.prepareStatement(d);
		System.out.println("Enter SSN number");
		String ssn=sc.next();

		ssn="'"+ssn+"'";
		find.setString(1, ssn);
		books.setString(1, ssn);
		ResultSet f=find.executeQuery();
		if(!f.next()) {//Checks if User SSN exists if not return
			System.out.println("User SSN not found");
			return;
		}
		Vector rows=getRows(books.executeQuery());
		System.out.println("Here are callNo's of books you checked out");
		for(int i=0; i<rows.size(); i++) {
			System.out.print(rows.get(i) + " ");
		}
		System.out.println();
		System.out.println("Enter call number of book taken out");
		String num=sc.next();
		p.setString(1, ssn);
		p.setString(2, num);
		p.executeUpdate();
	}

	public static void main(String[] args) throws IOException, SQLException {
		// TODO Auto-generated method stub
		
		Connection c=DriverManager.getConnection("jdbc:ucanaccess://c:/Users/Zack/Desktop/libraryn.accdb");
		System.out.println("Welcome to the library database. Whar would you like to do?");
		//System.out.println("1. Initial setup 2. Library operations);
		int option;
		//Statement s=c.createStatement();
		//s.executeQuery("Drop Table checkedOutBooks");
		while(true) {
			System.out.println("1.Database setup tools 2.Library user tools 3.Exit");
			int main=sc.nextInt();
			if(main==1){
				while(true) {
				System.out.println("1.Create a table 2.Include an entry in a table ");
				System.out.println("3.Delete an entry from a table 4.List the entries from a table");
				System.out.println("5.Back");
				option=sc.nextInt();
				if(option==1) {
					create(c);
				}
				else if(option==2) {
					insert(c);
				}
				else if(option==3) {
					delete(c);
				}
				else if(option==4) {
					listfile(c);
				}
				else if(option==5) {
					break;
				}
				}
			}
			else if(main==2) {
				while(true) {
				System.out.println("1.Add new book 2.Add new user");
				System.out.println("3.List users with checked out books");
				System.out.println("4.Check out a book 5 Return a book");
				System.out.println("6.Back");
				option=sc.nextInt();
				if(option==1) {
					addNewBook(c);
				}
				else if(option==2) {
					addNewUser(c);
				}
				else if(option==3) {
					findCheckedOutUsers(c);
				}
				else if(option==4) {
					checkOut(c);
				}
				else if(option==5) {
					returnBook(c);
				}
				else if(option==6) {
					break;
				}
				}
			}
			else {
				break;
			}
		}
		
		sc.close();
		/*
		 * System.out.println("Welcome to the library database what would you like to do?");
		 * System.out.println("1.Insert a new book 2.Insert a new user");
			System.out.println("3.List users with checked out books 4.Check out a book 5. Return a book");
			System.out.println("5.Exit");
		 */
	}

}
