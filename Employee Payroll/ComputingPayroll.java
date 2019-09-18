/*Zack Kuchar
 * February 17, 2016
 * Computing Payroll
 * This is a program where the user inputs employees into a database as well as each type of employee
 * and the program calculates the pay of each one.  The program will put each employee in order from
 * highest paid to lowest paid, it will print out the total number of each type of employee, and it will
 * print out the total number of pay and hours for each person entered combined
 * /

/**
 * Auto Generated Java Class.
 */
import java.util.Scanner;
public class ComputingPayroll {
  
  
  public static void main(String[] args) {
    int he=0;//number of hourly employees
    int pe=0;//number of part-time employees
    int ie=0;//number of interns
    int se=0;//nuber of salaried employees
    int hours=0;//variable for entering hours
    int id=0;//variable for entering the id
    int payPoint=0;//variable for inserting into array list of employees
    double hourlyPay=0;//variable for entering hourly pay
    Semployee s=null;
    Hemployee h=null;
    Intern i=null;
    PTemployee p=null;
    Scanner sc=new Scanner(System.in);
    
    //user inputs the number of each type of employee
    System.out.println("How many Hourly employees are there?");
    he=sc.nextInt();
    System.out.println("How many Part Time employees are there?");
    pe=sc.nextInt();
    System.out.println("How many Salaried employees are there?");
    se=sc.nextInt();
    System.out.println("How many Interns are there?");
    ie=sc.nextInt();
    Bemployee[] employeePay=new Bemployee[he+pe+se+ie];//list of all employees
    
    for(int k=0; k<he; k++){//obtains info for each hourly employee
      System.out.println("Enter the 5 digit id for the Hourly employee" + (k+1) + ".");
      id=sc.nextInt();
      System.out.println("Enter the hourly pay for the Hourly employee" + (k+1) + ".");
      hourlyPay=sc.nextDouble();
      System.out.println("Enter the hours worked for the Hourly employee" + (k+1) + ".");
      hours=sc.nextInt();
      h=new Hemployee(id, hours, hourlyPay);
      employeePay[payPoint]=h;//inserts employee into the list of employees
      payPoint++;
    }
    
    for(int k=0; k<ie; k++){//obtains info for each Intern
      System.out.println("Enter the id for Intern" + (k+1) + ".");
      id=sc.nextInt();
      System.out.println("Enter the hours worked for the Intern" + (k+1) + ".");
      hours=sc.nextInt();
      i= new Intern(id, hours);
      employeePay[payPoint]=i;//inserts the intern into the list of employees
      payPoint++;
    }
    
    for(int k=0; k<pe; k++){//obtains info for each Part-time employee
     System.out.println("Enter the 5 digit id for the Part time employee" + (k+1) + ".");
     id=sc.nextInt();
     System.out.println("Enter the hourly pay for the Part time employee" + (k+1) + ".");
     hourlyPay=sc.nextDouble();
     System.out.println("Enter the hours worked for the Part time employee" + (k+1) + ".");
     hours=sc.nextInt();
     p= new PTemployee(id,hours,hourlyPay);
     employeePay[payPoint]=p;//inserts employee into the list of employees
     payPoint++;
    }
    
    for(int k=0; k<se; k++){//obtains the info for each Salaried employee
     System.out.println("Enter the 5 digit id for the salaried employee" + (k+1) + ".");
     id=sc.nextInt();
     System.out.println("Enter the hourly pay for the Salaried employee" + (k+1) + ".");
     hourlyPay=sc.nextDouble();
     System.out.println("Enter the hours worked for the Salaried employee" + (k+1) + ".");
     hours=sc.nextInt();
     s=new Semployee(id, hours,hourlyPay);
     employeePay[payPoint]=s;//inserts employee into the list of employees
     payPoint++;
    }
    
    //organizes the array list in order of highest paid to lowest paid
    int num=employeePay.length;
    for(int k = 0; k < num-1; k++) {//code taken from class slides and modified
      boolean swapped = false;
      for(int j = 0; j < num-1-k; j++) {
        if(employeePay[j].compareTo(employeePay[j+1])==-1) {
          swap(employeePay, j, j+1);
          swapped = true;
        }
      }
      if(!swapped) break;
    }

    
    System.out.println("Here is the list of how good employees get paid from highest to lowest.");
    for(int k=0; k<employeePay.length; k++){//prints out each employee in order from highest paid to lowest paid
      System.out.println(employeePay[k]);
    }
    
    //prints out total pay, total hours, and total number of each type of empployee
    System.out.println("Each employee combined to make " + Bemployee.totPay+ " dollarsthis week.");
    System.out.println("Each employee worked " + Bemployee.totHours+ " this week.");
    System.out.println("There are " + Intern.numInterns + " Interns");
    System.out.println("There are " + Hemployee.numHemployees + " hourly employees.");
    System.out.println("There are " + Semployee.numSemployees + " salaried employees.");
    System.out.println("There are " + PTemployee.numPTemployees + " part time employees.");
     
    sc.close();
    
  }
  
  private static void swap(Bemployee[] employeePay, int i, int j) {//modified version of code from class slides
    // swaps the values of employeePay[i] and employeePay[j].
    Bemployee t = employeePay[i]; employeePay[i] = employeePay[j]; employeePay[j] = t;
  }

  
  /* ADD YOUR CODE HERE */
  
}
