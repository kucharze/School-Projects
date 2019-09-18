/**
 * Auto Generated Java Class.
 */
public class Semployee extends Bemployee implements Employee {
  public double pay;
  public int hours;
  public int id;
  public static int numSemployees;
  public int basePay;
  
  public Semployee(int id, int hours,double basePay){
    super(id,"S", hours, basePay);
    numSemployees++;
  }
  
  public double getPay(){
    return basePay;
  }

  public int getHours(){
    return hours;
  }
  
  public double calculatePay(double basePay,int hours){//calcualtes the weekly pay
    pay=((basePay)*hours);
    pay+=((pay) * .2);//calculation for benifits
    return pay;
  }
  
 
  
  /* ADD YOUR CODE HERE */
  
}
