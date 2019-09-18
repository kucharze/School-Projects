/**
 * Auto Generated Java Class.
 */
public class Intern extends Bemployee implements Employee {
  public int hours;
  public int id;
  public int pay;
  public static int numInterns;
  
  public Intern(int id,int hours){
    super(id, "I", hours, 0);
    System.out.println(id);
    numInterns++;
  }
  
  public double getPay(){//interns do not get paif
    return 0;
  }

  public int getHours(){
    return hours;
  }
  
  public double calculatePay(double basePay,int hours){//inters do not get paid
    return 0;
  }
  
  
  /* ADD YOUR CODE HERE */
  
}
