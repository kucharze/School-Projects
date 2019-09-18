/**
 * Auto Generated Java Class.
 */
public class PTemployee extends Bemployee implements Employee {
  public double pay;
  public int hours;
  public int id;
  public static int numPTemployees;
  public double basePay;
  
  public PTemployee(int id, int hours,double basePay){
    super(id,"PT",hours, basePay);
    numPTemployees++;
  }
  
  public double getPay(){
    return basePay;
  }

  public int getHours(){
    return hours;
  }
  
  public double calculatePay(double basePay,int hours){//calcuates the weekly pay
    pay=(basePay*hours);
    return pay;
  }
  
  /* ADD YOUR CODE HERE */
  
}
